//
// Created by bronc on 06.06.2023.
//

#ifndef PROJEKT_ZALICZENIOWY_CLIENT_H
#define PROJEKT_ZALICZENIOWY_CLIENT_H

#include <iostream>
#include <vector>
#include <map>
#include "Products.h"

using namespace std;
enum Gender {
    male, female, other
};
enum PaymentMethod {
    elixir, blik, cash
};

class Client : public Products {
    string firstName;
    string lastName;
    string address;
    string telNum;
    string accNum;
    Gender gender;

    string readGender();

    void changeGender();

    void setPaymentMethod();

    string readPaymentMethod();

    vector<string> transactionHistory;
    PaymentMethod method = cash;
public:
    Client(string fN = "", string lN = "", string aD = "", string tN = "", string aN = "", Gender g = other);

    map<int, Products> transaction;

    void modifyUserData();

    void showUserData();

    void saveUserData();

//    void readDataFromCsv();
    float getTotalTransactionAmount();

    void addToTransaction(map<int, Products> &productMap, int id, int quantity);

    void submitTransaction(float totalAmount);

    void saveTransactionHistory();

    void displayCurrentTransaction();

    void modifyCurrentTransaction(float &totalAmount);

};


#endif //PROJEKT_ZALICZENIOWY_CLIENT_H
