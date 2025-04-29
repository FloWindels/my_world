/*
** EPITECH PROJECT, 2025
** My_world
** File description:
** events
*/

#include "my.h"
#include "struct.h"
#include <unistd.h>

void move_map(csfml_t *csfml, sfVector2i mouse)
{
    sfFloatRect tools;

    for (int i = 2; i < 8; i++) {
        tools = sfSprite_getGlobalBounds(csfml->sprite[i]);
        if (sfFloatRect_contains(&tools, mouse.x, mouse.y))
            sfSprite_setColor(csfml->sprite[i], sfColor_fromRGB(94, 94, 94));
        else
            sfSprite_setColor(csfml->sprite[i], sfWhite);
    }
}

void take_entered_text(sfEvent event, csfml_t *csfml)
{
    if (event.text.unicode < 128 && csfml->index_text_user < 255) {
        if (event.text.unicode == 8 && csfml->index_text_user > 0) {
            csfml->index_text_user--;
            csfml->user_text[csfml->index_text_user] = '\0';
        } else {
            csfml->user_text[csfml->index_text_user] =
            (char)event.text.unicode;
            csfml->index_text_user++;
            csfml->user_text[csfml->index_text_user] = '\0';
        }
    }
}

void key_pressed(sfEvent event, csfml_t *csfml)
{
    if (event.key.code == sfKeyQ)
        csfml->anglex++;
    if (event.key.code == sfKeyD)
        csfml->anglex--;
    if (event.key.code == sfKeyZ)
        csfml->angley++;
    if (event.key.code == sfKeyS)
        csfml->angley--;
    move_cam(event, csfml);
}

void analyse_events(csfml_t *csfml)
{
    sfMouseButtonEvent event_mouse;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(csfml->window);

    while (sfRenderWindow_pollEvent(csfml->window, &csfml->event)) {
        if (csfml->event.type == sfEvtClosed)
            sfRenderWindow_close(csfml->window);
        if (csfml->event.type == sfEvtKeyPressed)
            key_pressed(csfml->event, csfml);
        if (csfml->event.type == sfEvtTextEntered)
            take_entered_text(csfml->event, csfml);
        if (csfml->event.type == sfEvtMouseMoved)
            move_map(csfml, mouse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            change_tool(csfml->event, csfml, mouse);
    }
}
