#include <stdio.h>
#include <string.h>
#include <math.h>

/* ===================== FONCTIONS AVANCÉES SUR LES CHAÎNES ===================== */

/* Retire les espaces en début et fin (trim) */
void trim(char *s) {
    int start = 0;
    int end = strlen(s) - 1;

    while (s[start] == ' ') start++;
    while (end >= start && s[end] == ' ') end--;

    int j = 0;
    for (int i = start; i <= end; i++) {
        s[j++] = s[i];
    }
    s[j] = '\0';
}

/* Compte les occurrences d'un mot dans une chaîne */
int count_word(const char *str, const char *word) {
    int count = 0;
    size_t len = strlen(word);

    for (size_t i = 0; str[i]; i++) {
        if (strncmp(&str[i], word, len) == 0) {
            count++;
            i += len - 1;
        }
    }
    return count;
}

/* Supprime un caractère partout dans la chaîne */
void remove_char(char *s, char c) {
    int j = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/* Inverse l'ordre des mots */
void reverse_words(char *s) {
    char temp[200];
    strcpy(temp, s);

    char *words[50];
    int count = 0;

    char *token = strtok(temp, " ");
    while (token) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    s[0] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        strcat(s, words[i]);
        if (i > 0) strcat(s, " ");
    }
}

/* Supprime les doublons de lettres successives (ex: "heeellooo" -> "helo") */
void remove_duplicates(char *s) {
    int j = 0;
    for (int i = 0; s[i]; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/* Trouve le plus long mot de la chaîne */
void longest_word(const char *s, char *dest) {
    int maxLen = 0, currentLen = 0;
    int bestStart = 0, start = 0;

    for (int i = 0; ; i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            if (currentLen == 0) start = i;
            currentLen++;
        } else {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                bestStart = start;
            }
            currentLen = 0;
        }
        if (s[i] == '\0') break;
    }

    strncpy(dest, &s[bestStart], maxLen);
    dest[maxLen] = '\0';
}

/* Vérifie si une chaîne est un palindrome */
int is_palindrome(const char *s) {
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

/* ===================== DEMO ===================== */
int main() {
    char text1[100] = "   hello world   ";
    trim(text1);
    printf("Trim: '%s'\n", text1);

    printf("Count 'lo' in 'hello lololo': %d\n", count_word("hello lololo", "lo"));

    char text2[100] = "heeellooo woooorld";
    remove_duplicates(text2);
    printf("Remove duplicates: %s\n", text2);

    char text3[200] = "C language is very powerful";
    reverse_words(text3);
    printf("Reverse words: %s\n", text3);

    char lw[50];
    longest_word("ChatGPT generates awesome code", lw);
    printf("Longest word: %s\n", lw);

    printf("Palindrome 'level': %d\n", is_palindrome("level"));
    printf("Palindrome 'openai': %d\n", is_palindrome("openai"));

    return 0;
}
