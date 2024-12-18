Dungeon Adventure Game This is a command-line-based dungeon exploration game written in C. The game allows players to explore rooms, interact with items, battle creatures, and manage inventory. The goal is to navigate through a dungeon, solve challenges, and survive.

Room Navigation: Move through various rooms in the dungeon. Combat: Engage in turn-based combat with creatures. Inventory: Manage your items and pick them up from rooms. Saving and Loading: Save your game state and load it later. Room Descriptions: Each room has a unique description and may contain items or creatures.

File Structure

/project-folder /src main.c # Main entry point of the game game.c # Core game logic game.h # Header file for game functions parser.c # Command parser parser.h # Header file for parser functions /build # Build directory where compiled binaries are placed Makefile # Makefile for compiling the project README.md # Project documentation

How to Build: make or mingw31-make.exe

How to play ./build/dungeon for windows: ./build/dungeon.exe

Gameplay: Once the game is running, you will be presented with a prompt to enter commands. You can perform actions like moving between rooms, looking around, attacking enemies, and managing your inventory.

Commands: The available commands during gameplay are:

move : Move to another room (e.g., move north, move east). look: View the current room's description and contents. inventory: List the items you currently have in your inventory. pickup : Pick up an item if it’s present in the room. attack: Attack a creature present in the room. save : Save your game state to a file. load : Load a previously saved game. exit: Exit the game.

Dependencies A C compiler (e.g., GCC or MinGW). A terminal or command-line interface to run the game.