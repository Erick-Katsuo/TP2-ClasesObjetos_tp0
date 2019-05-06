#include "Menu.h"

#include <iostream>

using namespace std;

Menu::Menu(){
    cout<<"Constructor Menu"<<endl;
    opcion_usuario = MENU_ACTIVO;
    posicion_producto_buscado = POSICION_INVALIDA;
}

void Menu::iniciar_interfaz(){
    cargar_gondola();
    while(opcion_usuario != OPCION_SALIR){
        mostrar_menu();
        recibir_opcion();
        ejecutar_opcion();
    }
}

void Menu::cargar_gondola(){
    int cantidad_productos = CANTIDAD_INICIAL_PRODUCTOS;
    ifstream archivo_productos("productos.txt");
    leer_cantidad_productos(cantidad_productos, archivo_productos);
    cout << "Cantidad de productos en Gondola: " << cantidad_productos << endl;
    gondola_principal.asignar_tamanio_gondola(cantidad_productos);
    gondola_principal.preparar_gondola();
    leer_productos(archivo_productos);
    archivo_productos.close();
}

void Menu::leer_cantidad_productos(int &cantidad_productos, ifstream &archivo_productos){
	archivo_productos >> cantidad_productos;
}

void Menu::leer_productos(ifstream &archivo_productos){
    Producto obtenido;
    cout << "Acomodando productos en gondola..." << endl;
    string nombre;
    int codigo;
    float precio;
    bool oferta;
    int stock;
    int i = 0;
    while(archivo_productos >> codigo >> nombre >> precio >> oferta >> stock){
        gondola_principal.obtener_producto(i)->asignar_codigo(codigo);
        gondola_principal.obtener_producto(i)->asignar_nombre(nombre);
        gondola_principal.obtener_producto(i)->asignar_precio(precio);
        gondola_principal.obtener_producto(i)->asignar_oferta(oferta);
        gondola_principal.obtener_producto(i)->asignar_stock(stock);
        i++;
    }
    cout << "Productos cargados correctamente." << endl;
}


void Menu::mostrar_menu(){
    opcion_usuario = MENU_ACTIVO;
    cout << endl << endl;
    cout << "\t\t\t ---Menu de acciones en gondola---"<<endl;
    cout << "\t Primero seleccionar una opcion del Menu, luego una del SubMenu" << endl;
    cout << "\t\t\t      [Menu(*) - SubMenu(-)]" << endl << endl;
    cout << " * Cargar nuevo producto        [a]" << endl;
    cout << " * Buscar producto por nombre   [b]" << endl;
    cout << "     - Modificar precio            -d-" << endl;
    cout << "     - Quitar un producto          -e-" << endl;
    cout << "     - Agregar al chango           -g-" << endl;
    cout << " * Buscar producto por codigo   [c]" << endl;
    cout << "     - Modificar precio            -d-" << endl;
    cout << "     - Quitar un producto          -e-" << endl;
    cout << "     - Agregar al chango           -g-" << endl;
    cout << " * Contar productos en oferta   [f]" << endl;
    cout << " * Mostrar productos en gondola [h]" << endl;
    cout << " * Mostrar productos en chango  [i]" << endl<<endl;
    cout << " * Salir                        [x]" << endl<<endl;
    cout << "Por favor ingrese su opcion:" << endl<<endl;
}

void Menu::mostrar_productos_de_la_gondola(){
    gondola_principal.mostrar_productos_gondola();
}

void Menu::mostrar_productos_del_chango(){
    chango_principal.mostrar_productos_chango();
}

void Menu::recibir_opcion(){
    cin >> opcion_usuario;
    cout<<endl<<endl;
}

void Menu::ejecutar_opcion(){
    system("cls");
    switch(opcion_usuario){
        case OPCION_CARGAR_PRODUCTO:
            cargar_nuevos_productos_gondola();
            break;
        case OPCION_BUSCAR_PRODUCTO_NOMBRE:
            posicion_producto_buscado = buscar_producto_nombre();
            ejecutar_opcion_secundaria();
            break;
        case OPCION_BUSCAR_PRODUCTO_CODIGO:
            posicion_producto_buscado = buscar_producto_codigo();
            ejecutar_opcion_secundaria();
            break;
        case OPCION_CANTIDAD_OFERTA:
            mostrar_productos_oferta();
            break;
        case OPCION_MOSTRAR_PRODUCTOS_GONDOLA:
            mostrar_productos_de_la_gondola();
            break;
        case OPCION_MOSTRAR_PRODUCTOS_CHANGO:
            mostrar_productos_del_chango();
            break;
        case OPCION_SALIR:
            cout << "Saliendo de la tienda" << endl;
            break;
        default:
            cout << "Ingreso invalido. Recuerde que debe ingresar una de las opciones del Menu." <<endl<<endl;
    }
}

void Menu::mostrar_submenu(){
    cout<<" * Modificar precio             [d]"<<endl;
    cout<<" * Quitar producto              [e]"<<endl;
    cout<<" * Agregar producto al chango   [g]"<<endl;
    cout<<" * Volver al menu               [cualquier letra]"<<endl;
    cout<<" * Salir                        [x]" << endl<<endl;
    cout << "Por favor ingrese su opcion:" << endl<<endl;
    recibir_opcion();
}

void Menu::ejecutar_opcion_secundaria(){
    if(posicion_producto_buscado != POSICION_INVALIDA){
        mostrar_submenu();
        switch(opcion_usuario){
            case OPCION_MODIFICAR_PRECIO:
                gondola_principal.cambiar_precio_producto(posicion_producto_buscado);
                break;
            case OPCION_QUITAR_PRODUCTO:
                gondola_principal.quitar_producto(posicion_producto_buscado);
                break;
            case OPCION_CARGAR_CHANGO:
                comprobar_stock();
        }
    }
}

void Menu::comprobar_stock(){
    if(gondola_principal.hay_stock(posicion_producto_buscado)){
        chango_principal.agregar_producto(gondola_principal.obtener_producto(posicion_producto_buscado));
        gondola_principal.restar_stock(posicion_producto_buscado);
    }else{
        cout<<endl<<"Actualmente, no contamos con stock de este producto. Intentelo la proxima! "<<endl<<endl;
    }
}


void Menu::mostrar_productos_oferta(){
    gondola_principal.contar_productos_oferta();
}


void Menu::cargar_nuevos_productos_gondola(){
    Producto productos_a_cargar[MAX_CARGAR_PRODUCTOS];
    int cantidad_a_cargar = POSICION_INVALIDA;
    cout << "Ingrese cantidad de productos a cargar - maximo diez (10)" <<endl<<endl;
    cin >> cantidad_a_cargar;
    if(cantidad_a_cargar<=0 || cantidad_a_cargar>MAX_CARGAR_PRODUCTOS ){
        cout <<endl<<"Recuerde que el máximo de productos a ingresar es de 10 y el mínimo 1\n Por favor, intente nuevamente." << endl;
        return cargar_nuevos_productos_gondola();
    }
    pedir_datos_producto(cantidad_a_cargar, productos_a_cargar);
    gondola_principal.cargar_productos_gondola(cantidad_a_cargar,productos_a_cargar);
}

void Menu::pedir_datos_producto(int cantidad_a_cargar, Producto productos_a_cargar[]){
	string nombre_aux;
    int codigo_aux;
    float precio_aux;
    bool oferta_aux;
    int stock_aux;
    for(int i = 0; i < cantidad_a_cargar; i++){
        cout <<endl<< "\t\tProducto a cargar numero: " << i+1 << endl << endl;
        cout << "\t\t*** Codigo y Nombre de los productos son UNICOS***" << endl;
        cout << "Ingrese Codigo: ";
        cin >> codigo_aux;
        productos_a_cargar[i].asignar_codigo(codigo_aux);
        cout<<"\nIngrese Nombre: ";
        cin >> nombre_aux;
        productos_a_cargar[i].asignar_nombre(nombre_aux);
        cout<<"\nIngrese Precio: ";
        cin >> precio_aux;
        productos_a_cargar[i].asignar_precio(precio_aux);
        cout << "\nSin oferta[0] - En oferta[1]";
        cout << "\nIngrese estado de Oferta: ";
        cin >> oferta_aux;
        productos_a_cargar[i].asignar_oferta(oferta_aux);
        cout << "\nIngrese stock: ";
        cin >> stock_aux;
        productos_a_cargar[i].asignar_stock(stock_aux);
    }
}


int Menu::buscar_producto_nombre(){
    bool producto_encontrado=false;
    int posicion = POSICION_INVALIDA;
    string nombre_producto_buscado = BUSQUEDA_NULA;
    cout << "Ingrese el nombre del producto a buscar: "<<endl<<endl;
    cin >> nombre_producto_buscado;
    gondola_principal.buscar_producto_por_nombre(nombre_producto_buscado, posicion, producto_encontrado);
    if(!producto_encontrado){
        cout<<"\t\t***Producto no encontrado***"<<endl;
        return posicion;
    }else{
        return posicion;
	}
}

int Menu::buscar_producto_codigo(){
    bool producto_encontrado=false;
    int posicion = POSICION_INVALIDA;
    int codigo_producto_buscado= POSICION_INVALIDA;
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigo_producto_buscado;
    gondola_principal.buscar_producto_por_codigo(codigo_producto_buscado, posicion, producto_encontrado);
    if(!producto_encontrado){
        cout<<"\t\t***Producto no encontrado***"<<endl;
        return posicion;
    }else{
        return posicion;
    }
}
