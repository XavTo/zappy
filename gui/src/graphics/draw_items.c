/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

void draw_items(map_t tile, pos_t pos, int ratio)
{
    size_t ressource = 0;
    pos_t *ressource_pos = NULL;

    for (size_t i = 0; i < RESSOURCE_NBR; i++) {
        ressource = ((size_t *)(tile.inv))[i];
        ressource_pos = (pos_t *)(&((size_t *)(tile.inv))[RESSOURCE_NBR + i]);
        if (ressource == 0) {
            ressource_pos->x = 0;
            ressource_pos->y = 0;
            continue;
        }
        if (ressource_pos->x == 0)
            ressource_pos->x = pos.x + (rand() % (ratio - 15));
        if (ressource_pos->y == 0)
            ressource_pos->y = pos.y + (rand() % (ratio - 15));
        DrawTexturePro(get_textures()[i + 1], (Rectangle){0, 0, 16, 16},
            (Rectangle){ressource_pos->x, ressource_pos->y, ratio / 5,
            ratio / 5}, (Vector2){0, 0}, 0, RAYWHITE);
    }
}

void draw_incantation(map_t tile, pos_t pos, int ratio)
{
    Rectangle tmp = {0};

    if (tile.incantation == false)
        return;
    tmp = (Rectangle){0 + (int)(GetTime() * 10) % 4 * 233, 210 * 2, 233, 210};
    DrawTexturePro(get_textures()[16], tmp,
        (Rectangle){pos.x, pos.y, ratio * 2, ratio * 2},
        (Vector2){ratio / 2, ratio / 2}, 0, RAYWHITE);
}

void draw_misc(client_t *client, int ratio, pos_t map, pos_t edge)
{
    for (int y = 0; y < client->size_map.y; y++) {
        for (int x = 0; x < client->size_map.x; x++) {
            draw_items(client->map[y][x], (pos_t){edge.x + x * ratio,
                edge.y + y * ratio}, ratio);
            draw_inventory(client, (pos_t){x, y}, map, edge);
            draw_player(client->map[y][x], ratio, (pos_t){edge.x + x * ratio,
                edge.y + y * ratio});
            draw_incantation(client->map[y][x], (pos_t){edge.x + x * ratio,
                edge.y + y * ratio}, ratio);
        }
    }
}
