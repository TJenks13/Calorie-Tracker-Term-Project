#ifndef WEIGHT_LOSS_H
#define WEIGHT_LOSS_H
#include "Person.h"

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
        void setVariables(double, double);
        double getHeight()
            {return height;}
        double getWeight()
            {return weight;}
        virtual void displayMenu(Weight_Loss);
        virtual void modifyInfo();
        virtual void viewUserInfo();
};

#endif // WEIGHT_LOSS_H
