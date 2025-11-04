#include <iostream>
#include "LoteMarca.h"
#include "LoteProductos.h"
using namespace std;

void OpcionesSwitch
(int opcion,
 bool &salir,
//-----------------------------LOTE DE MARCA----------------------------//
 int (&NumeroMarca)[10],
 string (&NombreMarca)[10],
//-----------------------------LOTE DE PRODUCTOS------------------------//
 int (&CodigoProducto)[20],
 string (&NombreProducto)[20],
 float (&PrecioVenta)[20],
 float (&PrecioCompra)[20],
 int (&StockDisponible)[20],
 int (&CodigoMarca)[20] )
//----------------------------LOTE DE VENTAS----------------------------//
{
    switch(opcion)
    {
    case 1:
        LoteMarca(NumeroMarca, NombreMarca);
        break;
    case 2:
        LoteProductos (CodigoProducto, NombreProducto, PrecioVenta, PrecioCompra, StockDisponible, CodigoMarca);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        salir = true;
        break;
    default:
        cout << "ingrese una opcion valida ..."<< endl;
        break;

    };
}
