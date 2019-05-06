#ifndef _CHANGO_H_
#define _CHANGO_H_
#include <cstdlib>
#include "Producto.h"
#include <iostream>

using namespace std;

int const TAMANIO_INICIAL_CHANGO = 0;
float const MONTO_INICIAL_A_ABONAR = 0;
float const AHORRO_INICIAL =0;
int const PRIMER_TAMANIO_CHANGO = 1;
float const TASA_DE_DESCUENTO = 0.10;
int const UN_PRODUCTO = 1;

class Chango{

	private:

		int tamanio_chango;
		float monto_a_abonar;
		float ahorro_total;

		Producto* productos_chango;
		Producto* chango_auxiliar;

		/*
        *Descripcion: Muestra por consola el producto de la posicion pasada por parametro.
        *Pre: -.
        *Post: Muestra por consola un producto particular del Chango.
        */
        void mostrar_producto_particular_chango(int posicion);

        /*
        *Descripcion: Este método se encarga de agregar un nuevo producto al vector dinámico de productos:
        "productos_chango" presente en un objeto de clase Chango.
        *Pre: Recibe como parámetro el producto a agregar en el vector dinámico.
        *Post: Agrega correctamente el producto a la última posición del vector dinámico de productos:
        "productos_chango" presente en un objeto de clase Chango.
        */
        void agregar_nuevo_producto(Producto* producto_a_agregar);

        /*
        *Descripcion: En caso de que el Chango tenga más de un producto, se realizan todas las operaciones
        correspondientes en pos de que se agregue un producto al final del vector dinámico de productos:
        "productos_chango" presente en un objeto de clase Chango.
        *Pre: Recibe como parámetro el producto a agregar en el vector dinámico.
        *Post: Se realizan todas las operaciones correspondientes en pos de poder agregar un nuevo producto al Chango.
        */
        void preparar_chango(Producto* producto_a_agregar);

        /*
        *Descripcion: Se copian todos los productos presentes en el vector dinámico "productos_chango" en otro vector
        dinámico "chango_auxiliar", utilizado para poder redimensionar el primero mencionado.
        *Pre: Todos los productos del Chango son válidos y el tamaño del Chango es mayor a 1.
        *Post: Todos los productos del vector dinámico "productos_chango" son copiados en otro vector dinámico "chango_auxiliar".
        */
        void desplazar_chango_viejo();

        /*
        *Descripcion: Este método se encarga de actualizar los valores de los atributos "monto_a_abonar" y "ahorro_total"
        presentes en un objeto de clase Chango, en el momento que un producto es agregado al Chango.
        *Pre: Se pasa como parámetro del método un producto que será agregado al Chango.
        *Post: "monto_a_abonar" y "ahorro_total" son actualizados en el momento que un producto es agregado al Chango.
        */
        void actualizar_monto_y_ahorro(Producto* producto_a_agregar);

        /*
        *Descripcion: Se informa al usuario cual es el monto total a abonar junto con el ahorro total que ha obtenido
        con su compra.
        *Pre: -.
        *Post: Se muestra por consola el monto a abonar y el ahorro total obtenidos en una compra.
        */
        void informar_monto_y_ahorro();

        /*
        *Descripción: Este método se encarga de verificar si el producto ya existe en el Chango, devolviendo por referencia
        la posición en el Chango de este producto en caso de que esto suceda.
        *Pre: Se pasa como parámetro el producto que se quiere verificar si existe en el Chango y la posición a modificar por referencia,
        en caso de que el producto ya exista en el Chango.
        *Post: En caso de que el producto ya se encuentre en el Chango, devuelve True, caso contrario False. Además, se devuelve
        por referencia la posición en el Chango del producto ya existente.
        */
        bool producto_ya_existente(Producto* producto_a_verificar, int &pos);

       	/*
        *Descripción: Agrega una unidad a la cantidad de unidades que lleva el usuario de un producto ya existente en el Chango.
        *Pre: Recibe el producto cuya cantidad hay que aumentar en uno en el Chango y la posición en la cual se encuentra en éste.
        *Post: Aumenta en uno la cantidad de unidades que lleva el usuario de un producto determinado.
        */
        void agregar_producto_existente(Producto* producto_a_agregar, int pos);

	public:

		/*Constructor
		*Descripcion: Inicializa los atributos "tamanio_gondola", "monto_a_abonar" y "ahorro_total".
		Además, muestra por consola que se ingresó al constructor.
        *Pre:-.
        *Post: Los atributos mencionados quedan correctamente inicializados.
        */
        Chango();

     	/*
        *Descripcion: Muestra por consola los productos actuales del vector dinamico "productos_chango".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinamico "productos_chango".
        */
        void mostrar_productos_chango();

        /*
        *Descripción: Este método se encargará de redimensionar el vector dinámico "productos_chango" presente
        en un objeto de clase Chango.
        *Pre: Recibe un producto válido de la Góndola.
        *Post: Redimensiona el vector dinámico "productos_chango" presente en un objeto de clase Chango.
        */
        void agregar_producto(Producto* producto_a_agregar);

        /*Descripción: 	Es el método destructor de objetos de clase Chango. Se encarga de liberar el espacio destinado
        *				para alocar el vector de Productos en memoria dinámica.
        *Precondiciones: -.
        *Postcondiciones: Libera el espacio utilizado para alocar el vector de productos en memoria dinámica.
        */
        ~Chango();
};

#endif /*_CHANGO_H_*/
