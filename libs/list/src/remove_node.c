/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main
*/

#include "list.h"

void list_remove_node(list_t *list, node_t *node)
{
    if (!node || !list)
        return;
    list->lenght--;
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    node->prev = NULL;
    node->next = NULL;
}
