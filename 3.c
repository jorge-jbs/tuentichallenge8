#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int tScale[7];
typedef bool tNotesSet[12];

const tScale MAJOR = { 2, 2, 1, 2, 2, 2, 1 };
const tScale MINOR = { 2, 1, 2, 2, 1, 2, 2 };

// Set should be set to false.
void genNotesSet(int root, const tScale mode, tNotesSet set) {
    for (int i = 0; i < 7; i++) {
        set[root % 12] = true;
        root += mode[i];
    }
}

void scan_note(int *note) {
    char s[3] = {0};
    scanf("%s", s);
    switch (s[0]) {
    case 'A': *note = 0; break;
    case 'B': *note = 2; break;
    case 'C': *note = 3; break;
    case 'D': *note = 5; break;
    case 'E': *note = 7; break;
    case 'F': *note = 8; break;
    case 'G': *note = 10; break;
    }
    *note += 12;
    switch (s[1]) {
    case '#': ++(*note); break;
    case 'b': --(*note); break;
    }
    *note %= 12;
}

void print_note(int note) {
    switch (note) {
    case 0:  printf("A");  break;
    case 1:  printf("A#"); break;
    case 2:  printf("B");  break;
    case 3:  printf("C");  break;
    case 4:  printf("C#"); break;
    case 5:  printf("D");  break;
    case 6:  printf("D#"); break;
    case 7:  printf("E");  break;
    case 8:  printf("F");  break;
    case 9:  printf("F#"); break;
    case 10: printf("G");  break;
    case 11: printf("G#"); break;
    }
}

bool is_match(int root, int notes[1000], int n, const tScale mode) {
    tNotesSet set = { false };
    genNotesSet(root, mode, set);
    for (int i = 0; i < n; i++) {
        if (!set[notes[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    int c;
    scanf("%d\n", &c);
    for (int i = 0; i < c; i++) {
        printf("Case #%d: ", i+1);
        int n;
        scanf("%d\n", &n);
        int notes[1000];
        for (int j = 0; j < n; j++) {
            scan_note(&notes[j]);
        }
        int *majors = malloc(sizeof(int)*12);
        int a = 0;
        for (int root = 0; root < 12; root++) {
            if (is_match(root, notes, n, MAJOR)) {
                majors[a] = root;
                a++;
            }
        }
        int *minors = malloc(sizeof(int)*12);
        int b = 0;
        for (int root = 0; root < 12; root++) {
            if (is_match(root, notes, n, MINOR)) {
                minors[b] = root;
                b++;
            }
        }
        int j;
        for (j = 0; j < a-1; j++) {
            printf("M");
            print_note(majors[j]);
            printf(" ");
        }
        if (a != 0) {
            printf("M");
            print_note(majors[j]);
            if (b != 0) printf(" ");
        }
        for (j = 0; j < b-1; j++) {
            printf("m");
            print_note(minors[j]);
            printf(" ");
        }
        if (b != 0) {
            printf("m");
            print_note(minors[j]);
        }
        if (a == 0 && b == 0) printf("None");
        printf("\n");
    }
}
