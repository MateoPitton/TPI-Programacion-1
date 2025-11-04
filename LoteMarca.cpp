#include<iostream>
using namespace std;

int LoteMarca(int (&NumeroMarca)[10], string (&NombreMarca)[10]){
 for(int i = 0; i < 10; i++)
        {
            cout << "Ingrese el numero (1 - 10)y nombre de la marca: "<< endl;
            cin >> NumeroMarca[i];
            while(NumeroMarca[i] < 0|NumeroMarca[i] > 10)
            {
                cout <<"ingrese un valor entre el 1 y 10: " << endl;
                cin  >> NumeroMarca[i];
            }
            cin.ignore();
            getline(cin, NombreMarca[i]);
            while (NombreMarca[i]. empty())
            {
                cout <<"ingrese un nombre " << endl;
                getline(cin, NombreMarca[i]);
            }
        }
}
