#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

using namespace std;

struct Marcas
{
    int NumeroMarca;
    string NombreMarca;
};
struct Productos
{
    int CodigoProducto;
    string NombreProducto;
    float PrecioVenta;
    float PrecioCompra;
    int StockDisponible;
    int CodigoMarca;
};
struct FPago
{
    string CodigoPago;
    string NombrePago;
    int PorcentajeDoI;/*DoI = Descuento o interes;*/
};
struct Ventas{
int NumeroCompra;
    int CodigoVenta;
    string FormaPago;
    int CantidadVendida;
    int CodigoCliente;
    int DiaVenta;

};
struct RecaudacionProductos{
int CodProducto;
string NomProducto;
float TotalRecaudado;
int CantVendida;
int StockRemanente;
};

#endif // STRUCT_H_INCLUDED
