#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

char ch;
string line;

inline void wrong_entry();
inline void title(string t);

void manager_portal();
void menu_management();
void view_menu();
void fastfood();
void drinks();
void dessert();
void add_item();
void edit_item();

struct
{
    string item_name;
    int price = 0;
    int sr_no = 0;
    int quantity = 0;
    int sum = 0;
    int num = 0;
    int fsr_no = 0;
    string line;
} item;

int main()
{
    int option;
    system("cls");
    // cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    title("WELCOME TO E-DINE CAFE");
    cout << "\t<1> MANAGER\n\n\t<2> CUSTOMER\n\n\t<3> KITCHEN\n\n\tEnter any key to exit...";
    cout << "\n\n\t\tChoose any one option: ";
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
    }
    return 0;
}

inline void wrong_entry() // WRONG OPTION ALERT
{
    cerr << "\n\n\t\t\tIncorrect Option! Please choose from the given option.Press any key to try again....";
    getch();
}

inline void title(string t) // TITLE ALIGNEMENT AND DESIGN
{
    cout << "\t\t\t***********************************************" << endl;
    cout << "\t\t\t                " << t << "                        " << endl;
    cout << "\t\t\t***********************************************" << endl;
}

void manager_portal()
{
    int option;
    do
    {
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MANAGER PORTAL*****\n\n";
        cout << "\n\t<1> Menu Management\n\n\t<2> Staff\n\n\t<3> Order History\n\n\t<4> Change Password\n\n\t<0> Back To Main Page\n\n\tPress any key to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            menu_management();
        }
        else if (option == 2)
        {
            /* code */
            break;
        }
        else if (option == 3)
        {
            /* code */
            break;
        }
        else if (option == 4)
        {
            /* code */
            break;
        }
        else if (option == 0)
        {
            /* code */
            break;
        }
        else if (option != 0)
        {
            exit(0);
        }
    }while (option!=0);
}

void menu_management()
{
    int option;
    do
    {
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MENU MANAGEMENT*****\n\n";
        cout << "\n\t<1> View Menu\n\n\t<2> Edit/Update Menu\n\n\t<0> Back\n\n\tPress any key to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            view_menu();
        }
        else if (option == 2)
        {
            edit_item();
            break;
        }
        else if (option == 3)
        {
            /* code */
            break;
        }
        else if (option != 0)
        {
            exit(0);
        }
    }while(option!=0);
}

void view_menu()
{
    int option;
    do{    
        system("cls");
        title("E-DINE CAFE MENU LIST");
        cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back\n\n\tPress any key to exit... ";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option==1)
        {
            fastfood();
        }
        else if (option == 2)
        {
            drinks();
        }
        else if (option == 3)
        {
            dessert();
        }
        else if (option != 0)
        {
            exit(0);
        }        
    }while(option!=0);
}

void fastfood()
{
    system("cls");
    title("FAST FOOD");
    fstream v_fastfood("fastfood.txt",ios :: in);
    while (getline(v_fastfood,line))
    {
        cout <<line<<endl;
    }
    cout <<"\n\nt\t\tPress any key to go Back";
    getch();
    v_fastfood.close();
}

void drinks()
{
    system("cls");
    title("DRINKS");
    fstream v_drinks("drinks.txt",ios :: in);
    while (getline(v_drinks,line))
    {
        cout <<line<<endl;
    }
    cout <<"\n\nt\t\tPress any key to go Back";
    getch();
    v_drinks.close();
}

void dessert()
{
    system("cls");
    title("DESSERT");
    fstream v_dessert("dessert.txt",ios :: in);
    while (getline(v_dessert,line))
    {
        cout <<line<<endl;
    }
    cout <<"\n\nt\t\tPress any key to go Back";
    getch();
    v_dessert.close();
}

void edit_item()
{
    int option;
    do{
        system("cls");
        title("MENU MANAGEMENT");
        cout << "\n\t<1> Add Item\n\n\t<2> Remove Item\n\n\t<3> Update Item\n\n\t<0> Back\n\n\tPress any key to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            add_item();
        }
        else if (option == 2)
        {
            /* code */
        }
        else if (option == 3)
        {
            /* code */
        }
        else if (option != 0)
        {
            exit(0);
        }
    }while(option!=0);
}

void add_item()
{
    fstream add_fastfood("fastfood.txt",ios::out | ios::app);
    fstream add_drinks("drinks.txt", ios::out | ios::app);
    fstream add_dessert("dessert.txt", ios::out | ios::app);
    int option;
    system("cls");
    title("ADD ITEM");
    cout << "\n\n\tSerial Number: ";
    cin >> item.sr_no;
    cout << "\n\n\tItem Name (use '-' instead of space): ";
    cin >> item.item_name;
    cout << "\n\n\tPrice : ";
    cin >> item.price;
    cout <<"\n\n\tSelect Option:\n\t<1> Fast Food\t<2> Drinks\t<3> Dessert";
    cout <<"\n\t\tChoose any one option: ";
    cin >> option;
    if (option == 1)
    {
        add_fastfood<<"\n"<<item.sr_no<<"\t"<<item.item_name<<"\t"<<item.price;
        add_fastfood.close();
        cout <<"\n\t\tSUCCESSFULLY SAVED!";
        cout <<"\n\tPress any key to go back...";
        getch();
    }
    else if (option == 2)
    {
        add_drinks<<"\n"<<item.sr_no<<"\t"<<item.item_name<<"\t"<<item.price;
        add_drinks.close();
        cout <<"\n\t\tSUCCESSFULLY SAVED!";
        cout <<"\n\tPress any key to go back...";
        getch();
    }
    else if (option == 3)
    {
        add_dessert<<"\n"<<item.sr_no<<"\t"<<item.item_name<<"\t"<<item.price;
        add_dessert.close();
        cout <<"\n\t\tSUCCESSFULLY SAVED!";
        cout <<"\n\tPress any key to go back...";
        getch();
    }
}