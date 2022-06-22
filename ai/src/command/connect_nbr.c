/*
** EPITECH PROJECT, 2022
** connect_nbr.c
** File description:
** connect_nbr ai
*/

#include "zappy_ai.h"

int connect_nbr(client_t *client, char *str)
{
    if (atoi(str) > 0) {
        client->unused_slot = atoi(str);
        printf("%s[COMMAND]%s connect_nbr = %d\n", B, W, client->unused_slot);
    }
    return 1;
}
