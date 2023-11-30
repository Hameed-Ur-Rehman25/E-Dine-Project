#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

inline void wrong_entry();
inline void title();


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
                return;
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
    }
    return 0;
}

inline void wrong_entry() // WRONG OPTION ALERT
{
    cerr << "\n\n\t\tIncorrect Option! Please choose from the given option.\n\tPress any key to try again...";
    getch();
}

inline void title(string t) // TITLE ALIGNEMENT AND DESIGN
{
    cout << "\t\t\t***********************************************" << endl;
    cout << "\t\t\t                " << t << "                        " << endl;
    cout << "\t\t\t***********************************************" << endl;
}

