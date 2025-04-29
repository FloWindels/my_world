/*
** EPITECH PROJECT, 2025
** My_world
** File description:
** sprites
*/

#include "struct.h"

void draw_sprite(csfml_t *csfml)
{
    for (int i = 0; i < csfml->nb_texture; i++)
        if (csfml->sprite[i] != NULL)
            sfRenderWindow_drawSprite(csfml->window, csfml->sprite[i], NULL);
}

void draw_button(csfml_t *csfml)
{
    sfSprite_setScale(csfml->sprite[1], (sfVector2f){2.5, 1.5});
    sfSprite_setPosition(csfml->sprite[1], (sfVector2f){-40, -80});
    sfRenderWindow_drawSprite(csfml->window, csfml->sprite[1], NULL);
    for (int i = 2; i < 4; i++) {
        sfSprite_setScale(csfml->sprite[i], (sfVector2f){0.4, 0.4});
        sfSprite_setPosition(csfml->sprite[i],
        (sfVector2f){200 + (i - 2) * 100, 25});
        sfRenderWindow_drawSprite(csfml->window, csfml->sprite[i], NULL);
    }
    for (int i = 4; i < 8; i++) {
        sfSprite_setScale(csfml->sprite[i], (sfVector2f){0.28, 0.28});
        sfSprite_setPosition(csfml->sprite[i],
        (sfVector2f){200 + (i - 2) * 100, 27});
        sfRenderWindow_drawSprite(csfml->window, csfml->sprite[i], NULL);
    }
}

int set_sprite(csfml_t *csfml)
{
    csfml->sprite = malloc(sizeof(sfSprite*) * csfml->nb_texture + 1);
    if (csfml->sprite == NULL)
        return -1;
    for (int i = 0; i < csfml->nb_texture; i++) {
        csfml->sprite[i] = sfSprite_create();
        if (csfml->sprite[i] == NULL)
            return -1;
        sfSprite_setTexture(csfml->sprite[i], csfml->textures[i], sfTrue);
        sfSprite_setScale(csfml->sprite[i], (sfVector2f){0.3, 0.3});
    }
    return 0;
}
