/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/Network.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
	#include <stddef.h>
    #include "struct.h"
    #include <math.h>

sfRenderWindow *make_window(window_make_t *window_data);
void analyse_events(csfml_t *csfml);
void init_window(csfml_t *csfml);
int my_arrlen(char **arr);
int texture_to_struct(csfml_t *csfml);
int set_sprite(csfml_t *csfml);
void draw_sprite(csfml_t *csfml);
sfVector2f **create_2d_map(int **map_3d, csfml_t *csfml);
void gere_map_struct(csfml_t *csfml);
void free_array(char **array);
void shape_to_struct(csfml_t *csfml);
void draw_shape(csfml_t *csfml);
void gere_map(csfml_t *csfml);
void move_cam(sfEvent event, csfml_t *csfml);
void draw_button(csfml_t *csfml);
void change_tool(sfEvent event, csfml_t *csfml, sfVector2i mouse);
void save_file(csfml_t *csfml);
void load_file(csfml_t *csfml);
char **my_strtok(char *str, char *delimiters);

#endif /* !MY_H_ */
