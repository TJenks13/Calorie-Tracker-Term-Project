#include "Weight_Loss.h"
#include <iostream>
#include <fstream>
#include "FoodReferenceGuide.h"

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

void Weight_Loss::displayWLMenu()
{
    char choice = ' ';
    FoodReferenceGuide database;

    do
    {
        cout << "\nWhat would you like to do?\n\n";

        cout << "1. View Current User Information\n";
        cout << "2. Update my caloric intake for the day\n";
        cout << "3. Set weight\n";
        cout << "4. Load Food Database\n";
        cout << "5. Add food to database\n";
        cout << "6. View food database\n";
        cout << "7. Quit\n";

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
                viewWL_UserInfo();
                break;
            case '2':
                setCaloricIntake();
                break;
            case '3':
                setWeight();
            case '4':
                database.loadFoodDatabase();
                break;
            case '5':
                database.addFoodDatabase();
                break;
            case '6':
                database.viewFoodDatabase();
                break;
        }
    }
    while (choice != '6');

    if(choice == '6')
    {
        database.saveFoodDatabase();
        saveUserData();
        return;
    }
}


void Weight_Loss::viewWL_UserInfo()
{
        viewUserInfo();
        cout << "User Height: " << height << endl;
        cout << "User Weight: " << weight << endl;
}

void Weight_Loss::setWeight()
{
    double newWeight;
    cout << "Please enter your current weight (in lbs): ";
    cin >> newWeight;

    weight = newWeight;
}

void Weight_Loss::setWeight(double newW)
{
    weight = newW;
}

void Weight_Loss::setHeight()
{
    double newHeight;
    cout << "Please enter your current weight (in lbs): ";
    cin >> newHeight;

    height = newHeight;
}

void Weight_Loss::setHeight(double newH)
{
    height = newH;
}

void Weight_Loss::saveUserData()
{
    ofstream writeFile;

    writeFile.open("weightLossPerson.txt", ios::app);

    writeFile << getUserName() << "\t" << getPassword() << "\t" << getCalGoal() << "\t" << getCurCal() << "\t" << height << "\t" << weight << endl;

    cout << "Data saved successfully.\n";

    writeFile.close();

}

bool Weight_Loss::loadUserData(string name, string pass)
{
    //Variables for reading in file.
    string names;
    string passwords;
    double calGoals;
    double curCals;
    double readHeight;
    double readWeight;
    int index = 0;

    ifstream readFile;

    readFile.open("weightLossPerson.txt");

    if(readFile.is_open())
    {
        while(readFile >> names >> passwords >> calGoals >> curCals >> readHeight >> readWeight)
        {
            if(name == names && pass == passwords)
            {
                setUserName(name);
                setPassword(pass);
                setCalorieGoal(calGoals);
                setCurrentCalories(curCals);
                setHeight(readHeight);
                setWeight(readWeight);
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
