#ifndef GUEST_H
#define GUEST_H
#include "Person.h"

class Guest: public Person
{
    private:

    public:
        Guest();
        virtual ~Guest();
        virtual void displayMenu(Guest);
        virtual void modifyInfo();
        virtual void viewUserInfo();
};

#endif // GUEST_H
