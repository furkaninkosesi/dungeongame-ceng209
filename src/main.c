#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void display_stats(GameObject *game){
    printf("Coordinates X: %d, Coordinates Y: %d, Health: %d, Strenght: %d \n", game->player.coordinates_x, game->player.coordinates_y, game->player.health, game->player.strength);
}

void display_menu()
{
    printf("Available commands, type the number:\n");
    printf("e exit             : Exit the game.\n");
    printf("1 move <direction> : Move a direction (up, down, left, right).\n");
    printf("2 look             : Look around\n");
    printf("3 inventory        : Show your inventory.\n");
    printf("4 pickup <item name> : Pick up item in the floor.\n");
    printf("5 drop <item name>   : Drop item in the floor.\n");
    printf("6 attack           : Attack a creature.\n");
    printf("7 save             : Save the game state.\n");
    printf("8 load             : Load the game state.\n");
}

int main(){
    char filename[30] = "savegame.dat"; 
    GameObject *game = _init_game();
    while(1){ //game main loop
        printf("\n>> ");
        display_menu(); 
        display_stats(game); 

        printf("\n>> ");
    
        char command[15];
        char second[15]; // move <second>, load <second> second string!!!
        scanf("%s", command); 

        if (strcmp(command, "e") == 0 || strcmp(command, "exit") == 0) {
            printf("Exiting game...\n");
            exit(0);
        }

        if (strcmp(command, "1") == 0 || strcmp(command, "move") == 0) {
      
            scanf("%s", second);
            move_direction(second, game);
        }
        if (strcmp(command, "2") == 0 || strcmp(command, "look") == 0) {
      
            look_arround(game);
        }
        if (strcmp(command, "3") == 0 || strcmp(command, "inventory") == 0) {
      
            intventory_list(game);
        }
        if (strcmp(command, "4") == 0 || strcmp(command, "pickup") == 0) {
            scanf("%s", second);
            pickup_item(second, game);
        }
        if (strcmp(command, "5") == 0 || strcmp(command, "drop") == 0) {
            scanf("%s", second);
            drop_item(second, game);
        }
        if (strcmp(command, "6") == 0 || strcmp(command, "attack") == 0) {
            attack(game);
        }
        if (strcmp(command, "7") == 0 || strcmp(command, "save") == 0) {
            save_game(game, filename);
        }
        if (strcmp(command, "8") == 0 || strcmp(command, "load") == 0) {
            load_game(game, filename);
        }
        else{
            printf("invalid command");
        }

    }

    return 0;
}
