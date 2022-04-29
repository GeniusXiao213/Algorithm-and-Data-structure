#include<iostream>
#include<stdio.h>
using namespace std;
// int main()
// {
//     int score[]={0,2,4,5,3,10};
//     int length=sizeof(score);
//     sortMethod1(score,length);
//     for(int i=0;i<length;i++)
//     {
//         cout<<score[i]<<",";
//     }
//     return 0;
// }

void sortMethod1(int score[],int length)   //bubble sorting Algorithm
{
    for(int i=0;i<length-1;i++)
    {
        bool isSwap=false;
        for(int j=0;j<length-i-1;j++)
        {
            if(score[i]>score[j+1])
            {
                int change=score[i];
                score[i]=score[j+1];
                score[j+1]=change;
                isSwap=true;
            }
        }
        if(!isSwap)
        {
            break;
        }
    }
}

void sortingMethod2(int score[],int length)  //select sorting algorithm
{   
    for(int i=0;i<length-1;i++)
    {
        int minIndex=i;
        int minValue=score[minIndex];
        for(int j=i;i<length-1;j++)
        {
            if(minValue>score[j+1])
            {
                minValue=score[j+1];
                minIndex=j+1;
            }
        }
        if(i!=minIndex)
        {
            int temp=score[i];
            score[i]=score[minIndex];
            score[minIndex]=temp;
        }
    }
}

void selectionSort(int list[],int len)  //same as above
{
    for(int i=0;i<len-1;i++)
    {
        int minvalue=list[i];
        int minindex=i;
        for(int j=i+1;j<len;j++)
        {
            if(minvalue>list[j])
            {
                int temp=list[j];
                list[j]=minvalue;
                minvalue=temp;
                minindex=j;
            }
        }
    }
}

void insertsort(int list[],int len)
{
    for(int i=1;i<len;i++)
    {
        int temp=list[i];
        int j=i;
        while(j>0&&list[j-1]>temp)
        {
            list[j]=list[j-1];
            j--;
        }
        list[j]=temp;
    }
}

int main()
{
    int list[]={1,34,2,5,3,7};
    insertsort(list,6);
    for(int i=0;i<6;i++)
    {
        int j=list[i];
        cout<<j<<" ";
    }
}