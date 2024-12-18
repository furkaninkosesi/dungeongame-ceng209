#include "game.h"
#include "rooms.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_INVENTORY 64
#define MAX_ITEMS 64
GameObject *_init_game()
{
    GameObject *game = malloc(sizeof(GameObject));
    game->player.coordinates_x = 0;
    game->player.coordinates_y = 0;
    game->player.health = 100;
    game->player.strength = 10;
    game->player.inventory_count = 1;
    game->player.inventory = malloc(64 * sizeof(char));
    game->current_room = 1;
    return game;
}
void remove_item_effects(char *item, GameObject *game)
{
    if (strcmp(item, "potion") == 0)
    {
        printf("You feel weaker... Health -20.\n");
        game->player.health -= 20;
        if (game->player.health < 0)
            game->player.health = 0;
    }
    else if (strcmp(item, "dagger") == 0)
    {
        printf("Your strength decreases... Strength -5.\n");
        game->player.strength -= 5;
        if (game->player.strength < 0)
            game->player.strength = 0;
    }
    else if (strcmp(item, "scroll") == 0)
    {
        printf("You feel your power fading... Strength -10.\n");
        game->player.strength -= 10;
        if (game->player.strength < 0)
            game->player.strength = 0;
    }
    else if (strcmp(item, "pekmez") == 0)
    {
        printf("You feel tired without pekmez... Health -10, Strength -2.\n");
        game->player.health -= 10;
        game->player.strength -= 2;
        if (game->player.health < 0)
            game->player.health = 0;
        if (game->player.strength < 0)
            game->player.strength = 0;
    }
    else if (strcmp(item, "healing herb") == 0)
    {
        printf("The soothing effect wears off... Health -15.\n");
        game->player.health -= 15;
        if (game->player.health < 0)
            game->player.health = 0;
    }
}

void apply_item_effects(char *item, GameObject *game)
{
    if (strcmp(item, "potion") == 0)
    {
        printf("You feel rejuvenated! Health +20.\n");
        game->player.health += 20;
        if (game->player.health > 100)
            game->player.health = 100;
    }
    else if (strcmp(item, "dagger") == 0)
    {
        printf("Your strength increases! Strength +5.\n");
        game->player.strength += 5;
    }
    else if (strcmp(item, "scroll") == 0)
    {
        printf("You learn a powerful spell! Strength +10.\n");
        game->player.strength += 10;
    }
    else if (strcmp(item, "pekmez") == 0)
    {
        printf("You consume pekmez and feel stronger! Health +10, Strength +2.\n");
        game->player.health += 10;
        game->player.strength += 2;
    }
    else if (strcmp(item, "healing herb") == 0)
    {
        printf("A soothing herb restores your vitality. Health +15.\n");
        game->player.health += 15;
        if (game->player.health > 100)
            game->player.health = 100;
    }
}
void move_direction(char *direction, GameObject *game)
{
    if (strcmp(direction, "left") == 0)
    {
        if (game->player.coordinates_x == 0)
        {
            printf("You are at the border, you can't go left.\n");
        }
        else
        {
            game->player.coordinates_x -= 1;
            printf("Moved left. New position: (%d, %d)\n", game->player.coordinates_x, game->player.coordinates_y);
        }
    }
    else if (strcmp(direction, "right") == 0)
    {
        if (game->player.coordinates_x == 5)
        {
            printf("You are at the border, you can't go right.\n");
        }
        else
        {
            game->player.coordinates_x += 1;
            printf("Moved right. New position: (%d, %d)\n", game->player.coordinates_x, game->player.coordinates_y);
        }
    }
    else if (strcmp(direction, "up") == 0)
    {
        if (game->player.coordinates_y == 5)
        {
            printf("You are at the border, you can't go up.\n");
        }
        else
        {
            game->player.coordinates_y += 1;
            printf("Moved up. New position: (%d, %d)\n", game->player.coordinates_x, game->player.coordinates_y);
        }
    }
    else if (strcmp(direction, "down") == 0)
    {
        if (game->player.coordinates_y == 0)
        {
            printf("You are at the border, you can't go up.\n");
        }
        else
        {
            game->player.coordinates_y -= 1;
            printf("Moved down. New position: (%d, %d)\n", game->player.coordinates_x, game->player.coordinates_y);
        }
    }
    else
    {
        printf("Invalid direction: %s\n", direction);
    }
    check_state(game);
}

void check_state(GameObject *game)
{
    for (size_t i = 0; i < 5; i++)
    {
        if (rooms[i].x == game->player.coordinates_x && rooms[i].y == game->player.coordinates_y)
        {
            printf("You found new room room:%d", i + 1);
            game->current_room = i + 1;
        }
    }
}
void intventory_list(GameObject *game)
{
    printf("%s", game->player.inventory);
}

void look_arround(GameObject *game)
{
    printf("you found lot of %s", rooms[game->current_room - 1].items);
}
void pickup_item(char *item, GameObject *game)
{
    Room *current_room = &rooms[game->current_room - 1];
    char *found_item = strstr(current_room->items, item);

    if (found_item != NULL)
    {
        printf("You picked up %s.\n", item);

        // Oyuncunun envanterine item ekle
        if (strlen(game->player.inventory) + strlen(item) + 2 < MAX_INVENTORY)
        {
            if (strlen(game->player.inventory) > 0)
            {
                strcat(game->player.inventory, ", ");
            }
            strcat(game->player.inventory, item);

            char new_items[MAX_ITEMS] = "";
            char *token = strtok(current_room->items, ", "); // Virgülle ayır
            while (token != NULL)
            {
                if (strcmp(token, item) != 0)
                {
                    if (strlen(new_items) > 0)
                    {
                        strcat(new_items, ", ");
                    }
                    strcat(new_items, token);
                }
                token = strtok(NULL, ", ");
            }
            strcpy(current_room->items, new_items);
            apply_item_effects(item, game);
        }
        else
        {
            printf("Your inventory is full!\n");
        }
    }
    else
    {
        // Item bulunamadı
        printf("Item '%s' not found in this room!\n", item);
    }
}
void drop_item(char *item, GameObject *game)
{
    char *found_item = strstr(game->player.inventory, item);

    if (found_item != NULL)
    {
        printf("You dropped %s.\n", item);

        char new_inventory[MAX_INVENTORY] = "";
        char *token = strtok(game->player.inventory, ", ");
        while (token != NULL)
        {
            if (strcmp(token, item) != 0)
            {
                if (strlen(new_inventory) > 0)
                {
                    strcat(new_inventory, ", ");
                }
                strcat(new_inventory, token);
            }
            token = strtok(NULL, ", ");
        }
        strcpy(game->player.inventory, new_inventory);

        Room *current_room = &rooms[game->current_room - 1];
        if (strlen(current_room->items) + strlen(item) + 2 < MAX_ITEMS)
        {
            if (strlen(current_room->items) > 0)
            {
                strcat(current_room->items, ", ");
            }
            strcat(current_room->items, item);
        }
        else
        {
            printf("The room cannot hold any more items!\n");
        }
        remove_item_effects(item, game);
    }
    else
    {
        printf("You don't have '%s' in your inventory!\n", item);
    }
}
void attack(GameObject* game) {
    Room* current_room = &rooms[game->current_room - 1];

    if (current_room->creature != NULL) {
        Creature* creature = current_room->creature;
        printf("You encounter a %s! (Health: %d, Strength: %d)\n", creature->name, creature->health, creature->strength);

        // Savaş döngüsü
        while (creature->health > 0 && game->player.health > 0) {
            // Oyuncu saldırır
            printf("You attack the %s!\n", creature->name);
            creature->health -= game->player.strength;
            if (creature->health <= 0) {
                printf("You defeated the %s!\n", creature->name);
                current_room->creature = NULL; // Canavar öldü
                return;
            }

            // Canavar saldırır
            printf("The %s attacks you!\n", creature->name);
            game->player.health -= creature->strength;
            if (game->player.health <= 0) {
                printf("You have been defeated by the %s...\n", creature->name);
                exit(0); // Oyun biter
            }

            // Durumları yazdır
            printf("Your Health: %d, %s's Health: %d\n", game->player.health, creature->name, creature->health);
        }
    } else {
        printf("There is no creature in this room.\n");
    }
}

void save_game(GameObject* game, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not save the game.\n");
        return;
    }

    // Oyuncu durumunu yaz
    fwrite(&game->player, sizeof(Player), 1, file);

    // Geçerli oda bilgisini yaz
    fwrite(&game->current_room, sizeof(int), 1, file);

    fclose(file);
    printf("Game saved successfully!\n");
}
void load_game(GameObject* game, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not load the game.\n");
        return;
    }

    // Oyuncu durumunu oku
    fread(&game->player, sizeof(Player), 1, file);

    // Geçerli oda bilgisini oku
    fread(&game->current_room, sizeof(int), 1, file);

    fclose(file);
    printf("Game loaded successfully!\n");
}
