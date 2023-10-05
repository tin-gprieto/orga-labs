#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void multiplicador(int *p, int mul)
{
    *p = *p * mul;
    // *p *= mul
}

void basic_pointers(){
    int x = 10;
    int *p = &x;

    printf("var x = %d\n", x);
    printf("var x in p = %d\n", *p);
    printf("dir of x  = 0x%x\n", p);

    void *pv;

    pv = p;
    printf("casting void p = %d\n", *(int *)pv);
}

void print_array(int *arr, size_t length)
{
    printf("[");
    for(size_t i = 0; i < length; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}

void basic_arrays()
{
    int arr_e[4] = {};
    print_array(arr_e, 4);
    int arr_e_2[4] = {0};
    print_array(arr_e_2, 4);
    int arr_ne_2[4] = {[1]=2, [3]=4};
    print_array(arr_ne_2, 4);
    
    int arr_ne[] = {0, 2, 0, 4};
    int *arr_p = arr_ne;
    // int *arr_p = &arr_ne[0];

    printf("[");
    for(size_t i = 0; i < 4; i++)
    {
        printf(" %d ", *(arr_p+i));
    }
    printf("]\n");

    int mat[2][3] = {{1,2,3}, {4,5,6}};

}

void basic_strings()
{
    char* str = "hola"; // in code (only read)

    char str2[] = {'h', 'o', 'l', 'a', '\0'}; //in stack (read and write)

    char* str_e = "";

    printf("Compare str: %d \n", strcmp(str, str2) == 0);
    printf("Compare str: %d \n", strcmp(str, str_e) == 0);

    //str[2] = 'j'; //seg fault
    str2[2] = 'j';

    printf(" %s \n", str);
    printf(" %s \n", str2);
}

int main()
{
    basic_pointers();
    basic_arrays();
    basic_strings();
}