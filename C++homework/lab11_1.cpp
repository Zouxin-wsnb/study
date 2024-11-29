#include<iostream>
#include<vector>
using namespace std;

vector<int> U_array(vector<int> arr1,vector<int> arr2)
{
    vector<int> union_array;
    for(int i=0;i<arr1.size();i++)
    {
        for(int j=0;j<arr2.size();j++)
        {
            if(arr1[i]==arr2[j])
            {
                union_array.push_back(arr1[i]);
                arr1.erase(arr1.begin()+i);
                arr2.erase(arr2.begin()+j);
                i--;
                break;
            }
        }
    }
    return union_array;
}

int main()
{
    int m,n;
    cin >> m ;
    vector<int> arr1(m);
    for(int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    cin >> n;
    vector<int> arr2(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    vector<int> union_array = U_array(arr1,arr2);

    for(int i=0;i<union_array.size();i++)
    {
        for(int j=i+1;j<union_array.size();j++)
        {
            if(union_array[i]>union_array[j])
            {
                int temp = union_array[i];
                union_array[i] = union_array[j];
                union_array[j] = temp;
            }
        }
    }

    cout<<"[";
    for(int i=0;i<union_array.size();i++)
    {
        if(union_array.empty())
        {
            break;
        }
        cout<<union_array[i];
        if(i!=union_array.size()-1)
        {
            cout<<", ";
        }
    }
    cout<<"]";
}