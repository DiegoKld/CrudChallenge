#include <iostream>
#include <stdlib.h>
#include "Crud.h"
#include <string>
#include<fstream>
#include <cstdlib>
#include <conio.h>



using namespace std;

Crud::Crud()
{
    //Constructor vacio por que se utilizan los getter y setter
}

//Ayudara crear de cero la base de datos. Si se llama nuevamente este metodo es por que se va a eliminar absolutamente todo para empezar de cero.
void Crud::crear(){
    ofstream archivo;//fichero de salida
	char rpt;
	int _id=0;

	archivo.open("DatosPersonas.txt",ios::out); //Abrimos el archivo en modo escritura

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}


	do{
		fflush(stdin);
		cout<<"\nDigite su nombre: ";
		getline(cin,nombre);
		cout<<"Digite su Apellido: ";
		getline(cin,apellido);

		cout<<"Digite su email: ";
		getline(cin,email);
		cout<<"Digite su edad: ";
		cin >> edad;
        //con ud ID local genero un indicador de busqueda que siempre iniciara en 0 debido a que este metodo solo se usa para crear una nueva base de datos
		_id = _id+1;
		//envio el ultimo ID creado al atributo privado id para tener un punto de partida a la hora de crear nuevos usuarios. Se envia el -1 para que el ID de las personas arranque en 0
		id = _id-1;

		archivo<<id<<" "<<nombre<<" "<<apellido<<" "<<email<<" "<<edad<<" "<<endl;


		cout<<"\nDesea Agregar otra persona? Yes:S: ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));

	archivo.close(); //Cerramos el archivo
}

void Crud::agregar(){
    ofstream archivo;
	char rpt;

	archivo.open("DatosPersonas.txt",ios::app); //Abrimos el archivo en modo agregar

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	do{
		fflush(stdin);
		cout<<"\nDigite su nombre: ";
		getline(cin,nombre);
		cout<<"Digite su Apellido: ";
		getline(cin,apellido);

		cout<<"Digite su email: ";
		getline(cin,email);
		cout<<"Digite su edad: ";
		cin >> edad;
        id = (id-2);//

		archivo<<id<<" "<<nombre<<" "<<apellido<<" "<<email<<" "<<edad<<" "<<endl;

		cout<<"\nDesea Agregar otro contacto ? YES: S NO:N : ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));

	archivo.close(); //Cerramos el archivo
	cout <<"Presione una tecla para continuar...";
	getch();
}

void Crud::listar(){
    ifstream archivo;
	string texto;
	int con=0;

	archivo.open("DatosPersonas.txt",ios::in); //Abrimos el archivo en modo lectura

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	while(!archivo.eof()){ //mientras no sea el final de archivo
		getline(archivo,texto);
		cout<<texto<<endl;
		con = con+1;//contador auxiliar de numero de lineas en el archivo de datos
	}
    id=con+1;//debido a que hay dos lineas de cabecera se envia una de mas para llegar al final del dato
	archivo.close(); //Cerramos el archivo

}

void Crud::modificar(){
    ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    int auxId=0;
    char auxNombre[30];
    aux.open("auxiliar.txt",ios::out);//archivo de escritura
    lectura.open("DatosPersonas.txt",ios::in);//archivo de lectura

    if(aux.is_open() && lectura.is_open()){

        cout<<"Ingresa el ID de la persona que deseas Modificar: ";
        cin>>auxId;//Se carga el dato en la variable auxiliar para comparar con lo guardado en el fichero

        lectura>>id;//Se carga el valor encontrado en la primera posicion del fichero al atributo id de la clase Crud() (ir a crud.h para ver como se declaro)

        while(!lectura.eof()){//mientras el fichero este abierto.
            //Cargo cada uno de los campos del fichero en los atributos
            lectura>>nombre;
            lectura>>apellido;
            lectura>>email;
            lectura>>edad;

            if(auxId==id){//comparador del atributo con la variable auxiliar para encontrar el ID o primer campo de la linea del fichero
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"ID: "<<id<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"apellido: "<<apellido<<endl;
                cout<<"E-mail: "<<email<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"__________________________"<<endl;
                cout<<"Ingresa el Nuevo Nombre de la persona con ID "<<id<<": ";
                cin>>auxNombre;
                aux<<id<<" "<<auxNombre<<" "<<apellido<<" "<<email<<" "<<edad<<" "<<endl;
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<id<<" "<<nombre<<" "<<apellido<<" "<<email<<" "<<edad<<" "<<endl;
            }
            lectura>>id;
        }


    }else{
        cout<<"No se pudoAbrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con clave "<<id<<endl;
    }
    aux.close();
    lectura.close();
    remove("DatosPersonas.txt");
    rename("auxiliar.txt","DatosPersonas.txt");
}

void Crud::eliminar(){
    ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    int auxId=0;
    char auxNombre[30];
    aux.open("auxiliar.txt",ios::out);//archivo de escritura
    lectura.open("DatosPersonas.txt",ios::in);//archivo de lectura

    if(aux.is_open() && lectura.is_open()){

        cout<<"Ingresa el ID de la persona que deseas Modificar: ";
        cin>>auxId;//Se carga el dato en la variable auxiliar para comparar con lo guardado en el fichero

        lectura>>id;//Se carga el valor encontrado en la primera posicion del fichero al atributo id de la clase Crud() (ir a crud.h para ver como se declaro)

        while(!lectura.eof()){//mientras el fichero este abierto.
            //Cargo cada uno de los campos del fichero en los atributos
            lectura>>nombre;
            lectura>>apellido;
            lectura>>email;
            lectura>>edad;

            if(auxId==id){//comparador del atributo con la variable auxiliar para encontrar el ID o primer campo de la linea del fichero
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"ID: "<<id<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"apellido: "<<apellido<<endl;
                cout<<"E-mail: "<<email<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"__________________________"<<endl;
                cout<<"Ingresa el Nuevo Nombre de la persona con ID "<<id<<": ";
                cin>>auxNombre;
                aux<<endl;
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<id<<" "<<nombre<<" "<<apellido<<" "<<email<<" "<<edad<<" "<<endl;
            }
            lectura>>id;
        }


    }else{
        cout<<"No se pudoAbrir el Archivo o aun no ha sido Creado"<<endl;
    }
    if(encontrado==false){
        cout<<"No se encontro ningun registro con clave "<<id<<endl;
    }
    aux.close();
    lectura.close();
    remove("DatosPersonas.txt");
    rename("auxiliar.txt","DatosPersonas.txt");
}
