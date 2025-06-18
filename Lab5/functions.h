#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"
int* initialize_array(int *array, int size);

void display_array(const int *array, int size);

int* free_memory(int *array);

void bubble_sort(int *array, int size);

void quick_sort(int* array, int size);

void quick_sort_helper(int arr[], int low, int high);

int linear_search(const int *array, int size, int target);

int binary_search(const int *array, int size, int target);

big_number* create_big_number(const char *num_str);

void free_big_number(big_number *num);

big_number* add_big_numbers(big_number *a, big_number *b);

void print_big_number(const big_number *num);

big_number* fast_fibonacci(int n);

#endif //FUNCTIONS_H
