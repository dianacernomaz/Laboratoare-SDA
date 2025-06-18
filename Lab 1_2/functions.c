#ifndef FUNCTIONS_C
#define FUNCTIONS_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
Film alloc_film(Film film) {
    film.title = malloc(30 * sizeof(char));
    film.genre = malloc(30 * sizeof(char));
    film.director = malloc(30 * sizeof(char));
    return film;
}
Film read_film(Film film,FILE *file_path) {
    fscanf(file_path, "%s %d %s %s %d", film.title, &film.year, film.genre, film.director, &film.duration);
    return film;
}
Film* scan_array_of_films(FILE *file_path,int number_of_films) {
    if (file_path == NULL) {
        printf("Error opening file\n");
        return NULL;
    }
    fscanf(file_path, "%d", &number_of_films);
    Film *array = malloc(number_of_films * sizeof(Film));
    if (!array) {
        printf("Memory allocation failed!\n");
        fclose(file_path);
        return NULL;
    }

    for (int i = 0; i < number_of_films; i++) {
        array[i]=alloc_film(array[i]);
        array[i]=read_film(array[i],file_path);
    }
    fclose(file_path);
    return array;
}
void printf_film(Film film) {
    printf("%-30s %-6d %-20s %-20s %-5d\n",film.title, film.year, film.genre, film.director, film.duration);
}
void print_array_of_films(Film *array, int number_of_films) {
    if (!array) {
        printf("No films available.\n");
        return;
    }

    printf("The list of films:\n");
    printf("%-3s %-30s %-6s %-20s %-20s %-5s\n", "ID", "Title", "Year", "Genre", "Director", "Duration");
    for (int i = 0; i < number_of_films; i++) {
        printf_film(array[i]);
    }
}
char* scanf_title() {
    printf("Enter a film title: ");
    char *find_title = (char*)malloc(30 * sizeof(char));
    scanf("%29s", find_title);
    return find_title;
}
int find_film_by_title(Film *array, int number_of_films) {
    if (!array) {
        printf("No films available.\n");
        return 0;
    }
    char* film_title=scanf_title();
    for (int i = 0; i < number_of_films; i++) {
        if (strcmp(array[i].title, film_title) == 0) {
            return i;
        }
    }
    return -1;
}
void printf_finded_film(Film *array,int number_of_films) {
    int position=find_film_by_title(array,number_of_films);
    if(position!=-1) {
        printf("Film found at index %d\n",position);
    }
    else {
        printf("No film found.\n");
    }

}
void sort_films_by_duration(Film *array, int number_of_films) {
    if (!array) {
        printf("No films available.\n");
        return;
    }

    for (int i = 0; i < number_of_films - 1; i++) {
        for (int j = 0; j < number_of_films - i - 1; j++) {
            if (array[j].duration > array[j + 1].duration) {
                Film temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Films sorted by duration.\n");
}
void free_fields_of_struct(Film film) {
    free(film.title);
    free(film.genre);
    free(film.director);
}

void free_films(Film *array, int number_of_films) {
    for (int i = 0; i < number_of_films; i++) {
        free_fields_of_struct(array[i]);
    }
    free(array);
}

#endif
