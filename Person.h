#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;
class Person
{
    private:
        double height;
        double weight;
        double calorieGoal;
        double currentCalories;
        string userName;
        string password;
    public:
        Person();
        virtual ~Person();

        string foodRecommend(string);
        void addFood(string);
        double getHeight();
        double getWeight()
            {return weight;}
        double getCalorieGoal()
            {return calorieGoal;}
        void setUserName(string name){userName = name;}
        void setPassword(string text){password = text;}

};

#endif // PERSON_H
