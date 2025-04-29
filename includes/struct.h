/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** struct
*/

#include "my.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct window_make_s {
    int height;
    int width;
    char *name;
} window_make_t;

typedef struct CSFML_s {
    sfRenderWindow *window;
    sfTexture **textures;
    sfSprite **sprite;
    sfConvexShape **shape;
    sfVector2f **map_2d;
    sfFont *font;
    sfText *text;
    sfMusic *music;
    sfEvent event;
    sfView *view;
    int nb_texture;
    int nb_tiles;
    int index_text_user;
    char *user_text;
    int anglex;
    int angley;
    int movex;
    int movey;
    int scale;
    int **map_3d;
    int tools;
} csfml_t;

#endif /* !STRUCT_H_ */
