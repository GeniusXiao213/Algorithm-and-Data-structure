#include "SLL.h"
#include<stdio.h>
#include <iostream>
using namespace std;

template<typename key, typename info>
void check(sequence<key,info> &s1)
{
    int checkNum1,checkNum2;
    s1.deleteList(s1);
    if(s1.isEmpty()==1)
    {
        cout<<"succeed in deleting sequence!"<<endl;
        s1.print();
    }
    else{
        cout<<"ERROR in deleting sequence!/n";
    }
    cout<<"Pushing back the elements from 1 to 10, the result sequence is:\n";
    s1.pushBack(1,2);
    s1.pushBack(3,4);
    s1.pushBack(5,6);
    s1.pushBack(7,8);
    s1.pushBack(9,10);
    s1.print();
    cout<<"Get info by key when key==1:"<<endl;
    cout<<s1.getInfo(1)<<endl;
    cout<<"Get key by info when info==4:"<<endl;
    cout<<s1.getKey(4)<<endl;
    if(s1.insertAfter(99,99,7)==1)
    {
        cout<<"Succeed in inserting node!"<<endl;
    }
    else
    {
        cout<<"ERROR in inserting node!"<<endl;
    }
    sequence<int,int> s2;
    s2.pushBack(1,1);
    if(s1==s2)
    {
        cout<<"ERROR in operator ==!"<<endl;
    }
    else
    {
        cout<<"Succeed in performing operator == !"<<endl;
    }
    cout<<"Performing += operator adding s1 and s2 together when s1 is <1,1>:"<<endl;
    s2+=s1;
    s2.print();
    if(s1.swap(s2)==1)
    {
        cout<<"Succeed in swaping two sequences!"<<endl;
    }
    else
    {
        cout<<"ERROR in swaping two sequences!"<<endl;
    }
    if(s1.insertPair(99,99,99,99,4)==1)
    {
        cout<<"Succeed in inserting pair nodes!"<<endl;
    }
    s1.print();
    // if(s2.remove(99)==1)
    // {
    //     cout<<"Succeed in removing node!"<<endl;
    // }
    // else
    // {
    //     cout<<"ERROR in removing node!"<<endl;
    // }
    // s2.copyList(s1);
    // if(s2.isEmpty()==1)
    // {
    //     cout<<"ERROR in copying sequence!"<<endl;
    // }
    // else
    // {
    //     s2.print();
    // }
}

int main()
{
    sequence<int,int> s1;
    check(s1);
}

