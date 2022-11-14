#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

#define HEAD(Q) (Q).Tab[(Q).HEAD]
#define TAIL(Q) (Q).Tab[(Q).TAIL]
#define IDX_HEAD(Q) (Q).HEAD
#define IDX_TAIL(Q) (Q).TAIL
#define CAPACITY(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (IDX_HEAD(Q) == NIL) && (IDX_TAIL(Q) == NIL);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
    return Length(Q) == MaxLength(Q);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q){
    if (!IsEmpty(Q)){
        if (IDX_TAIL(Q) >= IDX_HEAD(Q)){
            return (IDX_TAIL(Q) - IDX_HEAD(Q) + 1);
        } else {
            return (CAPACITY(Q) - (IDX_HEAD(Q) - IDX_TAIL(Q)) + 1);
        }  
    } else {
        return 0;
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q){
    return CAPACITY(Q);
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max){
    Queue Q;
    Q.Tab = (ElType *) malloc (Max*sizeof(ElType));
    if (Q.Tab != NULL){
        CAPACITY(Q) = Max;
        IDX_HEAD(Q) = NIL;
        IDX_TAIL(Q) = NIL;
    } else {
        CAPACITY(Q) = 0;
    }

    return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
    free((*Q).Tab);
    CAPACITY(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
    if (!IsEmpty(*Q)){
        IDX_TAIL(*Q) = (IDX_TAIL(*Q)+1) % CAPACITY(*Q);
    } else {
        IDX_TAIL(*Q) = 0;
        IDX_HEAD(*Q) = 0;
    }
    TAIL(*Q) = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q){
    ElType val = HEAD(*Q);
    if (Length(*Q) == 1){
        IDX_HEAD(*Q) = NIL;
        IDX_TAIL(*Q) = NIL;
    } else {
        IDX_HEAD(*Q) = (IDX_HEAD(*Q)+1) % CAPACITY(*Q);
    }
    return val;
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q){
    return HEAD(Q);
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
void displayQueue(Queue q){
   if (IsEmpty(q)){
      printf("[]\n");
   } else {
      printf("[%d,", HEAD(q));
      for (int i = 1; i < Length(q)-1; ++i){
         printf("%d,", q.Tab[(IDX_HEAD(q) + i) % CAPACITY(q)]);
      }
      printf("%d]\n", TAIL(q));
   }
}