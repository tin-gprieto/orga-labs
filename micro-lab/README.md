# Taller de Microarquitectura

## Repaso

### a) ¿Cuáles son y qué respresenta cada entrada y cada salida del componente?¿Cuáles entradas deben ser consideradas como de control?

inputs

- *clk*: Determina el ciclo de clock y por ende la entrada de todos los registros (Control)
- *input_bit*: El bit que se quiere almacenar en el registro (Data)
- *en_input_bit*: En caso de ser 1 habilita la entrada de input_bit para ser almacenada (Control)

- *w_n*: Determina si se escribe el registro n (Control)
- *en_out_n*: Determina si se puede leer el bit en el registro n (Control)

outputs

- *RN*: El bit que contiene el registro N
- *U*: El bit de entrada en caso de que este en_input_bit=1 o el bit de salida del registro n en caso de en_out_n=1. (sirve tambien como input para los registros)

### b) Las entradas input bit y en input bit sirven para poder introducir en el circuito un valor arbitrario. Escribir una secuencia de activación y desactivación de entradas para que el registro R1 pase a tener el valor 1

    input_bit en_input_bit w_1  

### c) Dar una secuencia de activaciones que inicialmente ponga un valor arbitrario en R0 (suponer para un valor y luego generalizarlo), luego que este valor se transfiera a R1, luego que el valor de R2 pase a R0 y finalmente el valor de R1 a R2

    (en_input_bit) --> si es que el valor llegar del input bit
    w_0             ; inicializa el registro 0
    en_out_0  w1    ; pasa R0 -> R1
    en_out_2  w0    ; pasa R2 -> R0
    en_out_1  w2    ; pasa R1 -> R2

-------------------------

## Checkpoint 1

### Analizar

#### a) ¿Cuál es el tamaño de la memoria?

El tamaño de la memoria es de 256 palabras de 8 bits, es decir 256B.

#### b) ¿Qué tamaño tiene el PC?

El PC tiene el tamaño de un registro, es decir 8 bits, una direccion de la memoria (256 posiciones es decir 2^8, se almacena en 8 bits).

#### c) ¿Cuántas instrucciones se podrı́an agregar respetando el formato de instrucción actual?

Se pueden almacenar 128 instrucciones ya que tienen el doble de tamaño que las palabras.

### Modulos de hardware

#### a) PC (Contador de Programa): ¿Qué función cumple la señal inc?

La señal ***PC_inc***, (si tiene valor 1) incremeta el valor actual de PC en uno.

#### b) ALU (Unidad Aritmético Lógica): ¿Qué función cumple la señal opW?

La señal ***ALU_opW*** habilita la escritura de los flags al realizar la operacion.

#### c) microOrgaSmall (DataPath): ¿Para qué sirve la señal DE enOutImm? ¿Qué parte del circuito indica que registro se va a leer y escribir?

La señal ***DE_enOutImm*** sirve para habilitar la entrada al bus de un valor inmediato, valor inmediato (M) que es output del Decode.  Para deteriminar que registro se va leer y cual escribir se utiliza ***RB_selectIndexIn*** (escribir) y ***RB_selectIndexOut*** (leer).

#### d) ControlUnit (Unidad de control): ¿Cómo se resuelven los saltos condicionales? Describir el mecanismo

Los saltos condicionales son instrucciones que permiten cambiar el flujo de un programa de acuerdo con una condicion especifica. 
Pueden utilizarse para salir de un ciclo o cambiar el flujo de un programa en función de una condicion dada.

JUMP utiliza una dirección de memoria o una ubicación especifica en el programa para saber donde saltar. 
La computadora no comprende etiquetas, sino que utiliza direcciones de memoria 
para localizar la ubicación de la proxima instrucción a ejecutar.

instrucciones de un salto condicional:
1. Lectura de la instruccion en la direccion indicada por el PC (Program Counter)
2. Se decodifica la instruccion para verificar la condicion especificada
3. Se evalua la condicion segun los valores almacenados y el estado del programa
4. Evalua si hacer el salto, de no cumplirse la condicion se continua con la siguiente secuencialmente
5. Si se hace el salto se continua ejecutando segun la nueva direccion de memoria
5b. De no cumplirse la condicion se sigue con el flujo del programa 

un ejemplo seria:

while a < 7 entonces:
    a = a + 1
    instruccion x
    instruccion y
termina while

direccion       programa            //Direccion del programa
                SET R0, 1           //Asignacion de valores
                SET R1, 7           
yyyyyyyy        CMP R3, R1          //Asignacion de memoria a la instruccion comparar
                JMP, xxxxxxxx       //Si se cumple, se sale del ciclo hacia otra etiqueta
                ADD R0, R3          //De no cumplirse se continua con el programa (while)
                instruccion x       //Se ejecutan las instrucciones necesarias
                instruccion y
                JMP yyyyyyyy        //Se regresa a la etiqueta y se compara nuevamente
xxxxxxxx

-------------------------

## Checkpoint 2

### output

    a0 
    02
    f8
    ff
    f9
    11
    08
    20
    a8
    06
    a0
    0a

### Preguntas

#### b) ¿Qué lugar ocupará cada instrucción en la memoria? Detallar por qué valor se reemplazarán las etiquetas

|    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |    09    |    10    |    11    |    12    |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|
|    a0    |    02    |    f8    |    ff    |    f9    |    11    |    08    |    20    |    a8    |    06    |    a0    |    0a    |
|   JMP    | seguir   |  SET R0  |   0xFF   |  SET R1  |   0X11   |  ADD R0  |    R1    |    JC    |siguiente |   JMP    |    halt   |

Como la memoria tiene un tamaño de palabra de 8 bits, cada instrucción ocupara 2 espacios de memoria. El valor de las etiquetas es la dirección de memoria que apunta a la ultima parte de la instrucción anterior a la etiqueta.

##### seguir

|    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |    09    |    10    |    11    |    12    |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|
|    a0    |    **02**    |    f8    |    ff    |    f9    |    11    |    08    |    20    |    a8    |    06    |    a0    |    0a    |
|   JMP    | **seguir**   |  SET R0  |   0xFF   |  SET R1  |   0X11   |  ADD R0  |    R1    |    JC    |siguiente |   JMP    |    halt   |

##### siguiente

|    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |    09    |    10    |    11    |    12    |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|
|    a0    |    02    |    f8    |    ff    |    f9    |    **11**    |    08    |    20    |    a8    |    06    |    a0    |    0a    |
|   JMP    | seguir   |  SET R0  |   0xFF   |  SET R1  |   **0X11**   |  ADD R0  |    R1    |    JC    |siguiente |   JMP    |    halt   |

##### halt

|    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |    09    |    10    |    11    |    12    |
|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|:----------:|
|    a0    |    02    |    f8    |    ff    |    f9    |    11    |    08    |    20    |    a8    |    **06**    |    a0    |    0a    |
|   JMP    | seguir   |  SET R0  |   0xFF   |  SET R1  |   0X11   |  ADD R0  |    R1    |    JC    | **siguiente** |   JMP    |    halt   |

Quedando asi **seguir** con la posicion 0x02 (2), **siguiente** con la posicion 0x06 (6), y **halt** con la posicion 0x0a (10).

#### c) Ejecutar y controlar ¿cuántos ciclos de clock son necesarios para que este código llegue a la instrucción JMP halt?

- Para que llegue a la instrucción JMP halt, el flag_C debe ser 0 para que la instrucción ***JC siguiente*** deja de ejecutarse y pase a halt. Para esto, la instrucción ***ADD R0,R1*** debería realizarse hasta que no haya un carry.

        11111111 (R0)
        +
        00010001 (R1)
        --------------
        00010000 (R0) C=1
        +
        00010001 (R1)
        --------------
        00100001 (R0) C=0

Por lo tanto, se realizan 3 operaciones (6 ciclos  de clock) para llegar a ***siguiente*** y luego esta se realiza 2 veces (con un tamaño es de 2 operaciones), por lo tanto se realiza en un total de 14 ciclos de clock para llegar a ***halt***.  

- En este caso nunca se puede llegar a halt ya que no se la asigna a la memoria de ejecución.

En primer lugar para conocer la cantidad de clocks necesarios, debemos partir de la base de que cada instrucción comienza con un fetch, el cual requiere 6 clocks (especificado en microCode.ops). A su vez cada instrucción despues de realizarse tiene el reset_microOP que hace que el contador vuelva a 0 para volver a iniciar el fetch de la siguiente.

En el conteo de clocks para cada operación ya vamos a estar incluyendo el reset_microOP.

En este caso particular, contamos con 3 instrucciones antes de llegar al ciclo, estas son:

    JMP ---> toma dos clocks + 6 del fetch = 8
    SET ---> toma dos clocks + 6 del fetch = 8 y a su vez como son dos SET sería 16 clocks ambos 

Sumando hasta acá tenemos 24.

Luego entramos al ciclo

En el cuerpo del ciclo tenemos dos intrucciones:

    ADD ---> Toma 5 clocks + 6 del fetch = 11 clocks
    JC  ---> Requiere 4 clocks + 6 del fetch = 10 

Luego volvemos a entrar al ciclo:

    ADD ---> Toma 5 clocks + 6 del fetch = 11 clocks

Y en este caso no se realiza la instrucción JC. 

Si sumamos = 24 + 21 + 11 = 56.

Esta es la cantidad de clocks que toma realizar el código.


#### d) ¿Cuántas microinstrucciones son necesarias para realizar el ADD? ¿Cuántas para el salto?

Para realizar ADD se requieren 12 microinstrucciones distribuidads en 5 ciclos de clock:

    RB_enOut  ALU_enA  RB_selectIndexOut=0
    RB_enOut  ALU_enB  RB_selectIndexOut=1
    ALU_OP=ADD ALU_opW
    RB_enIn   ALU_enOut RB_selectIndexIn=0
    reset_microOp

En cambio para el salto (JMP) se necesitan tan solo 3 microinstrucciones en 2 ciclos de clock:

    PC_load DE_enOutImm
    reset_microOp

-------------------------
