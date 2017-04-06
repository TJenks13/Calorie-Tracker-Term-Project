#include "Person.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Person::Person()
{
    calorieGoal = 0;
    userName = " ";
    password = " ";
    currentCalories = 0;
}

Person::Person(string name, string pass, double calGoal)
{
    userName = name;
    password = pass;
    calorieGoal = calGoal;
    currentCalories = 0;
}

Person::~Person()
{
    //dtor
}

void Person::setCalorieGoal(double goal)
{
    calorieGoal = goal;
}

void Person::setCurrentCalories(double curCals)
{
    currentCalories = curCals;
}

void Person::displayMenu(Person)
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

void Person::viewUserInfo()
{
    cout << "Username: " << userName << endl;
    cout << "Daily Calorie Goal: " << calorieGoal << endl;
    cout << "Caloric Intake: " << currentCalories << endl;
}

