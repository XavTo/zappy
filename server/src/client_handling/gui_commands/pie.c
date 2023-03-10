/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_pie(core_t *core, trantorian_t *trantorian)
{
    char *buff = NULL;

    if (asprintf(&buff, "pie %ld %ld %ld\n",
            trantorian->pos.x,
            trantorian->pos.y,
            trantorian->level) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
