#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"


using namespace std;
Menu::Menu()
{
    cout << "\t***********************************************************\n";
    cout << "\t**********************Calorie Tracker**********************\n";
    cout << "\t***********************************************************\n";
}

Menu::~Menu()
{
    //dtor
}

void Menu::signInMenu()
{
    //Prompt the user to either sign-in or create an account.
    cout << "Would you like to sign-in or create an account?(Y/N) ";
    cin >> userChoice;

    //Input verification.
    while(userChoice != 'Y' && userChoice != 'N' && userChoice != 'y' && userChoice != 'n')
    {
        cout << "Please enter a valid option(Y/N): ";
        cin >> userChoice;
    }

    if (userChoice == 'Y' || userChoice == 'y')
    {
        cout << "Would you like to sign in, or create an account?\n";
        cout << "1. Sign In\n";
        cout << "2. Create an Account\n";
        cin >> signInChoice;

        while (signInChoice != 1 && signInChoice != 2)
        {
            cout << "Please select a valid option: ";
            cin >> signInChoice;
        }

        if(signInChoice == 1)
        {
            signIn();
        }
        else if (signInChoice == 2)
            createAccount();
    }

    else if(userChoice == 'N' || userChoice == 'n')
    {
        displayMenu();
    }
}

void Menu::signIn()
{
    Person user;
    string userName = " ";
    string passWord = " ";
    cout << "Enter your username: ";
    cin >> userName;
    setUserName(userName);
    cout << "Enter your password: ";
    cin >> passWord;
    setPassword(passWord);

    cout << "Welcome back!\n\n";
    displayMenu();
}

void Menu::createAccount()
{
    cout << "Welcome to the program!\n";
    displayMenu();
}

void Menu::displayMenu()
{
    char choice = ' ';

    do
    {
        cout << "What would you like to do?\n\n";

        cout << "1. Add/Modify User Information\n";
        cout << "2. View Current User Information\n";
        cout << "3. Modify Calorie Goal\n";
        cout << "4. Update my caloric intake for the day\n";
        cout << "5. Quit\n";

        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore();

        while(choice < '1' || choice > '5')
        {
            cout << "Please enter a valid choice: ";
            cin >> choice;
        }

        switch(choice)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
        }
    }
    while (choice != '5');
}
