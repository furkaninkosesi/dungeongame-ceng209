File Structure

    /project-folder
        /src
            main.c              # Main entry point of the game
            game.c              # Core game logic
            game.h              # Header file for game functions
            parser.c            # Command parser
            parser.h            # Header file for parser functions
        /build                   # Build directory where compiled binaries are placed
        Makefile                 # Makefile for compiling the project
        README.md               # Project documentation

How to Build
    make or mingw31-make.exe 

How to play
    ./build/dungeon
    for windows: 
    ./build/dungeon.exe

Commands: The available commands during gameplay are:

    move <direction>: Move to another room (e.g., move north, move east).
    look: View the current room's description and contents.
    inventory: List the items you currently have in your inventory.
    pickup <item>: Pick up an item if it’s present in the room.
    attack: Attack a creature present in the room.
    save <filename>: Save your game state to a file.
    load <filename>: Load a previously saved game.
    exit: Exit the game



Dungeon Adventure Game
This is a command-line-based dungeon exploration game written in C. The game allows players to explore rooms, interact with items, battle creatures, and manage inventory. The goal is to navigate through a dungeon, solve challenges, and survive.

Room Navigation: Move through various rooms in the dungeon.
Combat: Engage in turn-based combat with creatures.
Inventory: Manage your items and pick them up from rooms.
Saving and Loading: Save your game state and load it later.
Room Descriptions: Each room has a unique description and may contain items or creatures.
File Structure
bash
/project-folder
    /src
        main.c              # Main entry point of the game
        game.c              # Core game logic
        game.h              # Header file for game functions
        parser.c            # Command parser
        parser.h            # Header file for parser functions
    /build                   # Build directory where compiled binaries are placed
    Makefile                 # Makefile for compiling the project
    README.md               # Project documentation
How to Build
Clone the repository (if applicable):


git clone https://github.com/your-username/dungeon-game.git
cd dungeon-game
Compile the game: Make sure you have a C compiler installed (e.g., GCC or MinGW) and run:


make
This will compile all the source files and create an executable in the build/ directory.

How to Play
Run the game: After the build completes, run the following command to start the game:


./build/dungeon
On Windows, use:


./build/dungeon.exe
Gameplay: Once the game is running, you will be presented with a prompt to enter commands. You can perform actions like moving between rooms, looking around, attacking enemies, and managing your inventory.

Commands: The available commands during gameplay are:

move <direction>: Move to another room (e.g., move north, move east).
look: View the current room's description and contents.
inventory: List the items you currently have in your inventory.
pickup <item>: Pick up an item if it’s present in the room.
attack: Attack a creature present in the room.
save <filename>: Save your game state to a file.
load <filename>: Load a previously saved game.
exit: Exit the game.

Dependencies
    A C compiler (e.g., GCC or MinGW).
    A terminal or command-line interface to run the game.#   d u n g e o n g a m e - c e n g 2 0 9  
 