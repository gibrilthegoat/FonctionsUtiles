#include <stdio.h>
#include <string.h>
#include <math.h>

/* ===================== CHAÎNES DE CARACTÈRES ===================== */

// Longueur d'une chaîne (implémentation perso)
size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') len++;
    return len;
}

// Copie une chaîne dans une autre
void my_strcpy(char *dest, const char *src) {
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

// Concatène deux chaînes
void my_strcat(char *dest, const char *src) {
    while (*dest) dest++;
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

// Compare deux chaînes
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++; s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

// Compte le nombre d'occurrences d'un caractère
int count_char(const char *s, char c) {
    int count = 0;
    while (*s) if (*s++ == c) count++;
    return count;
}

/* ===================== TABLEAUX ===================== */

// Affiche un tableau d'entiers
void print_array(const int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Trouve le maximum
int max_in_array(const int *arr, size_t size) {
    int max = arr[0];
    for (size_t i = 1; i < size; i++) if (arr[i] > max) max = arr[i];
    return max;
}

// Inverse un tableau
void reverse_array(int *arr, size_t size) {
    size_t i = 0, j = size - 1;
    while (i < j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++; j--;
    }
}

// Somme des éléments
int sum_array(const int *arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) sum += arr[i];
    return sum;
}

/* ===================== POINTEURS ===================== */

// Échange deux entiers via pointeurs
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Retourne un pointeur vers le max d'un tableau
int* ptr_to_max(int *arr, size_t size) {
    int *max = &arr[0];
    for (size_t i = 1; i < size; i++) if (arr[i] > *max) max = &arr[i];
    return max;
}

/* ===================== STATIC ===================== */

// Exemple de variable static : compteur d'appels
int call_counter() {
    static int count = 0; // mémorisé entre les appels
    return ++count;
}

/* ===================== MAIN DE DEMO ===================== */
int main() {
    char str[50] = "Hello";
    my_strcat(str, " World!");
    printf("Concat: %s\n", str);

    int arr[5] = {3, 8, 1, 5, 2};
    printf("Max: %d\n", max_in_array(arr, 5));

    reverse_array(arr, 5);
    print_array(arr, 5);

    printf("Call counter: %d\n", call_counter());
    printf("Call counter: %d\n", call_counter());

    return 0;
}
