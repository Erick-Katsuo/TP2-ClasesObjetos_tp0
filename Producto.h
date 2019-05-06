#ifndef _PRODUCTO_H_
#define _PRODUCTO_H_

#include <iostream>

using namespace std;

const string NOMBRE_POR_DEFECTO = " ";
const int CODIGO_POR_DEFECTO = 0;
const float PRECIO_POR_DEFECTO = 0;
const bool OFERTA_POR_DEFECTO = 0;
const int STOCK_POR_DEFECTO = 0;

class Producto{
    
    private:

        string nombre;
        int codigo;
        float precio;
        bool oferta;
        int stock;
    
    public:

        //Constructor
        //Descripcion: Inicializa los atributos de la clase y muestra por consola que se ingreso al constructor.
        //Pre:-.
        //Post: Los atributos quedan inicializados.
        Producto();
	
        // SETTERS

        /*
        *Descripcion: Este método se encarga de asignarle el valor de "nuevo_nombre" al atributo nombre de un objeto
        de clase Producto.
        *Pre: El parámetro que recibe el método es válido y se encuentra dentro del dominio del atributo "nombre".
        *Post: El atributo "nombre" de un objeto de clase Producto recibe el valor de "nuevo_nombre".
        */
		void asignar_nombre(string nuevo_nombre);
		
        /*
        *Descripcion: Este método se encarga de asignarle el valor de "nuevo_codigo" al atributo codigo de un objeto
        de clase Producto.
        *Pre: El parámetro que recibe el método es válido y se encuentra dentro del dominio del atributo "codigo".
        *Post: El atributo "codigo" de un objeto de clase Producto recibe el valor de "nuevo_codigo".
        */
        void asignar_codigo(int nuevo_codigo);
		
        /*
        *Descripcion: Este método se encarga de asignarle el valor de "nuevo_precio" al atributo precio de un objeto
        de clase Producto.
        *Pre: El parámetro que recibe el método es válido y se encuentra dentro del dominio del atributo "precio".
        *Post: El atributo "precio" de un objeto de clase Producto recibe el valor de "nuevo_precio".
        */
        void asignar_precio(float nuevo_precio);
		
        /*
        *Descripcion: Este método se encarga de asignarle el valor de "actualizar_oferta" al atributo oferta de un objeto
        de clase Producto.
        *Pre: El parámetro que recibe el método es válido y se encuentra dentro del dominio del atributo "oferta".
        *Post: El atributo "oferta" de un objeto de clase Producto recibe el valor de "actualizar_oferta".
        */
        void asignar_oferta(bool actualizar_oferta);

        /*
        *Descripción: Este método se encarga de asignarle el valor de "nuevo_stock" al atributo stock de un objeto
        de clase Producto.
        *Pre: El parámetro que recibe el método es válido y se encuentra dentro del dominio del atributo "stock".
        *Post: El atributo "stock" de un objeto de clase Producto recibe el valor de "nuevo_stock".
        */
        void asignar_stock(int nuevo_stock);
		
		// GETTERS

        /*
        *Descripcion: Este método se encarga de devolver el valor del atributo "nombre" de un objeto de  clase Producto.
        *Pre: -.
        *Post: Devuelve el valor del atributo "nombre" de un objeto de clase Producto.
        */
		string obtener_nombre();
    
    	/*
        *Descripcion: Este método se encarga de devolver el valor del atributo "codigo" de un objeto de  clase Producto.
        *Pre: -.
        *Post: Devuelve el valor del atributo "codigo" de un objeto de clase Producto.
        */	
        int obtener_codigo();
		
        /*
        *Descripcion: Este método se encarga de devolver el valor del atributo "precio" de un objeto de clase Producto.
        *Pre: -.
        *Post: Devuelve el valor del atributo "precio" de un objeto de clase Producto.
        */
        float obtener_precio();
		
        /*
        *Descripcion: Este método se encarga de devolver el valor del atributo "oferta" de un objeto de  clase Producto.
        *Pre: -.
        *Post: Devuelve el valor del atributo "oferta" de un objeto de clase Producto.
        */
        bool obtener_oferta();

        /*
        *Descripcion: Este método se encarga de devolver el valor del atributo "stock" de un objeto de clase Producto.
        *Pre: -.
        *Post: Devuelve el valor del atributo "stock" de un objeto de clase Producto.
        */	
        int obtener_stock();
};

#endif /*_PRODUCTO_H_*/
