/*
** EPITECH PROJECT, 2022
** look_around.c
** File description:
** look_around ai
*/

#include "zappy_ai.h"

size_t get_player_same_level(client_t *client, int level)
{
    size_t y = client->player->pos.y;
    size_t x = client->player->pos.x;
    size_t nb = 0;
    node_t *node;

    foreach (client->map[y][x].player->head, node) {
        if (((player_t *)node->data)->level == (size_t)level)
            nb++;
    }
    return nb;
}

bool ask_player(client_t *client, size_t nb_need, char level)
{
    char *com = NULL;

    if (get_player_same_level(client, (level - '0')) != nb_need) {
        com = calloc(1, sizeof(char) * (13));
        strcat(strncat(strcat(com, "Broadcast "), &level, 1), "\n");
        if (client->pending_commands->lenght < 10 && !send_message(client->
            pending_commands, client->command, client->socket, com)) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        free(com);
    }
    else if (client->pending_commands->lenght < 10 && !send_message(client->
        pending_commands, client->command, client->socket, "Incantation\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}

bool level_1(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
    }
    return ask_player(client, 1, (client->player->level + '0'));
}

bool level_2(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
    }
    if (client->player->inv->deraumere < 1) {
        if (!path_finding_object(client, "deraumere"))
            return false;
        if (!get_object(client, client->player->inv->deraumere, 1, "deraumere"))
            return false;
    }
    if (client->player->inv->sibur < 1) {
        if (!path_finding_object(client, "sibur"))
            return false;
        if (!get_object(client, client->player->inv->sibur, 1, "sibur"))
            return false;
    }
    return ask_player(client, 2, (client->player->level + '0'));
}