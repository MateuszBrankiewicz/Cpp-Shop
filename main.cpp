#include <iostream>
#include "Client.h"
#include "fstream"
#include <map>
#include "Products.h"
#include "sstream"
#define PASSWORD "admin"
#define  LOGIN "admin"
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



int main() {
    string login,password;
    map<int, Products> productMap;
    getProducts(productMap);
    int wybor,accountType = 0;
    int choice;
    int quantity;
    float totalAmount = 0;
    while(true){
    cout<<"Choose account type: 1-Administrator, 2-User"<<endl;
    cin>>accountType;
    if(accountType == 1){
        cout<<"Login: "<<endl;
        cin>>login;
        cout<<"Password: "<<endl;
        cin>>password;
        if(login == LOGIN&&password == PASSWORD){
            Products::modifyProductMap(productMap);
        }
        else{
            cout<<"Invalid login or password"<<endl;
        }
    }
    else if(accountType == 2){

        Client c1("", "", "", "", "");
        do {
            cout<<"What you will do? \n 1-Set/Modify user data,\n 2-Show user data,\n 3-Display available products,\n 4-Add products to basket,\n 5-Add 1 product to basket\n 6-Display current transaction,\n 7-Modify current transaction,\n 8-Submit transaction,\n 9-Exit"<<endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    c1.modifyUserData();
                    break;
                case 2:
                    c1.showUserData();
                    break;
                case 3:
                    Products::displayProducts(productMap);
                    break;
                case 4:
                    cout << "Select the product you want to buy " << endl;

                    do {
                        Products::displayProducts(productMap);
                        cout << "select the product id you want to buy (0 is the end of selection)" << endl;

                        cin >> wybor;
                        if (wybor == 0) {
                            totalAmount += c1.getTotalTransactionAmount();
                        } else if (wybor < 0) {
                            cout << "Wybierz poprwanie id" << endl;
                        } else {
                            cout << "Quantity? ";
                            cin >> quantity;
                            c1.addToTransaction(productMap, wybor, quantity);
                        }
                    } while (wybor != 0);
                    break;
                case 5:
                    cout << "Enter the product ID: ";
                    cin >> wybor;
                    cout << "Quantity? ";
                    cin >> quantity;
                    c1.addToTransaction(productMap, wybor, quantity);
                    totalAmount += c1.getTotalTransactionAmount();
                    break;
                case 6:
                    c1.displayCurrentTransaction();
                    break;
                case 7:
                    c1.modifyCurrentTransaction(totalAmount);
                    break;
                case 8:
                    c1.submitTransaction(totalAmount);
                    totalAmount = 0;
                    break;
                case 9:
                    return 0;
                default:
                    cout<<"Invalid choice"<<endl;

            }
        } while (choice);
    }
    else{
        return 0;
    }
    }


}
