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
    string newFirstName, newLastName, newAddress, newTelNumber, newAccNumber;
    int choice;
    cout << "Choose what u want to modify: " << endl;
    cout << "1 - First name and last name\n"
         << "2- Addres\n"
         << "3- Telephone number\n"
         << "4- Account number\n"
         << "5 - All data\n";
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
            cin.ignore();
            cout << "New addres: ";
            getline(cin,newAddress);
            address = newAddress;
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
            cin.ignore();
            cout << "New first name: ";
            getline(cin, newFirstName);
            cout << "New last name: ";
            getline(cin, newLastName);
            cout << "New address: ";
            getline(cin, newAddress);
            cout << "New telephone number: ";
            getline(cin, newTelNumber);
            cout << "New account number: ";
            getline(cin, newAccNumber);
            firstName = newFirstName;
            lastName = newLastName;
            address = newAddress;
            telNum = newTelNumber;
            accNum = newAccNumber;
            break;
        default:
            cout<<"Niepoprawny wybor"<<endl;
    }

}
void Client::showUserData() {
    cout<<"First name: "<<firstName<<endl;
    cout<<"Last name: "<<lastName<<endl;
    cout<<"Addres: "<<address<<endl;
    cout<<"Telephone number: "<<telNum<<endl;
    cout<<"Account number: "<<accNum<<endl;

}
