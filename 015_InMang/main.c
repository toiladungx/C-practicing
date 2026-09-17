/*
Bài tập C: In các phân tử của một mảng trong C
Đề bài: Viết chương trình C in các phần của của một mảng ra màn hình.
*/

#include <stdio.h>

#define THUAN;

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i, size;

    size = sizeof(arr) / sizeof(arr[0]);

    printf("Tat ca phan tu cua mang: ");
    
    #ifdef THUAN
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    #else
    for(i = size-1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    #endif
    
    return 0;
}