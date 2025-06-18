#include <stdio.h>
#include "structs.h"
#include "functions.h"

int main(void) {
    Films films = scan_array_of_films();
    print_array_of_films(films);

    printf("Enter a film title: ");
    char find_title[30];
    scanf(" %29[^\n]", find_title);
    find_film_by_title(films, find_title);

    return 0;
}
