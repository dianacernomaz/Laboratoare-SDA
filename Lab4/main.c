#include <stdio.h>
#include "structs.h"
#include "functions.h"
int main()
{
    int opt;
    student * head=NULL;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Read elements for balanced binary tree\n");
        printf("2. Read elements for unbalanced binary tree\\balance tree\n");
        printf("Display elements of binary tree\n");
        printf(" 3.SVD \n 4.VSD \n 5.SDV \n 6.Depth first search \n 7.Breadth first search\n");
        printf("8. Get tree mirroring\n");
        printf("9. Free memory of the tree\n");
        printf("Select option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: head=scan_elements_of_tree(head); break;
            case 2: {
                head=get_balanced_tree(); break;
            }
            case 3: {
                printf("Elements of the tree(SVD)\n");
                print_elements_of_tree_svd(head);
            }break;
            case 4: {
                printf("Elements of the tree(VSD)\n");
                print_elements_of_tree_vsd(head);
            }break;
            case 5: {
                printf("Elements of the tree(SDV)\n");
                print_elements_of_tree_sdv(head);
            }break;
            case 6: {
                printf("Elements of the tree(depth first search)\n");
                print_elements_of_tree_dfs(head);
            }break;
            case 7: {
                printf("Elements of the tree(breadth first search)\n");
                print_elements_of_the_tree_bfs(head);
            }break;
            case 8: {
                get_tree_mirroring(head);
                print_elements_of_the_tree_bfs(head);
            }break;
            case 9: free_tree(head);break;
            default:
                printf("Invalid option.\n");
        }
    } while (opt != 10);
}
