#include <bits/stdc++.h>
#include "cab.cpp"
#include "login.cpp"

int main()
{
    Login login;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Welcome to the S-CUBE Cab Services !" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    login.start();

    Graph g1;
    // Create an instance of the cabBooking class
    cabBooking bookingSystem;

    string userLocation;
    g1.printLocations();
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Enter user location (If new User Enter 2 times(Captcha)): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userLocation);
    bookingSystem.cabsAvailable(userLocation);
    cout << "------------------------------------------------------------------------------" << endl;
    cin.ignore();

    float amountNew = bookingSystem.getAmount();
    float people = bookingSystem.getPeople();
    float amountPerPerson = amountNew / people;

    if(login.getPremiumPoints() == 0){
        cout << "Total Amount: " << amountNew << endl;
        cout << "Amount per person: " << amountPerPerson << endl;
        cout<< "Payment in process !!"<<endl;
        cout<< "Payment done!"<<endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Thank you for choosing S-CUBE Cabs\nWe Hope You continue to avail our service " << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        return 0;
    }
    else {
        login.updatePremiumPoints();
        cout << "You got a premium discount!!\n18%* off for you :)\n";
        amountNew = amountNew - (amountNew * (0.18));
        amountPerPerson = amountNew / people;
        cout << "Total Amount: " << amountNew << endl;
        cout << "Amount per person: " << amountPerPerson << endl;
    }
    cout<< "Payment in process !!"<<endl;
    cout<< "Payment done!"<<endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Thank you for choosing S-CUBE Cabs\nWe Hope You continue to avail our service " << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    return 0;
}