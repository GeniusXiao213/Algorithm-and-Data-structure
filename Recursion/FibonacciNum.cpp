#include<stdio.h>
#include <iostream>
using namespace std;


//its Fibonacci number recursive method
//a and b are the first and second element in the fibonacci sequence respectively
int rFibNum(int a, int b,int n)
{
    if(n==1)
    {
        return a;
    }
    else if(n==2)
    {
        return b;
    }
    else
    {
        return rFibNum(a,b,n-1)+rFibNum(a,b,n-2);
    }
}

//Tower of hanoi
//transfer the disks from the first needle to the third needle

void moveDisks(int count,int needle1,int needle2,int needle3)
{
    if(count>0)
    {
        moveDisks(count-1,needle1,needle2,needle3);
        cout<<"move disk"<<count<<"from"<<needle1<<"to"<<needle3<<endl;
        moveDisks(count-1,needle2,needle3,needle1);
    }
}

//coverting a number from decimal to binary

void decTobin(int num,int base)
{
    if(num>0)
    {
        decTobin(num/base,base);
        cout<<num%base;
    }
}