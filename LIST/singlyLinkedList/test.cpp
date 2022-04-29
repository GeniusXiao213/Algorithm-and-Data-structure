#include "list.h"
#include<stdio.h>
#include <iostream>
using namespace std;

template<typename key,typename info>
void testStru(sequence<key,info> &seq1,sequence<key,info> &seq2,sequence<key,info> &seq3)
{
    key k;
    info i;
    bool tf;
    seq1.pushBack(1,2);
    seq1.pushBack(3,4);
    seq1.pushBack(5,6);
    seq1.pushBack(7,8);
    seq1.pushBack(9,10);
           // cout<<"Enter numbers ending with -999."<<endl;
           // cout<<"Enter key:"<<endl;
           // cin>>k;
           // cout<<"Enter info:"<<endl;
           // cin>>i;
           // while(k!=-999||i!=-999)
           // {
           //     seq1.push(k,i);
           //     cin>>k;
           //     cin>>i;
           // }  
           //initialization of the sequence by entering elements
    cout<<"Sequence 1 is:"<<endl;
    cout<<seq1<<endl;
    seq2.copyList(seq1);
    cout<<"After copy sequence 1 to sequence 2,sequence 2 is as following:"<<endl;
    cout<<seq2<<endl;
    tf=seq1.swap(seq2);
    cout<<"swap action between sequence 1 and sequence 2 is"<<tf<<endl;
}
//test the constructors and destructor of the class

template<typename key,typename info>
void testShuffle(sequence<key,info> &s1,sequence<key,info> &s2)
{   
    s2.pushBack(1,2);
    s2.pushBack(3,4);
    s2.pushBack(7,8);
    s2.pushBack(9,10);
    sequence<key,info> res;
    int i,j,m;
    bool tf;
    cout<<"Input len1:"<<endl;
    cin>>i;
    cout<<"Input len2:"<<endl;
    cin>>j;
    cout<<"Input repeat:"<<endl;
    cin>>m;
    res=shuffle(s1,i,s2,j,m);
    cout<<"The result sequence after shuffle is:"<<endl;
    cout<<res<<endl;
}
//this is used to test the shuffle() function

template<typename key,typename info>
void testOperators(sequence<key,info> &l1,sequence<key,info> &l2,sequence<key,info> &l3)
{
    cout<<"check if the two sequences are the same:"<<endl;
    cout<<(l1==l2)<<endl;
    l1+=l2;
    cout<<"after add the two sequences together,the result sequence is:"<<endl;
    cout<<l1<<endl;
}
//test the operators functions including ==,+=,+ and =

template<typename key,typename info>
void testInsertFunctions(sequence<key,info> &l1)
{
    key where,k;
    info i;
    cout<<"TEST INSERTAFTER: input where do you want to insert the node:"<<endl;
    cin>>where;
    cout<<"input the key and info:"<<endl;
    cin>>k>>i;
    l1.insertAfter(k,i,where);
    cout<<"the result sequence is:"<<endl;
    cout<<l1<<endl;
    cout<<"TEST INSERTBEFORE: input where do you want to insert the node:"<<endl;
    cin>>where;
    cout<<"input the key and info:"<<endl;
    cin>>k>>i;
    l1.insertBefore(k,i,where);
    cout<<"the result sequence is:"<<endl;
    cout<<l1<<endl;
}
//test insertAfter() and insertBefore()

template<typename key,typename info>
void testElem(sequence<key,info> &l1)
{
    key what;
    info find;
    key find2;
    bool ft;
    cout<<"input the key you want to find:"<<endl;
    cin>>what;
    ft=l1.searchKey(what);
    if(ft==true)
    {
        find=l1.getInfo(what);
        cout<<"info="<<find<<endl;
    }
    cout<<"input the info you want to find:"<<endl;
    cin>>what;
    ft=l1.searchInfo(what);
    if(ft==true)
    {
        find2=l1.getKey(what);
        cout<<"info="<<find2<<endl;
    }
    cout<<"input the element you want to remove it from the sequence:"<<endl;
    cin>>what;
    ft=l1.remove(what);
    cout<<"remove action is "<<ft<<endl;
    if(ft==true)
    {
        cout<<"after remove the element from the sequence,the result sequence is: "<<endl;
        cout<<l1<<endl;
    }
}
//test getKey(),remove() and search()

int main()
{
    sequence<int,int> seq1,seq2,seq3;
    testOperators(seq1,seq2,seq3);
    testStru<int,int>(seq1,seq2,seq3);
    testInsertFunctions(seq1);
    testElem(seq1);
    testShuffle(seq1,seq2);
    return 0;
}