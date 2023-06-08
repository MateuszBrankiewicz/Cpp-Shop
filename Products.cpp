//
// Created by bronc on 08.06.2023.
//

#include "Products.h"
#include "fstream"
#include "sstream"
#include <vector>
Products::Products(int i, string t, string p, string f, float outVat) {
    id =i;
    typeOfPart = t;
    producer = p;
    fullName = f;
    priceWithoutVat= outVat;
    priceWithVat = outVat * 1.23;
}

void Products::showData() {
   cout<<"Id "<<id<<" typeOfPart "<<typeOfPart<<" Producer "<<producer<<" FullName "<<fullName<<" Price out vat "<<priceWithoutVat<<" Price with Vat "<<priceWithVat<<endl;

}
float Products::getPriceWithVat() {
    return priceWithVat;
}
