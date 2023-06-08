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
    map<int, Products> productMap;
protected:
    float priceWithVat{};
public:
    Products(int i= 0, string t="",string p ="", string f="",float outVat = 0);
    float getPriceWithVat();
    void showData();
};


#endif //PROJEKT_ZALICZENIOWY_PRODUCTS_H
