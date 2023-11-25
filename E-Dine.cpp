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
// ---------------------
void main_page();
// ---------------------
void manager_portal(); //MAIN PAGE (1)

void menu_management(); 
void view_menu();
void fastfood();
void drinks ();
void desserts ();

void staff();
void staff_input();
void find_member();
void savefm();

void order_history();

/*CHANGE PASSWORD*/

// ---------------------
void customer(); //MAIN PAGE (2)
// ---------------------
/*KITCHEN*/ //MAIN PAGE (3)


struct staff 
{
    int ID;
    string fname;
    string lname;
    string DOB;
    // string mm,dd,yyyy;
    string Address;
    string Phone;
    string DOJ;
    string line;
    int fid;
};


int main() 
{
    main_page();
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void choose() //CHOOSE OPTION ALERT
{
    cout << "\n\n\t\tChoose any one option: ";
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void wrong_entry() //WRONG OPTION ALERT
{
    cerr << "\n\n\t\tIncorrect Option! Please choose from the given option.\n\tPress any key to try again...";
    getch();
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

inline void title(string t) //TITLE ALIGNEMENT AND DESIGN
{
    cout<< "\t\t\t***********************************************"<<endl;
    cout<< "\t\t\t                "<<t<<"                        "<<endl;
    cout<< "\t\t\t***********************************************"<<endl;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void main_page() //MAIN PAGE OF THE APPLICATION
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
fstream viewf("fastfood.txt", ios :: in | ios::out);
fstream viewd("drinks.txt", ios :: in | ios::out );
fstream viewdt("dessert.txt", ios :: in | ios::out );

void menu_management()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MENU MANAGEMENT*****\n\n";
    cout << "\n\t<1> View Menu\n\n\t<2> Edit/Update Menu\n\n\t<0> Back";
    choose();
    cin >> option;

    if (option == 1) //VIEW
    {
        // system("cls");
        view_menu();
    }
    else if (option == 2) //EDIT
    {
        ofstream edit("menu.txt", ios ::out);
        cout << "\n\t<1> Add Item\n\n\t<2> Remove Item\n\n\t<3> Update Item";
        choose();
        cin >> option;
        edit.close();
    }
    else if (option == 0)
    {
        manager_portal();
    }
    else
    {
        wrong_entry();
        menu_management();
    }
}

void view_menu() //view menu function
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back ";
    choose();
    cin >> option;
    if (option==1)
    {
        fastfood();
    }
    else if(option==2)
    {
        drinks();
    }
    else if(option == 3)
    {
        desserts();
    }
    else if (option == 0)
    {
        menu_management();
    }
    else
    {
        wrong_entry();
        view_menu();
    }
}

void fastfood() // view fast food function
{
    system("cls");
    while (!viewf.eof())
    {
        viewf.get(ch);
        cout << ch;
    }
    viewf.close();
}

void drinks() //view drinks function
{
    system("cls");
    while (!viewd.eof())
    {
        viewd.get(ch);
        cout << ch;
    }
    viewd.close();
}

void desserts() //view dessert function 
{
    system("cls");
    while (!viewdt.eof())
    {
        viewdt.get(ch);
        cout << ch;
    }
    viewdt.close();
} 