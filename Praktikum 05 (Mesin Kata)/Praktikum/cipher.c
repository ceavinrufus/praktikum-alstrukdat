// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 03/10/2022
// Topik: Mesin karakter dan kata
// Deskripsi: Nomor 3

#include <stdio.h>
#include "mesinkata.h"


boolean endWord;
Word currentWord;

char geser(char c, int i) {
    int a;
    a = 'A';
    return ((c - a + i)%26 + a);
}

int main() {
    STARTWORD();
    int i, n;
    i = 0;
    n = currentWord.Length; // panjang kata pertama

    while (!endWord) {
        for (i=0; i<currentWord.Length; i++){
            printf("%c",geser(currentWord.TabWord[i], n));
        }
        if (currentChar == MARK) {
            printf("%c\n", MARK);
        } else {
            printf("%c", BLANK);
        }
        ADVWORD();
    }
    return 0;
}