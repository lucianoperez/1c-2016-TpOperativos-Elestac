#include <stdio.h>
#include <stdlib.h>
#include <parser/parser.h>
#include <utilidades/general.h>
#include "lib/fcpu.h"

int main(void) {

	leerArchivoDeConfiguracion("config.txt"); // Abro archivo configuración

	void conectarConNucleo(); // Conexión con Núcleo

	return EXIT_SUCCESS;
}
