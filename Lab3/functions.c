#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

tree *create_new_node(int info) {
    tree *node = malloc(sizeof(tree));
    if (node == NULL) {
        printf("Failed to allocate memory for node");
        return NULL;
    }
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}

tree *insert_new_node(tree *head, int info) {
    if (head == NULL) {
        return create_new_node(info);
    }
    if (info < head->info)
        head->left = insert_new_node(head->left, info);
    else if (info > head->info)
        head->right = insert_new_node(head->right, info);
    return head;
}

tree *scan_elements_of_tree(tree *head) {
    int value = 0;
    printf("Insert values for binary tree (enter -1 to stop):\n");
    while (value != -1) {
        printf("value: ");
        scanf("%d", &value);
        if (value == -1) break;
        head = insert_new_node(head, value);
    }
    return head;
}

void print_elements_of_tree(tree *head) {
    if (head != NULL) {
        print_elements_of_tree(head->left);
        printf("%d ", head->info);
        print_elements_of_tree(head->right);
    }
}

tree *free_tree(tree *head) {
    if (head == NULL) return NULL;
    free_tree(head->left);
    free_tree(head->right);
    free(head);
    return head;
}

int depth_of_tree(tree *head) {
    if (head == NULL)
        return -1;
    int left_depth = depth_of_tree(head->left);
    int right_depth = depth_of_tree(head->right);
    int max_depth;
    if (left_depth > right_depth) {
        max_depth = left_depth;
    } else {
        max_depth = right_depth;
    }
    return max_depth + 1;
}

tree *search_node(tree *head, int info) {
    if (head == NULL || head->info == info)
        return head;
    if (info < head->info)
        return search_node(head->left, info);
    return search_node(head->right, info);
}

void get_value_for_search_node(tree *head) {
    int value;
    printf("Enter value for search node: ");
    scanf("%d", &value);
    tree *search = NULL;
    search = search_node(head, value);
    if (search == NULL)
        printf("Value not found\n");
    else
        printf("Value found: %d\n", search->info);
}

int find_depth_of_node(tree *head, int value) {
    if (head == NULL)
        return -1;
    int dist = -1;
    if ((head->info == value)
        || (dist = find_depth_of_node(head->left, value)) >= 0
        || (dist = find_depth_of_node(head->right, value)) >= 0)
        return dist + 1;
    return dist;
}

void get_value_for_get_node_depth(tree *head) {
    int val;
    printf("Enter value for node depth: ");
    scanf("%d", &val);
    tree *node = search_node(head, val);
    if (node == NULL) {
        printf("Node not found.\n");
        return;
    }
    int node_depth = find_depth_of_node(head, val);
    printf("Depth of node with value %d is %d\n", val, node_depth);
}

int get_node_height(tree *head) {
    if (head == NULL)
        return -1;
    int left_height = get_node_height(head->left);
    int right_height = get_node_height(head->right);
    int max_height;
    if (left_height > right_height) {
        max_height = left_height;
    } else {
        max_height = right_height;
    }
    return max_height + 1;
}

void get_value_for_get_node_height(tree *head) {
    int val;
    printf("Enter value for node: ");
    scanf("%d", &val);
    tree *node = search_node(head, val);
    if (node == NULL)
        printf("Node not found.\n");
    else
        printf("Height of node with value %d is %d\n", val, get_node_height(node));
}

void print_leaves(tree *head) {
    if (head == NULL) return;
    if (head->left == NULL && head->right == NULL)
        printf("%d ", head->info);
    print_leaves(head->left);
    print_leaves(head->right);
}
