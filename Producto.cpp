#include "Producto.h"
#include <iostream>

using namespace std;

Producto::Producto(){
    nombre = NOMBRE_POR_DEFECTO;
    codigo = CODIGO_POR_DEFECTO;
    precio = PRECIO_POR_DEFECTO;
    oferta = OFERTA_POR_DEFECTO;
    stock = STOCK_POR_DEFECTO;
}

void Producto::asignar_codigo(int nuevo_codigo){
    codigo = nuevo_codigo;
}

int Producto::obtener_codigo(){
    return codigo;
}

void Producto::asignar_nombre(string nuevo_nombre){
    nombre = nuevo_nombre;
}

string Producto::obtener_nombre(){
    return nombre;
}

void Producto::asignar_precio(float nuevo_precio ){
    precio = nuevo_precio;
}

float Producto::obtener_precio(){
    return precio;
}

void Producto::asignar_oferta(bool actualizar_oferta){
    oferta = actualizar_oferta;
}

bool Producto::obtener_oferta(){
    return oferta;
}

void Producto::asignar_stock(int nuevo_stock){
    stock = nuevo_stock;
}

int Producto::obtener_stock(){
    return stock;
}

