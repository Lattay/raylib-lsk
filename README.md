# Lattay's Starter Kit

This is my small starter kit to quickly create Raylib games.

It contains a main game loop, a finite state machine to manage different screens,
a default start menu, credit screen and end screen, an empty default level and some helpers.

This is MIT licensed, feel free to use it, change it or anything.
If you ever make something with this I would be happy to ear about it.

## Usage

- In the Makefile replace `EXE=starter_kit` with `EXE=name_of_your_game`
- Change the content of credit.txt
- In the menu add the buttons you need
- Implement new states in separate files (always associate a C file with a header of the same name) using state.h.sample as a blueprint
for the header
- In main.h `StateName` enum add states **before** `STATE_NUM`, include headers **after** `#ifdef IMPLE_MAIN_LOOP` and add new `GameState` pointers in `states` array.
