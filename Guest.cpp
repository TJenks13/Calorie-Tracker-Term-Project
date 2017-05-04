#include "Guest.h"
#include <iostream>
#include "FoodReferenceGuide.h"

using namespace std;

Guest::Guest()
{
    //ctor
}

Guest::~Guest()
{
    //dtor
}

void Guest::displayGuestMenu()
{
    char choice = ' ';
    FoodReferenceGuide dataBase;

    do
    {
        cout << "\nWhat would you like to do?\n\n";

        cout << "1. Add Calorie Goal\n";
        cout << "2. Update my caloric intake for the day\n";
        cout << "3. Add food to database\n";
        cout << "4. View food database\n";
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
                int calGoal;
                cout << "Please type in your current calorie goal: ";
                cin >> calGoal;
                setCalorieGoal(calGoal);
                break;
            case '2':
                updateCaloricIntake();
                break;
            case '3':
                dataBase.addFoodDatabase();
                break;
            case '4':
                dataBase.viewFoodDatabase();
                break;
        }
    }
    while (choice != '5');
}
