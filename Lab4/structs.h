#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct student {
    int key;
    char *name;
    char *address;
    int age;
    struct student *left, *right;
}student;
typedef struct student2 {
    int key;
    char *name;
    char *address;
    int age;
}student2;
#endif //STRUCTS_H
