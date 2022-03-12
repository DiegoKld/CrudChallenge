#include <iostream>
#include <stdlib.h>
#include "Crud.h"
#include <conio.h>
//#include <json/json.h>

using namespace std;

int main()
{
    int op, retorno=0;
    Crud crud;

    salto:
    cout << "[:]Menu principal\n" << endl;
    cout << "[1]Crear DataBase" << endl;
    cout << "[2]Agregar personas al DataBase" << endl;
    cout << "[3]Modificar nombre de persona" << endl;
    cout << "[4]Eliminar persona" << endl;
    cout << "[5]Listar \n" << endl;
    cout << "[6]Salir \n" << endl;
    cout << "Ingresa la opcion: ";
    cin >> op;

    switch(op){
        case 1:{
            crud.crear();
            goto salto;
            break;
        }
        case 2:{
            crud.listar();
            crud.agregar();
            goto salto;
            break;
        }
        case 3:{
            crud.listar();
            crud.modificar();
            goto salto;
            break;
        }
        case 4:{
            crud.listar();
            crud.eliminar();
            goto salto;
            break;
        }
        case 5:{
            crud.listar();
            goto salto;
            break;
        }
        case 6:
            exit(0);
    }




    return 0;
}
