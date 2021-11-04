#include <iostream>

using namespace std;

struct Nodo{
    int id;
    string encargado;
    string raza;
    float peso;
    int edad;
    Nodo * sig;
}registro;


class List_Circular
{
private:
    Nodo* inicio;
    Nodo* fin;
public:
    List_Circular();
    void Insertar_Inicio(int, string, string, float, int);
    void Insertar_Nodo();
    void Mostrar_Registro();
    void Mostrar_ID();
    int Total_nodos();
    void Borrar();
};

List_Circular::List_Circular(){
    inicio = NULL;
    fin = NULL;
}

void List_Circular::Insertar_Nodo(){

    cout<<"ID : "; cin>>registro.id; 
    cin.ignore();

    cout<<"Nombre del encargado: "; getline(cin, registro.encargado);
     
    cout<<"Raza de la mascota: "; getline(cin, registro.raza);

    cout<<"Peso: "; cout<<"kg: "; cin>>registro.peso;
    cin.ignore();

    cout<<"Edad: "; cin>>registro.edad;
    cin.ignore();

    cout<<"Inscrito correctamente"<<endl;

    Insertar_Inicio(registro.id, registro.encargado, registro.raza, registro.peso, registro.edad);
}

void List_Circular::Insertar_Inicio(int id, string encargado, string raza, float peso, int edad){
    Nodo * nuevo = new Nodo();
    nuevo->id = id;
    nuevo->encargado = encargado;
    nuevo->raza = raza;
    nuevo->peso = peso;
    nuevo->edad = edad;
    if (inicio == NULL){
        inicio = nuevo;
        fin = nuevo;
    }else{
        fin->sig = nuevo;
        nuevo->sig = inicio;
        fin = nuevo;
    }
    
};

int List_Circular::Total_nodos(){
    if (inicio == NULL){
        return 0;
    }else{
        Nodo * saltarin = inicio;
        int i = 0;

        do{
            saltarin = saltarin->sig;
            i++;
            cout<<i<<endl;
        } while (saltarin != inicio);
        return i;  
    }
}

void List_Circular::Mostrar_Registro(){
    if (inicio == NULL){
        cout<<"lista vacia"<<endl;
    }else{

        Nodo * saltarin = inicio;
        int i = 1;

        do{
            cout<<"Registro: "<<i<<endl;
            cout<<"ID: "<<saltarin->id<<endl;
            cout<<"Nombre de encargado: "<<saltarin->encargado<<endl;
            cout<<"Raza de mascota: "<<saltarin->raza<<endl;
            cout<<"Peso de mascota: "<<saltarin->peso<<" kg"<<endl;
            cout<<"Edad de mascota: "<<saltarin->edad<<endl;
            cout<<endl;
            i++;
            saltarin = saltarin->sig;
            
        } while (saltarin != inicio);
        
    }
    
}

void List_Circular::Mostrar_ID(){
    if (inicio == NULL){
        cout<<"lista vacia"<<endl;
    }else{
        Nodo * saltarin = inicio;
        int i = 1;
        
        do{
            cout<<"Registro "<<i<<" Nombre Encargado: "<<saltarin->encargado<<endl;
            i++;
            saltarin = saltarin->sig;
        } while (saltarin != inicio);
        
    }
    
}


void List_Circular::Borrar(){
    Nodo * saltarin;
    Nodo * anterior = inicio;
    int pos;

    cout<<"Ingrese el numero del registro que desea eliminar: "<<endl;
    cin>>pos;

    if (inicio == NULL){
        cout<<"Lista Vacia"<<endl;
    }
    else if (pos == 0){
        cout<< "No existe la posicion 0" <<endl;
    }
    else if (pos> Total_nodos())
    {
        cout<< "La Posicion "<<pos<< " excede el Tamano"<<endl;
    }
    else if (pos == 1){
        Nodo* Borrar = inicio;
        inicio = inicio ->sig;
        fin->sig = inicio;
        delete Borrar;
    }
    else if (pos == Total_nodos()){
        Nodo * borrarUltimo;
        saltarin = inicio;
        int i = 0;
        do
        {
            i++;
            if (i == pos - 1){
                anterior = saltarin;
                anterior->sig = inicio;
            }else if (i == pos){
                borrarUltimo = saltarin;
                delete borrarUltimo;
            }
            
            
            saltarin = saltarin->sig;
        } while (saltarin != inicio);
               
    }else {
        saltarin = inicio->sig;
        Nodo * borrarMedio;

        int i = 1;

        do
        {
            i++;
            if (i == pos){
                borrarMedio = saltarin;
                anterior->sig = saltarin->sig;
                delete borrarMedio;
                break;
            }else {
                anterior = anterior->sig;
                saltarin = saltarin->sig; 
            }
        } while (saltarin != inicio);
        
    }
    
    
}