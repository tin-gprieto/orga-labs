# Makefile para verificar la solución utilizando Logisim-Evolution y diff

# Comando para ejecutar Logisim-Evolution y generar la tabla de resultados
LOGISIM =  logisim-evolution
CIRCUIT = TallerLogica-Combinatorios-individual.circ

VERIFIER= verificador
OUTPUT_FILE = out.txt
EXPECTED_OUTPUT = salida_catedra.txt

all: test

# Regla principal para verificar la solución
test:
	@echo "inicio de verificacion"
	$(LOGISIM) --toplevel-circuit "$(VERIFIER)" -tty table "$(CIRCUIT)" > "$(OUTPUT_FILE)"
	@echo "Verificando resultados..."
	@diff -q "$(EXPECTED_OUTPUT)" "$(OUTPUT_FILE)" && echo "¡Los resultados son correctos!" || echo "¡ERROR: Los resultados son incorrectos!"
    
# Regla para limpiar los archivos generados
clean:
	@rm -f "$(OUTPUT_FILE)"

.PHONY: test clean

