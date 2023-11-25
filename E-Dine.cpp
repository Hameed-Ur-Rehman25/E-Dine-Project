#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

short int option;
char ch;

void choose();
void wrong_entry();
void title();
void main_page();

int main()
{
    main_page();
    return 0;
}

void main_page()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    cout << "\t<1> MANAGER\n\n\t<2> CUSTOMER\n\n\t<3> KITCHEN\n\n\tEnter any key to exit...";
    choose();
    cin >> option;
    if (option == 1)
    {
        manager_portal();
    }
    else if (option == 2)
    {
        customer();
    }
    else if (option == 3)
    {
        /* chef */
    }
}