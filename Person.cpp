#include "Person.h"
#include <string>

using namespace std;
Person::Person()
{
    height = 0;
    weight = 0;
    calorieGoal = 0;
    userName = " ";
    password = " ";
    currentCalories = 0;
}

Person::~Person()
{
    //dtor
}
