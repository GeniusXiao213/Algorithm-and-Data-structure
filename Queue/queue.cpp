#include<stdio.h>
#include <iostream>
using namespace std;

template<typename Key,typename Info>
class queue
{
    struct node
    {
        Key key;
        Info info;
        node *next;
    };
public:
    node* front
};