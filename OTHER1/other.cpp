#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    fflush(stdin);
    vector <string> arr;
    // Lay gia tri cho chuoi
    for (int i=0;i<n;++i)
    {
        string temp_s;
        getline (cin,temp_s);
        arr.push_back(temp_s);
    }
    // Tach cac gia tri cua the tag
    vector <vector<string>> arr2;
    for (int i=0;i<n;++i)
    {
        vector <string> temp_v;
        int dem2=0;
        string temp_s;
        do
        {
            if (arr[i][dem2] == '<')
            {
                ++dem2;
            }
            temp_s.push_back(arr[i][dem2]);
            if (arr[i][dem2+1] == ' ')
            {
                ++dem2;
                temp_v.push_back(temp_s);
                temp_s.clear();
            }
            if (arr[i][dem2] == ' ' && arr[i][dem2+1] == '"')
            {
                ++dem2;
            }
            if ( arr[i][dem2+1] == '"' && arr[i][dem2+2] == '>')
            {
                temp_v.push_back(temp_s);
                temp_s.clear();
                break;
            }
            if (arr[i][dem2+1] == '"' && arr[i][dem2+2] == ' ')
            {
                temp_v.push_back(temp_s);
                temp_s.clear();
                dem2+=2;
            }
            if(arr[i][dem2+1] == '>')
            {
                temp_v.push_back(temp_s);
                temp_s.clear();
                break;
            }
            ++dem2;
        }while (arr[i][dem2] != '>');
        arr2.push_back(temp_v);
        temp_v.clear();
    }
    // Xuat gia tri da tach (kiem tra)
    /*for (int i=0;i<arr2.size();++i)
    {
        for (int y=0;y<arr2[i].size();++y)
        {
            cout << arr2[i][y] << " ";
        }
    }*/
    // Lay gia tri cho chuoi
    vector <string> arr3;
    for (int i=0; i<q; ++i)
    {
        string temp_s;
        getline (cin,temp_s);
        arr3.push_back(temp_s);
    }
    //Tach gia tri cua chuoi
    vector <vector<string>> arr4;
    for (int i=0; i<q; ++i)
    {
        vector <string> temp_v;
        int dem=0;
        string temp_s;
        do
        {
            temp_s.push_back(arr3[i][dem]);
            /*if (arr3[i][dem+1] == '.')
            {
                temp_v.push_back(temp_s);
                temp_s.clear();
                ++dem;
                temp_v.push_back(".");
            }*/
            if (arr3[i][dem+1] == '~')
            {
                temp_v.push_back(temp_s);
                temp_s.clear();
                ++dem;
                temp_v.push_back("~");
            }
            if (arr3[i][dem+1] == '\0')
            {
                temp_v.push_back(temp_s);
                temp_s.clear();
            }
            ++dem;
        }while(arr3[i][dem] != '\0');
        arr4.push_back(temp_v);
        temp_v.clear();
    }
    // Xuat gia tri da tach (kiem tra)
    /*for (int i=0;i<arr4.size();++i)
    {
        for (int y=0;y<arr4[i].size();++y)
        {
            cout << arr4[i][y] << " ";
        }
    }*/
    //Sap xep lai chuoi n
    vector <vector<int>> sapxep;
    for (int i=0; i<n; ++i)
    {
        vector <int> temp_v;
        for (int y=1; y<n; ++y)
        {
            if ("/"+arr2[i][0] == arr2[y][0])
            {
                temp_v.push_back(i);
                temp_v.push_back(y);
            }
        }
        if (!temp_v.empty())
        {
            sapxep.push_back(temp_v);
        }
        temp_v.clear();
    }
    for (int i=0; i<1; ++i)
    {
        vector<string> temp_v;
        if (i==0)
        {
            temp_v.push_back(arr2[sapxep[i][0]][0]);
            temp_v.push_back(".");
            for (int y=i+1;y<sapxep.size();++y)
            {
                if (sapxep[y][0] > sapxep[y-1][0] && sapxep[y][1] < sapxep[y-1][1])
                {
                    temp_v.push_back(arr2[sapxep[y][0]][0]);
                    temp_v.push_back(".");
                    for (int z=0;z<temp_v.size()-1;++z)
                    {
                        if (z==0)
                        {
                            arr2[sapxep[y][0]][0].clear();
                        }
                        arr2[sapxep[y][0]][0].insert(arr2[sapxep[y][0]][0].size(),temp_v[z]);
                    }
                }
                else if (sapxep[y][0] > sapxep[y-1][1])
                {
                    for (int x=0;x<sapxep[y][0]-sapxep[y-1][1];++x)
                    {
                        temp_v.pop_back();
                        temp_v.pop_back();
                    }
                    temp_v.push_back(arr2[sapxep[y][0]][0]);
                    temp_v.push_back(".");
                    for (int z=0;z<temp_v.size()-1;++z)
                    {
                        if (z==0)
                        {
                            arr2[sapxep[y][0]][0].clear();
                        }
                        arr2[sapxep[y][0]][0].insert(arr2[sapxep[y][0]][0].size(),temp_v[z]);
                    }
                }
            }
        }
    }
    // Tao ket qua cho dau ra (output)
    for (int i=0;i<q;++i)
    {
        for (int y=0;y<n;++y)
        {
            if (arr2[y][0] == arr4[i][0])
            {
                int dem=1;
                if (arr2[y].size() == 1)
                {
                    cout << "Not Found!" << endl;
                    break;
                }
                do
                {
                    if (arr4[i][2] == arr2[y][dem])
                    {
                        cout << arr2[y][dem+2] << endl;
                        break;
                    }
                    dem+=3;
                    if (arr4[i][2] != arr2[y][dem] && dem ==  arr2[y].size())
                    {
                        cout << "Not Found!" << endl;
                    }
                } while (dem != arr2[y].size());
                break;
            }
            else if (arr2[y][0] != arr4[i][0] && y==n-1)
            {
                cout << "Not Found!" << endl;
            }
        }
    }
    return 0;
}