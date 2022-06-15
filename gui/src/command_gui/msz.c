/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

int msz(client_t *client, char *str)
{
    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    client->size_map.x = atoi(str);
    client->size_map.y = atoi(strchr(str, ' '));
    printf("x = %d y = %d\n", client->size_map.x, client->size_map.y);
    return 0;
}
