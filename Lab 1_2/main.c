#include <stdio.h>
#include "structs.h"
#include "functions.h"

int main() {
    int number_of_films = 0;
    const char *file_path = "E:\\UTM\\Structuri de date si algoritmi\\Lab1\\films.txt";
    Film *array = scan_array_of_films(*file_path,number_of_films);

    if (!array) return 1;
    int option;
    do {
        printf("Menu:\n");
        printf("1. Display the list of films\n");
        printf("2. Find a film by title\n");
        printf("3. Sort films by duration\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case PRINT_ARRAY: print_array_of_films(array, number_of_films); break;
            case FIND_FILM_BY_TITLE: find_film_by_title(array, number_of_films); break;
            case SORT_FILMS_BY_DURATION: sort_films_by_duration(array, number_of_films); break;
            case FREE_FILMS: free_films(array, number_of_films); printf("Exiting...\n"); return 0;
            default: printf("Invalid option!\n");
        }
    } while (option != 4);
}