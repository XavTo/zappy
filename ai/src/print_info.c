/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

void print_dir(direction_e dir)
{
    if (dir == North)
        printf("Direction = North\n");
    if (dir == South)
        printf("Direction = South\n");
    if (dir == East)
        printf("Direction = East\n");
    if (dir == West)
        printf("Direction = West\n");
}

void print_inventory(inventory_t *inv)
{
    printf("food = %d linemate = %d deraumere = %d sibur = %d mendiane"
        " = %d phiras = %d thystame = %d\n", inv->food, inv->linemate,
        inv->deraumere, inv->sibur, inv->mendiane, inv->phiras, inv->thystame);
}

void print_inventory_map(client_t *client)
{
    for (int y = 0; y != client->size_map.y; y++) {
        for (int x = 0; x != client->size_map.x; x++) {
            if (client->map[y][x].inv->food != -1) {
                printf("y = %d x = %d : ", y, x);
                print_inventory(client->map[y][x].inv);
            }
        }
    }
}
