#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"

tree *create_new_node(int info);

tree *insert_new_node(tree *head, int info);

tree *scan_elements_of_tree();

void print_elements_of_tree(tree *head);

tree *free_tree(tree *head);

int depth_of_tree(tree *head);

tree *search_node(tree *head, int info);

void get_value_for_search_node(tree *head);

int get_node_depth(tree *head, int info, int depth_level);

void get_value_for_get_node_depth(tree *head);

int get_node_height(tree *head);

void get_value_for_get_node_height(tree *head);

void print_leaves(tree *head);
#endif //FUNCTIONS_H
