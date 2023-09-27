; mcd(a, b)
;     while a != b
;         if a > b
;             a = a - b
;         else
;             b = b - a
;     return a

SET R0, 15          ; 00 ; a             
SET R1, 6           ; 02 ; b

ciclo: 
    CMP R0, R1       ; 04
    JZ igual         ; 06 
    JN R0menorR1     ; 08 
        SUB R0, R1   ; 0A
        JMP ciclo    ; 0C
    R0menorR1:
        SUB R1, R0   ; 0E
        JMP ciclo    ; 10
igual:

halt:
JMP halt             ; 12