/*
** EPITECH PROJECT, 2025
** find iso
** File description:
** find the iso of the texture
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "my.h"
#include "struct.h"

void gere_map(csfml_t *csfml)
{
    int **map = malloc(csfml->nb_tiles * sizeof(int *));

    if (map == NULL)
        return;
    for (int i = 0; i < csfml->nb_tiles; i++) {
        map[i] = malloc(csfml->nb_tiles * sizeof(int));
        if (map[i] == NULL)
            return;
        for (int j = 0; j < csfml->nb_tiles; j++) {
            map[i][j] = 0;
        }
    }
    csfml->map_3d = map;
}

sfVector2f project_iso_point(int x, int y, int z, csfml_t *csfml)
{
    sfVector2f point_2d;
    float angle_radx = csfml->anglex * M_PI / 180.0;
    float angle_rady = csfml->angley * M_PI / 180.0;

    point_2d.x = ((cos(angle_radx) * x - cos(M_PI / 6) * y) * csfml->scale);
    point_2d.y =
    ((sin(angle_rady) * y + sin(angle_rady) * x - z) * csfml->scale);
    return point_2d;
}

sfVector2f **create_2d_map(int **map_3d, csfml_t *csfml)
{
    sfVector2f **map = malloc(sizeof(sfVector2f *) * csfml->nb_tiles);

    if (map == NULL)
        return NULL;
    for (int x = 0; x < csfml->nb_tiles; x++) {
        map[x] = malloc(sizeof(sfVector2f) * csfml->nb_tiles);
        if (map[x] == NULL) {
            free(map);
            return NULL;
        }
        for (int y = 0; y < csfml->nb_tiles; y++)
            map[x][y] = project_iso_point(x, y, map_3d[x][y], csfml);
    }
    for (int i = 0; i < csfml->nb_tiles; i++) {
        for (int j = 0; j < csfml->nb_tiles; j++) {
            map[i][j].x += csfml->movex;
            map[i][j].y += csfml->movey;
        }
    }
    return map;
}

void gere_map_struct(csfml_t *csfml)
{
    sfVector2f **map_2d = NULL;

    map_2d = create_2d_map(csfml->map_3d, csfml);
    csfml->map_2d = map_2d;
}
