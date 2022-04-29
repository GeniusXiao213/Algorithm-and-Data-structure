#include "doublyLinkedRing.h"
#include<stdio.h>
#include <iostream>
using namespace std;

void testElement(Ring<int,int>& ring1)
//add at the back,add at the front,pop frint,pop back
{
    ring1.push_back(1,1);
    ring1.push_front(0,0);
    ring1.pop_front();
    ring1.pop_back();
    if(ring1.is_empty())
    {
        cout<<"functions of elements perfrom successfully!"<<endl;
    }
    ring1.push_back(0,0);
    ring1.push_back(1,1);
    ring1.push_back(2,2);

}

void testRingOperation(Ring<int,int>& ring1,Ring<int,int>& ring2)
{
    ring2=ring1;
    if(ring1==ring2&&ring1.size()==ring2.size())
    {
        cout<<"operation '=' performed successfully"<<endl;
    }
    else
    {
        cout<<"operation '=' failed to perform"<<endl;
    }
    ring1.clear();
    cout<<ring1<<endl;
}
int main()
{
    Ring<int,int> ring1;
    Ring<int,int> ring2;
    auto ite1=Ring<int,int>::iterator();
    auto ite2=Ring<int,int>::iterator(*ite1);
    if(ite1==ite2)
    {
        cout<<"copy constructor perform successfully!"<<endl;
    }
    else
    {
        cout<<"copy constructor failed to perfrom!"<<endl;

    }
    auto ite3=Ring<int,int>::iterator(1,1);
    auto ite4=Ring<int,int>::iterator(2,2);
    ite3=ring1.begin();
    ite4=ring1.end();

    //testElement(ring1);
    
    //testRingOperation(ring1,ring2);    
    ring1.print();
    
    return 0;
}