#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
#include "struct.h"
using namespace std;

void menu();

int VerOpciones(int opcion);

void OpcionesSwitch(int opcion,  bool &salir, bool &BMarca, Marcas VMarca[10], Productos VProductos[20], int OrdenProductos[20], FPago VPago[5]);

void LoteMarca( int (&NumeroMarca)[10], string (&NombreMarca)[10]);

void LoteProductos(Productos VProductos[20]);

void LotePago(FPago VPago[5], bool CodigoRepetido[5]);

int IndiceMarca(int CodigoBuscado, Marcas VMarca[10]);

int IndiceProductos(int CodigoBuscado, Productos VProductos[20]);

void VProductosOrdenados(RecaudacionProductos RecaudadoProductos[20],int OrdenProductos[20]);

void ProcesoProductos(RecaudacionProductos RecaudadoProducto[20],Productos VProductos[20],Ventas LVentas);


#endif // FUNCIONES_H_INCLUDED

