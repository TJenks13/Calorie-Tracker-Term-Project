#include "Person.h"
#include <string>
#include <fstream>
#include <iostream>
#include "FoodReferenceGuide.h"

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

void Person::displayMenu()
{
    char choice = ' ';
    FoodReferenceGuide database;

    do
    {
        cout << "\nWhat would you like to do?\n\n";

        cout << "1. View Current User Information\n";
        cout << "2. Update my caloric intake for the day\n";
        cout << "3. Load Food Database\n";
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
                viewUserInfo();
                break;
            case '2':
                updateCaloricIntake();
                break;
            case '3':
                database.loadFoodDatabase();
                break;
            case '4':
                database.addFoodDatabase();
                break;
            case '5':
                database.viewFoodDatabase();
                break;
        }
    }
    while (choice != '5');

    if(choice == '6')
    {
        database.saveFoodDatabase();
        saveUserData();
        return;
    }
}

void Person::viewUserInfo()
{
    cout << "Username: " << userName << endl;
    cout << "Daily Calorie Goal: " << calorieGoal << endl;
    cout << "Current Caloric Intake: " << currentCalories << endl;
}

void Person::updateCaloricIntake()
{
    double curCal = 0;
    cout << "How many calories have you consumed today? \n";
    cin >> curCal;
    setCurrentCalories(curCal);
    cout << "Calorie intake has been updated.\n";
}

void Person::saveUserData()
{
    ofstream writeFile;

    writeFile.open("personData.txt", ios::app);

    writeFile << userName << "\t" << password << "\t" << calorieGoal << "\t" << currentCalories << endl;

    cout << "Data saved successfully.\n";

    writeFile.close();
}

bool Person::personLoadUserData(string name, string pass)
{
    //Variables for reading in file.
    string names;
    string passwords;
    double calGoals;
    double curCals;
    int index = 0;

    ifstream readFile;

    readFile.open("personData.txt");

    if(readFile.is_open())
    {
        while(readFile >> names >> passwords >> calGoals >> curCals)
        {
            if(name == names && pass == passwords)
            {
                setUserName(name);
                setPassword(pass);
                setCalorieGoal(calGoals);
                setCurrentCalories(curCals);
                index = 1;
            }
        }
    }
    else
        cout << "File does not exist.\n";

    readFile.close();

    if(index == 1)
        return true;
    else
        return false;

}



