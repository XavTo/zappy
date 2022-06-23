/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool go_to_broadcast_direction(client_t *client)
{
    int x = client->player->pos.x;
    int y = client->player->pos.y;
    size_t d = client->player->broadcast_direction;

    if (d == 1 || d == 2 || d == 8)
        return(go_to_good_direction_y(client, y - 1, client->player->pos.y));
    if (d == 4 || d == 5 || d == 6)
        return(go_to_good_direction_y(client, y + 1, client->player->pos.y));
    if (d == 3)
        return(go_to_good_direction_x(client, x - 1, client->player->pos.x));
    if (d == 7)
        return(go_to_good_direction_x(client, x + 1, client->player->pos.x));
    return true;
}

bool basic_command(client_t *client)
{
    if (!send_message(client->pending_commands,
        client->command, client->socket, "Look\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (!send_message(client->pending_commands,
        client->command, client->socket, "Inventory\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (client->unused_slot == 0 && !send_message(client->pending_commands,
        client->command, client->socket, "Fork\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}
