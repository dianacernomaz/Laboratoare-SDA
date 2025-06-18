#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct Film {
    char *title;
    char *genre;
    char *director;
    int year;
    int duration; // in minutes
} Film;

enum {
    PRINT_ARRAY =1,
    FIND_FILM_BY_TITLE=2,
    SORT_FILMS_BY_DURATION=3,
    FREE_FILMS=4.
};
#endif
