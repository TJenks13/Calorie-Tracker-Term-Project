#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;
class Person
{
    private:
        double calorieGoal;
        double currentCalories;
        string userName;
        string password;
    public:
        Person();
        Person(string, string, double);
        virtual ~Person();

        string foodRecommend(string);
        void addFood(string);
        double getCalorieGoal()
            {return calorieGoal;}
        void setUserName(string name){userName = name;}
        void setPassword(string text){password = text;}
        void setCalorieGoal(double);
        void setCurrentCalories(double);
        virtual void displayMenu(Person);
        virtual void modifyInfo();
        virtual void viewUserInfo();

};

#endif // PERSON_H
