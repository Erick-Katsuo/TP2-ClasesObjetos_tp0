#ifndef _MENU_H_
#define _MENU_H_

#include "Gondola.h"
#include "Chango.h"
#include <fstream>
#include <iostream>
#include <cstdlib>


using namespace std;

const char OPCION_CARGAR_PRODUCTO = 'a';
const char OPCION_BUSCAR_PRODUCTO_NOMBRE = 'b';
const char OPCION_BUSCAR_PRODUCTO_CODIGO = 'c';
const char OPCION_MODIFICAR_PRECIO = 'd';
const char OPCION_QUITAR_PRODUCTO = 'e';
const char OPCION_CANTIDAD_OFERTA = 'f';
const char OPCION_CARGAR_CHANGO = 'g';
const char OPCION_MOSTRAR_PRODUCTOS_GONDOLA = 'h';
const char OPCION_MOSTRAR_PRODUCTOS_CHANGO = 'i';
const char OPCION_SALIR = 'x';

const char MENU_ACTIVO = 's'; // Este caracter es el que funciona como inicializador, es parte de las opciones que no hacen nada

const int MAX_CARGAR_PRODUCTOS = 10;
const string BUSQUEDA_NULA = "\0";

class Menu{

    private:

        char opcion_usuario;
        int posicion_producto_buscado;
        Gondola gondola_principal;
        Chango chango_principal;

        /*
        *Descripción: Recibe la opción del usuario guardándolo en el atributo "opcion_usuario".
        *Pre: -.
        *Post: Queda recibida la opción del usuario en el atributo "opcion_usuario".
        */
        void recibir_opcion();

        /*
        *Descripción: Lee del archivo de texto la cantidad de productos que tiene la góndola y luego los carga en un objeto Gondola.
        *Pre: El archivo "productos.txt" debe existir.
        *Post:  En el atributo "gondola_principal" queda inicializado el vector de clase Producto.
        *       con la cantidad y características de los productos del archivo "productos.txt".
        */
        void cargar_gondola();

        /*
        *Descripción: Lee la primer linea del archivo de texto, la cual dice la cantidad de productos que tendrá el archivo.
        *Pre: El archivo "productos.txt" debe existir.
        *Post: devuelve en el parametro "cantidad_productos" la cantidad exacta de productos en el archivo mencionado.
        */
        void leer_cantidad_productos(int &cantidad_productos, ifstream &archivo_productos);

                 /*
        *Descripción: Lee el archivo "productos.txt" guardando sus características en el vector de clase Productos del atributo "gondola_principal".
        *Pre:   El archivo "productos.txt" debe existir. El vector perteneciente al atributo
                "gondola_principal" debe estar correctamente inicializado. El archivo de lectura debe estar posicionado sobre
                el primer producto a leer, ya que la primer línea es la cantidad de productos,y no la debe leer
        *Post: Guarda los productos en el vector de Productos del atributo "gondola_principal".
        */
        void leer_productos(ifstream &archivo_productos);

        /*
        *Descripción: Muestra por consola los productos actuales del vector dinámico del atributo "gondola_principal".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinámico del atributo "gondola_principal".
        */
        void mostrar_productos_de_la_gondola();

        /*
        *Descripción: Muestra por consola los productos actuales del vector dinámico del atributo "chango_principal".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinámico del atributo "chango_principal".
        */
        void mostrar_productos_del_chango();

        /*Descripcion: Pedira los datos de la cantidad deseada de productos a ingresar.
        *Pre: Codigo y Nombre de los productos no pueden repetirse.
        *Post: Los datos de los productos a ingresar quedan almacenados en el vector de productos ingresado por parametro.
        */
        void pedir_datos_producto(int nuevo_tamanio_cargar, Producto productos_a_cargar[]);


        /*Descripción: De acuerdo con la opción que ha elegido el usuario, realiza una tarea particular.
        *Precondiciones: La opción elegida por el usuario se encuentra dentro del dominio de dicho atributo.
        *Postcondiciones: Ejecuta la opción acorde con lo que haya elegido el usuario.
        */
        void ejecutar_opcion();

        /*Descripción:      Si la opción elegida anteriormente fue para buscar un producto, este método
        *                   implementa las opciones que se pueden realizar con el producto encontrado
        *Precondiciones:    La opción elegida por el usuario se encuentra dentro del dominio de dicho atributo.
        *Postcondiciones:   Ejecuta la opción secundaria acorde con lo que haya elegido el usuario.
        */
        void ejecutar_opcion_secundaria();


        /*Descripción:  Este método se encarga de mostrarle el menú de opciones del supermercado
                        al usuario a través de una interfaz gráfica rudimentaria.
        *Precondiciones: -.
        *Postcondiciones: Se imprime por pantalla el menú de opciones para la visualización del usuario.
        */
        void mostrar_menu();

        /*Descripción:  Este método se encarga de mostrarle el submenú de opciones del supermercado
                        al usuario a través de una interfaz gráfica rudimentaria.
        *Precondiciones: -.
        *Postcondiciones: Se imprime por pantalla el submenú de opciones para la visualización del usuario.
        */
        void mostrar_submenu();

        /*Descripción:  Realizará los métodos necesarios para poder agregar productos al
                        vector dinámico de clase Prodcuto del atributo "gondola_principal".
         *Pre: Máximo 10 productos a ingresar..
         *Post: Queda actualizado el vector dinámico mencionado.
        */
        void cargar_nuevos_productos_gondola();


        /*Descripción:  Realiza la comprobacion de stock en el producto requerido.
         *Pre:-.
         *Post: Si comprueba un stock >0 prosigue a cargar productos al vector dinamico chango_principal, en caso contrario notifica
                la falta de stock mediante consola.
        */
        void comprobar_stock();

        /*Descripción:  Este método llama al método de gondola principal que muestra la cantidad de productos en oferta.
        *Precondiciones: -.
        *Postcondiciones: Se imprime por pantalla la cantidad de productos en oferta.
        */
        void mostrar_productos_oferta();

        /*Descripción: Busca el nombre del producto ingresado en el vector dinámico de clase Producto del atributo "gondola_principal".
         *Pre: -.
         *Post: Devuelve un puntero al producto buscado y un puntero nulo si no encontró el producto.
        */
        int buscar_producto_nombre();

        /*Descripcion: Busca el codigo del producto ingresado en el vector dinamico de clase Producto del atributo "gondola_principal".
         *Pre: -.
         *Post: Devuelve un puntero al producto buscado y un puntero nulo si no encontro el producto
        */
        int buscar_producto_codigo();

    public:

        /*Constructor
        *Descripcion: Inicializa el atributo "opcion_usuario". Muestra por consola que se ingreso al constructor.
        *Pre:-.
        *Post: El atributo mencionado queda inicializado. Muestra por consola el ingreso al constructor de esta clase.
        */
        Menu();

        /*
        *Descripción: Inicia la interfaz del programa usando los métodos y clases necesarios para realizar la misma.
        *Pre: El archivo "productos.txt" debe existir.
        *Post: Se muestra un menu mediante consola dando a elegir distintas opciones al usuario, el programa realizará las opciones del menú.
        */
        void iniciar_interfaz();
};

#endif /*_MENU_H_*/
