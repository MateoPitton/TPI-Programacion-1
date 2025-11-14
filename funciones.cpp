#include<iostream>
#include "struct.h"
using namespace std;
/*
1
1QWE
2QWE
3WQE
4QWE
5QWE
6QWE
7QWE
8QWE
9QWE
10QWE
2
313
coca
100
90
100
1
421
papitas
200
80
100
2
345
café
300
200
100
3
943
tostadas
430
40
100
4
124
sanguche
191
73
100
5
432
plomo
918
74
100
6
634
cobre
400
95
100
7
120
fluor
375
97
100
8
123
argon
326
63
100
9
111
hidrogeno
529
80
100
10
212
bronce
834
70
100
2
213
wolframio
902
17
100
3
214
uranio
331
90
100
1
215
potasio
973
60
100
2
216
fluor
615
81
100
3
223
trompo
983
65
100
4
224
rombo
664
66
100
5
221
horno
448
80
100
6
222
cromo
165
65
100
7
278
mono
58
48
100
9
3
MP
MercadoPago
10
EF
Efectivo
-10
TR
Transferencia
0
TC
Crédito
10
CT
Criptomoneda
0
4
1
313
EF
20
1
1
2
421
EF
10
2
2
3
345
MP
30
3
3
4
222
MP
55
4
4
5
313
TR
40
1
5
6
313
MP
10
1
6
7
278
TC
30
7
7
0
*/
void Recaudacion(RecaudacionProductos RecaudadoProducto[20], int OrdenProductos[20], float PorcentajeVentas[5], FPago VPago[5])
{
    for(int i = 0; i < 20; i++)
    {
        int ProductosOrdenados = OrdenProductos[i];
        if (RecaudadoProducto[ProductosOrdenados].CantVendida > 0)
        {
            cout << "Codigo de producto: "<<RecaudadoProducto[ProductosOrdenados].CodProducto<< endl;
            cout << "Nombre del producto: "<<RecaudadoProducto[ProductosOrdenados].NomProducto << endl;
            cout << "Total recaudado: "<<RecaudadoProducto[ProductosOrdenados].TotalRecaudado << "$" << endl;
            cout << "Cantidad vendida: "<<RecaudadoProducto[ProductosOrdenados].CantVendida << endl;
            cout << "Stock remanente: "<<RecaudadoProducto[ProductosOrdenados].StockRemanente << endl;
        }
    }
    string NombrePagos[5];
    for (int i = 0; i < 5; i++)
    {

        if(VPago[i].CodigoPago == "EF")
        {
            NombrePagos[i] = VPago[i].NombrePago;
        }
        if(VPago[i].CodigoPago == "MP")
        {
            NombrePagos[i] = VPago[i].NombrePago;
        }
        if(VPago[i].CodigoPago == "TR")
        {
            NombrePagos[i] = VPago[i].NombrePago;
        }
        if(VPago[i].CodigoPago == "TC")
        {
            NombrePagos[i] = VPago[i].NombrePago;
        }
        if(VPago[i].CodigoPago == "CT")
        {
            NombrePagos[i] = VPago[i].NombrePago;
        }
    }
    system("pause");
    cout << "Productos que no vendieron: "<< endl;
    for(int i = 0; i < 20; i++)
    {
        int ProductosOrdenados = OrdenProductos[i];
        if (RecaudadoProducto[ProductosOrdenados].CantVendida == 0)
        {
            cout << "Codigo de producto: "<<RecaudadoProducto[ProductosOrdenados].CodProducto<< endl;
            cout << "Nombre del producto: "<<RecaudadoProducto[ProductosOrdenados].NomProducto << endl;
        }
    }
    system("pause");
    cout << "Porcentajes: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << NombrePagos[i] << " tiene un: " << PorcentajeVentas[i] << " %" << endl;
    }
    system("pause");
}
IndicePagos(FPago VPago[5],string CodigoBuscadoPagos)
{
    for(int i = 0; i < 5; i++)
    {
        if (VPago[i].CodigoPago == CodigoBuscadoPagos)
        {
            return i;
        }
    }
}
//-----------------------------------------------------------------------//
int IndiceProductos(int CodigoBuscado, Productos VProductos[20])
{

    for(int i = 0; i < 20; i++)
    {
        if( VProductos[i].CodigoProducto == CodigoBuscado )
        {
            return i ;
        }

    }
    return -2;

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
void VProductosOrdenados(RecaudacionProductos RecaudadoProducto[20],int OrdenProductos[20])
{
    for (int i=0; i<20; i++)
    {
        OrdenProductos[i] = i;
    }
    for (int x = 0; x<20; x++)
    {
        for (int i=0; i<19; i++)
        {
            int i1 = OrdenProductos[i];
            int i2 = OrdenProductos[i + 1];
            if (RecaudadoProducto[i1].CantVendida < RecaudadoProducto[i2].CantVendida)
            {

                int aux = OrdenProductos[i];
                OrdenProductos[i]= OrdenProductos[i + 1];
                OrdenProductos[i + 1] = aux;
            }
        }
    }

}
//-----------------------------------------------------------------------//
void ProcesoProductos(RecaudacionProductos RecaudadoProducto[20],Productos VProductos[20],Ventas LVentas, float PorcentajeVentas[5], FPago VPago[5])
{
    float TotalVentas = 0;
    float NroParcialVentas[5] {};

    for(int i = 0; i < 20; i++)
    {
        RecaudadoProducto[i].NomProducto = VProductos[i].NombreProducto;
        RecaudadoProducto[i].CodProducto = VProductos[i].CodigoProducto;
        RecaudadoProducto[i].CantVendida = 0;
        RecaudadoProducto[i].StockRemanente = VProductos[i].StockDisponible;
        RecaudadoProducto[i].TotalRecaudado = 0;
    }

    cout << "Cargar Nro de compra: " <<endl;
    cin  >> LVentas.NumeroCompra;

    while(LVentas.NumeroCompra != 0)
    {
//----------------------CARGA DE DATOS-------------------------------
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
//---------------------INDICES-----------------------------------------

        int CodigoBuscado = LVentas.CodigoVenta;
        string CodigoBuscadoPagos = LVentas.FormaPago;
        int CodigoBuscadoProductos = IndiceProductos(CodigoBuscado, VProductos);
        int CodigoPago = IndicePagos(VPago, CodigoBuscadoPagos);

//-------------------------------TOTAL RECAUDADO DE LOS PRODUCTOS-----------------------------

        RecaudadoProducto[CodigoBuscadoProductos].StockRemanente -= LVentas.CantidadVendida;

        float GProducto = VProductos[CodigoBuscadoProductos].PrecioVenta - VProductos[CodigoBuscadoProductos].PrecioCompra;

        float GVenta = GProducto * LVentas.CantidadVendida;

        GVenta = GVenta +(GVenta * VPago[CodigoPago].PorcentajeDoI/100);

        RecaudadoProducto[CodigoBuscadoProductos].CantVendida += LVentas.CantidadVendida;

        RecaudadoProducto[CodigoBuscadoProductos].TotalRecaudado += GVenta;

        RecaudadoProducto[CodigoBuscadoProductos].NomProducto = VProductos[CodigoBuscadoProductos].NombreProducto;

        RecaudadoProducto[CodigoBuscadoProductos].CodProducto = VProductos[CodigoBuscadoProductos].CodigoProducto;
//-----------------------------PORCENTAJE VENTAS-------------------------------------------------
        TotalVentas++;

        if(LVentas.FormaPago == "EF")
        {
            NroParcialVentas[0]++;
        };
        if(LVentas.FormaPago == "MP")
        {
            NroParcialVentas[1]++;
        };
        if(LVentas.FormaPago == "TR")
        {
            NroParcialVentas[2]++;
        };
        if(LVentas.FormaPago == "TC")
        {
            NroParcialVentas[3]++;
        };
        if(LVentas.FormaPago == "CT")
        {
            NroParcialVentas[4]++;
        };
        for(int i = 0; i < 5; i++)
        {
            PorcentajeVentas[i] = NroParcialVentas[i]/TotalVentas * 100;
        }


        cout << "Cargar Nro de compra: " <<endl;
        cin  >> LVentas.NumeroCompra;

    }


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
        while (VMarca[i].NombreMarca.empty())
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

 RecaudacionProductos RecaudadoProducto[20], int OrdenProductos[20],
 float PorcentajeVentas[5])
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
//----------------------------PRODUCTOS ORDENADOS------------------------//
        ProcesoProductos(RecaudadoProducto, VProductos, LVentas, PorcentajeVentas, VPago);
        VProductosOrdenados(RecaudadoProducto, OrdenProductos);
//-----------------------------------------------------------------------//

        break;
    case 5:
        Recaudacion(RecaudadoProducto, OrdenProductos, PorcentajeVentas, VPago);
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
    int OrdenProductos[20];
    float PorcentajeVentas[5];

    do
    {
        system("cls");
        cout << "menu principal: elegir una opcion para continuar." << endl<< endl;
        opcion = VerOpciones(opcion);
        OpcionesSwitch(opcion, salir, BMarca, VMarca, VProductos, VPago, CodigoRepetido, LVentas, RecaudadoProducto,OrdenProductos, PorcentajeVentas);
    }
    while(salir!= true);
}

