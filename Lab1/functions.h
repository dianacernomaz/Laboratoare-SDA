#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"
Films scan_array_of_films();
void print_array_of_films(Films films);
void find_film_by_title(Films films, char find_title[30]);
#endif