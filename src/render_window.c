/*
** EPITECH PROJECT, 2025
** render window
** File description:
** rendu of the window
*/

#include "my.h"
#include "struct.h"

void tools_selection(csfml_t *csfml)
{
    for (int i = 2; i < 8; i++)
        if (csfml->tools == i - 2)
            sfSprite_setColor(csfml->sprite[i], sfColor_fromRGB(79, 79, 79));
}

void init_window(csfml_t *csfml)
{
    sfView *view = sfView_create();

    sfRenderWindow_setFramerateLimit(csfml->window, 61);
    while (sfRenderWindow_isOpen(csfml->window)) {
        analyse_events(csfml);
        gere_map_struct(csfml);
        draw_button(csfml);
        draw_shape(csfml);
        tools_selection(csfml);
        sfRenderWindow_display(csfml->window);
        sfRenderWindow_clear(csfml->window, sfColor_fromRGB(130, 130, 130));
    }
}
