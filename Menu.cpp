#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "Weight_Loss.h"
#include "Guest.h"


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
    cout << "Would you like to sign-in or create an account? (Y/N) ";
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
        cout << "Make your selection: ";
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
        Guest user;
        user.displayGuestMenu();
    }
}

void Menu::signIn()
{
    char choice = ' ';
    cout << "Were you tracking your weight?(Y/N) ";
    cin >> choice;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }

    if(choice == 'Y' || choice == 'y')
    {
        Weight_Loss user;
        string userName = " ";
        string passWord = " ";
        cout << "Enter your username: ";
        cin >> userName;
        setUserName(userName);
        cout << "Enter your password: ";
        cin >> passWord;
        setPassword(passWord);

        bool result = user.loadUserData(userName, passWord);

        if(result == 1)
        {
            cout << "Welcome back!\n\n";
            user.displayWLMenu();
        }

        else if(result == 0)
        {
            char choice;
            cout << "No account was found. Would you like to create an account? (Y/N) ";
            cin >> choice;
            cin.ignore();

            while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
            {
                cout << "Please enter a valid choice: ";
                cin >> choice;
            }

            if(choice == 'Y' || choice == 'y')
            {
                createAccount();
            }

            else if(choice == 'N' || choice == 'n')
            {
                cout << "Goodbye.\n";
                return;
            }
        }
    }

    else if(choice == 'N' || choice == 'n')
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

        bool result = user.personLoadUserData(userName, passWord);

        if(result == 1)
        {
            cout << "Welcome back!\n\n";
            user.displayMenu();
        }

        else if(result == 0)
        {
            char choice;
            cout << "No account was found. Would you like to create an account? (Y/N) ";
            cin >> choice;
            cin.ignore();

            while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
            {
                cout << "Please enter a valid choice: ";
                cin >> choice;
            }

            if(choice == 'Y' || choice == 'y')
            {
                createAccount();
            }

            else if(choice == 'N' || choice == 'n')
            {
                cout << "Goodbye.\n";
                return;
            }
        }
    }
}

void Menu::createAccount()
{
    char choice = ' ';
    string userName = " ";
    string passWord = " ";
    cout << "Create an Account\n";
    cout << "-----------------\n";
    cout << "Please type in a username and password.\n";
    cout << "Username: ";
    cin >> userName;
    cout << "Password: ";
    cin >> passWord;
    cout << "Would you like to track your weight? (Y/N) ";
    cin >> choice;
    cin.ignore();

    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }

    if(choice == 'Y' || choice == 'y')
    {
        double calGoal = 0;
        double height = 0;
        double weight = 0;
        cout << "Please enter your height (in inches): ";
        cin >> height;
        cout << "Please enter your weight (in pounds): ";
        cin >> weight;
        cout << "Please enter your daily calorie goal: ";
        cin >> calGoal;
        Weight_Loss user(height, weight, userName, passWord, calGoal);
        cout << "Account Created!\n";
        user.displayWLMenu();
    }

    else if(choice == 'N' || choice == 'n')
    {
        double calGoal = 0;
        cout << "Please enter your daily calorie goal: ";
        cin >> calGoal;
        Person user(userName, passWord, calGoal);
        cout << "Account Created!\n";
        user.displayMenu();
    }

}
