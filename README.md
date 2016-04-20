# Elestac

## Checkpoint 1 (30 abril):
- [x] ~~agregar commons~~
  - [ ] implementar librerías
- [x] ~~agregar parser~~
  - [ ] implementar parser en programa de ejemplo
- [ ] conectar módulos
  - [ ] función handshake

## Instalar ambiente de trabajo
1. `git clone http://github.com/sisoputnfrba/tp-2016-1c-Cazadores-de-cucos.git`
2. Abrir eclipse
3. File - New - Import - General - Existing...
4. Browse - Seleccionan la carpeta "tp-2016-1c-Cazadores-de-cucos" y OK
5. Ahora hay que hacer que linken las librerías
  1. Ir con consola a la carpeta de commons de nuestro repositorio
  2. Escribimos en consola: `sudo make install`
  3. Repetimos para el parser

## Vamos a trabajar todos sobre la rama 'master'. Comandos necesarios:
1. *Indicar la direcicón de mi proyecto:* `cd /home/utnso/...` (donde lo tengan guardado)
2. *Averiguar el estado de mi proyecto:* `git status`
3. *Bajar del repo la última versión del proyecto:* `git pull` (siempre antes de un push)
4. *Agregar (todos) los cambios realizados:* `git add .`
5. *Agregar solo un cambio realizado:* `git add nombre_del_archivo`
5. *Hacer el commit correspondiente:* `git commit -m "los cambios que hice"`
6. *Actualizar la versión existente en Github (subir lo que hice):* `git push`

Más comandos acá (branches, etc.): http://blog.desdelinux.net/guia-rapida-para-utilizar-github/

## Para implementar/usar alguna de las common libraries en un .c/.h debe incluirse así:

- Logging: `#include <commons/log.h>`

- Manipulación de Strings: `<commons/string.h>`

- Manipulación de archivos de configuración: `<commons/config.h>`

- Manejo/Funciones de fechas: `<commons/temporal.h>`

- Manejo de array de bits: `<commons/bitarray.h>`

- Información de procesos: `<commons/process.h>`

- Manejo simple de archivos de texto: `<commons/txt.h>`

Conjunto de elementos:

- List: `#include <commons/collections/list.h>`

- Dictionary: `#include <commons/collections/dictionary.h>`

- Queue: `#include <commons/collections/queue.h>`

## Debuguear
- [Tutorial de UTN](https://youtu.be/XsefDXRfA9k)
- F6: siguiente instrucción
- F5: meterse en instrucción
- Para debuggear hilos usar breakpoints

## Links importantes
- [Enunciado](http://www.utn.so/wp-content/uploads/2016/04/1C2016-Elestac-1.pdf)
- [Tutorial básico GitHub](https://youtu.be/cEGIFZDyszA?list=PL6gx4Cwl9DGAKWClAD_iKpNC0bGHxGhcx)
- [Direccionario UTN](http://faq.utn.so/)
- [Git Difftool](https://youtu.be/iCGrKFH2oeo)
