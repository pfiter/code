#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int k;
    cin >> k;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            continue;
        }
        str.erase(i, 1);
        --i;
    }
    vector <string> numbers;
    numbers.push_back(str);
    for (int i = 0; i <= str.length() - k; ++i)
    {
        numbers[i].erase(i, k);
        numbers.push_back(str);
    }
    numbers.pop_back();
    int max_number;
    for (int i = 0; i < numbers.size(); ++i)
    {
        int add = 1;
        int number_temp = 0;
        for (int j = numbers[i].length() - 1; j >= 0; --j)
        {
            number_temp += ((int)numbers[i][j] - 48) * add;
            add *= 10;
        }
        if (i == 0)
        {
            max_number = number_temp;
        }
        else 
        {
            if (max_number < number_temp)
            {
                max_number = number_temp;
            }
        }
    }
    cout << max_number;
    return 0;
}