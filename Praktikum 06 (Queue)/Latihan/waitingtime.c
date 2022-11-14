#include "circular_queue.h"

#define NOT_FOUND -1

int WaitingTime(Queue Q, int x) {
    int waitTime;
    if (IsEmpty(Q)) {
        waitTime = NOT_FOUND;
    } else {
        /**
         * Perhatikan bahwa Queue di-pass secara value dan
         * operasi Pop hanya mengubah nilai HEAD dari Q, sehingga
         * reference Queue yang sebenarnya di-pass tidak akan
         * mengalami perubahan nilai.
         * 
         * [WARNING] Pahami bahwa walaupun Q di-pass secara value,
         * array Q.Tab tetap di-pass secara reference karena bentuk
         * array sendiri pada dasarnya adalah sebuah pointer.
         */
        ElType currentEl = Pop(&Q);
        waitTime = 0;
        while (!IsEmpty(Q) && currentEl != x) {
            currentEl = Pop(&Q);
            waitTime++;
        }
        if (currentEl != x) {
            waitTime = NOT_FOUND;
        }
    }
    return waitTime;
}
