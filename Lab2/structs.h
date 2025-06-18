
#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct song {
    char *album;
    char *name;
    char *author;
    int nr;
    int year;
    int duration;
    struct song* next;
}song;
enum {
    DISPLAY_SONGS =1,
    SCAN_SONGS_FROM_FILE=2,
    FIND_SONG_AFTER_NAME=3,
    DELETE_LIST=4,
    SORT_LIST_BY_TITLE=5,
    INSERT_AT_END=6,
    INSERT_AT_BEGINNING=7,
    INSERT_AT_POSITION=8,
    DELETE_FROM_POSITION=9,
    INVERSE_LIST=10,
    EXITING=11
};
#endif //STRUCTS_H
