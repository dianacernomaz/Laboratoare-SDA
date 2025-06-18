#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main(void) {
    scan_songs_from_file();
    int option;
    do {
        printf("Menu:\n");
        printf("1. Display the list of songs\n");
        printf("2. Read songs from file\n");
        printf("3. Find a song by title\n");
        printf("4. Delete list\n");
        printf("5. Sort list by title\n");
        printf("6. Insert new song at the end of list\n");
        printf("7. Insert new song at the beginning\n");
        printf("8. Insert new song at the position\n");
        printf("9. Delete song from list\n");
        printf("10. Reverse list\n");
        printf("11. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case DISPLAY_SONGS: display_songs(); break;
            case SCAN_SONGS_FROM_FILE: scan_songs_from_file(); break;
            case FIND_SONG_AFTER_NAME: find_song_after_name(); break;
            case DELETE_LIST: delete_list(); break;
            case SORT_LIST_BY_TITLE: sort_list_by_title(); break;
            case INSERT_AT_END: insert_at_end(); break;
            case INSERT_AT_BEGINNING: insert_at_beginning(); break;
            case INSERT_AT_POSITION: insert_at_position(); break;
            case DELETE_FROM_POSITION: delete_song_from_position(); break;
            case INVERSE_LIST: inverse_list(); break;
            case EXITING: printf("Exiting...\n"); return 0;
            default: printf("Invalid option!\n");
        }
    } while (option != 12);
}
