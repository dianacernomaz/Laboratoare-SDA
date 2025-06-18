#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
int main() {
    srand(time(NULL));

    int option;
    int *array = NULL;
    int size = 0;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Initialize array with random numbers\n");
        printf("2. Display array\n");
        printf("3. Free memory\n");
        printf("4. Sort array (Bubble Sort)\n");
        printf("5. Sort array (Quick Sort)\n");
        printf("6. Linear Search\n");
        printf("7. Binary Search (array must be sorted)\n");
        printf("8. Calculate Fibonacci number (50-1000000)\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the array size: ");
                scanf("%d", &size);
                if (size <= 0) {
                    printf("Invalid array size.\n");
                    break;
                }
                array = initialize_array(array, size);
                break;
            case 2:
                display_array(array, size);
                break;
            case 3:
                array = free_memory(array);
                size = 0;
                printf("Memory freed.\n");
                break;
            case 4:
                bubble_sort(array, size);
                break;
            case 5:
                quick_sort(array, size);
                break;
            case 6: {
                int target;
                printf("Enter number to search (Linear Search): ");
                scanf("%d", &target);
                linear_search(array, size, target);
            }
                break;
            case 7: {
                int target;
                printf("Enter number to search (Binary Search): ");
                scanf("%d", &target);
                binary_search(array, size, target);
            }
                break;
            case 8: {
                int n;
                printf("Enter Fibonacci position (50-1000000): ");
                scanf("%d", &n);

                if (n < 50 || n > 1000000) {
                    printf("Position must be between 50 and 1000000.\n");
                    break;
                }

                printf("Calculating Fibonacci(%d)...\n", n);
                clock_t start = clock();
                big_number *fib = fast_fibonacci(n);
                clock_t end = clock();

                if (fib) {
                    printf("Fibonacci(%d) = ", n);
                    print_big_number(fib);
                    printf("Calculated in %.3f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
                    print_big_number(fib);
                } else {
                    printf("Memory allocation failed.\n");
                }
                break;
            }
            case 0:
                array = free_memory(array);
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 0);

    return 0;
}