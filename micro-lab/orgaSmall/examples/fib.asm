; fib(n)
;     a=1
;     b=1
;     for i in 0 to n:
;         n = a + b
;         a = b
;         b = n
;     return a

SET R0, 11     ; 00 ; n
SET R1,  0     ; 02 ; 0
SET R2,  1     ; 04 ; a 
SET R3,  1     ; 06 ; b
               ;
DEC R0         ; 08
CMP R0, R1     ; 0A
JZ fin         ; 0C
DEC R0         ; 0E
               ; 
ciclo:         ; 
    CMP R0, R1 ; 10
    JZ fin     ; 12
               ;
    ADD R2, R3 ; 14
               ;
    MOV R4, R3 ; 16
    MOV R3, R2 ; 18
    MOV R2, R4 ; 1A
               ;
    DEC R0     ; 1C
    JMP ciclo  ; 1E
fin:           ;
               ;
halt:          ;
JMP halt       ; 20
