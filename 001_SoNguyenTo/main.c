#include <stdio.h>

// Định nghĩa: số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó.
// Ví dụ: 2, 3, 5, 7, 11, 13, 17, ... là những số nguyên tố.

void main()
{
    int mangA[10] = { 100,3,99,19,22,17,23,29,31,37 };

    printf("So nguyen to la: ");
    for(int i = 0; i < 10; i++)
    {
        if(mangA[i] > 1 && ((mangA[i] % 1) == 0) && ((mangA[i] % mangA[i]) == 0))
        {
            printf("%d, ", mangA[i]);
        }
    }
}