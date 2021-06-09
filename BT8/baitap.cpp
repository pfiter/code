#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream cau;
    int n,t,q;
    int thaotac[100][4];
    int vitri[100][2];
    int bang[100][100];
    int socong=0;
    cau.open ("IN.txt",ios::in);
    cau >> n >> t;
    for (int i=1;i<=t;i++)
    {
        for (int y=1;y<=4;y++)
        {
            cau >> thaotac[i][y];
        }
    }
    cau >> q;
    for (int i=1;i<=q;i++)
    {
        for (int y=1;y<=2;y++)
        {
            cau >> vitri[i][y];
        }
    }
    cau.close();
    for (int i=1;i<=n;i++)
    {
        for (int y=1;y<=n;y++)
        {
            bang[i][y]=0;
        }
    }
    for (int m=1;m<=t;m++)
    {
        int y=thaotac[m][4];
        if (thaotac[m][1]==1)
        {
            for (int i=thaotac[m][3];i<=thaotac[m][3]+(thaotac[m][4]-thaotac[m][3]+1)/2-1;i++)
            {
                if ((thaotac[m][4]-thaotac[m][3]+1)%2==0)
                {
                    socong++;
                    bang[thaotac[m][2]][i]+=socong;
                    bang[thaotac[m][2]][y]+=socong;
                    y--;
                }
                else if ((thaotac[m][4]-thaotac[m][3]+1)%2==1)
                {
                    socong++;
                    bang[thaotac[m][2]][i]+=socong;
                    bang[thaotac[m][2]][y]+=socong;
                    y--;
                    if (i==thaotac[m][3]+(thaotac[m][4]-thaotac[m][3]+1)/2-1)
                    {
                        socong++;
                        bang[thaotac[m][2]][i+1]+=socong;
                    }
                }
            }
        }
        else if (thaotac[m][1]==2)
        {
            for (int j=thaotac[m][3];j<=thaotac[m][3]+(thaotac[m][4]-thaotac[m][3]+1)/2-1;j++)
            {
                if ((thaotac[m][4]-thaotac[m][3]+1)%2==0)
                {
                    socong++;
                    bang[j][thaotac[m][2]]+=socong;
                    bang[y][thaotac[m][2]]+=socong;
                    y--;
                }
                else if ((thaotac[m][4]-thaotac[m][3]+1)%2==1)
                {
                    socong++;
                    bang[j][thaotac[m][2]]+=socong;
                    bang[y][thaotac[m][2]]+=socong;
                    y--;
                    if (j==thaotac[m][3]+(thaotac[m][4]-thaotac[m][3]+1)/2-1)
                    {
                        socong++;
                        bang[j+1][thaotac[m][2]]+=socong;
                    }
                }
            }
        }
        socong=0;
    }
    for (int i=1;i<=q;i++)
    {
        cout << bang[vitri[i][1]][vitri[i][2]]<< endl;
    }
    //Xem bang sau khi thuc hien thao tac
    /*for (int i=1;i<=n;i++)
    {
        for (int y=1;y<=n;y++)
        {
            cout << bang[i][y] << " ";
        }
        cout << endl;
    }*/
    return 0;
}