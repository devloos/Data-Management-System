#include <iostream>
#include <string>

class User
{
public:
    std::string UserName;
};

void UserMenu()
{
    char UserMenuSelection {};

   do
   {
       std::cout << "\n-------------------\n";
       std::cout << "1. Write to file.\n";
       std::cout << "2. Create a new file\n";
       std::cout << "3. Delete file\n";
       std::cout << "Q. Save and Quit.\n";

       std::cout << "Enter Menu Selection: ";
       std::cin >> UserMenuSelection;

       switch (UserMenuSelection)
       {
           case '1':
           {

               break;
           }
           case '2':
           {

               break;
           }
           case '3':
           {

               break;
           }
           case 'Q':
           {

               break;
           }
           default:
           {
               std::cout << "Invalid Menu Selection! Try Again.\n";
               break;
           }
       }
   } while (UserMenuSelection != 'Q' && UserMenuSelection != 'q');
    
}

int main()
{
    //std::string UserNameHolder;
    //User Profile;
    //Profile.UserName(UserNameHolder);

}