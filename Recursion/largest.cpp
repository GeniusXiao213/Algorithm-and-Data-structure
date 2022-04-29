#include<stdio.h>
#include <iostream>
using namespace std;

int largest(const int list[],int lower,int upper)
{
    int max;
    if(lower==upper)
    {
        return list[lower];
    }
    else
    {
        max=largest(list, lower+1, upper);
        if(list[lower]>max)
        {
            max=list[lower];
        }
    }
    return max;
}

int main()
{
    int arr[10]={2,3,4,5,2,3,4,2,3,4};
    cout<<largest(arr,0,9);
    return 0;
}