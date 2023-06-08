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
enum Gender{male,female,other};
class Client: public Products{
    string firstName;
    string lastName;
    string address;
    string telNum;
    string accNum;
    Gender gender;
    string readGender();
    void changeGender();
    vector <Client> transactionHistory;
    vector <Products>transaction;
public:
    Client(string fN = "", string lN = "", string aD = "", string tN = "", string aN = "",Gender g = other);
    void modifyUserData();
    void showUserData();
    void saveDataToCsv();
//    void readDataFromCsv();
    float getTotalTransactionAmount();
    void addToTransaction(map<int, Products> &productMap,int id);
};


#endif //PROJEKT_ZALICZENIOWY_CLIENT_H
