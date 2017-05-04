#ifndef GUEST_H
#define GUEST_H
#include "Person.h"
#include "FoodReferenceGuide.h"

class Guest: public Person
{
    private:

    public:
        Guest();
        virtual ~Guest();
        void displayGuestMenu();
};

#endif // GUEST_H
