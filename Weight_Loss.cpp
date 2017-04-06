#include "Weight_Loss.h"
#include <iostream>

using namespace std;

void Weight_Loss::setVariables(double h, double w)
{
    height = h;
    weight = w;
}

Weight_Loss::~Weight_Loss()
{
    //dtor
}

void Weight_Loss::displayMenu(Weight_Loss user)
{
 char choice = ' ';

    do
    {
        cout << "What would you like to do?\n\n";

        cout << "1. Modify User Information\n";
        cout << "2. View Current User Information\n";
        cout << "3. Update my caloric intake for the day\n";
        cout << "4. Add food to database\n";
        cout << "5. View food database\n";
        cout << "6. Quit\n";

        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore();

        while(choice < '1' || choice > '6')
        {
            cout << "Please enter a valid choice: ";
            cin >> choice;
        }

        switch(choice)
        {
            case '1':
                break;
            case '2':
                viewUserInfo();
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
        }
    }
    while (choice != '6');
}
