#include <iostream>
#include <fstream>

using namespace std;

void tinhchuso(int so, int chuso[],int &dem)
{
    int chusoao[100];
    do
    {
        dem++;
        chusoao[dem]=so%10;
        so=so/10;
    }while (so!=0);
    int dem1=dem;
    for (int i=1;i<=dem;i++)
    {
        chuso[i]=chusoao[dem1];
        dem1--;
    }
}

void xoadau(int chusoao[], int &so)
{
    for (int i=1;i<=so;i++)
    {
        chusoao[i]=chusoao[i+1];
    }
    so--;
}

void copychuso (int chusocopy[], int chusoao[], int so)
{
    for (int i=1;i<=so;i++)
    {
        chusocopy[i]=chusoao[i];
    }
}

int main()
{
    fstream cau;
    int a,b;
    int chusoa[100];
    int chusob[100];
    int chusoacopy[100];
    int chusobcopy[100];
    int chusobe[100];
    int chusolon[100];
    int dem=0;
    int dema=0;
    int demacopy;
    int demb=0;
    int dembcopy;
    int dembe=0;
    int demlon=0;
    int demchuso;
    cau.open ("IN.txt",ios::in);
    cau >> a >> b;
    cau.close();
    tinhchuso(a,chusoa,dema);
    tinhchuso(b,chusob,demb);
    demchuso = dema + demb;
    demacopy = dema;
    dembcopy = demb;
    copychuso(chusoacopy,chusoa,demacopy);
    copychuso(chusobcopy,chusob,dembcopy);
    // Tinh so be
    for (int i=1;i<=demchuso;i++)
    {
        if (demb==0)
        {
            dembe++;
            chusobe[dembe]=chusoa[1];
            xoadau(chusoa,dema);
            continue;
        }
        if (dema==0)
        {
            dembe++;
            chusobe[dembe]=chusob[1];
            xoadau(chusob,demb);
            continue;
        }
        if (chusoa[1]<chusob[1])
        {
            dembe++;
            chusobe[dembe]=chusoa[1];
            xoadau(chusoa,dema);
            continue;
        }
        else if (chusoa[1]>chusob[1])
        {
            dembe++;
            chusobe[dembe]=chusob[1];
            xoadau(chusob,demb);
            continue;
        }
        else if (chusoa[1]==chusob[1])
        {
            if (dema>demb)
            {
                for (int y=1;y<=demb;y++)
                {
                    if (chusoa[y]<chusob[y])
                    {
                        dembe++;
                        chusobe[dembe]=chusoa[1];
                        xoadau(chusoa,dema);
                        dem++;
                        continue;
                    }
                    else if (chusoa[y]>chusob[y])
                    {
                        dembe++;
                        chusobe[dembe]=chusob[1];
                        xoadau(chusob,demb);
                        dem++;
                        continue;
                    }
                    if (y==demb && dem==0)
                    {
                        dembe++;
                        chusobe[dembe]=chusob[1];
                        xoadau(chusob,demb);
                        continue;
                    }
                }
                dem=0;
            }
            else if (dema<=demb)
            {
                for (int j=1;j<=dema;j++)
                {
                    if (chusoa[j]<chusob[j])
                    {
                        dembe++;
                        chusobe[dembe]=chusoa[1];
                        xoadau(chusoa,dema);
                        dem++;
                        continue;
                    }
                    else if (chusoa[j]>chusob[j])
                    {
                        dembe++;
                        chusobe[dembe]=chusob[1];
                        xoadau(chusob,demb);
                        dem++;
                        continue;
                    }
                    if (j==dema && dem==0)
                    {
                        dembe++;
                        chusobe[dembe]=chusoa[1];
                        xoadau(chusoa,dema);
                        continue;
                    }
                }
                dem=0;
            }
        }
    }
    //Tinh so lon
    for (int i=1;i<=demchuso;i++)
    {
        if (dembcopy==0)
        {
            demlon++;
            chusolon[demlon]=chusoacopy[1];
            xoadau(chusoacopy,demacopy);
            continue;
        }
        if (demacopy==0)
        {
            demlon++;
            chusolon[demlon]=chusobcopy[1];
            xoadau(chusobcopy,dembcopy);
            continue;
        }
        if (chusoacopy[1]<chusobcopy[1])
        {
            demlon++;
            chusolon[demlon]=chusobcopy[1];
            xoadau(chusobcopy,dembcopy);
            continue;
        }
        else if (chusoacopy[1]>chusobcopy[1])
        {
            demlon++;
            chusolon[demlon]=chusoacopy[1];
            xoadau(chusoacopy,demacopy);
            continue;
        }
        else if (chusoacopy[1]==chusobcopy[1])
        {
            if (demacopy>dembcopy)
            {
                for (int y=1;y<=dembcopy;y++)
                {
                    if (chusoacopy[y]<chusobcopy[y])
                    {
                        demlon++;
                        chusolon[demlon]=chusobcopy[1];
                        xoadau(chusobcopy,dembcopy);
                        dem++;
                        continue;
                    }
                    else if (chusoacopy[y]>chusobcopy[y])
                    {
                        demlon++;
                        chusolon[demlon]=chusoacopy[1];
                        xoadau(chusoacopy,demacopy);
                        dem++;
                        continue;
                    }
                    if (y==dembcopy && dem==0)
                    {
                        demlon++;
                        chusolon[demlon]=chusobcopy[1];
                        xoadau(chusobcopy,dembcopy);
                        continue;
                    }
                }
                dem=0;
            }
            else if (demacopy<=dembcopy)
            {
                for (int j=1;j<=demacopy;j++)
                {
                    if (chusoacopy[j]<chusobcopy[j])
                    {
                        demlon++;
                        chusolon[demlon]=chusobcopy[1];
                        xoadau(chusobcopy,dembcopy);
                        dem++;
                        continue;
                    }
                    else if (chusoacopy[j]>chusobcopy[j])
                    {
                        demlon++;
                        chusolon[demlon]=chusoacopy[1];
                        xoadau(chusoacopy,demacopy);
                        dem++;
                        continue;
                    }
                    if (j==demacopy && dem==0)
                    {
                        demlon++;
                        chusolon[demlon]=chusoacopy[1];
                        xoadau(chusoacopy,demacopy);
                        continue;
                    }
                }
                dem=0;
            }
        }
    }
    //Xuat ra ket qua
    cau.open ("OUT.txt",ios::out);
    for (int i=1;i<=demchuso;i++)
    {
        cout << chusobe[i] << " ";
        cau << chusobe[i];
    }
    cout << endl;
    cau << "\n";
    for (int i=1;i<=demchuso;i++)
    {
        cout << chusolon[i] << " ";
        cau << chusolon[i];
    }
    return 0;
}