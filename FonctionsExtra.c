#include <stdio.h>
#include <string.h>
#include <math.h>

/* ===================== FONCTIONS SUR LES CHAÎNES ===================== */

// Convertit une chaîne en majuscules
void to_upper(char *s) {
    for (size_t i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
}

// Convertit une chaîne en minuscules
void to_lower(char *s) {
    for (size_t i = 0; s[i]; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
}

// Trouve un caractère, renvoie pointeur ou NULL
char* my_strchr(const char *s, char c) {
    while (*s) {
        if (*s == c) return (char*)s;
        s++;
    }
    return NULL;
}

// Renverse une chaîne
void reverse_string(char *s) {
    size_t i = 0;
    size_t j = strlen(s) - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
}

/* ===================== TABLEAUX ===================== */

// Recherche d'un élément dans un tableau
int find_in_array(const int *arr, size_t size, int value) {
    for (size_t i = 0; i < size; i++) if (arr[i] == value) return (int)i;
    return -1;
}

// Moyenne des valeurs
float avg_array(const int *arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) sum += arr[i];
    return size ? (float)sum / size : 0;
}

// Tri simple (bubble sort)
void bubble_sort(int *arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/* ===================== POINTEURS ===================== */

// Retourne un pointeur vers le min du tableau
int* ptr_to_min(int *arr, size_t size) {
    int *min = arr;
    for (size_t i = 1; i < size; i++) if (arr[i] < *min) min = &arr[i];
    return min;
}

// Décale un pointeur n cases en vérifiant la limite
int* safe_ptr_shift(int *base, size_t size, int shift) {
    if (shift < 0 && (size_t)(-shift) > size) return NULL;
    if ((size_t)shift >= size) return NULL;
    return base + shift;
}

/* ===================== STATIC ===================== */

// Exemple : retourne une suite de Fibonacci avec static
int fibonacci_static(void) {
    static int a = 0;
    static int b = 1;
    int next = a + b;
    a = b;
    b = next;
    return next;
}

/* ===================== DEMO ===================== */
int main() {
    char text[50] = "OpenAI is cool";
    to_upper(text);
    printf("UPPER: %s\n", text);

    reverse_string(text);
    printf("REVERSE: %s\n", text);

    int arr[6] = {7, 2, 9, 1, 4, 3};
    bubble_sort(arr, 6);
    for (int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Fibo static: %d\n", fibonacci_static());
    printf("Fibo static: %d\n", fibonacci_static());

    return 0;
}
