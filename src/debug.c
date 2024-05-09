#include "debug.h"
#include "event_object_movement.h"
#include "global.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "overworld.h"
#include "rtc.h"
#include "script.h"
#include "sound.h"
#include "window.h"
#include "constants/songs.h"

#if DEBUG_SYSTEM_ENABLE == TRUE

// Constants
#define DEBUG_MENU_WIDTH_MAIN 16
#define DEBUG_MENU_HEIGHT_MAIN 9

// Enums
enum { // Main
    DEBUG_MENU_ITEM_QUICK_START,
    DEBUG_MENU_ITEM_TEST_1,
    DEBUG_MENU_ITEM_TEST_2,
    DEBUG_MENU_ITEM_TEST_3,
    DEBUG_MENU_ITEM_TEST_4,
    DEBUG_MENU_ITEM_TEST_5,
    DEBUG_MENU_ITEM_TEST_6,
    DEBUG_MENU_ITEM_CANCEL
};

// Windows
static const struct WindowTemplate sDebugMenuWindowTemplateMain =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_MENU_WIDTH_MAIN,
    .height = DEBUG_MENU_HEIGHT_MAIN * 2,
    .paletteNum = 15,
    .baseBlock = 1,
};

// Define functions
static u8 Debug_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
static void Debug_DestroyMenu(u8 taskId);
static void Debug_RefreshListMenu(u8 taskId);

static void DebugTask_HandleMenuInput_Main(u8 taskId);

static void DebugAction_Cancel(u8 taskId);
static void DebugAction_QuickStart(u8 taskId);
static void DebugAction_Test_1(u8 taskId);
static void DebugAction_Test_2(u8 taskId);
static void DebugAction_Test_3(u8 taskId);
static void DebugAction_Test_4(u8 taskId);
static void DebugAction_Test_5(u8 taskId);
static void DebugAction_Test_6(u8 taskId);

// Scripts
extern u8 Debug_ShowFieldMessageStringVar4[];
extern u8 Debug_QuickStart[];
extern u8 Debug_Script_1[];
extern u8 Debug_Script_2[];
extern u8 Debug_Script_3[];
extern u8 Debug_Script_4[];
extern u8 Debug_Script_5[];
extern u8 Debug_Script_6[];

// Text
static const u8 sDebugText_QuickStart[]   = _("Quick Start");
static const u8 sDebugText_DebugTest1[]   = _("Time Day");
static const u8 sDebugText_DebugTest2[]   = _("Time Night");
static const u8 sDebugText_DebugTest3[]   = _("Test 3");
static const u8 sDebugText_DebugTest4[]   = _("Test 4");
static const u8 sDebugText_DebugTest5[]   = _("Test 5");
static const u8 sDebugText_DebugTest6[]   = _("Test 6");
static const u8 sDebugText_Cancel[]       = _("Cancel");

// Menu Actions
static void (*const sDebugMenu_Actions_Main[])(u8) =
{
    [DEBUG_MENU_ITEM_QUICK_START]     = DebugAction_QuickStart,
    [DEBUG_MENU_ITEM_TEST_1]          = DebugAction_Test_1,
    [DEBUG_MENU_ITEM_TEST_2]          = DebugAction_Test_2,
    [DEBUG_MENU_ITEM_TEST_3]          = DebugAction_Test_3,
    [DEBUG_MENU_ITEM_TEST_4]          = DebugAction_Test_4,
    [DEBUG_MENU_ITEM_TEST_5]          = DebugAction_Test_5,
    [DEBUG_MENU_ITEM_TEST_6]          = DebugAction_Test_6,
    [DEBUG_MENU_ITEM_CANCEL]          = DebugAction_Cancel
};

// List Menu Items
static const struct ListMenuItem sDebugMenu_Items_Main[] =
{
    [DEBUG_MENU_ITEM_QUICK_START]     = {sDebugText_QuickStart, DEBUG_MENU_ITEM_QUICK_START},
    [DEBUG_MENU_ITEM_TEST_1]          = {sDebugText_DebugTest1, DEBUG_MENU_ITEM_TEST_1},
    [DEBUG_MENU_ITEM_TEST_2]          = {sDebugText_DebugTest2, DEBUG_MENU_ITEM_TEST_2},
    [DEBUG_MENU_ITEM_TEST_3]          = {sDebugText_DebugTest3, DEBUG_MENU_ITEM_TEST_3},
    [DEBUG_MENU_ITEM_TEST_4]          = {sDebugText_DebugTest4, DEBUG_MENU_ITEM_TEST_4},
    [DEBUG_MENU_ITEM_TEST_5]          = {sDebugText_DebugTest5, DEBUG_MENU_ITEM_TEST_5},
    [DEBUG_MENU_ITEM_TEST_6]          = {sDebugText_DebugTest6, DEBUG_MENU_ITEM_TEST_6},
    [DEBUG_MENU_ITEM_CANCEL]          = {sDebugText_Cancel,     DEBUG_MENU_ITEM_CANCEL}
};

// List menu templates
static const struct ListMenuTemplate sDebugMenu_ListTemplate_Main =
{
    .items = sDebugMenu_Items_Main,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenu_Items_Main),
};

// Functions
void Debug_ShowMainMenu(void)
{
    Debug_ShowMenu(DebugTask_HandleMenuInput_Main, sDebugMenu_ListTemplate_Main);
}

static u8 Debug_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // Create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplateMain);
    DrawStdWindowFrame(windowId, FALSE);

    // Create list menu
    menuTemplate = LMtemplate;
    menuTemplate.maxShowed = DEBUG_MENU_HEIGHT_MAIN;
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = 1;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // Create input handler task
    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
    gTasks[inputTaskId].data[2] = 0;

    Debug_RefreshListMenu(inputTaskId);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // return taskId for use right after
    return inputTaskId;
}

static void Debug_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    DestroyTask(taskId);
    UnfreezeObjectEvents();
}

// TODO: Implement me
static void Debug_RefreshListMenu(u8 taskId)
{
    // Set list menu data
    gMultiuseListMenuTemplate.items = sDebugMenu_Items_Main;
    gMultiuseListMenuTemplate.totalItems = gMultiuseListMenuTemplate.totalItems;
    gMultiuseListMenuTemplate.maxShowed = DEBUG_MENU_HEIGHT_MAIN;
    gMultiuseListMenuTemplate.windowId = gTasks[taskId].data[1];
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.upText_Y = 1;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 1;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.lettersSpacing = 1;
    gMultiuseListMenuTemplate.itemVerticalPadding = 0;
    gMultiuseListMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    gMultiuseListMenuTemplate.fontId = 1;
    gMultiuseListMenuTemplate.cursorKind = 0;
}

static void DebugTask_HandleMenuInput_Main(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenu_Actions_Main[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMenu(taskId);
        ScriptContext_Enable();
    }
}

static void DebugAction_Cancel(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    ScriptContext_Enable();
}

static void DebugAction_QuickStart(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    ScriptContext_SetupScript(Debug_QuickStart);
}

static void DebugAction_Test_1(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    RtcInitLocalTimeOffset(12, 0);
    UpdateTimeOfDay();
    ScriptContext_SetupScript(Debug_Script_1);
}

static void DebugAction_Test_2(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    RtcInitLocalTimeOffset(22, 0);
    UpdateTimeOfDay();
    ScriptContext_SetupScript(Debug_Script_2);
}

static void DebugAction_Test_3(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    ScriptContext_SetupScript(Debug_Script_3);
}

static void DebugAction_Test_4(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    ScriptContext_SetupScript(Debug_Script_4);
}

static void DebugAction_Test_5(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    ScriptContext_SetupScript(Debug_Script_5);
}

static void DebugAction_Test_6(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    LockPlayerFieldControls();
    ScriptContext_SetupScript(Debug_Script_6);
}

#endif // DEBUG_SYSTEM_ENABLE