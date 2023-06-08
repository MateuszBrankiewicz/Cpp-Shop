//
// Created by bronc on 06.06.2023.
//

#ifndef PROJEKT_ZALICZENIOWY_CLIENT_H
#define PROJEKT_ZALICZENIOWY_CLIENT_H
#include <iostream>
using namespace std;

class Client {
    string firstName;
    string lastName;
    string address;
    string telNum;
    string accNum;
public:
    Client(string fN = "", string lN = "", string aD = "", string tN = "", string aN = "");
    void modifyUserData();
};


#endif //PROJEKT_ZALICZENIOWY_CLIENT_H
