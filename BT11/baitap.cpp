#include <iostream>
#include <math.h>
#include <fstream>
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
using namespace std;

int main()
{
    fstream cau;
    cau.open("IN.txt",ios::in);
    double thuaSo[3];
    double m;
    double maxRemainder;
    for (int i = 0; i < 3; ++i)
    {
        cau >> thuaSo[i];
    }
    cau >> m;
    cau.close();
    for (int i = 0; i < 2; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            static int dem = 0;
            if (dem == 0)
            {
                maxRemainder = fmod(thuaSo[i] * thuaSo[j], m);
            }
            else if (maxRemainder < fmod(thuaSo[i] * thuaSo[j], m))
            {
                maxRemainder = fmod(thuaSo[i] * thuaSo[j], m);
            }
            ++dem;
        }
    }
    cau.open("OUT.txt",ios::out);
    cau << maxRemainder;
    cau.close();
    return 0;
}