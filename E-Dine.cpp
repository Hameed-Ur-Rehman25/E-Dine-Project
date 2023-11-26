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
void remove_m();
void find_member();
void savefm();

void order_history();

/*CHANGE PASSWORD*/

// ---------------------
void customer(); //MAIN PAGE (2)
// ---------------------
/*KITCHEN*/ //MAIN PAGE (3)

struct 
{
    string item_name;
    int price;
    int sr_no;
} item;


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

//-----------------------------------------------------------------------------------------------

inline void title(string t) //TITLE ALIGNEMENT AND DESIGN
{
    cout<< "\t\t\t***********************************************"<<endl;
    cout<< "\t\t\t                "<<t<<"                        "<<endl;
    cout<< "\t\t\t***********************************************"<<endl;
}

//-----------------------------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------------------------

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
            system("cls");
            title("ADD ITEM");
            // viewf.app;
            cout << "\n\n\tSerial Number: ";
            cin >> item.sr_no;
            cout << "\n\n\tItem Name (use '-' instead of space): ";
            cin >> item.item_name;
            // getline(cin, item.item_name);
            cout << "\n\n\tPrice : ";
            cin >> item.price;
            do
            {
                cout << "\n\t\tDo you want to Find again y/n: ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    viewf << item.sr_no<<" "<<item.item_name<<" "<<item.price;
                    cout << "Successfully Saved! Press any key to go back...";
                    getch();
                    break;
                }
                else if (ch == 'n' || ch == 'N')
                {
                    cout << "Not Saved in file! Press any key to go back...";
                    getch();
                    add_item();
                    break;
                }
                else
                    cout << "\n\t\tINCORRECT OPTION! PLEASE ENTER Y/N...";
            } while (true);
            viewf.close();
            break;
        }  
        case 2:
        {
            system("cls");
            title("ADD ITEM");
            // viewd.app;
            cout << "\n\n\tSerial Number: ";
            cin >> item.sr_no;
            cout << "\n\n\tItem Name (use '-' instead of space): ";
            cin >> item.item_name;
            // getline(cin, item.item_name);
            cout << "\n\n\tPrice : ";
            cin >> item.price;
            do
            {
                cout << "\n\t\tDo you want to Find again y/n: ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    viewd <<"\n"<<item.sr_no<<" "<<item.item_name<<" "<<item.price;
                    cout << "Successfully Saved! Press any key to go back...";
                    getch();
                    break;
                }
                else if (ch == 'n' || ch == 'N')
                {
                    cout << "Not Saved in file! Press any key to go back...";
                    getch();
                    add_item();
                    break;
                }
                else
                    cout << "\n\t\tINCORRECT OPTION! PLEASE ENTER Y/N...";
            } while (ch != 'y' || ch != 'n');
            viewd.close();
            break;
        }  
        case 3:
        {
            system("cls");
            title("ADD ITEM");
            cout << "\n\n\tSerial Number: ";
            cin >> item.sr_no;
            cout << "\n\n\tItem Name (use '-' instead of space): ";
            cin >> item.item_name;
            // getline(cin, item.item_name);
            cout << "\n\n\tPrice : ";
            cin >> item.price;
            do
            {
                cout << "\n\t\tDo you want to Find again y/n: ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    viewdt << item.sr_no<<" "<<item.item_name<<" "<<item.price;
                    viewdt.close();
                    cout << "Successfully Saved! Press any key to go back...";
                    getch();
                    break;
                }
                else if (ch == 'n' || ch == 'N')
                {
                    cout << "Not Saved in file! Press any key to go back...";
                    getch();
                    add_item();
                    break;
                }
                else
                    cout << "\n\t\tINCORRECT OPTION! PLEASE ENTER Y/N...";
            } while (true);
            
            break;
        }  
        case 0:
        {
            edit_item();
            system("cls");
            break;
        }  
        default:
        {
            wrong_entry();
            add_item();
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

//-----------------------------------------------------------------------------------------------

fstream order_history_file("order history.txt", ios ::in | ios ::out);
void order_history()
{
    system("cls");
    title("ORDER HISTORY");
    cout << "\t\t<1> View\n\n\t<2> Delete\n\n\t<0> Back";
    switch (option)
    {
        case 1:
        {
            while (!order_history_file.eof())
            {
                order_history_file.get(ch);
                cout << ch;
            }
            cout << "\n\n\tPress any key to go back...";
            getch();
            manager_portal();
            break;
        }  
        case 2:
        {
            order_history_file.trunc;
            order_history_file << "\t\t\tORDER HISTORY\n";
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
            order_history();
            break;
        }
    }
}

//-----------------------------------------------------------------------------------------------

fstream staff_file("staff.txt", ios::in | ios ::out | ios::app);
void staff()
{
    system("cls");
    // cout << "\t\t\t\t\t\t\t\t\t*****STAFF MANAGEMENT*****\n\n";
    title("STAFF MANAGEMENT");
    cout << "\n\t<1> View Member List\n\n\t<2> Add Member \n\n\t<3> Remove Member\n\n\t<4> Update Member Data\n\n\t<5> Find Member\n\n\t<0> Back";
    choose();
    cin >> option;
    if (option == 1)
    {
        while (!staff_file.eof())
        {
            staff_file.get(ch);
            cout << ch;
        }
        cout << "\n\n\tPress any key to back...";
        getch();
        staff();
    }
    else if (option == 2)
    {
        staff_input();
    }
    else if (option == 3)
    {
        remove_m();
    }
    else if (option == 4)
    {
        // -----
    }
    else if (option == 5)
    {
        find_member();
    }
    else if (option == 0)
    {
        manager_portal();
    }
    else
    {
        wrong_entry();
        staff();
    }
}

void staff_input() //ADD MEMBER
{
    system("cls");
    title("ADD MEMBER");
    struct staff v;
    cout << "ID: ";
    cin >> v.ID;
    cout << "First Name: ";
    cin >> v.fname;
    cout << "last Name: ";
    cin >> v.lname;
    cout << "DOB(dd/mm/yyyy): ";
    cin >> v.DOB;
    // cin >> v.dd >> v.mm >> v.yyyy;
    cout << "Address: ";
    cin >> v.Address;
    cout << "Phone: ";
    cin >> v.Phone;
    cout << "DOJ(dd/mm/yyyy): ";
    cin >> v.DOJ;
    v.line = v.fname + " " + v.lname+ " " + v.DOB + " " + v.Phone + " " + v.DOJ+ " " + v.Address;
    do
    {
        cout << "\nDo you want to Save y/n: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            // staff_file.app;
            staff_file << "\n"
                       << v.ID << " " << v.line;
            cout << "Successfully Saved! Press any key to go back...";
            getch();
            staff_file.close();
            break;
        }
        else if (ch == 'n' || ch == 'N')
        {
            cout << "Not Saved in file! Press any key to go back...";
            getch();
            break;
        }
        else
            cout << "INCORRECT OPTION! PLEASE ENTER Y/N...";
    } while (true);
}

void remove_m()
{
    system("cls");
    title("REMOVE MEMBER");
    struct staff x;
    cout <<"\n\n\t\tEnter ID: ";
    cin >> x.fid;
    // staff_file.beg;
    staff_file.seekg(0);
    while(getline(staff_file,x.line))
    {
        stringstream xs(x.line);
        xs >> x.ID >> x.fname >> x.lname >> x.DOB >> x.Phone >> x.DOJ >> x.Address;
        if (x.line.length()!=0)
        {
        
            if(x.fid != x.ID)
            {
                // cout <<"\tID: "<<x.ID<<endl;
                // cout <<"\tName: "<<x.fname<<" "<<x.lname<<endl;
                // cout << "\tDOB: "<<x.DOB<<endl;
                // cout << "\tPhone: "<<x.Phone<<endl;
                // cout << "\tDOJ: "<<x.DOJ<<endl;
                // cout << "\tAddress: "<<x.Address<<endl;
                // staff_file.trunc;
                // ofstream staff_file2;
                // staff_file2.open("staff.txt");
                staff_file<<'\n' <<x.ID << " "<<x.fname << " " << x.lname+ " " << x.DOB + " " << x.Phone + " " << x.DOJ+ " " << x.Address;
                cout<<'\n' <<x.ID << " "<<x.fname << " " << x.lname+ " " << x.DOB + " " << x.Phone + " " << x.DOJ+ " " << x.Address;
            }   
        }
        else{
            cout <<" ";
        }
    }
    staff_file.close();
}

void find_member() //FIND MEMBER
{
    system("cls");
    // cout<< "\t\t\t------------------------------------------"<<endl;
    // cout<< "\t\t\t               MEMBER FINDER              "<<endl;
    // cout<< "\t\t\t------------------------------------------"<<endl;
    title("MEMBER FNDER");
    struct staff x;
    cout <<"\n\n\t\tEnter ID: ";
    cin >> x.fid;
    // staff_file.beg;
    while(!staff_file.eof())
    {
        getline(staff_file,x.line);
        stringstream xs(x.line);
        xs >> x.ID >> x.fname >> x.lname >> x.DOB >> x.Phone >> x.DOJ >> x.Address;
        
        if(x.line.length()!= 0)
        {
            if(x.fid == x.ID)
            {
                cout <<"\tID: "<<x.ID<<endl;
                cout <<"\tName: "<<x.fname<<" "<<x.lname<<endl;
                cout << "\tDOB: "<<x.DOB<<endl;
                cout << "\tPhone: "<<x.Phone<<endl;
                cout << "\tDOJ: "<<x.DOJ<<endl;
                cout << "\tAddress: "<<x.Address<<endl;
                savefm();
            }
        }   
    }
    if(x.fid != x.ID)
    {
        cout << "\n\t\tInvalid ID! Please enter correct ID number."<<endl;
        savefm();
    }
    staff_file.close();
}

void savefm()
{
    do
    {
        cout << "\n\t\tDo you want to Find again y/n: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            staff_file.seekg(0 , ios :: beg);
            find_member();
        }
        else if (ch == 'n' || ch == 'N')
        {
            cout << "\n\t\tPress any key to go back...";
            getch();
            staff();
            break;
        }
        else
            cout << "\n\t\tINCORRECT OPTION! PLEASE ENTER Y/N...";
    } while (true);
}



void customer()
{
    system("cls");
    // cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    title("WELCOME TO E-DINE");
    view_menu();
    
}