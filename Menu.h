#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Person.h"
#include "Weight_Loss.h"
#include "Guest.h"

using namespace std;
//Menu class to display a welcome message to the user and present the
//user with a core menu to maneuver through the application.
class Menu:public Person
{
    private:
        char userChoice;
        int signInChoice = 0;

    public:
        Menu();
        virtual ~Menu();

        void signInMenu();
        //Will create class Person to sign in with credentials and read from a file.
        void signIn();
        //Creates person class to create an account to write credentials to class, which will be
        //stored in a file using a dtor.
        void createAccount();
        void modifyInformation();
};

#endif // MENU_H
