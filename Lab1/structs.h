#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct Film {
    char title[30];
    int year;
    char genre[20];
    char director[30];
    int duration; // in minutes
} Film;
typedef struct Films {
    Film array[100];
    int number_of_films;
} Films;
#endif
