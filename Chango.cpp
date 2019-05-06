#include <iostream>
#include "Chango.h"

using namespace std;

Chango::Chango(){
	cout << "Constructor de Chango" << endl;
	tamanio_chango = TAMANIO_INICIAL_CHANGO;
	monto_a_abonar = MONTO_INICIAL_A_ABONAR;
	ahorro_total = AHORRO_INICIAL;
	productos_chango = NULL;
	chango_auxiliar = NULL;
}

void Chango::agregar_producto(Producto* producto_a_agregar){
	tamanio_chango ++;
	if(tamanio_chango == PRIMER_TAMANIO_CHANGO){
		productos_chango = new Producto[tamanio_chango];
		agregar_nuevo_producto(producto_a_agregar);
	}
	else{
		chango_auxiliar = new Producto[tamanio_chango];
		preparar_chango(producto_a_agregar);
	}
}

void Chango::agregar_nuevo_producto(Producto* producto_a_agregar){
	productos_chango[tamanio_chango-1].asignar_nombre(producto_a_agregar->obtener_nombre());
	productos_chango[tamanio_chango-1].asignar_codigo(producto_a_agregar->obtener_codigo());
	productos_chango[tamanio_chango-1].asignar_precio(producto_a_agregar->obtener_precio());
	productos_chango[tamanio_chango-1].asignar_oferta(producto_a_agregar->obtener_oferta());
	productos_chango[tamanio_chango-1].asignar_stock(UN_PRODUCTO);
	system("cls");
	cout<<endl<<"Su producto ha sido agregado correctamente al Chango"<<endl<<endl;
	actualizar_monto_y_ahorro(producto_a_agregar);
	informar_monto_y_ahorro();
}

void Chango::preparar_chango(Producto* producto_a_agregar){
	int posicion_producto_existente=0;
	desplazar_chango_viejo();
	delete[] productos_chango;
	productos_chango = chango_auxiliar;
	if(producto_ya_existente(producto_a_agregar, posicion_producto_existente)){
		tamanio_chango --;
		agregar_producto_existente(producto_a_agregar, posicion_producto_existente);
	}
	else{
		agregar_nuevo_producto(producto_a_agregar);
	}
	chango_auxiliar = NULL;
}

void Chango::agregar_producto_existente(Producto* producto_a_agregar, int pos){
    system("cls");
    productos_chango[pos].asignar_stock((productos_chango[pos].obtener_stock())+1);
    cout<<endl<<"Su producto ha sido agregado correctamente al Chango"<<endl;
    actualizar_monto_y_ahorro(producto_a_agregar);
    informar_monto_y_ahorro();
}

bool Chango::producto_ya_existente(Producto* producto_a_verificar, int &pos){
	bool resultado = false;
	for(int i=0;i<tamanio_chango;i++){
		if((productos_chango[i].obtener_nombre())==(producto_a_verificar->obtener_nombre())){
			resultado=true;
			pos=i;
		}
	}
	return resultado;
}

void Chango::desplazar_chango_viejo(){
	for(int i=0;i<(tamanio_chango-1);i++){
		chango_auxiliar[i].asignar_nombre(productos_chango[i].obtener_nombre());
		chango_auxiliar[i].asignar_codigo(productos_chango[i].obtener_codigo());
		chango_auxiliar[i].asignar_precio(productos_chango[i].obtener_precio());
		chango_auxiliar[i].asignar_oferta(productos_chango[i].obtener_oferta());
		chango_auxiliar[i].asignar_stock(productos_chango[i].obtener_stock());
	}
}

void Chango::mostrar_productos_chango(){
	cout << "Mostrando productos de Chango [" << tamanio_chango << "]" << endl << endl;
    if(tamanio_chango>TAMANIO_INICIAL_CHANGO){
    	for(int i = 0; i < tamanio_chango; i++){
       	 	mostrar_producto_particular_chango(i);
    	}
    	informar_monto_y_ahorro();
    }
    else{
    	cout << endl << "Actualmente no tiene ningun producto en su Chango." << endl;
    }
}

void Chango::mostrar_producto_particular_chango(int posicion){
    cout << "Codigo: " << productos_chango[posicion].obtener_codigo() << endl;
    cout << "Producto: " << productos_chango[posicion].obtener_nombre() << endl;
    cout << "Precio: $ " << productos_chango[posicion].obtener_precio() << endl;
    if(productos_chango[posicion].obtener_oferta()){
        cout << "Oferta: Esta en oferta! :D" << endl;
    }else{
        cout << "Oferta: No esta en oferta :(" << endl;
    }
    cout << "Cantidad de unidades que lleva: " << productos_chango[posicion].obtener_stock() << endl <<endl;
}

void Chango::actualizar_monto_y_ahorro(Producto* producto_a_agregar){
	monto_a_abonar += producto_a_agregar->obtener_precio();
	if(producto_a_agregar->obtener_oferta()){
		ahorro_total += ((producto_a_agregar->obtener_precio()) * TASA_DE_DESCUENTO);
	}
}

void Chango::informar_monto_y_ahorro(){
	cout << endl << "Precio: $" << monto_a_abonar << endl;
	cout <<"Ahorro: $" << ahorro_total << endl;
	cout <<"Costo final: $" << monto_a_abonar - ahorro_total << endl;
}

Chango::~Chango(){
	cout << "Destructor Chango" << endl;
    if(productos_chango!=NULL){
    	delete[] productos_chango;
    }
}
