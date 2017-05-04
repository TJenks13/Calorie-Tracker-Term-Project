#include "FoodReferenceGuide.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

FoodReferenceGuide::FoodReferenceGuide()
{

}

FoodReferenceGuide::~FoodReferenceGuide()
{

}

void FoodReferenceGuide::addFoodDatabase()
{
    string foodName;
    double calorieAmt;
    cout << "Please enter the name of the food you would like to enter,\n";
    cout << "followed by its calorie content per serving (Ex: Chicken 150): ";
    cin >> foodName;
    cin >> calorieAmt;

    if(find(foodDb.begin(), foodDb.end(), foodName) != foodDb.end())
        for(int i = 0; i < foodDb.size(); i++)
        {
            if(foodDb[i] == foodName)
            {
                cout << "Food already exists in the database.\n";
                return;
            }
        }
    else
    {
        foodDb.push_back(foodName);
        foodDbCalories.push_back(calorieAmt);
    }
}

void FoodReferenceGuide::viewFoodDatabase()
{
    if(foodDb.size() != 0)
    {
        cout << "Food\t" << "Calorie Amount Per Serving\n";
        cout << "----\t" << "--------------------------\n";
        for(int i = 0; i < foodDb.size(); i++)
        {
                cout << foodDb[i] << "\t";
                cout << foodDbCalories[i] << "\n";
        }
    }
}

void FoodReferenceGuide::loadFoodDatabase()
{
    ifstream readFile;
    string food;
    double numCal;

    readFile.open("foodDataBase.txt");

    if(readFile.is_open())
    {
        while(readFile >> food >> numCal)
        {
            foodDb.push_back(food);
            foodDbCalories.push_back(numCal);
        }

        cout << "File was loaded successfully.\n";
    }

    else
        cout << "File does not exist. Please try again with a different file name.\n";

    readFile.close();
}

void FoodReferenceGuide::saveFoodDatabase()
{
    ofstream writeFile;

    writeFile.open("foodDataBase.txt", ios::app);

    for(int i = 0; i < foodDb.size(); i++)
    {
        writeFile << foodDb[i] << "\t";
        writeFile << foodDbCalories[i] << "\n";
    }

    cout << "File saved successfully.\n";

    writeFile.close();
}
