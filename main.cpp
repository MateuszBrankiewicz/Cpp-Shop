#include <iostream>
#include "Client.h"
using namespace std;
int main() {
    Client c1("","","","","");
    c1.showUserData();
    c1.modifyUserData();
    c1.showUserData();
    c1.savaDataToCsv();
    return 0;
}
