#include "reverse.h"
#include <stdio.h>
void transferReverse(Queue *q1, Queue *q2)
{
    IdxType tempTail = q1->TAIL;

    q2->TAIL = q1->TAIL+1;
    q2->HEAD = q1->HEAD;

    while(q2->TAIL >= q2->HEAD){
        q2->TAIL -= 2;
        Push(q2, Pop(q1));
    }

    q2->TAIL = tempTail;
}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
