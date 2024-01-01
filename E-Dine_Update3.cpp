#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

char ch;
string line;

inline void title(string t);

void manager_portal();
void menu_management();
void view_menu();
void v_menu(string file_name);
void add_item();
void edit_item();
void remove_item();
void order_history();
void update_item();
void update_f(string file_n);
void staff();
void add_member();
void remove_member();
void find_member();
void order_p();
void customer();

struct menu_var
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

struct employee
{
    int ID;
    string fname;
    string lname;
    string DOB;
    // string mm,dd,yyyy;
    string Address; // char address[100]
    string Phone;   // double
    string DOJ;     //
    string line;
    int fid;
} staf;

int main()
{
    int option;
    do
    {
        system("cls");
        title("WELCOME TO E-DINE CAFE");
        cout << "\t<1> MANAGER\n\n\t<2> CUSTOMER\n\n\t<3> ABOUT US\n\n\tEnter any key to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            // pssword enter
            manager_portal();
        }
        else if (option == 2)
        {
            customer();
        }
        else if (option == 3)
        {
            system("cls");
            title("TEAM MEMBERS");
            cout << "\n\t--> ANSA ANWAAR\n\t--> AHMAD BUTT\n\t--> HAMEED UR REHMAN\n";
            getch();
        }
    } while (option != 0);
    return 0;
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
        title("WELCOME TO MANAGER PORTAL");
        cout << "\n\t<1> Menu Management\n\n\t<2> Staff\n\n\t<3> Order History\n\n\t<4> Change Password\n\n\t<0> Back To Main Page\n\n\tPress any key to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            menu_management();
        }
        else if (option == 2)
        {
            staff();
            break;
        }
        else if (option == 3)
        {
            order_history();
            break;
        }
        else if (option == 4)
        {
            /* change password*/
            break;
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void menu_management()
{
    int option;
    do
    {
        system("cls");
        title("WELCOME TO MENU MANAGEMENT");
        // cout << "\t\t\t\t\t\t\t\t\t*****WELCOME TO MENU MANAGEMENT*****\n\n";
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
    } while (option != 0);
}

void view_menu()
{
    int option;
    do
    {
        system("cls");
        title("E-DINE CAFE MENU LIST");
        cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back\n\n\tPress any key to exit... ";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;

        if (option == 1)
        {
            v_menu("fastfood");
            cout << "\n\n\t\tPress any key to go Back";
            getch();
        }
        else if (option == 2)
        {
            v_menu("drinks");
            cout << "\n\n\t\tPress any key to go Back";
            getch();
        }
        else if (option == 3)
        {
            v_menu("dessert");
            cout << "\n\n\t\tPress any key to go Back";
            getch();
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void v_menu(string file_name)
{
    system("cls");
    title(file_name);
    fstream v_file(file_name + ".txt", ios ::in);
    while (getline(v_file, line))
    {
        cout << line << endl;
    }
    v_file.close();
}

void edit_item()
{
    int option;
    do
    {
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
            remove_item();
        }
        else if (option == 3)
        {
            update_item();
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void add_item()
{
    fstream add_fastfood("fastfood.txt", ios::out | ios::app);
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
    cout << "\n\n\tSelect Option:\n\t<1> Fast Food\t<2> Drinks\t<3> Dessert";
    cout << "\n\t\tChoose any one option: ";
    cin >> option;

    if (option == 1)
    {
        add_fastfood << "\n"
                     << item.sr_no << "\t" << item.item_name << "\t" << item.price;
        add_fastfood.close();
        cout << "\n\t\tSUCCESSFULLY SAVED!";
        cout << "\n\tPress any key to go back...";
        getch();
    }
    else if (option == 2)
    {
        add_drinks << "\n"
                   << item.sr_no << "\t" << item.item_name << "\t" << item.price;
        add_drinks.close();
        cout << "\n\t\tSUCCESSFULLY SAVED!";
        cout << "\n\tPress any key to go back...";
        getch();
    }
    else if (option == 3)
    {
        add_dessert << "\n"
                    << item.sr_no << "\t" << item.item_name << "\t" << item.price;
        add_dessert.close();
        cout << "\n\t\tSUCCESSFULLY SAVED!";
        cout << "\n\tPress any key to go back...";
        getch();
    }
}

void remove_item()
{
    int option;
    do
    {
        system("cls");
        title("REMOVE ITEM");
        cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back\n\n\tPress any key  to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;

        if (option == 1)
        {
            vector<string> ff;
            cout << "\n\t\tEnter Item Serial Number: ";
            cin >> item.fsr_no;
            fstream f1("fastfood.txt", ios::in | ios ::out);
            f1.seekg(0, ios::beg);
            while (getline(f1, item.line))
            {
                stringstream sf1(item.line);
                sf1 >> item.sr_no;
                if (item.fsr_no != item.sr_no)
                {
                    ff.push_back(item.line);
                }
            }
            f1.close();
            fstream ff1("fastfood.txt", ios ::out);
            for (int i = 0; i < ff.size(); i++)
            {
                ff1 << ff[i] << endl;
            }
            cout << "\n\tPress any key to remove another item...";
            getch();
            ff1.close();
        }
        else if (option == 2)
        {
            vector<string> d;
            cout << "\n\t\tEnter Item Serial Number: ";
            cin >> item.fsr_no;
            fstream d1("drinks.txt", ios::in | ios ::out);
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
            fstream dd1("drinks.txt", ios ::out);
            for (int i = 0; i < d.size(); i++)
            {
                dd1 << d[i] << endl;
            }
            cout << "\n\tPress any key to remove another item...";
            getch();
            dd1.close();
        }
        else if (option == 3)
        {
            vector<string> dt;
            fstream dt1("dessert.txt", ios::in | ios ::out);
            dt1.seekg(0, ios::beg);
            cout << "\n\t\tEnter Item Serial Number: ";
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
            fstream ddt1("dessert.txt", ios ::out);
            for (int i = 0; i < dt.size(); i++)
            {
                ddt1 << dt[i] << endl;
            }
            cout << "\n\tItem Removed Succesfully";
            cout << "\n\tPress any key to remove another item...";
            getch();
            ddt1.close();
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void order_history()
{
    int option;
    do
    {
        system("cls");
        title("ORDER HISTORY");
        cout << "\n\t<1> View\n\n\t<2> Delete\n\n\t<0> Back\n\n\tPress any key to exit...";
        cout << "\n\n\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            fstream ohf_v("order history.txt", ios ::in);
            ohf_v.seekg(0, ios::beg);
            while (getline(ohf_v, line))
            {
                cout << line << endl;
            }
            ohf_v.close();
            cout << "\n\n\tPress any key to go back...";
            getch();
        }
        else if (option == 2)
        {
            fstream ohf_t("order history.txt", ios ::trunc | ios ::out);
            ohf_t << "\t\t\tORDER HISTORY\n";
            ohf_t.close();
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void update_item()
{
    int option;
    do
    {
        system("cls");
        title("UPDATE ITEM");
        cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back\n\n\tPress any key to exit... ";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;

        if (option == 1)
        {
            v_menu("fastfood");
            update_f("fastfood");
        }
        else if (option == 2)
        {
            v_menu("drinks");
            update_f("drinks");
        }
        else if (option == 3)
        {
            v_menu("dessert");
            update_f("dessert");
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void update_f(string file_n)
{
    vector<string> update_list;
    bool flag = false;
    int option;
    cout << "\n\n\t\t Enter Item number to update: ";
    cin >> item.fsr_no;
    fstream up_ff(file_n + ".txt", ios ::in);
    // up_ff.seekg(0, ios ::beg);
    while (!(up_ff.eof()))
    {
        getline(up_ff, item.line);
        stringstream pss(item.line);
        pss >> item.sr_no >> item.item_name >> item.price;
        if (item.fsr_no == item.sr_no)
        {
            flag = true;
            line = item.line;
        }
        else
        {
            update_list.push_back(item.line);
        }
    }
    up_ff.close();

    if (flag)
    {
        stringstream update_ss(line);
        update_ss >> item.sr_no >> item.item_name >> item.price;
        cout << "\n\t<1> Update Name\n\t<3> Update Price\n\t<3> Update Serial Number\n\t<0> Back\n\tPress any key to exit...";
        cout << "Choose any one option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\n\t New Name: ";
            cin >> item.item_name;
            break;
        case 2:
            cout << "\n\t New Price: ";
            cin >> item.price;
            break;
        case 3:
            cout << "\n\t New Serial Number: ";
            cin >> item.sr_no;
            break;
        default:
            exit(0);
            break;
        }
    }
    fstream up_file(file_n + ".txt", ios::out);
    for (int i = 0; i < update_list.size(); i++)
    {
        up_file << update_list[i] << endl;
    }
    up_file << item.sr_no << "\t" << item.item_name << "\t" << item.price;
    up_file.close();
    cout << "\n\tMenu Is Updated Successfully";
    v_menu(file_n +".txt");
    cout << "\n\tPress any key to go back";
    getch();
}

void staff()
{
    int option;
    do
    {
        system("cls");
        title("STAFF MANAGEMENT");
        cout << "\n\t<1> View Member List\n\n\t<2> Add Member \n\n\t<3> Remove Member\n\n\t<4> Find Member\n\n\t<0> Back\n\n\tPress any key to exit...";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;

        if (option == 1)
        {
            system("cls");
            title("MEMBER LIST");
            fstream v_staff("staff.txt", ios::in);
            while (!v_staff.eof())
            {
                v_staff.get(ch);
                cout << ch;
            }
            v_staff.close();
            cout << "\n\n\tPress any key to back...";
            getch();
        }
        else if (option == 2)
        {
            add_member();
        }
        else if (option == 3)
        {
            remove_member();
        }
        else if (option == 4)
        {
            find_member();
        }
        else if (option != 0)
        {
            exit(0);
        }
    } while (option != 0);
}

void add_member()
{
    int option;
    fstream add_staff("staff.txt", ios::out | ios::app);
    do
    {
        system("cls");
        title("ADD MEMBER");
        cout << "\n\t\tID: ";
        cin >> staf.ID;
        cout << "\n\t\tFirst Name: ";
        cin >> staf.fname;
        cout << "\n\t\tlast Name: ";
        cin >> staf.lname;
        cout << "\n\t\tDOB(dd/mm/yyyy): ";
        cin >> staf.DOB;
        cout << "\n\t\tPhone: ";
        cin >> staf.Phone;
        cout << "\n\t\tDOJ(dd/mm/yyyy): ";
        cin >> staf.DOJ;
        do
        {
            cout << "\nDo you want to Save y/n: ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                add_staff << "\n"
                          << staf.ID << "\t" << staf.fname << "\t" << staf.lname << "\t" << staf.DOB << "\t" << staf.Phone << "\t" << staf.DOJ;
                add_staff.close();
                cout << "Successfully Saved!";
                break;
            }
            else if (ch == 'n' || ch == 'N')
            {
                cout << "Not Saved in file!";
                break;
            }
            else
                cout << "INCORRECT OPTION! PLEASE ENTER Y/N...";
        } while (true);
        cout << "\n\n\tPress 1 to add member(or any key to go back): ";
        cin >> option;
    } while (option == 1);
}

void remove_member()
{
    int option;
    vector<string> r_staff;
    do
    {
        system("cls");
        title("REMOVE MEMBER");
        cout << "\n\n\tEnter ID: ";
        cin >> staf.fid;
        fstream s1("staff.txt", ios::in);
        s1.seekg(0, ios::beg);
        while (getline(s1, staf.line))
        {
            stringstream ss(staf.line);
            ss >> staf.ID;
            if (staf.fid != staf.ID)
            {
                r_staff.push_back(staf.line);
            }
        }
        s1.close();
        fstream ss1("staff.txt", ios::out);
        for (int i = 0; i < r_staff.size(); i++)
        {
            ss1 << r_staff[i] << endl;
        }
        cout << "\n\n\tMember removed!";
        ss1.close();
        cout << "\n\n\tPress 1 to add member(or any key to go back): ";
        cin >> option;
    } while (option == 1);
}

void find_member()
{
    int option;
    do
    {
        system("cls");
        title("FIND MEMBER");
        cout << "\n\nn\t\tEnter ID: ";
        cin >> staf.fid;
        fstream st_f("staff.txt", ios::in);
        st_f.seekg(0, ios::beg);
        while (getline(st_f, staf.line))
        {
            stringstream xs(staf.line);
            xs >> staf.ID >> staf.fname >> staf.lname >> staf.DOB >> staf.Phone >> staf.DOJ;
            if (staf.fid == staf.ID)
            {
                cout << "\tID: " << staf.ID << endl;
                cout << "\tName: " << staf.fname << " " << staf.lname << endl;
                cout << "\tDOB: " << staf.DOB << endl;
                cout << "\tPhone: " << staf.Phone << endl;
                cout << "\tDOJ: " << staf.DOJ << endl;
                break;
            }
        }
        if (staf.fid != staf.ID)
        {
            cerr << "\n\tInvalid ID! Please correct correct ID number";
        }

        cout << "\n\n\tPress 1 to search again (or any key to go back): ";
        cin >> option;
        if (!(isdigit(option)))
        {
            return;
        }
    } while (option == 1);
}

void customer()
{
    int option;
    do
    {
        system("cls");
        title("WELCOME TO E-DINE");
        cout << "\n\t<1> FASTFOOD \n\n\t<2> DRINKS\n\n\t<3> DESSERTS\n\n\t<0> Back\n\n\tPress any key to exit ";
        cout << "\n\n\t\tChoose any one option: ";
        cin >> option;
        if (option == 1)
        {
            v_menu("fastfood");
            cout << "\n\n\t\tEnter Item Number: ";
            cin >> item.num;
            ifstream viewf2("fastfood.txt", ios ::in);
            viewf2.seekg(0, ios::beg);
            while (getline(viewf2, item.line))
            {
                stringstream xs(item.line);
                xs >> item.sr_no >> item.item_name >> item.price;
                if (item.num == item.sr_no)
                {
                    cout << "\n\t\tQuantity: ";
                    cin >> item.quantity;
                    item.sum = item.sum + (item.price * item.quantity);
                    viewf2.close();
                    break;
                }
            }
            if (item.num == item.sr_no)
                order_p();
            else
                cerr << "\n\tInvalid Input!\n";
            getch();
        }
        else if (option == 2)
        {
            string l2;
            v_menu("drinks");
            cout << "\n\n\t\tEnter drinks: ";
            cin >> item.num;
            ifstream viewd2("drinks.txt", ios::in);
            viewd2.seekg(0, ios::beg);
            while (getline(viewd2, l2))
            {
                stringstream xs(l2);
                xs >> item.sr_no >> item.item_name >> item.price;
                if (item.num == item.sr_no)
                {
                    cout << "\n\t\tQuantity: ";
                    cin >> item.quantity;
                    item.sum = item.sum + (item.price * item.quantity);
                    viewd2.close();
                    break;
                }
            }
            if (item.num == item.sr_no)
                order_p();
            else
                cerr << "\n\tInvalid Input!\n";
            getch();
        }
        else if (option == 3)
        {
            v_menu("dessert");
            cout << "\n\n\t\tEnter your desserts: ";
            cin >> item.num;
            ifstream viewdt1("dessert.txt", ios::in);
            viewdt1.seekg(0, ios::beg);
            while (getline(viewdt1, item.line))
            {
                stringstream xs(item.line);
                xs >> item.sr_no >> item.item_name >> item.price;
                if (item.num == item.sr_no)
                {
                    cout << "\n\t\tQuantity: ";
                    cin >> item.quantity;
                    item.sum = item.sum + (item.price * item.quantity);
                    viewdt1.close();
                    break;
                }
            }
            if (item.num == item.sr_no)
                order_p();
            else
                cerr << "\n\tInvalid Input!\n";
            getch();
        }
    } while (option != 0);
}

void order_p()
{
    int option;
    // do{
    cout << "\n\n\t<1> Order again\n\t<2> Proceed To Bill \n\n\tPress any key to exit";
    cout << "\n\n\t\tChoose any one option: ";
    cin >> option;
    if (option == 2)
    {
        string name, number;
        int pin;
        cout << "\n\n\tYour total bill: " << item.sum;
        cout << "\n\tEnter the following credentials:";
        cout << "\n\tName : ";
        cin >> name;
        // getline(cin, name);
        cout << "\n\tPhone number : ";
        cin >> number;
        cout << "\n\tPay the cash on the counter!";

        cout << "\n\t\t***THANK YOU***\nWait for your order!You will be srved earlier";
        fstream order_h("order history.txt", ios ::out | ios::app);
        order_h << "\nName: " << name << "\nPhone: " << number << "\nTotal Bill: " << item.sum << "\n";
        order_h.close();
    }
    cout << "\n\nPress any key to go back...";
    getch();
    // }while(option != 1);
}