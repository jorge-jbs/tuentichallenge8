#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int tScale[7];
typedef bool tNotesSet[12];

const tScale MAJOR = { 2, 2, 1, 2, 2, 2, 1 };
const tScale MINOR = { 2, 1, 2, 2, 1, 2, 2 };

void genScale(int root, const tScale mode, tScale scale) {
    for (int i = 0; i < 7; i++) {
        scale[i] = root % 12;
        root += mode[i];
    }
}

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


    /*
    char c;
    scanf("%c", &c);
    switch (c) {
    case 'M': *mode = Major; break;
    case 'm': *mode = Minor; break;
    }
    scanf("%c", &c);
    */
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

void find_scales(tNotesSet scales, const tScale mode, int notes[1000], int n, int *k) {
    *k = 0;
    for (int root = 0; root < 12; root++) {
        if (is_match(root, notes, n, mode)) {
            printf("M");
            print_note(root);
            printf(" ");
            ++(*k);
        }
    }
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

    /*
    tScale scale;
    genScale(0, MINOR, scale);
    for (int i = 0; i < 7; i++) {
        print_note(scale[i]);
        printf(" ");
    }
    printf("\n");
    */
    /*
    tMode mode;
    int note;
    scan_note(&mode, &note);
    printf("%d %d\n", mode, note);
    notes[0] = 3;
    notes[1] = 3;
    notes[2] = 10;
    notes[3] = 10;
    notes[4] = 0;
    notes[5] = 0;
    notes[6] = 10;
    */
    //printf("%d\n", is_match(2, notes, 7, MAJOR));
}
