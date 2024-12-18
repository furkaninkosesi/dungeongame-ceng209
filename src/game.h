#ifndef GAME_H
#define GAME_H
typedef struct
{
    int health;
    int strength;
    int coordinates_x;
    int coordinates_y;
    char *inventory;    // Player's inventory
    int inventory_count; // Number of items the player has
} Player;

typedef struct
{
    char name[50];
    int health;
    int strength;
} Creature;

typedef struct 
{
    Player player;
    int current_room;
} GameObject;


GameObject* _init_game();
void move_direction(char* direction, GameObject* game);
void check_state(GameObject* game);
void look_arround(GameObject* game);
void pickup_item(char* item ,GameObject* game);
void drop_item(char* item ,GameObject* game);
void attack(GameObject* game);
void save_game(GameObject* game, const char* filename);
void load_game(GameObject* game, const char* filename);
#endif