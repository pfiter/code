#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream cau;
    string s;
    string kitu;
    int demkitu=0;
    int demdoixung=0;
    int dem=0;
    int dem1=0;
    int doixung=0;
    int sodoixung[100];
    cau.open ("IN.txt",ios::in);
    getline (cau,s);
    cau.close();
    for (int i=0;i<s.length();i++)
    {
        if (i==0)
        {
            kitu.push_back(s[0]);
            demkitu++;
            continue;
        }
        for(int y=0;y<kitu.length();y++)
        {
            if (s[i]!=kitu[y])
            {
                dem++;
            }
        }
        if(dem==kitu.length())
        {
            kitu.push_back(s[i]);
            demkitu++;
        }
        dem=0;
    }
    for (int i=0;i<s.length();i++)
    {
        for (int y=i;y<s.length();y++)
        {
            if (y==i)
            {
                dem++;
                continue;
            }
            dem++;
            if (s[i]==s[y])
            {
                int m=y;
                for (int n=i;n<i+(y-i+1)/2;n++)
                {
                    if (s[n]==s[m])
                    {
                          demdoixung++;
                    }
                     m--;
                }
                if(demdoixung==dem/2)
                {
                    sodoixung[dem1]=dem;
                    dem1++;
                }
                demdoixung=0;
            }
        }
        dem=0;
    }
    for (int i=0;i<dem1;i++)
    {
        if (i==0)
        {
            doixung = sodoixung[0];
            continue;
        }
        if(doixung<sodoixung[i])
        {
            doixung = sodoixung[i];
        }
    }
    cau.open ("OUT.txt",ios::out);
    cout << demkitu << "\n" << doixung;
    cau << demkitu << "\n" << doixung;
    cau.close();
    return 0;
}