/*
** EPITECH PROJECT, 2025
** My_world
** File description:
** textures
*/

#include "struct.h"
#include "my.h"

const char *path_to_texture[] = {
    "./ref/ground.jpg",
    "./ref/baniere_my_world-removebg-preview.png",
    "./ref/dig_my_world.png",
    "./ref/level_up_my_world.png",
    "./ref/flat.png",
    "./ref/nothing_my_world.png",
    "./ref/save_my_world.png",
    "./ref/load_my_world.png",
    NULL
};

int texture_to_struct(csfml_t *csfml)
{
    csfml->textures = malloc(sizeof(sfTexture*) * (csfml->nb_texture + 1));
    if (csfml->textures == NULL)
        return -1;
    for (int i = 0; path_to_texture[i]; i++) {
        csfml->textures[i] =
        sfTexture_createFromFile(path_to_texture[i], NULL);
        if (!csfml->textures[i]) {
            return -1;
        }
    }
    csfml->textures[csfml->nb_texture] = NULL;
    return 0;
}
