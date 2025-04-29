/*
** EPITECH PROJECT, 2025
** My_world
** File description:
** window
*/

#include "my.h"
#include "struct.h"

sfRenderWindow *make_window(window_make_t *window_data)
{
    sfVideoMode mode = {window_data->height, window_data->width, 61};
    sfRenderWindow *window;

    window = sfRenderWindow_create(
    mode, window_data->name, sfClose, NULL);
    return window;
}
