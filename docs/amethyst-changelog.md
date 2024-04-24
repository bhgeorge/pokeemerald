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
- Eggs hatch at lvl 1 instead of lvl 5
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

For any overworld encounters of POKéMON, if accidentally defeated, they can be retried by first defeating the Elite Four again. Once caught, they will not respawn in this way. Sudowoodo is the exception here, it will respawn forever each time you defeat the Elite Four.

| NationalDex # | POKéMON    | Location                                           | Encounter Odds |
| ------------- | ---------- | -------------------------------------------------- | -------------- |
| 001           | Bulbasaur  | Verdanturf Town (Friendship rater)                 |                |
| 004           | Charmander | Route 111 (Old Lady's Rest Stop)                   |                |
| 007           | Squirtle   | Devon Corporation 1F (After returning DEVON GOODS) |                |
| 010           | Caterpie   | Petalburg Woods                                    | 10%            |
| 016           | Pidgey     | Route 115                                          | 40%            |
| 017           | Pidgeotto  | Route 115                                          | 10%            |
| 021           | Spearow    | Route 123                                          | 8%             |
| 022           | Fearow     | Route 123                                          | 1%             |
| 029           | Nidoran F  | Route 116, Route 117                               | 4% / 20%       |
| 030           | Nidorina   | Old Lab Exterior                                   | 10%            |
| 031           | Nidoqueen  | Old Lab Exterior                                   | 1%             |
| 032           | Nidoran M  | Route 116, 117                                     | 4% / 20%       |
| 033           | Nidorino   | Old Lab Exterior                                   | 20%            |
| 046           | Paras      | Route 119                                          | 5%             |
| 050           | Diglett    | Meteor Falls 1F_1R                                 | 21%            |
| 051           | Dugtrio    | Meteor Falls 1F_2R                                 | 14%            |
| 056           | Mankey     | Safari Zone South                                  | 20%            |
| 058           | Growlithe  | Magma Hideout                                      | 5%             |
| 060           | Poliwag    | Route 114 (Surf)                                   | 30%            |
| 061           | Poliwhirl  | Route 114 (Surf)                                   | 5%             |
| 069           | Bellsprout | Route 119, Route 120                               | 25%            |
| 077           | Ponyta     | Safari Zone North                                  | 10%            |
| 079           | Slowpoke   | Route 120 (Grass or Surf)                          | 5% / 30%       |
| 080           | Slowbro    | Route 120 (Surf)                                   | 5%             |
| 083           | Farfetch'd | Dewford Town (Trade)                               |                |
| 086           | Seel       | Shoal Cave Entrance (Low tide)                     | 10%            |
| 087           | Dewgong    | Shoal Cave Entrance (Low tide)                     | 1%             |
| 090           | Shellder   | Underwater Route 124                               | 5%             |
| 095           | Onix       | Victory Road 1F                                    | 4%             |
| 097           | Hypno      | Fortree Jungle                                     | 4%             |
| 098           | Krabby     | Safari Zone Northwest (Surf)                       | 30%            |
| 102           | Exeggcute  | Fortree Jungle                                     | 20%            |
| 104           | Cubone     | Mt Pyre 4F, 5F, 6F                                 | 5%             |
| 108           | Lickitung  | Fortree Jungle                                     | 10%            |
| 113           | Chansey    | Safari Zone Southeast                              | 5%             |
| 114           | Tangela    | Route 123, Fortree Jungle                          | 10%            |
| 115           | Kangaskhan | Safari Zone Northeast                              | 5%             |
| 122           | Mr Mime    | Verdanturf Town (Trade)                            |                |
| 123           | Scyther    | Safari Zone Southeast                              | 10%            |
| 124           | Jynx       | Slateport City (Trade)                             |                |
| 125           | Electabuzz | New Mauville Inside                                | 1%             |
| 126           | Magmar     | Magma Hideout (any room with lava)                 | 1%             |
| 128           | Tauros     | Safari Zone South                                  | 1%             |
| 131           | Lapras     | Old Lab Island Cave                                |                |
| 133           | Eevee      | Mom's House (After helping Wally)                  |                |
| 137           | Porygon    | Game Corner                                        |                |
| 138           | Omanyte    | Shoal Cave Ice Room Expansion (Helix Fossil)       |                |
| 140           | Kabuto     | Fortree Jungle (Dome Fossil)                       |                |
| 142           | Aerodactyl | Navel Rock                                         |                |
| 143           | Snorlax    | Fortree Jungle (requires Blue Flute)               |                |
| 144           | Articuno   | Shoal Cave Ice Room Expansion                      |                |
| 145           | Zapdos     | New Mauville Expansion (requires being Champion)   |                |
| 146           | Moltres    | Mt Pyre Summit (requires being Champion)           |                |
| 147           | Dratini    | Old Lab Cave (Surf & Fish)                         | 5%             |
| 148           | Dragonair  | Old Lab Cave (Surf)                                | 1%             |
| 150           | Mewtwo     | Old Lab Island                                     |                |
| 152           | Chikorita  | See Jhoto Starters                                 |                |
| 155           | Cyndaquil  | See Jhoto Starters                                 |                |
| 158           | Totodile   | See Jhoto Starters                                 |                |
| 161           | Sentret    | Route 117                                          | 30%            |
| 166           | Ledian     | Fortree Jungle                                     | 10%            |
| 187           | Hoppip     | Fortree Jungle                                     | 4%             |
| 189           | Jumpluff   | Fortree Jungle                                     | 10%            |
| 193           | Yanma      | Fortree Jungle                                     | 10%            |
| 198           | Murkrow    | Old Lab Exterior                                   | 10%            |
| 200           | Misdreavus | Old Lab Cave                                       | 20%            |
| 201           | Unown      | Tanoby Ruins (Fortree Jungle)                      | 100%           |
| 206           | Dunsparce  | Old Lab Cave                                       | 24%            |
| 211           | Qwilfish   | Old Lab Cave (Surf & Fish)                         | 30%            |
| 215           | Sneasel    | Old Lab Exteriror                                  | 8%             |
| 220           | Swinub     | Shoal Cave Ice Room Expansion                      | 10%            |
| 225           | Delibird   | Shoal Cave Ice Room Expansion                      | 10%            |
| 226           | Mantine    | Old Lab Cave (Surf)                                | 60%            |
| 246           | Larvitar   | Old Lab Exterior, Old Lab Cave                     | 10%            |
| 247           | Pupitar    | Old Lab Cave                                       | 1%             |
| 251           | Celebi     | Fortree Jungle (requires Lugia & Ho-oh)            |                |

### Jhoto Starters

As a part of base Emerald, you get one of the Jhoto starters for completing the HOENN dex. Based on the one you choose you'll get the other two from the following new events:

#### Final Rival Battle

| Starter Chosen at Birch's lab | POKéMON Given |
| ----------------------------- | ------------- |
| Chikorita                     | Cyndaquil     |
| Cyndaquil                     | Totodile      |
| Totodile                      | Chikorita     |

#### ????

| Starter Chosen at Birch's lab | POKéMON Given |
| ----------------------------- | ------------- |
| Chikorita                     | Totodile      |
| Cyndaquil                     | Chikorita     |
| Totodile                      | Cyndaquil     |

## Updated item locations

### One-time

| Item          | Location                                                                    |
| ------------- | --------------------------------------------------------------------------- |
| EXP Share     | Devon researcher in Petalburg Woods                                         |
| Ever Repel    | Rustobro after delivering Steven's letter (replaces old Exp Share location) |
| Link Stone    | Fortree Jungle, Old Lab Island Cave                                         |
| Destiny Knot  | French Ditto trade (held)                                                   |
| Up-Grade      | Old Lab Island                                                              |
| Strange Notes | Replaces the NUGGET in the Northeast area of the Safari Zone                |
| Mystic Ticket | Give Eugene an Unown in the Fortree Jungle                                  |
| Old Sea Map   | Old Lab Island                                                              |
| Bottle Cap    | Old Lab Island Gatehouse                                                    |
| Adamant Mint  | Fortree Jungle                                                              |
| Bold Mint     | Fortree Jungle                                                              |
| Modest Mint   | Old Lab Island Cave                                                         |

### Repeatable

| Item | Location |
| ---- | -------- |
