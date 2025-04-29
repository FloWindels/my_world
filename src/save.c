q/*
** EPITECH PROJECT, 2025
** save
** File description:
** save and load file in a fichier .legend
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void save_file(csfml_t *csfml)
{
    FILE *fptr = fopen("save.legend", "w");

    for (int i = 0; i < csfml->nb_tiles; i++) {
        for (int j = 0; j < csfml->nb_tiles; j++) {
            fprintf(fptr, "%d ", csfml->map_3d[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}

void load_map(char *buffer, FILE *fptr, int size_file, csfml_t *csfml)
{
    char **map_load = NULL;

    fread(buffer, sizeof(char), size_file, fptr);
    buffer[size_file] = '\0';
    map_load = my_strtok(buffer, " \n");
    for (int i = 0; i < csfml->nb_tiles; i++) {
        for (int j = 0; j < csfml->nb_tiles; j++) {
            csfml->map_3d[i][j] = atoi(map_load[j + (i * csfml->nb_tiles)]);
        }
    }
    free(buffer);
}

void load_file(csfml_t *csfml)
{
    FILE *fptr = fopen("save.legend", "r");
    struct stat sb;
    char *buffer = NULL;

    if (fptr == NULL) {
        fprintf(stderr, "This file doesn't exist\n");
        return;
    }
    if (stat("save.legend", &sb) == -1) {
        perror("stat");
        fclose(fptr);
        return;
    }
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL) {
        fclose(fptr);
        return;
    }
    load_map(buffer, fptr, sb.st_size, csfml);
    fclose(fptr);
}
