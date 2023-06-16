//
// Created by bronc on 08.06.2023.
//

#include "Products.h"
#include "fstream"
#include "sstream"
#include <vector>

Products::Products(int i, string t, string p, string f, float outVat) {
    id = i;
    typeOfPart = t;
    producer = p;
    fullName = f;
    priceWithoutVat = outVat;
    priceWithVat = outVat * 1.23;
}

void Products::showData() {
    cout << "Id " << id << " typeOfPart " << typeOfPart << " Producer " << producer << " FullName " << fullName
         << " Price out vat " << priceWithoutVat << " Price with Vat " << priceWithVat << endl;

}

float Products::getPriceWithVat() const {
    return priceWithVat;
}

string Products::transactionsToString(map<int, Products> transaction) {
    string allTransaction;
    for (const auto &it: transaction) {
        allTransaction += it.second.typeOfPart + " " + it.second.producer + " " + it.second.fullName + " " +
                          to_string(it.second.priceWithVat) + " " +
                          to_string(it.second.quantity) + "\n";
    }
    return allTransaction;
}

void Products::modifyProductMap(map<int, Products> &productMap) {

    short choice = 1;
    string typeOfPart, producer, fullName;
    float outVat;

    while (choice != 0) {
        cout << "1- Add product, 2-Delete Product, 0-Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            auto it = productMap.end();
            cout << "Type of part: " << endl;
            cin >> typeOfPart;
            cout << "Producer: " << endl;
            cin >> producer;
            cout << "Full name: " << endl;
            cin >> fullName;
            fflush(stdin);
            cout << "Prize without vat: " << endl;
            cin >> outVat;
            Products p(it->first + 1, typeOfPart, producer, fullName, outVat);
            productMap[it->first + 1] = p;
            ofstream file;
            file.open(R"(C:\Studia\c++\Projekt zaliczeniowy - sklep\ProductList.csv)");
            if (file.is_open()) {
                file << "\n" + to_string(it->first) + ";" + typeOfPart + ";" + producer + ";" + fullName + ";" +
                        to_string(outVat);
            } else {
                cout << "File error" << endl;
            }
        } else if (choice == 2) {
            int id;
            Products::displayProducts(productMap);
            cout << "Select product to delete (id)" << endl;
            cin >> id;
            productMap.erase(id);
            map<int, Products> updatedProductMap;
            int newId = 1;
            for (auto &item: productMap) {

                item.second.id = newId;
                updatedProductMap[newId] = item.second;

                newId++;

            }

            productMap = std::move(updatedProductMap);
            Products::displayProducts(productMap);
            ofstream file;
            file.open(R"(C:\Studia\c++\Projekt zaliczeniowy - sklep\ProductList.csv)");
            if (file.is_open()) {
                for (const auto &it: productMap) {
                    file << "\n" + to_string(it.first) + ";" + it.second.typeOfPart + ";" + it.second.producer + ";" +
                            it.second.fullName + ";" +
                            to_string(it.second.priceWithoutVat);
                }
            } else {
                cout << "File error" << endl;
            }
        }
    }


}

void Products::displayProducts(map<int, Products> productMap) {
    if (productMap.empty()) {
        cout << "Map is empty" << endl;
    } else {
        for (const auto &pair: productMap) {
            int id = pair.first;
            Products product = pair.second;
            product.showData();
        }
    }
}

