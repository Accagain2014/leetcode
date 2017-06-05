// Author :  Accagain
// Date   :  17/6/2
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * 题目：
 *  用C语言实现一个冒泡排序函数，要求支持泛型。
 *
 * 
 * 做法：
 *      
 * 时间复杂度：
 *          
 * size_t 是 unsigned int, 如果是 sizeof() / stl.size() 返回的都是unsigned int类型，如果值为0的话，-1,
 * -1会转化为unsigned int，会是一个很大的数，这样会出错；
 *
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>


void swap(char *a,char *b,size_t size)
{
    char tmp;
    if ( a != b ) {
        while ( size-- ) {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
    }

}

void bubblesort(void *base, int n, size_t elem_size,
                int (*compare)( void *, void * ))
{
    int  i, last, end = n - 1;
    char * addr1, * addr2;

    while (end > 0) {
        last = 0;
        for (i = 0; i < end; i++) {

            addr1 = (char *)base + i * elem_size;
            addr2 = (char *)base + (i + 1) * elem_size;

            if (compare( addr1, addr2 ) > 0) {
                swap(addr1, addr2, elem_size);
                last = i;
            }
        }

        end = last;
    }
}


int compare_int(void *elem1, void *elem2)
{
    return (*(int *)elem1 - *(int *)elem2);
}


int compare_double(void *elem1, void *elem2)
{
    return (*(double *)elem1 > *(double *)elem2) ? 1 : 0;
}


int main(){
    int num_int[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    double num_double[8] = {8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};

    bubblesort(num_int, 8, sizeof(int), compare_int);
    bubblesort(num_double, 8, sizeof(double), compare_double);

    for (int i = 0; i < 8; i++) {
        printf("%.1f ", num_double[i]);
    }
    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("%d ", num_int[i]);
    }
    return 0;
}

//
// Created by cms on 17/6/2.
//

