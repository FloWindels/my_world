/*
** EPITECH PROJECT, 2025
** camera
** File description:
** handle the mov of the camera
*/

#include "my.h"
#include "struct.h"
#include <unistd.h>

void move_map_action(csfml_t *csfml, sfVector2i mouse, int i, int j)
{
    if (abs(csfml->map_2d[i][j].x - mouse.x) < 10
        && abs(csfml->map_2d[i][j].y - mouse.y) < 10) {
        if (csfml->tools == 1)
            csfml->map_3d[i][j]++;
        if (csfml->tools == 0)
            csfml->map_3d[i][j]--;
        if (csfml->tools == 2)
            csfml->map_3d[i][j] = 0;
    }
}

void move_cam(sfEvent event, csfml_t *csfml)
{
    if (event.key.code == sfKeyUp)
        csfml->movey -= 3;
    if (event.key.code == sfKeyDown)
        csfml->movey += 3;
    if (event.key.code == sfKeyLeft)
        csfml->movex += 3;
    if (event.key.code == sfKeyRight)
        csfml->movex -= 3;
    if (event.key.code == sfKeyAdd)
        csfml->scale++;
    if (event.key.code == sfKeySubtract)
        csfml->scale--;
}

void load_save_file(csfml_t *csfml)
{
    if (csfml->tools == 4) {
        save_file(csfml);
        csfml->tools = 0;
    }
    if (csfml->tools == 5) {
        load_file(csfml);
        csfml->tools = 0;
    }
}

void change_tool(sfEvent event, csfml_t *csfml, sfVector2i mouse)
{
    sfFloatRect tools;

    for (int i = 2; i < 8; i++) {
        tools = sfSprite_getGlobalBounds(csfml->sprite[i]);
        if (sfFloatRect_contains(&tools, mouse.x, mouse.y)) {
            sfSprite_setColor(csfml->sprite[i], sfWhite);
            csfml->tools = i - 2;
        }
    }
    load_save_file(csfml);
    for (int i = 0; i < csfml->nb_tiles - 1; i++) {
        for (int j = 0; j < csfml->nb_tiles - 1; j++) {
            move_map_action(csfml, mouse, i, j);
        }
    }
}
