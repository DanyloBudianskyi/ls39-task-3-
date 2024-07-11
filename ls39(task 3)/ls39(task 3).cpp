#include "Users.h"

int main()
{
    Users users;
    users.userRegister("Danil", "123321");
    users.signIn("Danil", "123321");


    users.showAllRegistered();
    cout << "\n-----------------------------\n";
    users.showAllSignIn();
    users.signOut("Danil");
}