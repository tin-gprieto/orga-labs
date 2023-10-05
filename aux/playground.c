#include  <stdio.h>
#include  <stdint.h>

int main(){
    short int x = -16162;
    unsigned short int ux = (unsigned short int) x;

    //printf ("%i\n", x);
    //printf ("%i\n", ux);

    uint8_t a = 0xFF;

    printf ("0x%02X ; 0X%02X\n", a, ~a);  
    printf ("0x%02X ; 0X%02X\n", a, (uint8_t)~a);  

    uint32_t b = 0xFF;
    printf ("0x%08X ; shift der: 0X%08X\n", a, (uint32_t) b >> 3);  
    printf ("0x%08X ; shift izq: 0X%08X\n", a, (uint32_t) b << 3);  


}