#ifndef LOTEPRODUCTOS_H_INCLUDED
#define LOTEPRODUCTOS_H_INCLUDED
#include <string>
using namespace std;

void LoteProductos(int (&CodigoProducto)[20],
 string (&NombreProducto)[20],
 float (&PrecioVenta)[20],
 float (&PrecioCompra)[20],
 int (&StockDisponible)[20],
 int (&CodigoMarca)[20] );

#endif // LOTEPRODUCTOS_H_INCLUDED
