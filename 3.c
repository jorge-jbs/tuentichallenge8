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
    /*
    tScale scale;
    genScale(0, MINOR, scale);
    for (int i = 0; i < 7; i++) {
        print_note(scale[i]);
        printf(" ");
    }
    printf("\n");
    */
    for (int i = 0; i < 24000*10000; i++) {
    }
    int notes[1000];
    notes[0] = 3;
    notes[1] = 3;
    notes[2] = 10;
    notes[3] = 10;
    notes[4] = 0;
    notes[5] = 0;
    notes[6] = 10;
    printf("%d\n", is_match(2, notes, 7, MAJOR));
}
