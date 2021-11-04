#include <iostream>

using namespace std;

int opciones(){
    int opcion;

    cout<<"Eliga lo que desea hacer: "<<endl;
    cout<<"1. Crear nuevo registro."<<endl;
    cout<<"2. Mostrar registros."<<endl;
    cout<<"3. Borrar un registro."<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"Opcion: "; cin>>opcion;
    return opcion;

}