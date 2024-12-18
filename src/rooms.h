#include "game.h"
typedef struct {
    int x, y;                
    char description[256];    
    char items[256];      
    Creature* creature;    
} Room;
Creature giant_spider = {"Giant Spider", 50, 8};
Creature fairy = {"Fairy", 30, 5};
Creature golem = {"Golem", 100, 15};
Creature skeleton_warrior = {"Skeleton Warrior", 70, 10};
Creature wraith = {"Wraith", 120, 20};
Creature wolf = {"Wolf", 40, 7};
Room rooms[] = {
    {0, 0, "A dark, damp cave with the sound of dripping water echoing.", "torch, pekmez", &giant_spider},
    {1, 3, "A vibrant garden, with glowing plants and strange humming insects buzzing around.", "healing herb, crystal", &fairy},
    {2, 1, "An abandoned forge with the remnants of old tools scattered around.", "anvil, iron ingot", &golem},
    {3, 0, "A cold, empty hall with broken windows letting in the harsh sunlight.", "shield, old map", &skeleton_warrior},
    {4, 5, "A mystical chamber with glowing runes on the walls and an eerie silence.", "magic scroll, enchanted gem", &wraith},
    {5, 2, "A lush forest clearing, with towering trees and a small sparkling stream.", "berries, wooden staff", &wolf}
};