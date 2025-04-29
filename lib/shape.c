/*
** EPITECH PROJECT, 2025
** shape
** File description:
** manage the shape
*/

#include "struct.h"
#include "my.h"

void convex_shape_set_multiple_point(csfml_t *csfml,
    sfConvexShape *shape, int i, int j)
{
    sfConvexShape_setPoint(shape, 0, csfml->map_2d[i][j]);
    sfConvexShape_setPoint(shape, 1, csfml->map_2d[i][j + 1]);
    sfConvexShape_setPoint(shape, 2, csfml->map_2d[i + 1][j + 1]);
    sfConvexShape_setPoint(shape, 3, csfml->map_2d[i + 1][j]);
}

sfConvexShape *make_shape(csfml_t *csfml, int i, int j)
{
    size_t pointCount = 4;
    sfConvexShape *shape = sfConvexShape_create();

    sfConvexShape_setPointCount(shape, pointCount);
    sfConvexShape_setFillColor(shape, sfColor_fromRGB(64, 135, 41));
    convex_shape_set_multiple_point(csfml, shape, i, j);
    sfConvexShape_setOutlineColor(shape, sfBlue);
    sfConvexShape_setOutlineThickness(shape, 2);
    return shape;
}

void shape_to_struct(csfml_t *csfml)
{
    int total_tiles = csfml->nb_tiles * csfml->nb_tiles;
    int index = 0;

    csfml->shape = malloc(sizeof(sfConvexShape *) * (total_tiles));
    for (int i = 0; i < csfml->nb_tiles - 1; i++)
        for (int j = 0; j < csfml->nb_tiles - 1; j++) {
            csfml->shape[index] = make_shape(csfml, i, j);
            index++;
        }
}

void draw_shape(csfml_t *csfml)
{
    int total_tiles = (csfml->nb_tiles - 1) * (csfml->nb_tiles - 1);

    for (int i = 0; i < csfml->nb_tiles - 1; i++) {
        for (int j = 0; j < csfml->nb_tiles - 1; j++) {
            convex_shape_set_multiple_point(csfml,
            csfml->shape[i * j], i, j);
            sfRenderWindow_drawConvexShape
            (csfml->window, csfml->shape[i * j], NULL);
        }
    }
}
