#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream cau;
    int n;
    char phieu[100][100];
    int songuoi=0;
    int sophieu=0;
    int dem=0;
    int thutu[100];
    cau.open ("IN.txt",ios::in);
    cau >> n;
    for (int i=1;i<=n;i++)
    {
        for (int y=1;y<=n;y++)
        {
            cau >> phieu[i][y];
        }
    }
    cau.close();
    for (int i=1;i<=n;i++)
    {
        for (int y=1;y<=n;y++)
        {
            if (phieu[y][i]=='X')
            {
                dem++;
            }
        }
        if (sophieu < dem)
        {
            sophieu=dem;
        }
        dem=0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int y=1;y<=n;y++)
        {
             if (phieu[y][i]=='X')
            {
                dem++;
            }
        }
        if (dem == sophieu)
        {
            songuoi++;
            thutu[songuoi]=i;
        }
        dem=0;
    }
    cau.open ("OUT.txt",ios::out);
    cout << songuoi << " " << sophieu << "\n";
    cau << songuoi << " " << sophieu << "\n";
    for (int i=1;i<=songuoi;i++)
    {
        cout << thutu[i] << " ";
        cau << thutu[i] << " ";
    }
    return 0;
}