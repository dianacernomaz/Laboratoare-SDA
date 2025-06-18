#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"
song* alloc_memory_for_song(song* new);
void scan_songs_from_file();
void display_songs();
void find_song_after_name();
void delete_list();
void sort_list_by_title();
song* scan_values_for_song(song* new);
void insert_at_end();
void insert_at_beginning();
void insert_at_position();
void delete_song_from_position();
void inverse_list();

#endif //FUNCTIONS_H
