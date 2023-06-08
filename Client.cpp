//
// Created by bronc on 06.06.2023.
//

#include "Client.h"

Client::Client(string fN, string lN, string aD, string tN, string aN) {
    firstName = fN;
    lastName = lN;
    address = aD;
    telNum = tN;
    accNum = aN;
}

void Client::modifyUserData() {
    string newFirstName, newLastName, newAddres, newTelNumber, newAccNumber;
    int choice;
    cout << "Choose what u want to modify: " << endl;
    cout << "1 - First name and last name"
         << "2- Addres"
         << "3- Telephone number"
         << "4- Account number"
         << "5 - All data";
    cin >> choice;
    switch (choice) {
        case 1:

            cout << "New first name: ";
            cin >> newFirstName;
            cout << "New last name: ";
            cin >> newLastName;

            lastName = newLastName;
            firstName = newLastName;
            break;
        case 2:
            cout << "New addres: ";
            cin >> newAddres;
            address = newAddres;
            break;
        case 3:
            cout << "New telephone number: ";
            cin >> newTelNumber;
            telNum = newTelNumber;
            break;
        case 4:
            cout << "New account number: ";
            cin >> newAccNumber;
            accNum = newAccNumber;
            break;
        case 5:
            cout << "New first name: ";
            cin >> newFirstName;
            cout << "New last name: ";
            cin >> newLastName;
            cout << "New addres: ";
            cin >> newAddres;
            cout << "New telephone number: ";
            cin >> newTelNumber;
            cout << "New account number: ";
            cin >> newAccNumber;
            firstName = newFirstName;
            lastName = newLastName;
            address = newAddres;
            telNum = newTelNumber;
            accNum = newAccNumber;
            break;
        default:
            cout<<"Niepoprawny wybor"<<endl;
    }

}