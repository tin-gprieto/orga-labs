global intercambiar

;void intercambiar(char *cadena)
;                       rdi
intercambiar:

    xor rax, rax; inicializa longitud/fin

    .condition:
        cmp byte [rdi + rax], 0; cadena[longitud] != 0 
                               ; 0 - cadena[longitud] 
        jz .iter ; si es 0 salta al iter (consiguió la longitud)
        inc rax; longitud++
        jmp .condition

    .iter:
        test rax, rax; corta si fin == 0
        jz .corte

        dec rax
        mov rdx, 0 ; inicializa inicio

    .ciclo:
        mov cl, byte[rdi + rdx] ; byte de rcx (variable inicio) => c_i 
        mov sil, byte[rdi + rax]; byte de rsi (variable fin) => c_f
        
        mov byte[rdi + rdx], sil; str[i] = c_f
        mov byte[rdi + rax], cl; str[f] = c_i

        inc rdx
        dec rax

        cmp rdx, rax; fin(rax) - inicio(rdx) 
        jl .ciclo

    .corte:
        ret

