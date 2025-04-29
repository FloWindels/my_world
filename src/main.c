/*
** EPITECH PROJECT, 2025
** My_world
** File description:
** main
*/

#include "my.h"
#include "struct.h"

int window(csfml_t *csfml)
{
    window_make_t *window_data = malloc(sizeof(window_make_t));
    sfRenderWindow *window;
    sfEvent event;

    if (window_data == NULL)
        return 1;
    csfml->nb_texture = 8;
    texture_to_struct(csfml);
    set_sprite(csfml);
    window_data->height = 1920;
    window_data->width = 1080;
    window_data->name = "my_world";
    window = make_window(window_data);
    csfml->window = window;
    csfml->event = event;
    free(window_data);
    return 0;
}

void cleanup(csfml_t *csfml)
{
    if (csfml->window)
        sfRenderWindow_destroy(csfml->window);
    for (int i = 0; csfml->textures[i]; i++)
        sfTexture_destroy(csfml->textures[i]);
}

int init_strcut_csfml(csfml_t *csfml)
{
    csfml->index_text_user = 0;
    csfml->nb_tiles = 10;
    csfml->anglex = 30;
    csfml->angley = 30;
    csfml->movex = 1920 / 2;
    csfml->movey = 1080 / 2;
    csfml->scale = 40;
    csfml->tools = 0;
}

int main(void)
{
    csfml_t *csfml = malloc(sizeof(csfml_t));

    if (csfml == NULL || window(csfml))
        return 84;
    init_strcut_csfml(csfml);
    csfml->user_text = malloc(256 * sizeof(char));
    if (csfml->user_text == NULL)
        return 84;
    gere_map(csfml);
    gere_map_struct(csfml);
    shape_to_struct(csfml);
    init_window(csfml);
    cleanup(csfml);
    free(csfml);
    return 0;
}
