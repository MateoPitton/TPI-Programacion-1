
#include <iostream>
#include "VerOpciones.h"
#include "OpcionesSwitch.h"
using namespace std;

void menu()
{

    bool salir = false;
    int opcion;
    //------------------------LOTE DE MARCA-------------------------------//
    int NumeroMarca[10]{};
    string NombreMarca[10]{};
    //------------------------LOTE DE PRODUCTO----------------------------//
    int CodigoProducto[20]{};
    string NombreProducto[20]{};
    float PrecioVenta[20]{};
    float PrecioCompra[20]{};
    int StockDisponible[20]{};
    int CodigoMarca[20]{};
    //------------------------LOTE DE VENTA--------------------------------//
    int NumeroCompra;
    int CodigoVenta;
    string FormaPago;
    int CantidadVendida;
    int CodigoCliente;
    int DiaVenta;
    do
    {
        system("cls");
        cout << "menu principal: elegir una opcion para continuar." << endl<< endl;
        opcion = VerOpciones(opcion);
        OpcionesSwitch(opcion, salir, NumeroMarca, NombreMarca, CodigoProducto, NombreProducto, PrecioVenta, PrecioCompra, StockDisponible, CodigoMarca);

    }
    while(salir!= true);
}
