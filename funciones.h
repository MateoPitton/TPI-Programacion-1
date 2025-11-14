#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
#include "struct.h"
using namespace std;
//---------------------------------MENU-------------------------------------
void menu();

int VerOpciones(int opcion);

void OpcionesSwitch(int opcion,  bool &salir, bool &BMarca, Marcas VMarca[10], Productos VProductos[20], int OrdenProductos[20], FPago VPago[5]);
//-------------------------------LOTES DE CARGA-------------------------------
void LoteMarca( int (&NumeroMarca)[10], string (&NombreMarca)[10]);

void LoteProductos(Productos VProductos[20]);

void LotePago(FPago VPago[5], bool CodigoRepetido[5]);
//-----------------------INDICES-----------------------------

int IndiceMarca(int CodigoBuscado, Marcas VMarca[10]);

int IndiceProductos(int CodigoBuscado, Productos VProductos[20]);

int IndicePagos(FPago VPago[5],string CodigoBuscadoPagos);

//----------------------PROCESOS-------------------------------

void VProductosOrdenados(RecaudacionProductos RecaudadoProducto[20],int OrdenProductos[20]);

void Procesos(RecaudacionProductos RecaudadoProducto[20],Productos VProductos[20],Ventas LVentas, float PorcentajeVentas[5], FPago VPago[5], VPMarcas VentasPorMarca[10], Marcas VMarca[10]);

void Recaudacion(RecaudacionProductos RecaudadoProducto[20], int OrdenProductos[20], float PorcentajeVentas[5], FPago VPago[5], VPMarcas VentasPorMarca[10]);

#endif // FUNCIONES_H_INCLUDED

