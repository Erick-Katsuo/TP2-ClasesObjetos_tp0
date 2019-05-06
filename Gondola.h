#ifndef _GONDOLA_H_
#define _GONDOLA_H_

#include "Producto.h"
#include <iostream>

using namespace std;

const int CANTIDAD_INICIAL_PRODUCTOS = 0;
const int CANTIDAD_INICIAL_CARGAR_PRODUCTOS = 0;
const float PRECIO_INVALIDO = -1;
const int POSICION_INVALIDA = -1;


class Gondola{

    private:

        int tamanio_gondola;
       	int cantidad_productos_oferta; 

        Producto* productos_gondola;
        Producto* gondola_auxiliar; // Vector dinamico aux para la redimension

        /*
        *Descripcion: Crea un vector dinamico auxiliar con el valor que recibe tamanio_nuevo.
        *Pre: tamanio_nuevo tiene que ser mayor a cero (0).
        *Post: Queda asignada la memoria dinamica para el vector dinamico auxiliar.
        */
        void crear_espacio_gondola(int tamanio_nuevo);

        /*
        *Descripcion: Desplaza los productos actuales al vector dinamico auxiliar.
        *Pre: El vector auxiliar debe tener el tamanio necesario para que entren los productos
        *Post: El vector dinamico auxiliar posee los productos actuales.
        */
        void desplazar_productos_actuales();

        /*
        *Descripcion: Acomoda los nuevos productos al vector dinamico auxiliar.
        *Pre: El vector de productos que recibe debe ser válido.
        *Post: El vector dinamico auxiliar queda actualizado con todos los productos.
        */
        void desplazar_productos_nuevos(Producto productos_a_cargar[], int tamanio_nuevo);

        /*
        *Descripcion: Muestra por consola el productos de la posición pasada por parémetro.
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinamico "productos_gondola".
        */
        void mostrar_producto_particular_gondola(int posicion);

    public:

	    /*Constructor
        *Descripcion: Inicializa el atributo "tamanio_gondola" y muestra por consola qué se ingreso al constructor.
        *Pre:-.
        *Post: El atributo mencionado queda inicializado.
        */
        Gondola();

        /*Descripción: 	Este método se encargará de asignarle un nuevo valor al tamaño de la góndola,
        				que representa la cantidad de productos presentes en ella.
        *Pre: 			El nuevo_tamanio_gondola pasado como parámetro debe ser un número positivo y natural.
        *Post: 			Al atributo tamanio_gondola de un objeto de clase Gondola se le asigna el valor de
        				nuevo_tamanio_gondola, variable pasada como parámetro.
        */
        void asignar_tamanio_gondola(int nuevo_tamanio_gondola);

         /*
        *Descripción: Crea el vector dinámico del atributo "productos_gondola".
        *Pre: "tamanio_gondola" tiene que ser mayor a cero (0).
        *Post: Queda asignada la memoria dinamica para el vector del atributo "productos_gondola"
        */
        void preparar_gondola();

        /*
        *Descripción: Resta una unidad al stock del producto que se encuentre en la posición pasada por parámetro del vector 
        dinámico de productos de un objeto de clase Gondola.   
        *Pre: La posición pasada por parámetro corresponde a un producto existente del vector dinámico de productos.
        *Post: El stock del producto cuya posición es pasada por parámetro es restado en una unidad.
        */
        void restar_stock(int pos);

        /*
        *Descripcion: Devuelve la direccion del vector dinamico "productos gondola" en la posicion requerida.
        *Pre: posicion >= 0.
        *Post: Retorna la direccion del vector "productos_gondola" en la posicion requerida.
        */
        Producto* obtener_producto(int posicion);

        /*
        *Descripción: Actualiza el vector dinámico del atributo "gondola_principal" junto a "tamanio_gondola".
        *Pre:	Recibe la cantidad de productos a cargar, tiene que ser mayor a 0  
        		Recibe un vector de productos que contiene los productos a cargar en la góndola, este vector debe ser valido
     			y debe respetar la cantidad de productos a cargar
        *Post: El vector dinámico mencionado queda actualizado con los productos anteriores y nuevos, "tamanio_gondola" actualizado a la nueva cantidad de productos.
        */
        void cargar_productos_gondola(int cantidad_a_cargar, Producto productos_a_cargar[]);

        /*
        *Descripción: Busca el nombre pedido (producto_buscado) en el vector dinámico "productos_gondola".
        *Pre: Recibe el nombre del producto buscado junto con una variable "posicion" pasada por referencia en caso de que el producto se encuentre. Además,
        le llega un booleano pasado por referencia que indica si el producto ha sido encontrado.
        *Post: En caso de que el producto se encuentre, se cambia el valor de encontrado a true, y se devuelve por referencia la posición del producto encontrado.
        */
        void buscar_producto_por_nombre(string producto_buscado, int &posicion, bool &encontrado);

        /*
        *Descripción: Busca el codigo pedido (producto_buscado) en el vector dinamico "productos_gondola".
        *Pre: Recibe el código del producto buscado (producto_buscado) junto con una variable "posicion" pasada por referencia en caso de que el producto se encuentre.
        Además, le llega un booleano pasado por referencia que indica si el producto ha sido encontrado.
        *Post: En caso de que el producto se encuentre, se cambia el valor de encontrado a true, y se devuelve por referencia la posición del producto encontrado.
        */
        void buscar_producto_por_codigo(int producto_buscado, int &posicion, bool &encontrado);

        /*
        *Descripción: Cambia el precio del producto en la "posicion" del vector dinámico "productos_gondola".
        *Pre: El nuevo precio tiene que ser de tipo float.
        *Post: Queda actualizado el precio del producto en la "posicion" del vector dinámico mencionado.
        */
        void cambiar_precio_producto(int posicion);

        /*Descripción: Este método se encarga de quitar el producto correspondiente del vector dinámico de productos "productos_gondola".
        *Pre: Se toma como precondición que el usuario no puede remover todos los productos. Además, llega la posición en la cual se encuentra
        el producto a eliminar.
        *Post: Quita el producto correspondiente del vector dinámico de productos de un objeto de clase Góndola.
        */
        void quitar_producto(int posicion);

        /*Descripción: Este método se encarga de verificar si hay stock del producto cuya posición en el vector dinámico "productos_gondola"
        es pasado como parámetro.
        *Pre: La posición que se pasa como parámetro pertenece a un producto válido.
        *Post: Se devuelve true en caso de que haya stock del producto o false en caso contrario.
        */
        bool hay_stock(int pos);

        /*
        *Descripción: Muestra por consola los productos actuales del vector dinámico "productos_gondola".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinámico "productos_gondola".
        */
        void mostrar_productos_gondola();

        /*
        *Descripción: Muestra por pantalla la cantidad de productos en oferta que tiene la góndola.
        *Pre: -.
        *Post: Muestra la cantidad de productos en oferta.
        */
        void contar_productos_oferta();

        /*Descripción: 	Es el método destructor de objetos de clase Gondola. Se encarga de liberar el espacio destinado 
        *				para alocar el vector de Productos en memoria dinámica.
        *Precondiciones: -.
        *Postcondiciones: Libera el espacio utilizado para alocar el vector de productos en memoria dinámica.
        */
        ~Gondola();

};

#endif /*_GONDOLA_H_*/