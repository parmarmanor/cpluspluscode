#include <iostream>
#include <map>
#include <string>


using namespace std;

int main2()
{
    string str = "aabbabsdfs";
    map<char, int> charCountMap;

    for (auto itr : str)
    {
        cout << "\n" << itr;

        if (itr == 'a' || itr == 'b')
        {
            charCountMap[itr]++;
        }
        else
        {
            cout << "\nNO...";
            break;
        }
    }

    if (charCountMap['a'] == charCountMap['b'])
    {
        cout << "\n\n\tYes\n\n";
    }


    return 0;
}