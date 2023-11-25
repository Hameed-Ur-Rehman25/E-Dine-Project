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
void edit_item();
void add_item();
void remove_item();
void update_item(); 

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
    switch (option)
    {
        case 1:
        {
            manager_portal();
            break;
        }  
        case 2:
        {
            // customer();
            break;
        }   
        case 3:
        {
            /* chef */
            break;
        }  
        default:
        {
            break;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void manager_portal()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MANAGER PORTAL*****\n\n";
    cout << "\n\t<1> Menu Management\n\n\t<2> Staff\n\n\t<3> Order History\n\n\t<4> Change Password\n\n\t<0> Back To Main Page";
    choose();
    cin >> option;
    switch (option)
    {
        case 1:
        {
            //pswd
            menu_management();
            break;
        }  
        case 2:
        {
            staff();
            break;
        }  
        case 3:
        {
            order_history();
            break;
        }  
        case 4:
        {
            //settings
            break;
        }  
        case 0:
        {
            main_page();
            break;
        }  
        default:
        {
            wrong_entry();
            manager_portal();
            break;
        }
    }
}

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
    switch (option)
    {
        case 1: //view
        {
            view_menu();
            break;
        }  
        case 2: //edit or update
        {
            edit_item();
            break;
        }   
        case 0:
        {
            manager_portal();
            break;
        }  
        default:
        {
            wrong_entry();
            menu_management();
            break;
        }
    }
}

void edit_item()
{
    system("cls");
    title("MENU MANAGEMENT");
    cout << "\n\t<1> Add Item\n\n\t<2> Remove Item\n\n\t<3> Update Item\n\n\t<0> Back";
    cin >> option;
    switch (option)
    {
        case 1:
        {
            add_item();
            break;
        }  
        case 2:
        {
            remove_item();
            break;
        }  
        case 3:
        {
            update_item();
            break;
        }  
        case 0:
        {
            menu_management();
            break;
        }  
        default:
        {
            wrong_entry();
            edit_item();
            break;
        }
    }
}

void add_item()
{
    system("cls");
    title("ADD ITEM");
    cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back ";
    choose();
    cin >> option;
    switch (option)
    {
        case 1:
        {
            fastfood();
            break;
        }  
        case 2:
        {
            drinks();
            break;
        }  
        case 3:
        {
            desserts();
            break;
        }  
        case 0:
        {
            menu_management();
            system("cls");
            break;
        }  
        default:
        {
            wrong_entry();
            view_menu();
            break;
        }
    }
}

void remove_item()
{

}

void update_item()
{

}

void view_menu() //view menu function
{
    // system("cls");
    // cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back ";
    choose();
    cin >> option;
    switch (option)
    {
        case 1:
        {
            fastfood();
            break;
        }  
        case 2:
        {
            drinks();
            break;
        }  
        case 3:
        {
            desserts();
            break;
        }  
        case 0:
        {
            menu_management();
            system("cls");
            break;
        }  
        default:
        {
            wrong_entry();
            view_menu();
            break;
        }
    }
}

void fastfood() // view fast food function
{
    system("cls");
    title("FAST FOOD");
    while (!viewf.eof())
    {
        viewf.get(ch);
        cout <<  ch;
    }
    viewf.close();
}

void drinks() //view drinks function
{
    system("cls");
    title("DRINKS");
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
    title("DESSERT");
    while (!viewdt.eof())
    {
        viewdt.get(ch);
        cout << ch;
    }
    viewdt.close();
} 

void order_history()
{

}

void staff()
{

}