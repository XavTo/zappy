/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast ai
*/

#include "zappy_ai.h"

static bool go_to_good_direction_y_s(client_t *client, size_t dest, size_t src)
{
    if (src > dest && client->player->dir != North) {
        if (client->player->dir == East && !send_message(client->
            pending_commands, client->command, client->socket, "Left\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == West && !send_message(client->
            pending_commands, client->command, client->socket, "Right\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == South && (!send_message(client->
            pending_commands, client->command, client->socket, "Left\n")
            || !send_message(client->pending_commands,
            client->command, client->socket, "Left\n"))) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    return true;
}

static bool go_to_good_direction_y(client_t *client, size_t dest, size_t src)
{
    if (src < dest && client->player->dir != South) {
        if (client->player->dir == East && !send_message(client->
            pending_commands, client->command, client->socket, "Right\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == West && !send_message(client->
            pending_commands, client->command, client->socket, "Left\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == North && (!send_message(client->
            pending_commands, client->command, client->socket, "Left\n")
            || !send_message(client->pending_commands,
            client->command, client->socket, "Left\n"))) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    return (go_to_good_direction_y_s(client, dest, src));
}

static bool go_to_good_direction_x_s(client_t *client, size_t dest, size_t src)
{
    if (src > dest && client->player->dir != West) {
        if (client->player->dir == North && !send_message(client->
            pending_commands, client->command, client->socket, "Left\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == South && !send_message(client->
            pending_commands, client->command, client->socket, "Right\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == West && (!send_message(client->
            pending_commands, client->command, client->socket, "Left\n")
            || !send_message(client->pending_commands,
            client->command, client->socket, "Left\n"))) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    return true;
}

static bool go_to_good_direction_x(client_t *client, size_t dest, size_t src)
{
    if (src < dest && client->player->dir != East) {
        if (client->player->dir == North && !send_message(client->
            pending_commands, client->command, client->socket, "Right\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == South && !send_message(client->
            pending_commands, client->command, client->socket, "Left\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        if (client->player->dir == West && (!send_message(client->
            pending_commands, client->command, client->socket, "Left\n")
            || !send_message(client->pending_commands,
            client->command, client->socket, "Left\n"))) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    return (go_to_good_direction_x_s(client, dest, src));
}

bool go_to_next_object(client_t *client, size_t dest_x, size_t dest_y)
{
    find_closest_round(client, &dest_x, &dest_y);
    if (!go_to_good_direction_x(client, dest_x, client->player->pos.x))
        return false;
    for (size_t srx_x = client->player->pos.x; srx_x != dest_x;) {
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    if (!go_to_good_direction_y(client, dest_y, client->player->pos.y))
        return false;
    for (size_t srx_y = client->player->pos.y; srx_y != dest_y; srx_y++) {
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    return true;
}
