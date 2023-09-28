# Taller de Microarquitectura

## Repaso

**a)** ¿Cuáles son y qué respresenta cada entrada y cada salida del componente?¿Cuáles
entradas deben ser consideradas como de control?

inputs

- *clk*: Determina el ciclo de clock y por ende la entrada de todos los registros (Control)
- *input_bit*: El bit que se quiere almacenar en el registro (Data)
- *en_input_bit*: En caso de ser 1 habilita la entrada de input_bit para ser almacenada (Control)

- *w_n*: Determina si se escribe el registro n (Control)
- *en_out_n*: Determina si se puede leer el bit en el registro n (Control)

outputs

- *RN*: El bit que contiene el registro N
- *U*: El bit de entrada en caso de que este en_input_bit=1 o el bit de salida del registro n en caso de en_out_n=1. (sirve tambien como input para los registros)

**b)** Las entradas input bit y en input bit sirven para poder introducir en el circuito
un valor arbitrario. Escribir una secuencia de activación y desactivación de entradas
para que el registro R1 pase a tener el valor 1.

    w_1 , en_input_bit, input_bit, clk

**c)** Dar una secuencia de activaciones que inicialmente ponga un valor arbitrario en R0
(suponer para un valor y luego generalizarlo), luego que este valor se transfiera a
R1, luego que el valor de R2 pase a R0 y finalmente el valor de R1 a R2.

    (en_input_bit) --> si es que el valor llegar del input bit
    w_0 , clk  // inicializa el registro 0
    en_out_0 , w1 , clk // pasa R0 -> R1
    en_out_2 , w0 , clk // pasa R2 -> R0
    en_out_1 , w2 , clk // pasa R1 -> R2

-------------------------

## Checkpoint 1

### Analizar

**a)** ¿Cuál es el tamaño de la memoria?

El tamaño de la memoria es de 256 palabras de 8 bits, es decir 256B.

**b)** ¿Qué tamaño tiene el PC?

El PC tiene el tamaño de un registro, es decir 8 bits, una direccion de la memoria (256 posiciones es decir 2^8, se almacena en 8 bits).

**c)** ¿Cuántas instrucciones se podrı́an agregar respetando el formato de instrucción actual?

Se pueden almacenar 128 instrucciones ya que tienen el doble de tamaño que las palabras.

### Modulos de hardware

**a)** PC (Contador de Programa): ¿Qué función cumple la señal inc?

La señal ***PC_inc***, (si tiene valor 1) avanza a la siguiente posicion de memoria donde se ubican las instrucciones.

**b)** ALU (Unidad Aritmético Lógica): ¿Qué función cumple la señal opW?

La señal ***ALU_opW*** indica si se deben tener en cuenta los flags al realizar la operacion.

**c)** microOrgaSmall (DataPath): ¿Para qué sirve la señal DE enOutImm? ¿Qué parte del circuito indica que registro se va a leer y escribir?

La señal ***DE_enOutImm*** sirve para habilitar la entrada al bus de un valor inmediato, valor inmediato (M) que es output del Decode.  Para deteriminar que registro se va leer y cual escribir se utiliza ***RB_selectIndexIn*** (escribir) y ***RB_selectIndexOut*** (leer).

**d)** ControlUnit (Unidad de control): ¿Cómo se resuelven los saltos condicionales?
Describir el mecanismo.

Para resolver los saltos condicionales se utilizan

FALTA

-------------------------

## Checkpoint 2

output

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

**b)** ¿Qué lugar ocupará cada instrucción en la memoria? Detallar por qué valor se reemplazarán las etiquetas.

Como la memoria tiene un tamanio de palabra de 8 bits, cada instrucción ocupara 2 espacios de memoria. Por lo tanto el valor de cada las etiquetas sera:

    2 * cantidad de instrucciones + pos de ultima instruccion

Quedando asi **seguir** con la posicion 0x02 y **siguiente** con la posicion 0x06.

|    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |
|----------|----------|----------|----------|----------|----------|----------|----------|
|   JMC    |  SET R0  |   0xFF   |  SET R1  |   0X11   |  ADD R0  |    R1    |    JC    |

**c)** Ejecutar y controlar ¿cuántos ciclos de clock son necesarios para que este código llegue a la instrucción JMP halt?

Como se realiza una instruccion cada 2 clocks (8 bits por cada flanco de clock), para llegar a JMP halt deberian realizarse 5 intrucciones y por lo tanto 10 ciclos de clock.

**d)** ¿Cuántas microinstrucciones son necesarias para realizar el ADD? ¿Cuántas para el salto?

Para realizar el ADD deben hacerse 5 clocks, y para el el salto 7.

-------------------------
