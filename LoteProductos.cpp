#include<iostream>
using namespace std;

void LoteProductos(int (&CodigoProducto)[20],
 string (&NombreProducto)[20],
 float (&PrecioVenta)[20],
 float (&PrecioCompra)[20],
 int (&StockDisponible)[20],
 int (&CodigoMarca)[20] )
{
      for(int i=0; i<20; i++)
        {
            cout << "Ingrese el codigo de producto (3 digitos enteros no consecutivos): "<< endl;
            cin >> CodigoProducto[i];
            while(CodigoProducto[i] == 0)
            {
                cout << "Ingrese el codigo de producto (3 digitos enteros no consecutivos): "<< endl;
                cin >> CodigoProducto[i];
            }
//----------------------------------------------------------------------------------------------------
            cin.ignore();
            cout << "Ingrese el nombre del producto: "<< endl;
            getline(cin, NombreProducto[i]);
            while(NombreProducto[i]. empty())
            {
                cout << "Ingrese el nombre del producto: "<< endl;
                getline(cin, NombreProducto[i]);
            }
//----------------------------------------------------------------------------------------------------
            cout << "Ingrese el precio de venta: "<< endl;
            cin >> PrecioVenta[i];
            while(PrecioVenta[i] == 0)
            {
                cout << "Ingrese el precio de venta: "<< endl;
                cin >> PrecioVenta[i];
            }
//----------------------------------------------------------------------------------------------------
            cout << "Ingrese el precio de compra: "<< endl;
            cin >> PrecioCompra[i];
            while(PrecioCompra[i] == 0 )
            {
                cout << "Ingrese el precio de compra: "<< endl;
                cin >> PrecioCompra[i];
            }
//----------------------------------------------------------------------------------------------------
            cout << "Ingrese el stock disponible: "<< endl;
            cin >>StockDisponible[i];
            while( StockDisponible[i] == 0 )
            {
                cout << "Ingrese el stock disponible: "<< endl;
                cin >>StockDisponible[i];
            }
//----------------------------------------------------------------------------------------------------
            cout << "Ingrese el codigo de marca: "<< endl;
            cin >> CodigoMarca[i];
            while(CodigoMarca[i] == 0)
            {
                cout << "Ingrese el codigo de marca: "<< endl;
                cin >> CodigoMarca[i];
            }
        }




}
