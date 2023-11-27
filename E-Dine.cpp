#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

short int option;
char ch;
bool run = false;

void choose();
void wrong_entry();
void title();
// ---------------------
void main_page();
// ---------------------
void manager_portal(); // MAIN PAGE (1)

void menu_management();
void edit_item();
void add_item();
void remove_item();
void update_item();

void view_menu();
void fastfood();
void drinks();
void desserts();

void staff();
void staff_input();
void remove_m();
void find_member();
void savefm();

void order_history();

/*CHANGE PASSWORD*/

// ---------------------
void customer(); // MAIN PAGE (2)
void order_p();
// ---------------------
/*KITCHEN*/ // MAIN PAGE (3)

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

void choose() // CHOOSE OPTION ALERT
{
    cout << "\n\n\t\tChoose any one option: ";
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void wrong_entry() // WRONG OPTION ALERT
{
    cerr << "\n\n\t\tIncorrect Option! Please choose from the given option.\n\tPress any key to try again...";
    getch();
}

//-----------------------------------------------------------------------------------------------

inline void title(string t) // TITLE ALIGNEMENT AND DESIGN
{
    cout << "\t\t\t***********************************************" << endl;
    cout << "\t\t\t                " << t << "                        " << endl;
    cout << "\t\t\t***********************************************" << endl;
}

//-----------------------------------------------------------------------------------------------

void main_page() // MAIN PAGE OF THE APPLICATION
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
                customer();
                break;
            }
        case 3:
            {
                /* chef */
                break;
            }
        default:
            {
                exit;
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
                // pswd
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
                // settings
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

void menu_management()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MENU MANAGEMENT*****\n\n";
    cout << "\n\t<1> View Menu\n\n\t<2> Edit/Update Menu\n\n\t<0> Back";
    choose();
    cin >> option;
    switch (option)
    {
        case 1: // view
            {
                // cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back ";
                // choose();
                // cin >> option;
                // switch (option)
                // {
                //     case 1:
                //         {
                //             fastfood();
                //             break;
                //         }
                //     case 2:
                //         {
                //             drinks();
                //             break;
                //         }
                //     case 3:
                //         {
                //             desserts();
                //             break;
                //         }
                //     case 0:
                //         {
                //             menu_management();
                //             break;
                //         }
                //     default:
                //         {
                //             wrong_entry();
                //             view_menu();
                //             break;
                //         }
                // }
                fastfood();
                cout <<'\n';
                desserts();
                cout <<'\n';
                drinks();
                break;
            }
        case 2: // edit or update
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
    choose();
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
        fstream add_f("fastfood.txt", ios ::out | ios::app);
        cout << "\n\n\tSerial Number: ";
        cin >> item.sr_no;
        cout << "\n\n\tItem Name (use '-' instead of space): ";
        cin >> item.item_name;
        // getline(cin, item.item_name);
        cout << "\n\n\tPrice : ";
        cin >> item.price;
            do
            {
                cout << "\n\t\tDo you want to Save changes y/n: ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    {
                        add_f << item.sr_no << " " << item.item_name << " " << item.price;
                        add_f.close();
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
    case 2:
    {
        system("cls");
        title("ADD ITEM");
        fstream add_d("drinks.txt", ios ::out | ios::app);
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
                        add_d << "\n"
                            << item.sr_no << " " << item.item_name << " " << item.price;
                        add_d.close();
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
        break;
    }
    case 3:
    {
        system("cls");
        title("ADD ITEM");
        fstream add_dt("dessert.txt", ios ::out | ios::app);
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
                        add_dt << item.sr_no << " " << item.item_name << " " << item.price;
                        add_dt.close();
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
    system("cls");
    title("ITEAM REMOVER");
    cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back ";
    choose();
    cin >> option;
    switch (option)
    {
        case 1:
            {
                vector <string> f;
                cout <<"\n\t\tEnter Item Serial Number: ";
                cin >> item.fsr_no;
                fstream f1("fastfood.txt", ios::in | ios :: out);
                f1.seekg(0, ios::beg);
                while (getline(f1, item.line))
                    {
                        stringstream sf1(item.line);
                        sf1 >> item.sr_no;
                        if (item.fsr_no != item.sr_no)
                            {
                                f.push_back(item.line);
                            }
                    }
                f1.close();
                fstream ff1("fastfood.txt", ios :: out);
                for (int i = 0; i < f.size(); i++)
                    {
                        ff1 << f[i]<<endl;
                    }
                ff1.close();
                break;
            }    
        case 2:
            {
                vector <string> d;
                cout <<"\n\t\tEnter Item Serial Number: ";
                cin >> item.fsr_no;
                fstream d1("drinks.txt", ios::in | ios :: out);
                d1.seekg(0, ios::beg);
                while (getline(d1, item.line))
                    {
                        stringstream sd1(item.line);
                        sd1 >> item.sr_no;
                        if (item.fsr_no != item.sr_no)
                            {
                                d.push_back(item.line);
                            }
                    }
                d1.close();
                fstream dd1("drinks.txt", ios :: out);
                for (int i = 0; i < d.size(); i++)
                    {
                        dd1 << d[i]<<endl;
                    }
                dd1.close();
                break;
            }    
        case 3:
            {
                vector <string> dt;
                fstream dt1("dessert.txt", ios::in | ios :: out);
                dt1.seekg(0, ios::beg);
                cout <<"\n\t\tEnter Item Serial Number: ";
                cin >> item.fsr_no;
                while (getline(dt1, item.line))
                    {
                        stringstream sdt1(item.line);
                        sdt1 >> item.sr_no;
                            if (item.fsr_no != item.sr_no)
                                {
                                    dt.push_back(item.line);
                                }
                    }
                dt1.close();
                fstream ddt1("dessert.txt", ios :: out);
                    for (int i = 0; i < dt.size(); i++)
                        {
                            ddt1 << dt[i]<<endl;
                        }
                cout <<"\n\tItem Removed Succesfully";
                ddt1.close();  
                break;
            }    
        case 0:
            {
                edit_item();
                break;
            }    
        default:
            {

                break;
            }
    }
}

void update_item()
{

}

inline void fastfood() // view fast food function
{
    system("cls");
    title("FAST FOOD");
    fstream f1("fastfood.txt", ios::in);
        while (!f1.eof())
            {
                f1.get(ch);
                cout << ch;
            }
    f1.close();
}

inline void drinks() // view drinks function
{
    system("cls");
    title("DRINKS");
    fstream d1("fastfood.txt", ios::in);
    while (!d1.eof())
    {
        d1.get(ch);
        cout << ch;
    }
    d1.close();
}

inline void desserts() // view dessert function
{
    system("cls");
    title("DESSERT");
    fstream dt1("fastfood.txt", ios::in);
    while (!dt1.eof())
    {
        dt1.get(ch);
        cout << ch;
    }
    dt1.close();
}

//-----------------------------------------------------------------------------------------------

void order_history()
{
    system("cls");
    title("ORDER HISTORY");
    cout << "\t\t<1> View\n\n\t<2> Delete\n\n\t<0> Back";
    switch (option)
    {
        case 1:
            {
                fstream ohf_v("order history.txt", ios ::in);
                while (!ohf_v.eof())
                {
                    ohf_v.get(ch);
                    cout << ch;
                }
                ohf_v.close();
                cout << "\n\n\tPress any key to go back...";
                getch();
                manager_portal();
                break;
            }
        case 2:
            {
                fstream ohf_t("order history.txt", ios ::trunc | ios ::out);
                ohf_t << "\t\t\tORDER HISTORY\n";
                ohf_t.close();
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
                fstream sf_v("staff.txt", ios::in);
                    while (!sf_v.eof())
                        {
                            sf_v.get(ch);
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

void staff_input() // ADD MEMBER
{
    fstream st_add("staff.txt", ios ::out | ios::app);
    struct staff v;
    system("cls");
    title("ADD MEMBER");
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
    v.line = v.fname + " " + v.lname + " " + v.DOB + " " + v.Phone + " " + v.DOJ + " " + v.Address;
    do
        {
            cout << "\nDo you want to Save y/n: ";
            cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    {
                        // staff_file.app;
                        st_add << "\n"
                                << v.ID << " " << v.line;
                        cout << "Successfully Saved! Press any key to go back...";
                        getch();
                        st_add.close();
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
    struct staff x;
    system("cls");
    title("REMOVE MEMBER");
    cout << "\n\n\t\tEnter ID: ";
    cin >> x.fid;
    // staff_file.beg;
    fstream st_r("staff.txt",ios::in | ios:: out);
    st_r.seekg(0, ios::beg);
    while (getline(st_r, x.line))
    {
        stringstream xs(x.line);
        xs >> x.ID >> x.fname >> x.lname >> x.DOB >> x.Phone >> x.DOJ >> x.Address;
        if (x.line.length() != 0)
            {
                if (x.fid != x.ID)
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
                    st_r << '\n'
                            << x.ID << " " << x.fname << " " << x.lname + " " << x.DOB + " " << x.Phone + " " << x.DOJ + " " << x.Address;
                    cout << '\n'
                        << x.ID << " " << x.fname << " " << x.lname + " " << x.DOB + " " << x.Phone + " " << x.DOJ + " " << x.Address;
                }
            }
        else
            {
                cout << " ";
            }
    }
    st_r.close();
}

fstream st_v("staff.txt", ios::in);
void find_member() // FIND MEMBER
{
    struct staff x;
    system("cls");
    title("MEMBER FNDER");
    cout << "\n\n\t\tEnter ID: ";
    cin >> x.fid;
        while (getline(st_v, x.line))
            {
                stringstream xs(x.line);
                xs >> x.ID >> x.fname >> x.lname >> x.DOB >> x.Phone >> x.DOJ >> x.Address;

                if (x.line.length() != 0)
                    {
                        if (x.fid == x.ID)
                            {
                                cout << "\tID: " << x.ID << endl;
                                cout << "\tName: " << x.fname << " " << x.lname << endl;
                                cout << "\tDOB: " << x.DOB << endl;
                                cout << "\tPhone: " << x.Phone << endl;
                                cout << "\tDOJ: " << x.DOJ << endl;
                                cout << "\tAddress: " << x.Address << endl;
                                savefm();
                            }
                    }
            }
        if (x.fid != x.ID)
            {
                cout << "\n\t\tInvalid ID! Please enter correct ID number." << endl;
                savefm();
            }
    st_v.close();
}

void savefm()
{
    do
    {
        cout << "\n\t\tDo you want to Find again y/n: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            {
                st_v.seekg(0, ios ::beg);
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

//-----------------------------------------------------------------------------------------------

void customer()
{
    system("cls");
    // cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO E-DINE CAFE*****\n\n";
    title("WELCOME TO E-DINE");
    cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back ";
    choose();
    cin >> option;
    switch (option)
    {
    case 1:
    {
        fastfood();
        cout << "\n\n\t\tEnter Item Number: ";
        cin >> item.num;
        // viewf.seekg(0, ios::beg);
        ifstream viewf2("fastfood.txt", ios ::in);
        while (!viewf2.eof())
        {
            getline(viewf2, item.line);
            stringstream xs(item.line);
            xs >> item.sr_no >> item.item_name >> item.price;
            if (item.num == item.sr_no)
            {
                cout << "\n\t\tQuantity: ";
                cin >> item.quantity;
                item.sum = item.sum + (item.price * item.quantity);
                cout << item.sum;
                viewf2.close();
                break;
            }
        }
        order_p();
        break;
    }
        // case 2:
        // {
        //     drinks();
        //     cout <<"\n\n\t<1> Order again\n\t<2> Proceed To Bill ";
        //     choose();
        //     cin >> option;
        //     switch (option)
        //     {
        //         case 1:
        //         {
        //             customer();
        //             break;
        //         }
        //         case 2:
        //         {
        //             cout <<"\n\t\tQuantity: ";
        //             cin >> item.quantity;
        //             item.sum = item.sum+(item.price*item.quantity);
        //             break;
        //         }
        //         default:
        //         {
        //             wrong_entry();
        //             customer();
        //             break;
        //         }
        //     }
        //     break;
        // }
        // case 3:
        // {
        //     desserts();

        //     cout <<"\n\n\t<1> Order again\n\t<2> Proceed To Bill ";
        //     choose();
        //     cin >> option;
        //     switch (option)
        //     {
        //         case 1:
        //         {
        //             customer();
        //             break;
        //         }
        //         case 2:
        //         {
        //             cout <<"\n\t\tQuantity: ";
        //             cin >> item.quantity;
        //             item.sum = item.sum+(item.price*item.quantity);
        //             break;
        //         }
        //         default:
        //         {
        //             wrong_entry();
        //             customer();
        //             break;
        //         }
        //     }
        //     break;
        // }
        // case 0:
        // {
        //     main_page();
        //     break;
        // }
        // default:
        // {
        //     wrong_entry();
        //     customer();
        //     break;
        // }
    }
}

void order_p()
{
    cout << "\n\n\t<1> Order again\n\t<2> Proceed To Bill ";
    choose();
    cin >> option;
    switch (option)
    {
    case 1:
    {
        customer();
        break;
    }
    case 2:
    {
        cout << "\n\n\tBill: " << item.sum;
        break;
    }
    default:
    {
        wrong_entry();
        customer();
        break;
    }
    }
}
