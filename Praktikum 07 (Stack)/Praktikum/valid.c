// Nama: Ceavin Rufus De Prayer Purba
// NIM: 18221162
// Tanggal: 24 Oktober 2022
// Topik: Stack
// Deskripsi: Nomor 3

#include <stdio.h>
#include "valid.h"

Stack validParantheses(char *input, int length)
{
    int i;
    Stack s;
    CreateEmpty(&s);
    for (i = 0; i < length - 1; i++)
    {
        if (input[i] == '(' && input[i + 1] == ')')
        {
            Push(&s, '(');
            Push(&s, ')');
        }
        else if (input[i] == '{' && input[i + 1] == '}')
        {
            Push(&s, '{');
            Push(&s, '}');
        }
        else if (input[i] == '[' && input[i + 1] == ']')
        {
            Push(&s, '[');
            Push(&s, ']');
        }
    }
    return s;
}