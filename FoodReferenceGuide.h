#ifndef FOODREFERENCEGUIDE_H
#define FOODREFERENCEGUIDE_H
#include <vector>
#include <string>

using namespace std;

class FoodReferenceGuide
{
    private:
        vector<string> foodDb;
        vector<double> foodDbCalories;


    public:
        FoodReferenceGuide();
        void addFoodDatabase();
        void loadFoodDatabase();
        void saveFoodDatabase();
        void viewFoodDatabase();
        virtual ~FoodReferenceGuide();

};

#endif // FOODREFERENCEGUIDE_H
