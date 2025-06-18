// #ifndef FUNCTIONS_C
// #define FUNCTIONS_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"

song* head = NULL;

song* alloc_memory_for_song(song* new) {
    new = malloc(sizeof(struct song));
    if(new==NULL) {
        printf("Allocation failed!\n");
        return NULL;
    }
    new->name = malloc(30 * sizeof(char));
    new->author = malloc(30 * sizeof(char));
    new->album = malloc(30 * sizeof(char));

    return new;
}
void scan_songs_from_file() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
    strcat(cwd, "/songs.txt");
    FILE *file = fopen(cwd, "r");
    int i=1;
    while(feof(file) == 0) {
        song* new = alloc_memory_for_song(new);
        new->nr = i; i++;
        fscanf(file, "%s %s %d %s %d", new->name,new->author,&new->year,new->album,&new->duration);
        new->next = NULL;
        if (head == NULL) {
            head = new;
        } else {
            song* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new;
        }
    }
    fclose(file);
    printf("The list has been read!\n");
}
void display_songs() {
    printf("Nr   Name            Author          Year  Album           Duration\n");
    song* current = head;
    while(current != NULL) {
        printf("%-4d ", current->nr);
        printf("%-15s ", current->name);
        printf("%-15s ", current->author);
        printf("%-5d ", current->year);
        printf("%-15s ", current->album);
        printf("%-4d ", current->duration);
        printf("\n");
        current = current->next;
    }
}
void find_song_after_name() {
    char name[30];
    printf("Enter the name of the song you want to find: ");
    scanf("%s", &name);
    song* current = head;
    int find=0;
    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("The song was find on number: %d\n",current->nr);
            find=1;
        }
        current = current->next;
    }
    if(!find) printf("The song was not found!\n");
}
void delete_list() {
    while(head != NULL) {
        song* temp = head;
        head = head->next;
        free(temp);
    }
    printf("The list was deleted!\n");
}
void sort_list_by_title() {
    if (head == NULL || head->next == NULL) return;

    int sorted;
    do {
        sorted = 1;
        song **current = &head;

        while ((*current)->next != NULL) {
            if (strcmp((*current)->name, (*current)->next->name) > 0) {
                song* temp = (*current)->next;
                (*current)->next = temp->next;
                temp->next = *current;
                *current = temp;
                sorted = 0;
            }
            current = &((*current)->next);
        }
    } while (!sorted);

    printf("The songs were sorted!\n");
}
song* scan_values_for_song(song* new) {
    printf("Enter nr.");
    scanf("%d", &new->nr);
    printf("Enter name.");
    scanf("%s", new->name);
    printf("Enter author.");
    scanf("%s", new->author);
    printf("Enter year.");
    scanf("%d", &new->year);
    printf("Enter album.");
    scanf("%s", new->album);
    printf("Enter duration.");
    scanf("%d", &new->duration);
    return new;
}
void insert_at_end() {
    song* current =head;
    while(current->next != NULL) {
        current = current->next;
    }
    song* new=NULL;
    new = alloc_memory_for_song(new);
    if(new==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new = scan_values_for_song(new);
    current->next = new;
    new->next = NULL;
    printf("The song was successfully inserted in the list!\n");
}
void insert_at_beginning() {
    song* new=NULL;
    new = alloc_memory_for_song(new);
    if(new==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new = scan_values_for_song(new);
    new->next = head;
    head = new;
    printf("The song was successfully inserted in the list!\n");
}
void insert_at_position() {
    int position;
    printf("Enter the position:");
    scanf("%d", &position);
    while(head->nr != position) {
        head = head->next;
    }
    song* temp = head;
    song* new=NULL;
    new = alloc_memory_for_song(new);
    if(new==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new = scan_values_for_song(new);
    head = new;
    new->next = temp;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("The song was successfully inserted in the list!\n");
}
void delete_song_from_position() {
    int position;
    printf("Enter the position:");
    scanf("%d", &position);
    while(head->next->nr != position) {
        head = head->next;
    }
    song* prev=head;
    song* temp = head->next;
    prev->next=head->next->next;
    free(temp);
    printf("Song was successfully deleted!\n");
}
void inverse_list() {
    if (head == NULL || head->next == NULL) return;
    song* prev = NULL;
    song* current = head;
    song* next_node = NULL;
    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
    printf("The list was successfully reversed!\n");
}
// #endif