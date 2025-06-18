#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct tree {
    int info;
    struct tree *left, *right;
}tree;
enum {
    CREATE_NEW_NODE=1,
    PRINT_ELEMENTS_OF_TREE=2,
    INSERT_NEW_NODE=3,
    DEPTH_OF_TREE=4,
    GET_VALUE_FOR_SEARCH_NODE=5,
    GET_VALUE_FOR_GET_NODE_DEPTH=6,
    GET_VALUE_FOR_GET_NODE_HEIGHT=7,
    PRINT_LEAVES=8,
    FREE_TREE=9
};
#endif //STRUCTS_H
