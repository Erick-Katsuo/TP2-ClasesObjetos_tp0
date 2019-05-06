#include "Gondola.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Gondola::Gondola(){
    cout << "Constructor Gondola" << endl;
    tamanio_gondola = CANTIDAD_INICIAL_PRODUCTOS;
    cantidad_productos_oferta = 0;
}

void Gondola::asignar_tamanio_gondola(int nuevo_tamanio_gondola){
    tamanio_gondola = nuevo_tamanio_gondola;
}

void Gondola::preparar_gondola(){
    productos_gondola = new Producto[tamanio_gondola];
}

Producto* Gondola::obtener_producto(int posicion){
    return (&productos_gondola[posicion]);
}

void Gondola::mostrar_productos_gondola(){
    cout << "Mostrando productos de gondola [" << tamanio_gondola << "]" << endl << endl;
    for(int i = 0; i < tamanio_gondola; i++){
        mostrar_producto_particular_gondola(i);
    }
}

void Gondola::mostrar_producto_particular_gondola(int posicion){
    cout << "Codigo: " << productos_gondola[posicion].obtener_codigo() << endl;
    cout << "Producto: " << productos_gondola[posicion].obtener_nombre() << endl;
    cout << "Precio: $ " << productos_gondola[posicion].obtener_precio() << endl;
    if(productos_gondola[posicion].obtener_oferta()){
        cout << "Oferta: Esta en oferta! :D" << endl;
    }else{
        cout << "Oferta: No esta en oferta :(" << endl;
    }
    cout << "Stock: " << productos_gondola[posicion].obtener_stock() << endl << endl;
}


void Gondola::cargar_productos_gondola(int cantidad_a_cargar, Producto productos_a_cargar[]){
	int tamanio_nuevo = cantidad_a_cargar + tamanio_gondola;
	crear_espacio_gondola(tamanio_nuevo);
	desplazar_productos_actuales();
	desplazar_productos_nuevos(productos_a_cargar, tamanio_nuevo);
	cout << endl<<endl<<"Limpiando gondola..."<<endl;
    delete[] productos_gondola;
    cout << "Nuevos productos acomodados correctamente."<<endl;
    productos_gondola = gondola_auxiliar;
    tamanio_gondola = tamanio_nuevo;
    gondola_auxiliar = NULL;
}

void Gondola::crear_espacio_gondola(int tamanio_nuevo){
    system("cls");
    cout << "Creando espacio en la nueva gondola" << endl;
    gondola_auxiliar = new Producto[tamanio_nuevo];
}

void Gondola::desplazar_productos_actuales(){
    for(int i = 0; i < tamanio_gondola ; i++){
        gondola_auxiliar[i] = productos_gondola[i];
    }
}

void Gondola::desplazar_productos_nuevos(Producto productos_a_cargar[], int tamanio_nuevo){
    int contador_productos_a_agregar=0;
    for(int i = tamanio_gondola; i < tamanio_nuevo; i++){
        gondola_auxiliar[i]=productos_a_cargar[contador_productos_a_agregar];
    	contador_productos_a_agregar++;
    }
}

void Gondola::buscar_producto_por_nombre(string producto_buscado, int &posicion, bool &encontrado){
    cout<<endl<<"Buscando producto: "<<producto_buscado<<" ..."<<endl<<endl;
    int contador = 0;
    while(!encontrado && (contador<tamanio_gondola)){
        if(productos_gondola[contador].obtener_nombre() == producto_buscado){
            encontrado = true;
            posicion=contador;
            system("cls");
            cout << "Producto encontrado:"<<endl<<endl;
            mostrar_producto_particular_gondola(posicion);
            cout<<"Que desea hacer con este producto?" << endl << endl;
        }else{
            contador++;
        }
    }
}

void Gondola::buscar_producto_por_codigo(int producto_buscado, int &posicion, bool &encontrado){
    cout << endl<< "Buscando codigo: "<<producto_buscado<< " ..." << endl << endl;
    int contador = 0;
    while(!encontrado && (contador<tamanio_gondola)){
        if(productos_gondola[contador].obtener_codigo() == producto_buscado){
            encontrado = true;
            posicion = contador;
            system("cls");
            cout << "Producto encontrado:"<<endl<<endl;
            mostrar_producto_particular_gondola(posicion);
            cout<<"Que desea hacer con este producto?" << endl << endl;
        }else{
            contador++;
        }
    }
}

void Gondola::cambiar_precio_producto(int posicion){
    float nuevo_precio = PRECIO_INVALIDO;
    while(nuevo_precio < 0){
    	cout << "Ingrese el nuevo precio para " << productos_gondola[posicion].obtener_nombre() << endl<<endl;
    	cin >> nuevo_precio;
    	if(nuevo_precio < 0){
    		cout << endl << "Recuerde que el nuevo precio debe ser mayor que 0. Intente nuevamente." << endl << endl;
    	}
    }
    productos_gondola[posicion].asignar_precio(nuevo_precio);
    system("cls");
    cout << "\t\t***Precio actualizado***" << endl<<endl;
    mostrar_producto_particular_gondola(posicion);
}

void Gondola::restar_stock(int pos){
	productos_gondola[pos].asignar_stock(((productos_gondola[pos].obtener_stock())-1));
}

bool Gondola::hay_stock(int pos){
	bool resultado = true;
	if((productos_gondola[pos].obtener_stock())<=0){
		resultado = false;
	}

	return resultado;
}

void Gondola::quitar_producto(int posicion){
    system("cls");
    cout << "\t\t *** Producto: " << productos_gondola[posicion].obtener_nombre() << " removido ***" << endl << endl;
    for(int i = posicion; i < tamanio_gondola-1; i++){
        productos_gondola[i] = productos_gondola[i+1];
    }
    tamanio_gondola--;
}

void Gondola::contar_productos_oferta(){
   cantidad_productos_oferta = 0;
   cout << "Contando productos en oferta ..." << endl;
   int contador;
   for(contador = 0; contador < tamanio_gondola; contador ++){
    	if(productos_gondola[contador].obtener_oferta()){
        cantidad_productos_oferta ++;
    	}
   }
   cout << endl << "La cantidad de productos en oferta es igual a " << cantidad_productos_oferta << endl;
}

Gondola::~Gondola(){
    cout << "Destructor Gondola" << endl;
    delete[] productos_gondola;
}

