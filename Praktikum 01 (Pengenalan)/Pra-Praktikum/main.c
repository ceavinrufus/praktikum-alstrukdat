#include <stdio.h>

int main()
{
    int j, m, d, det;
    scanf("%d", &d);
    j = d / 3600;
    m = (d % 3600) / 60;
    det = d - m * 60 - j * 3600;
    printf("%d detik = %d jam %d menit %d detik\n", d, j, m, det);
    return 0;
}
