#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef void (*Register)();
map<int, Register> registrar;

void menu()
{
    cout << "\n From Menu";
}


void display()
{
    cout << "\n From Display";
}

void shop()
{
    cout << "\n From Shop";
}
int main3()
{
    int choice = 0;

    registrar[1] = &menu;
    registrar[2] = &display;
    registrar[3] = &shop;

    while (choice != -1)
    {
        cout << "   \nEnter the choice (-1 to Exist): ";
        cin >> choice;

        registrar[choice]();
    }


    cout << "\n";
    return 0;
}

