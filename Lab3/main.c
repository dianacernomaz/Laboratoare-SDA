#include <stdio.h>
#include "structs.h"
#include "functions.h"
int main() {
    int opt;
    tree * head=NULL;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Read elements of binary tree\n");
        printf("2. Display elements of binary tree\n");
        printf("3. Get depth of tree\n");
        printf("4. Search a node in binary tree\n");
        printf("5. Get depth for a node\n");
        printf("6. Get height of the node\n");
        printf("7. Display leaves of the tree\n");
        printf("8. Free tree\n");
        printf("9. Exit...\n");
        printf("Select option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: head=scan_elements_of_tree(head); break;
            case 2: {
                printf("Elements of the tree(SVD)");
                print_elements_of_tree(head);
            }break;
            case 3: printf("The depth of the tree = %d\n",depth_of_tree(head)); break;
            case 4: get_value_for_search_node(head); break;
            case 5: get_value_for_get_node_depth(head); break;
            case 6: get_value_for_get_node_height(head); break;
            case 7: {
                printf("Leaves of the tree are: ");
                print_leaves(head);
                printf("\n");
            } break;
            case 8: {
                head = free_tree(head);
                printf("Tree memory has been freed.\n");
            } break;
            case 9: return 0;
            default:
                printf("Invalid option.\n");
        }
    } while (opt != 9);
}
