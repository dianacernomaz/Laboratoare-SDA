#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int* initialize_array(int *array, int size) {
    if (array != NULL) {
        free(array);
    }
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}

void display_array(const int *array, int size) {
    if (array == NULL || size <= 0) {
        printf("Array is not initialized or has invalid size.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* free_memory(int *array) {
    if (array != NULL) {
        free(array);
    }
    return NULL;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int *array, int size) {
    if (array == NULL || size <= 0) {
        printf("Array is not initialized or has invalid size.\n");
        return;
    }

    clock_t start = clock();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort executed in %.6f seconds.\n", time_spent);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_helper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

void quick_sort(int* array, int size) {
    if (array == NULL || size <= 0) {
        printf("Array is not initialized or has invalid size.\n");
        return;
    }

    clock_t start = clock();

    quick_sort_helper(array, 0, size - 1);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort executed in %.6f seconds.\n", time_spent);
}

int linear_search(const int *array, int size, int target) {
    if (array == NULL || size <= 0) {
        printf("Array is not initialized or has invalid size.\n");
        return -1;
    }

    clock_t start = clock();

    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            clock_t end = clock();
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Linear Search: Element found at index %d in %.6f seconds.\n", i, time_spent);
            return i;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear Search: Element not found. Time spent: %.6f seconds.\n", time_spent);
    return -1;
}

int binary_search(const int *array, int size, int target) {
    if (array == NULL || size <= 0) {
        printf("Array is not initialized or has invalid size.\n");
        return -1;
    }

    clock_t start = clock();

    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            clock_t end = clock();
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Binary Search: Element found at index %d in %.6f seconds.\n", mid, time_spent);
            return mid;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary Search: Element not found. Time spent: %.6f seconds.\n", time_spent);
    return -1;
}

big_number* create_big_number(const char *num_str) {
    big_number *num = (big_number*)malloc(sizeof(big_number));
    if (!num) return NULL;

    while (*num_str == '0' && *(num_str + 1) != '\0') {
        num_str++;
    }

    num->length = strlen(num_str);
    num->digits = (char*)malloc(num->length + 1);
    if (!num->digits) {
        free(num);
        return NULL;
    }

    strcpy(num->digits, num_str);
    return num;
}

void free_big_number(big_number *num) {
    if (num) {
        if (num->digits) free(num->digits);
        free(num);
    }
}

big_number* add_big_numbers(big_number *a, big_number *b) {
    int max_len;
    if (a->length > b->length) {
        max_len = a->length;
    } else {
        max_len = b->length;
    }

    char *result = calloc(max_len + 2, 1);

    int i = a->length - 1, j = b->length - 1, k = 0;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digit_a;
        if (i >= 0) {
            digit_a = a->digits[i] - '0';
            i--;
        } else {
            digit_a = 0;
        }

        int digit_b;
        if (j >= 0) {
            digit_b = b->digits[j] - '0';
            j--;
        } else {
            digit_b = 0;
        }

        int sum = digit_a + digit_b + carry;
        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    for (int l = 0, m = k - 1; l < m; l++, m--) {
        char temp = result[l];
        result[l] = result[m];
        result[m] = temp;
    }

    big_number *sum_num = create_big_number(result);
    free(result);
    return sum_num;
}

void print_big_number(const big_number *num) {
    if (num && num->digits) {
        printf("%s\n", num->digits);
    }
}

big_number* fast_fibonacci(int n) {
    if (n == 0) return create_big_number("0");
    if (n == 1) return create_big_number("1");

    big_number *a = create_big_number("0");
    big_number *b = create_big_number("1");
    big_number *c = NULL;

    for (int i = 2; i <= n; i++) {
        c = add_big_numbers(a, b);
        free_big_number(a);
        a = b;
        b = c;
    }

    free_big_number(a);
    return b;
}
