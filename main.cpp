#include <iostream>
#include "litaaaa.h"
#include "menu.hpp"

using namespace std;

int main(){
    system("cls");
    bool continuar = true;
    List_Circular veterinaria;

    cout<<"Bienvenido BTC pets."<<endl;
    do
    {
        switch (opciones())
        {
        case 1:
            veterinaria.Insertar_Nodo();
            break;
        
        case 2:
          
            veterinaria.Mostrar_Registro();

            break;

        case 3:
            veterinaria.Mostrar_ID();
            veterinaria.Borrar();
            cout<<"registro borrado "<<endl;
            
            
            break;
        
        case 4:
            continuar = false;
            break;
        
        default:
            break;
        }
    } while (continuar);
    
};