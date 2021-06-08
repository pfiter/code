#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream cau;
    string x;
    char s[100];
    char tam;
    int k;
    int dem=0;
    cau.open ("IN.txt",ios::in);
    cau >> k;
    cau.ignore();
    getline (cau,x);
    cau.close();
    for (int i=0;i<x.length();i++)
    {
        s[i]=x[i];
    }
    for (int i=x.length()-1;i>=0;i--)
    {
        tam = s[i];
        s[i]=s[k];
        s[k]=tam;
    }
    cau.open ("OUT.txt",ios::out);
    for (int i=0;i<x.length();i++)
    {
        cout << s[i];
        cau << s[i];
    }
    cau.close();
    return 0;
}