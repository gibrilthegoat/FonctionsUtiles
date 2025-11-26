#include <stdio.h>
s[j] = s[i];
j++;
}
i++;
}
s[j] = '
␀
';
}


// Split a string by delimiter (manual strtok)
int split(const char *s, char delim, char tokens[][50], int max_tokens) {
int ti = 0;
int ci = 0;
while (*s && ti < max_tokens) {
if (*s == delim) {
tokens[ti][ci] = '
␀
';
ti++;
ci = 0;
} else {
tokens[ti][ci] = *s;
ci++;
}
s++;
}
tokens[ti][ci] = '
␀
';
return ti + 1;
}


// Test functions
int main() {
char s[200] = "Hello World";


printf("Length = %d", my_strlen(s));


my_reverse(s);
printf("Reverse = %s", s);


printf("Count 'l' = %d", count_char(s, 'l'));


char copy[200];
my_strdup(copy, s);
printf("Copy = %s", copy);


my_strcat(copy, "!!!");
printf("Concat = %s", copy);


printf("Index of 'W' = %d", find_char(copy, 'W'));


printf("Find substring 'lo' = %d", find_substring(copy, "lo"));


char spaced[200] = "A string with spaces";
remove_spaces(spaced);
printf("Without spaces = %s", spaced);


char text[] = "un;deux;trois;quatre";
char tokens[10][50];
int n = split(text, ';', tokens, 10);
printf("Split (%d tokens):", n);
for (int i = 0; i < n; i++) {
printf(" %s", tokens[i]);
}


return 0;
}
