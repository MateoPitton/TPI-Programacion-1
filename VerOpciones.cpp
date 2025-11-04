#include <iostream>

using namespace std;

int VerOpciones(int opcion)
{
    cout << "Cargar lote de marcas - 1" << endl;
    cout << "Cargar lote de productos - 2"<< endl;
    cout << "Cargar lote de formas de pago - 3"<< endl;
    cout << "Cargar lote de ventas - 4"<< endl;
    cout << "Mostrar reportes - 5"<< endl;
    cout << "Salir - 0"<< endl;

    cin >> opcion;
    return opcion;
};
