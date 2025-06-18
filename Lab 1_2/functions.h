#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"
Film alloc_film(Film film);
Film read_film(Film film,FILE *file_path);
Film* scan_array_of_films(FILE *file_path,int number_of_films);
void printf_film(Film film);
void print_array_of_films(Film *array, int number_of_films);
char* scanf_title();
int find_film_by_title(Film *array, int number_of_films);
void printf_finded_film(Film *array,int number_of_films);
void sort_films_by_duration(Film *array, int number_of_films);
void free_films(Film *array, int number_of_films);

#endif
