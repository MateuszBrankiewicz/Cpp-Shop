//
// Created by bronc on 08.06.2023.
//

#include "Products.h"
#include "fstream"
#include "sstream"

Products::Products(int i, string t, string p, string f, float outVat) {
    id =i;
    typeOfPart = t;
    producer = p;
    fullName = f;
    priceWithoutVat= outVat;
    priceWithVat = outVat * 1.23;
}

void Products::showData() {
   cout<<"Id "<<id<<endl;
   cout<<"typeOfPart "<<typeOfPart<<endl;
   cout<<"Producer "<<producer<<endl;
   cout<<"FullName "<<fullName<<endl;
    cout<<"Price out vat "<<priceWithoutVat<<endl;
    cout<<"Price with Vat "<<priceWithVat<<endl;

}
