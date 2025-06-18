#ifndef FUNCTIONS_C
#define FUNCTIONS_C
#include <stdio.h>
#include <string.h>
#include "functions.h"
Films scan_array_of_films() {
    Films films;
    films.number_of_films = 0;

    FILE *file = fopen("E:\\UTM\\Structuri de date si algoritmi\\Lab1\\films.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return films;
    }

    fscanf(file, "%d", &films.number_of_films);
    for (int i = 0; i < films.number_of_films; i++) {
        fscanf(file, "%s %d %s %s %d", &films.array[i].title, &films.array[i].year, &films.array[i].genre, &films.array[i].director, &films.array[i].duration);
    }

    fclose(file);
    return films;
}

void print_array_of_films(Films films) {
    if (films.number_of_films == 0) {
        printf("No films available.\n");
        return;
    }

    printf("The list of films:\n");
    printf("%-3s %-20s %-6s %-20s %-20s %-5s\n", "ID", "Title", "Year", "Genre", "Director", "Duration");

    for (int i = 0; i < films.number_of_films; i++) {
        printf("%-3d %-20s %-6d %-20s %-20s %-5d\n",
               i, films.array[i].title, films.array[i].year,
               films.array[i].genre, films.array[i].director,
               films.array[i].duration);
    }
}

void find_film_by_title(Films films, char find_title[30]) {
    int found = 0;
    for (int i = 0; i < films.number_of_films; i++) {
        if (strcmp(films.array[i].title, find_title) == 0) {
            printf("Title found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Film not found!\n");
    }
}

#endif