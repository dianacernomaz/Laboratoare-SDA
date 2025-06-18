#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

/**
 * @brief Creează un nou nod de tip student.
 *
 * @param key Cheia unică a studentului.
 * @param name Numele studentului.
 * @param address Adresa studentului.
 * @param age Vârsta studentului.
 * @return Un pointer către noul nod creat.
 */
student* create_new_node(int key, char *name, char *address, int age);

/**
 * @brief Inserează un nou nod în arbore.
 *
 * @param head Rădăcina arborelui.
 * @param key Cheia noului nod.
 * @param name Numele studentului.
 * @param address Adresa studentului.
 * @param age Vârsta studentului.
 * @return Rădăcina arborelui actualizată.
 */
student* insert_new_node(student* head, int key, char* name, char* address, int age);

/**
 * @brief Citește elemente de la tastatură și le inserează în arbore.
 *
 * @param head Rădăcina arborelui.
 * @return Rădăcina arborelui actualizată.
 */
student* scan_elements_of_tree(student* head);

/**
 * @brief Afișează arborele în ordine SVD (stânga, valoare, dreapta).
 *
 * @param head Rădăcina arborelui.
 */
void print_elements_of_tree_svd(student* head);

/**
 * @brief Afișează arborele în ordine VSD (valoare, stânga, dreapta).
 *
 * @param head Rădăcina arborelui.
 */
void print_elements_of_tree_vsd(student* head);

/**
 * @brief Afișează arborele în ordine SDV (stânga, dreapta, valoare).
 *
 * @param head Rădăcina arborelui.
 */
void print_elements_of_tree_sdv(student* head);

/**
 * @brief Afișează arborele în adâncime (DFS).
 *
 * @param head Rădăcina arborelui.
 */
void print_elements_of_tree_dfs(student* head);

/**
 * @brief Afișează arborele în lățime (BFS).
 *
 * @param head Rădăcina arborelui.
 */
void print_elements_of_the_tree_bfs(student* head);

/**
 * @brief Creează un arbore dezechilibrat pe baza inputului.
 *
 * @return Rădăcina arborelui dezechilibrat.
 */
student2* scan_unbalanced_tree();

/**
 * @brief Eliberează memoria ocupată de o listă liniară de tip student2.
 *
 * @param head Capul listei.
 */
void free_list(student2* head);

/**
 * @brief Eliberează memoria ocupată de arbore.
 *
 * @param root Rădăcina arborelui.
 */
void free_tree(student* root);

/**
 * @brief Generează un arbore echilibrat.
 *
 * @return Rădăcina arborelui echilibrat.
 */
student* get_balanced_tree();

/**
 * @brief Creează o oglindire (mirror) a arborelui.
 *
 * @param head Rădăcina arborelui inițial.
 * @return Rădăcina arborelui oglindit.
 */
student* get_tree_mirroring(student* head);

#endif // FUNCTIONS_H
