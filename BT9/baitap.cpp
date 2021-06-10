#include <iostream>
#include <fstream>

using namespace std;
int maxso(int arr[][4], int so, int kieu)
{
    if (kieu==1)
    {
        int somax = arr[1][1];
        for (int i=1;i<=so;i++)
        {
            if (somax<arr[i][1])
            {
                somax = arr[i][1];
            }
        }
    return somax;
    }
    else if (kieu==2)
    {
        int somax = arr[1][2];
        for (int i=1;i<=so;i++)
        {
            if (somax<arr[i][2])
            {
                somax = arr[i][2];
            }
        }
    return somax;
    }
}

int main()
{
    fstream cau;
    int sotran;
    int ketqua[100];
    int tinhchat[100][4];
    int dem=0;
    int tong=0;
    int demthang=0;
    int demhoa=0;
    int dem1=0;
    cau.open ("IN.txt",ios::in);
    cau >> sotran;
    for (int i=1;i<=sotran;i++)
    {
        cau >> ketqua[i];
    }
    cau.close();
    for (int i=1;i<=sotran;i++)
    {
        if (ketqua[i]==0)
        {
            dem1++;
            tinhchat[dem1][1]=dem;
            tinhchat[dem1][2]=tong;
            tinhchat[dem1][3]=demthang;
            tinhchat[dem1][4]=demhoa;
            dem=0;
            tong=0;
            demthang=0;
            demhoa=0;
            continue;
        }
        dem++;
        tong+=ketqua[i];
        if (ketqua[i]==3)
        {
            demthang++;
        }
        else if (ketqua[i]==1)
        {
            demhoa++;
        }
    }
    dem=0;
    for (int i=1;i<=sotran;i++)
    {
        if (tinhchat[i][1]==maxso(tinhchat,dem1,1))
        {
            dem++;
        }
    }
    cau.open ("OUT.txt",ios::out);
    if (dem==1)
    {
        for (int i=1;i<=dem1;i++)
        {
            if (tinhchat[i][1]==maxso(tinhchat,dem1,1))
            {
                cout << tinhchat[i][1] << endl;
                cout << tinhchat[i][2] << endl;
                cout << tinhchat[i][3] << " ";
                cout << tinhchat[i][4];
                cau << tinhchat[i][1] << endl;
                cau << tinhchat[i][2] << endl;
                cau << tinhchat[i][3] << " ";
                cau << tinhchat[i][4];
            }
        }
    }
    else if (dem>1)
    {
        for (int i=1;i<=dem1;i++)
        {
            if (tinhchat[i][2]==maxso(tinhchat,dem1,2))
            {
                cout << tinhchat[i][1] << endl;
                cout << tinhchat[i][2] << endl;
                cout << tinhchat[i][3] << " ";
                cout << tinhchat[i][4];
                cau << tinhchat[i][1] << endl;
                cau << tinhchat[i][2] << endl;
                cau << tinhchat[i][3] << " ";
                cau << tinhchat[i][4];
                break;
            }
        }
    }
    cau.close();
    return 0;
}