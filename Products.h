//
// Created by bronc on 08.06.2023.
//

#ifndef PROJEKT_ZALICZENIOWY_PRODUCTS_H
#define PROJEKT_ZALICZENIOWY_PRODUCTS_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Products {
    int id{};
    string typeOfPart;
    string producer;
    string fullName;
    float priceWithoutVat{};
protected:
    float priceWithVat{};
public:

    int quantity;

    float getPriceWithVat() const;

    void showData();

    static string transactionsToString(map<int, Products> transaction);

    static void modifyProductMap(map<int, Products> &productMap);

    static void displayProducts(map<int, Products> productMap);

    Products(int i = 0, string t = "", string p = "", string f = "", float outVat = 0);
};


#endif //PROJEKT_ZALICZENIOWY_PRODUCTS_H
