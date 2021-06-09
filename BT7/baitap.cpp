#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream cau;
    int n,m;
    char delrow[100][100];
    int dem=0;
    int dem1=0;
    int xoahang=0;
    cau.open ("IN.txt",ios::in);
    cau >> n >> m;
    for (int i=1;i<=n;i++)
    {
        for (int y=1;y<=m;y++)
        {
            cau >> delrow[i][y];
        }
    }
    cau.close();
    for (int x=1;x<=m;x++)
    {
        for (int i=1;i<=m;i++)
        {
            for (int j=m;j>i;j--)
            {
                dem1++;
                for (int y=x;y<=n;y++)
                {
                    if (delrow[y][i]!=delrow[y][j])
                    {
                        dem++;
                        break;
                    }
                }
            }
        }
        if(dem1==dem)
        {
            xoahang++;

        }
        else if (dem1!=dem)
        {
            xoahang--;
            break;
        }
        dem1=0;
        dem=0;
    }
    cau.open ("OUT.txt",ios::out);
    cau << xoahang;
    cout << xoahang;
    cau.close();
    return 0;
}