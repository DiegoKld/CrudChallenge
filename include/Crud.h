#ifndef CRUD_H
#define CRUD_H
#include <string.h>
using namespace std;
class Crud
{
    public:
        Crud();
        void crear();
        void agregar();
        void modificar();
        void eliminar();
        void listar();

    protected:

    private://Atributos de la clase
        string nombre, apellido, email;
        int edad, id;

};

#endif // CRUD_H
