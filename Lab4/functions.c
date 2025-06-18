#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>

student* create_new_node(int key, char *name, char *address, int age) {
    student *node = malloc(sizeof(student));
    if (node == NULL) {
        printf("Failed to allocate memory for node\n");
        return NULL;
    }
    node->name = malloc(20 * sizeof(char));
    node->address = malloc(20 * sizeof(char));
    node->key = key;
    strcpy(node->name, name);
    strcpy(node->address, address);
    node->age = age;
    node->left = NULL;
    node->right = NULL;
    return node;
}

student* insert_new_node(student* head, int key, char* name, char* address, int age) {
    if (head == NULL) {
        return create_new_node(key, name, address, age);
    }
    if (key < head->key)
        head->left = insert_new_node(head->left, key, name, address, age);
    else if (key > head->key)
        head->right = insert_new_node(head->right, key, name, address, age);
    return head;
}

student* scan_elements_of_tree(student* head) {
    char name[20];
    char address[20];
    int age;
    int key = 0;
    printf("Insert values (enter -1 to stop):\n");
    while (key != -1) {
        printf("key: "); scanf("%d", &key);
        if (key == -1) break;
        printf("name: "); scanf("%s", name);
        printf("address: "); scanf("%s", address);
        printf("age: "); scanf("%d", &age);
        head = insert_new_node(head, key, name, address, age);
    }
    return head;
}

void print_elements_of_tree_svd(student* head) {
    if (head != NULL) {
        print_elements_of_tree_svd(head->left);
        printf("Key: %d\n", head->key);
        printf("Name: %s  ", head->name);
        printf("Address: %s  ", head->address);
        printf("Age: %d\n", head->age);
        print_elements_of_tree_svd(head->right);
    }
}

void print_elements_of_tree_vsd(student* head) {
    if (head != NULL) {
        printf("Key: %d\n", head->key);
        printf("Name: %s  ", head->name);
        printf("Address: %s  ", head->address);
        printf("Age: %d\n", head->age);
        print_elements_of_tree_vsd(head->left);
        print_elements_of_tree_vsd(head->right);
    }
}

void print_elements_of_tree_sdv(student* head) {
    if (head != NULL) {
        print_elements_of_tree_sdv(head->left);
        print_elements_of_tree_sdv(head->right);
        printf("Key: %d\n", head->key);
        printf("Name: %s  ", head->name);
        printf("Address: %s  ", head->address);
        printf("Age: %d\n", head->age);
    }
}

void print_elements_of_tree_dfs(student* head) {
    if (head != NULL) {
        printf("Key: %d\n", head->key);
        printf("Name: %s  ", head->name);
        printf("Address: %s  ", head->address);
        printf("Age: %d\n", head->age);
        print_elements_of_tree_dfs(head->left);
        print_elements_of_tree_dfs(head->right);
    }
}
void print_elements_of_the_tree_bfs(student* root) {
    if (root == NULL)
        return;

    student* nodes[100];
    int front = 0, last = 0;

    nodes[last++] = root;

    while (front < last) {
        student* current = nodes[front++];

        printf("Key: %d\n", current->key);
        printf("Name: %s\n", current->name);
        printf("Address: %s\n", current->address);
        printf("Age: %d\n", current->age);

        if (current->left)
            nodes[last++] = current->left;
        if (current->right)
            nodes[last++] = current->right;
    }
}
student2* scan_unbalanced_tree(int size) {
    student2* array = malloc(size * sizeof(student2));
    printf("Enter elements of unbalanced tree:\n");
    for (int i = 0; i < size; i++) {
        array[i].name = malloc(20 * sizeof(char));
        array[i].address = malloc(20 * sizeof(char));
        printf("Key: "); scanf("%d", &array[i].key);
        printf("Name: "); scanf("%s", array[i].name);
        printf("Address: "); scanf("%s", array[i].address);
        printf("Age: "); scanf("%d", &array[i].age);
    }
    return array;
}

student* insert_node_into_balanced(student2* array, int start, int end) {
    if (start > end) {
        return NULL;
    }
    if(array==NULL) {
        return NULL;
    }
    int mid = (start + end) / 2;
    student* root = create_new_node(array[mid].key, array[mid].name, array[mid].address, array[mid].age);

    root->left = insert_node_into_balanced(array, start, mid - 1);
    root->right = insert_node_into_balanced(array, mid + 1, end);
    return root;
}
student2* sort_array(student2* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i].key > array[j].key) {
                student2 temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}
void free_student2_array(student2* array, int size) {
    if (array == NULL)
        return;

    for (int i = 0; i < size; i++) {
        free(array[i].name);
        free(array[i].address);
    }
    free(array);
}
student* get_balanced_tree() {
    printf("Enter number of elements:");
    int size;
    scanf("%d", &size);
    student2* array = scan_unbalanced_tree(size);
    array=sort_array(array, size);
    student* head = insert_node_into_balanced(array, 0, size - 1);
    free_student2_array(array,size);
    return head;
}
void free_tree(student* head) {
    if (head == NULL)
        return;
    free_tree(head->left);
    free_tree(head->right);
    free(head->name);
    free(head->address);
    free(head);
}
student* get_tree_mirroring(student* head) {
    if (head == NULL)
        return NULL;

    student* temp = head->left;
    head->left = head->right;
    head->right = temp;

    get_tree_mirroring(head->left);
    get_tree_mirroring(head->right);

    return head;
}
