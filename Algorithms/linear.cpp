#include<iostream>
using namespace std;
int main()
{
    int score[]={90,2,3,4,5,6};
    int length=sizeof(score);
    for(int i=0;i<length;i++)
    {
        cout<<score[i]<<",";
    }
    cout<<"please enter the value you want to search"<<endl;
    int value;
    cin>>value;
    bool issearch=0;
    for(int j=0;j<length;j++)
    {
        if(score[j]==value)
        {
            cout<<"index="<<j+1;
            issearch=issearch+1;
            break;
        }
    }
    cout<<"issearch="<<issearch;
    return 0;
}