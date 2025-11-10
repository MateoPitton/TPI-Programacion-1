#include<iostream>
#include "struct.h"
using namespace std;
/*
111
v
10
9
100
1
222
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1
111
v
10
9
100
1

*/
void Recaudacion()
{
    /*VProductos: int CodigoProducto; string NombreProducto; float PrecioVenta; float PrecioCompra; int StockDisponible; int CodigoMarca;*/

}
//-----------------------------------------------------------------------//
int IndiceProductos(int CodigoBuscado, Productos VProductos[20])
{

    for(int i = 0; i < 20; i++)
    {
        if( VProductos[i].CodigoProducto == CodigoBuscado )
        {
            return i;
        }

    }
    return 0;

}
//-----------------------------------------------------------------------//
int IndiceMarca(int CodigoBuscado, Marcas VMarca[10])
{
    for(int i = 0; i<10; i++)
    {
        if( VMarca[i].NumeroMarca == CodigoBuscado )
        {
            return i;
        }

    }
    return 0;
}
//-----------------------------------------------------------------------//
void LoteVentas(Ventas LVentas)/*LVentas: int NumeroCompra; int CodigoVenta; string FormaPago; int CantidadVendida; int CodigoCliente; int DiaVenta;*/
{

//-----------------
    cout <<"Cargar codigo de producto: "<< endl;
    cin  >> LVentas.CodigoVenta;
//------------------------------------------
    cout <<"Cargar forma de pago: "<<endl;
    cin  >>LVentas.FormaPago;
//------------------------------------------
    cout <<"Cargar cantidad vendida: "<<endl;
    cin  >>LVentas.CantidadVendida;
//------------------------------------------
    cout <<"Cargar codigo de cliente(1 a 50): "<<endl;
    cin  >>LVentas.CodigoCliente;
//------------------------------------------
    cout <<"Cargar dia de Venta(1 a 30): "<<endl;
    cin  >>LVentas.DiaVenta;
}
//-----------------------------------------------------------------------//
void LotePago(FPago VPago[5], bool CodigoRepetido[5])
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Ingrese codigo de forma de pago (EF, MP, TR, TC, CT): "<< endl;
        cin >> VPago[i].CodigoPago;
        while(VPago[i].CodigoPago != "EF" && VPago[i].CodigoPago != "MP" && VPago[i].CodigoPago != "TR" && VPago[i].CodigoPago != "TC" && VPago[i].CodigoPago != "CT")
        {
            cout << "Ingrese un codigo de pago valida: " << endl;
            cin >> VPago[i].CodigoPago;
        }
        CodigoRepetido[i]= false;

        for(int x = 0; x < i; x++)
        {
            if (VPago[i].CodigoPago == VPago[x].CodigoPago)
            {
                CodigoRepetido[i] = true;
            }
            if (CodigoRepetido[i])
            {
                cout << "El codigo " << VPago[i].CodigoPago << " ya fue ingresado. Ingrese uno distinto: ";
                cin >> VPago[i].CodigoPago;

            }
        }

        //------------------------------------------------------------------------------
        cout << "Ingrese nombre de pago: " << endl;
        cin >>VPago[i].NombrePago;
        //------------------------------------------------------------------------------
        cout <<"ingrese porcentaje de descuento o interes: " << endl;
        cin >>VPago[i].PorcentajeDoI;
    }
};
//-----------------------------------------------------------------------//
void LoteMarca(Marcas VMarca[10])
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Ingrese el numero (1 - 10)y nombre de la marca: "<< endl;
        cin >> VMarca[i].NumeroMarca;
        while(VMarca[i].NumeroMarca < 0|VMarca[i].NumeroMarca > 10)
        {
            cout <<"ingrese un valor entre el 1 y 10: " << endl;
            cin  >> VMarca[i].NumeroMarca;
        }
        cin.ignore();
        getline(cin, VMarca[i].NombreMarca);
        while (VMarca[i].NombreMarca. empty())
        {
            cout <<"ingrese un nombre " << endl;
            getline(cin, VMarca[i].NombreMarca);
        }
    }
}
//-----------------------------------------------------------------------//
void LoteProductos(Productos VProductos[20], Marcas VMarca[10])
{
    for(int i=0; i<20; i++)
    {
        cout << "Ingrese el codigo de producto (3 digitos enteros no consecutivos): "<< endl;
        cin >> VProductos[i].CodigoProducto;
        while(VProductos[i].CodigoProducto == 0)
        {
            cout << "Ingrese el codigo de producto (3 digitos enteros no consecutivos): "<< endl;
            cin >> VProductos[i].CodigoProducto;
        }
//----------------------------------------------------------------------------------------------------
        cin.ignore();
        cout << "Ingrese el nombre del producto: "<< endl;
        getline(cin, VProductos[i].NombreProducto);
        while(VProductos[i].NombreProducto. empty())
        {
            cout << "Ingrese el nombre del producto: "<< endl;
            getline(cin, VProductos[i].NombreProducto);
        }
//----------------------------------------------------------------------------------------------------
        cout << "Ingrese el precio de venta: "<< endl;
        cin >> VProductos[i].PrecioVenta;
        while(VProductos[i].PrecioVenta == 0)
        {
            cout << "Ingrese el precio de venta: "<< endl;
            cin >> VProductos[i].PrecioVenta;
        }
//----------------------------------------------------------------------------------------------------
        cout << "Ingrese el precio de compra: "<< endl;
        cin >> VProductos[i].PrecioCompra;
        while(VProductos[i].PrecioCompra == 0 )
        {
            cout << "Ingrese el precio de compra: "<< endl;
            cin >> VProductos[i].PrecioCompra;
        }
//----------------------------------------------------------------------------------------------------
        cout << "Ingrese el stock disponible: "<< endl;
        cin >>VProductos[i].StockDisponible;
        while( VProductos[i].StockDisponible == 0 )
        {
            cout << "Ingrese el stock disponible: "<< endl;
            cin >>VProductos[i].StockDisponible;
        }
//----------------------------------------------------------------------------------------------------
        cout << "Ingrese el codigo de marca: "<< endl;
        cin >> VProductos[i].CodigoMarca;
        while(VProductos[i].CodigoMarca == 0)
        {
            cout << "Ingrese el codigo de marca: "<< endl;
            cin >> VProductos[i].CodigoMarca;
        }
        int CodigoBuscado = VProductos[i].CodigoMarca;
        int CodigoBuscadoMarca = IndiceMarca(CodigoBuscado, VMarca);


        if( VProductos[i].CodigoMarca != VMarca[CodigoBuscadoMarca].NumeroMarca)
        {
            cout<<"error";
            system("pause");
            break;
        }

    }




}
//-----------------------------------------------------------------------//
void OpcionesSwitch
(int opcion,
 bool &salir,
 bool &BMarca,

//-----------------------------LOTE DE MARCA----------------------------//

 Marcas VMarca[10],

//-----------------------------LOTE DE PRODUCTOS------------------------//

 Productos VProductos[20],

//---------------------------LOTE DE FORMAS DE PAGO--------------------//

 FPago VPago[5],
 bool CodigoRepetido[5],

//----------------------------LOTE DE VENTAS----------------------------//

 Ventas LVentas,

//---------------------------PROCESOS----------------------------------//

 RecaudacionProductos RecaudadoProducto[20]
)
{
    switch(opcion)
    {
    case 1:
        /*VMarca: int NumeroMarca; string NombreMarca;*/
        LoteMarca(VMarca);
        BMarca = true;
        break;
    case 2:
        /*VProductos: int CodigoProducto; string NombreProducto; float PrecioVenta; float PrecioCompra; int StockDisponible; int CodigoMarca;*/
        if(BMarca)
        {
            LoteProductos (VProductos, VMarca);
        }
        else
        {
            cout <<"Ingrese lote de marca porfavor ";
            system("pause");
        }
        break;
    case 3:
        /*VPago: string CodigoPago; string NombrePago; int PorcentajeDoI;(DoI Descuento o interes;)*/
        LotePago(VPago, CodigoRepetido);
        break;
    case 4:
        /*LVentas: int NumeroCompra; int CodigoVenta; string FormaPago; int CantidadVendida; int CodigoCliente; int DiaVenta;*/

        for(int i = 0; i < 20; i++)
        {
            RecaudadoProducto[i].NomProducto = VProductos[i].NombreProducto;
            RecaudadoProducto[i].CodProducto = VProductos[i].CodigoProducto;
            RecaudadoProducto[i].CantVendida = 0;
            RecaudadoProducto[i].StockRemanente = VProductos[i].StockDisponible;
            RecaudadoProducto[i].TotalRecaudado = 0;
        }

        do
        {
            cout << "Cargar Nro de compra: " <<endl;
            cin  >> LVentas.NumeroCompra;
            cout <<"Cargar codigo de producto: "<< endl;
            cin  >> LVentas.CodigoVenta;
//------------------------------------------
            cout <<"Cargar forma de pago: "<<endl;
            cin  >>LVentas.FormaPago;
//------------------------------------------
            cout <<"Cargar cantidad vendida: "<<endl;
            cin  >>LVentas.CantidadVendida;
//------------------------------------------
            cout <<"Cargar codigo de cliente(1 a 50): "<<endl;
            cin  >>LVentas.CodigoCliente;
//------------------------------------------
            cout <<"Cargar dia de Venta(1 a 30): "<<endl;
            cin  >>LVentas.DiaVenta;

            int CodigoBuscado = LVentas.CodigoVenta;
            int CodigoBuscadoProductos = IndiceProductos(CodigoBuscado, VProductos);

            RecaudadoProducto[CodigoBuscadoProductos].StockRemanente -= LVentas.CantidadVendida;

            float GProducto = VProductos[CodigoBuscadoProductos].PrecioVenta - VProductos[CodigoBuscadoProductos].PrecioCompra;

            RecaudadoProducto[CodigoBuscadoProductos].CantVendida += LVentas.CantidadVendida;

            float TPRecaudado = GProducto * RecaudadoProducto[CodigoBuscadoProductos].CantVendida;

            RecaudadoProducto[CodigoBuscadoProductos].NomProducto = VProductos[CodigoBuscadoProductos].NombreProducto;

            RecaudadoProducto[CodigoBuscadoProductos].CodProducto = VProductos[CodigoBuscadoProductos].CodigoProducto;

            cout << "Cargar Nro de compra: " <<endl;
            cin  >> LVentas.NumeroCompra;
        }
        while(LVentas.NumeroCompra != 0);

        for(int i = 0; i < 20; i++)
        {
            cout << "cd"<<RecaudadoProducto[i].CodProducto<< endl;
            system("pause");
            cout << "np"<<RecaudadoProducto[i].NomProducto << endl;
            system("pause");
            cout << "tr"<<RecaudadoProducto[i].TotalRecaudado << endl;
            system("pause");
            cout << "cv"<<RecaudadoProducto[i].CantVendida << endl;
            system("pause");
            cout << "sr"<<RecaudadoProducto[i].StockRemanente << endl;
            system("pause");
        };

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
//-----------------------------------------------------------------------//
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
//-----------------------------------------------------------------------//

void menu()
{

    bool salir = false;
    int opcion;

    //------------------------LOTE DE MARCA-------------------------------//

    Marcas VMarca[10] {};

    //------------------------LOTE DE PRODUCTO----------------------------//

    Productos VProductos[20];
    bool BMarca = false;

    //------------------------LOTE DE FORMAS DE PAGO----------------------//

    FPago VPago[5];
    bool CodigoRepetido[5]; /*(ESTE BOOLEANO SIRVE PARA UNA VERIDICACION EN LOTEPAGO)*/

    //------------------------LOTE DE VENTA-------------------------------//
    Ventas LVentas;
    //------------------------PROCESOS------------------------------------//
    RecaudacionProductos RecaudadoProducto[20];
    do
    {
        system("cls");
        cout << "menu principal: elegir una opcion para continuar." << endl<< endl;
        opcion = VerOpciones(opcion);
        OpcionesSwitch(opcion, salir, BMarca, VMarca, VProductos, VPago, CodigoRepetido, LVentas, RecaudadoProducto);
    }
    while(salir!= true);
}

