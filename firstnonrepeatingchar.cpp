#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>


using namespace std;


int main121()
{
    string ch = "";
    unordered_map<string, int> m;
    string lastNonRepeatingChar = "";

    int t, n;
    cin >> t;
    vector<vector<string>> input;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<string> str;

        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            str.push_back(ch);

        }

        input.push_back(str);
    }

    vector<string> final;

    for (auto testCase : input)
    {
        lastNonRepeatingChar = "-1";
        m.clear();
        final.clear();

        for (auto ch : testCase)
        {
            auto itr = m.find(ch);

            if (itr == m.end())
            {
                m.insert(std::make_pair<std::string, int>((string)ch, 1));

                if (lastNonRepeatingChar == "-1")
                {
                    lastNonRepeatingChar = ch;
                }
            }
            else
            {
                m[ch]++;

                if (ch == lastNonRepeatingChar)
                {
                    lastNonRepeatingChar = "-1";

                    for (auto itrch : m)
                    {
                        cout << "\n manor: " << itrch.first << " " << itrch.second << m.size();

                        if (itrch.second == 1)
                        {
                            lastNonRepeatingChar = itrch.first;
                            break;
                        }
                    }
                }

                for (auto itrch : m)
                {
                    cout << "map: " << itrch.first << " " << itrch.second;
                }

                cout <<"\n";
            }

            final.push_back(lastNonRepeatingChar);
        }

        cout << "\n";

        for (auto fitr : final)
        {
            cout << fitr << " ";
        }
    }


    cout << "\n";
    return 0;
}