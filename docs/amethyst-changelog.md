# Amehtyst Changelog

## Future game functionality

### Day night cycle

- Different times of day now display different tints on the overworld
- Night encounters have been added, see the POKéMON location table for more info
- POKéMON that evolve during a time of day have been adjusted to match the visuals for day & night
  - Day is from 7:01 am -> 8:00 pm
  - Night is from 8:01 pm -> 7:00 am

### Moves

- Physical & Special use the generation 4+ system, where it's determined by the move rather than the move type
- TMs can be used infinitely
- HMs can be overwritten by learned moves & TMs
- Your POKéMON no longer need to know HMs to use them in the overworld
  - You still need to have the HM and the required badge to use it
  - Fly can be used by selecting a POKéMON that could learn it from the party menu or by selecting your first POKéMON

### Omega Ruby & Alpha Sapphire

- EXP Share is a toggle-able key item that shares EXP to the whole party when it's on
  - The location of the EXP Share has been updated to the location from Omega Ruby & Alpha Sapphire
- Sheen no longer prevents eating POKéBLOCKS

### Breeding

- The daycare no longer gives EXP, and costs `$500` up front rather than `$100 + $100 * lvl` when retrieving the POKéMON
- Added the Destiny Knot, holding it causes 5 IVs to be inherited instead of 3
  - The Destiny Knot also maintains its held item effect in battle
- Bugfix for general IV inheritance that made it more difficult to inherit HP, ATK, & DEF IVs
- Added the Masuda method, where breeding with a POKéMON from a different language version of the game increases shiny chance
  - There is a new in-game trade for a French Ditto
    - ...that also has perfect IVs...

## Mon min-maxing

- A hyper trainer's house has been added just outside of Fallarbor Town
  - Each stat costs 1 bottle cap to train
  - Hyper trained IVs will NOT be passed down to children
  - A Hyper trained IV will display in red on the stats screen
- Nature mints have been added
  - The current nature of a POKéMON is always displayed in red on it's stats screen
  - The nature it will pass down when breeding is it's original nature, shown in parentheses when a nature mint has been used

### Shinies

- The Shiny Charm has been added, doubling the odds that a POKéMON is shiny
  - This stacks additively with the Masuda method for up to 8x more likely
- Shiny odds in general have been _drastically_ lowered

## General quality of life

- Text speed is faster, even at the fastest speed
- You can view a POKéMON's EVs and IVs from the stats menu by pressing A, L, or R
- Berry trees don't disappear until you've picked them

## New additions

### Items

- The LINK STONE has been added as an alternative to trade evolutions
  - You can still trade to evolve
  - If a POKéMON would evolve by being traded while holding an item, the link stone will only evolve the POKéMON if it's holding the correct item
- An Infinite repel has been added as a key item
  - It is toggleable on & off from the bag menu or can be registered

### Locations

- The Fortree Jungle has been added north east of Route 120
  - This area requires you to have defeated the Elite Four to access

## Updated POKéMON locations

Amethyst includes the ability to get all 386 POKéMON on a single save file without trading.

In general when encounters have been added to existing areas of the game, they've tried to replace POKéMON that are readily available elsewhere (or even in the same location). If a POKéMON is not listed in the table below, it is exactly where it is found in vanilla POKéMON Emerald.

For any overworld encounters of POKéMON, if accidentally defeated, they can be retried by first defeating the Elite Four again. Once caught, they will not respawn in this way.

| NationalDex # | POKéMON | Location                                | Encounter Odds |
| ------------- | ------- | --------------------------------------- | -------------- |
| 140           | Kabuto  | Fortree Jungle (Dome Fossil)            |                |
| 143           | Snorlax | Fortree Jungle (requires Blue Flute)    |                |
| 201           | Unown   | Tanoby Ruins (Fortree Jungle)           | 100%           |
| 251           | Celebi  | Fortree Jungle (requires Lugia & Ho-oh) |                |

## Update item locations

| Item          | Location                                                                    |
| ------------- | --------------------------------------------------------------------------- |
| EXP Share     | Devon researcher in Petalburg Woods                                         |
| Ever Repel    | Rustobro after delivering Steven's letter (replaces old Exp Share location) |
| Link Stone    | Fortree Jungle                                                              |
| Adamant Mint  | Fortree Jungle                                                              |
| Bold Mint     | Fortree Jungle                                                              |
| Destiny Knot  | French Ditto trade (held)                                                   |
| Strange Notes | Replaces the NUGGET in the Northeast area of the Safari Zone                |
| Mystic Ticket | Give Eugene an Unown in the Fortree Jungle                                  |
