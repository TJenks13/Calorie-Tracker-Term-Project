#ifndef WEIGHT_LOSS_H
#define WEIGHT_LOSS_H
#include "Person.h"
#include "FoodReferenceGuide.h"

class Weight_Loss: public Person
{
    private:
        double height;
        double weight;

    public:
        Weight_Loss(): Person()
        {
            height = 0;
            weight = 0;
        }

        Weight_Loss(double height, double weight, string user, string pass, double calGoal): Person(user, pass, calGoal)
        {
            setVariables(height, weight);
        }
        virtual ~Weight_Loss();

        void destroy();
        void setVariables(double, double);
        double getHeight()
            {return height;}
        double getWeight()
            {return weight;}
        void setWeight(double);
        void setHeight(double);
        void setWeight();
        void setHeight();
        void setCaloricIntake() {updateCaloricIntake();}
        void addFoodDb();
        void viewFoodDb();
        void loadFoodDb();
        void viewWL_UserInfo();
        virtual bool loadUserData(string, string);
        virtual void saveUserData();
        void displayWLMenu();
};

#endif // WEIGHT_LOSS_H
