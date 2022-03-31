#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec1(4,10);
    vector<string> vec2;
    int array1[]={2,3,4,2,4};
    vector<int> vec3(array1,array1+5);
    vec3.push_back(2);
    for(int i=0;i<6;i++)
    {
        cout<<vec3[i]<<endl;
    }
     while(int i=0;i<5;i++)
    {
        
        if(arr[i]<0)
        {
            neg++;
        }
        if(arr[i]>0)
        {
            pos++;
        }
        else {
        zeroNum++;
        }
    }
}