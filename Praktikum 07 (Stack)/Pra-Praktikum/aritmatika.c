#include "aritmatika.h"
#include <stdio.h>

boolean isOperator(char input){
    return (input == '+') || (input == '-') || (input == '*') || (input == '/');
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op){
    switch(op) {
      case '+':
        return angka1 + angka2;
      case '-':
        return angka1 - angka2;
      case '*':
        return angka1 * angka2;
      case '/':
        return angka1 / angka2;
    }
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length){
    Stack S;
    int angka1, angka2, hasil=0;

    CreateEmpty(&S);
    for (int i = 0; i < length; ++i)
    {
        if (isOperator(input[i])) {
            Pop(&S, &angka2);
            Pop(&S, &angka1);
            hasil = hitung(angka1, angka2, input[i]);
            Push(&S, hasil);
        } else {
            Push(&S, (int) input[i] - 48);
        }
    }
    return hasil;
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
