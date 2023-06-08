#include <iostream>
#include "Client.h"
#include "fstream"
#include <map>
#include "Products.h"
#include "sstream"

using namespace std;

void getProducts(map<int, Products> &productMap) {

    ifstream plik;
    string sciezka, linia, typeOfProduct, producer, name, outVat, id;

    sciezka = R"(C:\Studia\c++\Projekt zaliczeniowy - sklep\ProductList.csv)";
    plik.open(sciezka);

    if (plik.is_open()) {
        while (getline(plik, linia)) {
            stringstream ss(linia);
            getline(ss, id, ';');
            getline(ss, typeOfProduct, ';');
            getline(ss, producer, ';');
            getline(ss, name, ';');
            getline(ss, outVat);

            Products p(stoi(id), typeOfProduct, producer, name, stof(outVat));
            productMap[stoi(id)] = p;
        }

        plik.close();
    } else {
        cout << "Nie udało się otworzyć pliku" << endl;
    }

}

void displayProducts(map<int, Products> &productMap) {
    if (productMap.empty()) {
        cout << "Mapa jest pusta" << endl;
    } else {
        for (const auto &pair: productMap) {
            int id = pair.first;
            Products product = pair.second;
            product.showData();
        }
    }
}

int main() {
    map<int, Products> productMap;
    int wybor;
//    vector <Products>transaction;
    getProducts(productMap);
    Client c1("","","","","");
//    c1.showUserData();
//    c1.modifyUserData();
//    c1.showUserData();
//    c1.saveDataToCsv();
//    displayProducts(productMap);
cout<<"Wybieraj produkty które chcesz kupić"<<endl;
bool shopping = true;
    do {
        displayProducts(productMap);
        cout<<"Wybierz id produktu który chcesz kupić (0 to koniec wyboru)"<<endl;
        cin>>wybor;
        if (wybor == 0) {
            shopping = false;
            cout<<c1.getTotalTransactionAmount()<<endl;
        } else if (wybor < 0) {
            cout << "Wybierz poprwanie id" << endl;
        } else { c1.addToTransaction(productMap, 1); }

    } while (wybor!=0);
    return 0;
}
