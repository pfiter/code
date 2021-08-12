#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

void xoa (vector <int> &vec,int vitri)
{
    for (int i=vitri;i<vec.size()-1;++i)
    {
        vec[i] = vec[i+1];
    }
    vec.pop_back();
}

int main()
{
    fstream cau;
    cau.open("IN.txt",ios::in);
    int n,k;
    cau >> n >> k;
    --k;
    vector <int> vec;
    for (int i=0;i<n;++i)
    {
        int temp_i;
        cau >> temp_i;
        vec.push_back(temp_i);
    }
    cau.close();
    vector <vector<int>> sapxep;
    for (int y=0;y<1;++y)
    {
        vector <int> temp_v;
        for (int i=0;i<n;++i)
        {
            if (i==k)
            {
                temp_v.push_back(vec[k]);
                continue;
            }
            temp_v.push_back(0);
        }
        sapxep.push_back(temp_v);
    }
    vector <vector<int>> so;
    for (int i=0;i<1;++i)
    {
        vector<int> temp_v;
        for (int y=0;y<n;++y)
        {
            if (y==k)
            {
                continue;
            }
            temp_v.push_back(vec[y]);
        }
        so.push_back(temp_v);
    }
    vector <vector<int>> vitri_trai;
    for (int i=0;i<1;++i)
    {
        vector <int> temp_v;
        temp_v.push_back(k);
        temp_v.push_back(k-1);
        vitri_trai.push_back(temp_v);
    }
    vector <vector<int>> vitri_phai;
    for (int i=0;i<1;++i)
    {
        vector <int> temp_v;
        temp_v.push_back(k);
        temp_v.push_back(k+1);
        vitri_phai.push_back(temp_v);
    }
    //===========================
    for (int i=0;i<sapxep.size();++i)
    {
        vector <vector<int>> distance;
        //============LEFT============
        if (vitri_trai[i][1]>=0)
        {
            //====Finding nearsest number======
            int minDistance;
            vector <int> temp_v;
            for (int y=0;y<so[i].size();++y)
            {
                temp_v.push_back(abs(so[i][y]-sapxep[i][vitri_trai[i][0]]));
                if (y==0)
                {
                    minDistance = temp_v[0];
                    continue;
                }
                if (minDistance > temp_v[y])
                {
                    minDistance = temp_v[y];
                }
            }
            distance.push_back(temp_v);
            int dem=0;
            for (int z=0;z<distance[0].size();++z)
            {
                if (minDistance == distance[0][z])
                {
                    ++dem;
                }
            }
            if (dem==2)
            {
                int dem1=0;
                sapxep.push_back(sapxep[i]);
                so.push_back(so[i]);
                vitri_trai.push_back(vitri_trai[i]);
                vitri_phai.push_back(vitri_phai[i]);
                distance.push_back(distance[0]);
                for (int z=0;z<so[so.size()-1].size();++z)
                {
                    if (distance[0][z] == minDistance && dem1==0)
                    {
                        sapxep[i][vitri_trai[i][1]] = so[i][z];
                        --vitri_trai[i][0];
                        --vitri_trai[i][1];
                        xoa(so[i],z);
                        ++dem1;
                        continue;
                    }
                    if (distance[1][z] == minDistance && dem1==1)
                    {
                        sapxep[sapxep.size()-1][vitri_trai[sapxep.size()-1][1]] = so[sapxep.size()-1][z];
                        --vitri_trai[sapxep.size()-1][0];
                        --vitri_trai[sapxep.size()-1][1];
                        xoa(so[sapxep.size()-1],z);
                        continue;
                    }
                }
            }
            if (dem == 1)
            {
                for (int z=0; z<so[i].size(); ++z)
                {
                    if (minDistance == distance[0][z])
                    {
                        sapxep[i][vitri_trai[i][1]] = so[i][z];
                        xoa(so[i],z);
                        --vitri_trai[i][0];
                        --vitri_trai[i][1];
                    }
                }
            }
            distance.clear();
        }
        //============RIGHT============
        if (vitri_phai[i][1]<sapxep[i].size())
        {
            //====Finding nearsest number======
            int minDistance;
            vector <int> temp_v;
            for (int y=0;y<so[i].size();++y)
            {
                temp_v.push_back(abs(so[i][y]-sapxep[i][vitri_phai[i][0]]));
                if (y==0)
                {
                    minDistance = temp_v[0];
                    continue;
                }
                if (minDistance > temp_v[y])
                {
                    minDistance = temp_v[y];
                }
            }
            distance.push_back(temp_v);
            int dem=0;
            for (int z=0;z<distance[0].size();++z)
            {
                if (minDistance == distance[0][z])
                {
                    ++dem;
                }
            }
            if (dem==2)
            {
                int dem1=0;
                sapxep.push_back(sapxep[i]);
                so.push_back(so[i]);
                vitri_trai.push_back(vitri_trai[i]);
                vitri_phai.push_back(vitri_phai[i]);
                distance.push_back(distance[0]);
                for (int z=0;z<so[so.size()-1].size();++z)
                {
                    if (distance[0][z] == minDistance && dem1==0)
                    {
                        sapxep[i][vitri_phai[i][1]] = so[i][z];
                        ++vitri_phai[i][0];
                        ++vitri_phai[i][1];
                        xoa(so[i],z);
                        ++dem1;
                        continue;
                    }
                    if (distance[1][z] == minDistance && dem1==1)
                    {
                        sapxep[sapxep.size()-1][vitri_phai[sapxep.size()-1][1]] = so[sapxep.size()-1][z];
                        ++vitri_phai[sapxep.size()-1][0];
                        ++vitri_phai[sapxep.size()-1][1];
                        xoa(so[sapxep.size()-1],z);
                        continue;
                    }
                }
            }
            if (dem == 1)
            {
                for (int z=0; z<so[i].size(); ++z)
                {
                    if (minDistance == distance[0][z])
                    {
                        sapxep[i][vitri_phai[i][1]] = so[i][z];
                        xoa(so[i],z);
                        ++vitri_phai[i][0];
                        ++vitri_phai[i][1];
                        //xoa(distance[i],z);
                    }
                }
            }
            distance.clear();
        }
        //==========PRINT==============
        for (int b=0;b<sapxep.size();++b)
        {
            for (int a=0;a<sapxep[b].size();++a)
            {
                cout << sapxep[b][a] << " ";
            }
            cout << endl;
        }
        cout << endl;
        // for (int b=0;b<so.size();++b)
        // {
        //     for (int a=0;a<so[b].size();++a)
        //     {
        //         cout << so[b][a] << " ";
        //     }
        //     cout << endl;
        // }
        // for (int b=0;b<vitri_trai.size();++b)
        // {
        //     for (int a=0;a<vitri_trai[b].size();++a)
        //     {
        //         cout << vitri_trai[b][a] << " ";
        //     }
        //     cout << endl;
        // }
        // for (int b=0;b<vitri_phai.size();++b)
        // {
        //     for (int a=0;a<vitri_phai[b].size();++a)
        //     {
        //         cout << vitri_phai[b][a] << " ";
        //     }
        //     cout << endl;
        // }
        //=========CHECK_LEFT==========
        if (i==sapxep.size()-1)
        {
            int dem2=0;
            for (int y=0;y<vitri_trai.size();++y)
            {
                if (vitri_trai[y][1]<0)
                {
                    ++dem2;
                }
            }
            if (dem2<vitri_trai.size())
            {
                i=-1;
            }
        }
        //=========CHECK_RIGHT==========
        if (i==sapxep.size()-1)
        {
            int dem2=0;
            for (int y=0;y<vitri_phai.size();++y)
            {
                if (vitri_phai[y][1]>sapxep[y].size()-1)
                {
                    ++dem2;
                }
            }
            if (dem2<vitri_phai.size())
            {
                i=-1;
            }
        }
    }
    int minDistanceOfRow;
    for (int i=0;i<sapxep.size();++i)
    {
        int temp_i=0;
        for (int y=0;y<sapxep[i].size()-1;++y)
        {
            temp_i += abs(sapxep[i][y] - sapxep[i][y+1]);
        }
        if (i==0)
        {
            minDistanceOfRow = temp_i;
        }
        if (minDistanceOfRow > temp_i)
        {
            minDistanceOfRow = temp_i;
        }
    }
    cout << endl << minDistanceOfRow ;
    return 0;
}