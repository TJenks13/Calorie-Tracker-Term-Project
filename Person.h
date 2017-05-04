#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "FoodReferenceGuide.h"

using namespace std;
class Person
{
    private:
        string userName;
        string password;
        double calorieGoal;
        double currentCalories;
    public:
        Person();
        Person(string, string, double);
        virtual ~Person();

        void personDestroy();
        string foodRecommend(string);
        string getUserName() {return userName;}
        string getPassword() {return password;}
        double getCalGoal() {return calorieGoal;}
        double getCurCal() {return currentCalories;}
        void setUserName(string name){userName = name;}
        void setPassword(string text){password = text;}
        void setCalorieGoal(double);
        void setCurrentCalories(double);
        void updateCaloricIntake();
        void viewUserInfo();
        bool personLoadUserData(string, string);
        virtual void saveUserData();
        void displayMenu();
};

#endif // PERSON_H
