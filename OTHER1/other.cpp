#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string ketqua;
    int select;
    cout << "Nhap van ban can chuyen doi: ";
    getline (cin,str);
    cout << "Hay nhap lua chon: 1.chu in thuong  2.CHU IN HOA"<<endl;
    cout << "Lua chon: ";
    cin >> select;
    if (select==1)
    {
        for (int y=0;y<str.length();y++)
        {
            for (int i=0;i<uppercase.length();i++)
            {
                if (str.at(y)==uppercase[i])
                {
                    ketqua.push_back(lowercase[i]);
                    break;
                }
                if (i==uppercase.length()-1) 
                {
                    ketqua.push_back(str[y]);
                }
            }
        }
    }
    else if (select==2)
    {
        for (int y=0;y<str.length();y++)
        {
            for (int i=0;i<lowercase.length();i++)
            {
                if (str.at(y)==lowercase[i])
                {
                    ketqua.push_back(uppercase[i]);
                    break;
                }
                if (i==lowercase.length()-1) 
                {
                ketqua.push_back(str[y]);
                }
            }
        }
    }
    cout << ketqua;
    return 0;
}