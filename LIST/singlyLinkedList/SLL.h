#pragma once

#include <iostream>
#include<stdio.h>
using namespace std;

template<typename key, typename info>
class sequence
{
private:
    struct node
    {
        key k;
        info i;
        node *next;
public:
        node(const key& kk, const info& ii, node* nex);
        ~node();
        key get_key() const
        {
            return k;
        }
        info get_info() const
        {
            return i;
        }

    };
    node *head;
    node *tail;
public:
    sequence();
    //sequence(const key&k,const info&i);
    ~sequence();
    void pushBack(const key& k,const info& i);
    void deleteList(sequence& s1);  //function to implement deconstuctor
    bool isEmpty() const;
    sequence copyList(const sequence<key,info>& other);
    info getInfo(const key& k,int occurance=1)const;
    key getKey(const info& i,int occurance=1)const;
    bool insertAfter(const key& k,const info& i,const key& where,int occurance=1);
    bool insertBefore(const key& k,const info& i,const key& where,int occurance=1);

    bool insertPair(const key& k1,const info& i1,const key& k2,const info& i2,const key& where,int occurance=1);
    bool removePair(const key& which);
//insert elements in the middle of list

    //void insertFront(const key&,const info&);
    //void insertBack(const key&,const info&);
//These functions are similar to insertAfter and insertBeofre so im not gonna overwrite it again

//insert elements in the front/back of the linked list
    bool remove(const key& which,int occurance=1);
    bool searchKey(const key& what, int occurance=1) const; //search key element
    bool searchInfo(const info& what,int occurance=1) const;

    sequence& operator+=(const sequence<key,info>& otherList);
    bool operator==(const sequence<key,info>& otherList) const;
    int size() const;
    bool swap(sequence&  otherList);

    info getInfoByIndex(int i);
    key getKeyByIndex(int j);//functions used to implement shuffle method

    void print() const;
    //It can also be implemented as following:

    // template<typename key, typename info>
    // friend ostream& operator<<(ostream& os, const sequence<info,key>& s1);
    //     template<typename key,typename info>
    // ostream& operator<<(std::ostream& os, const sequence<key,info>& s1)
    // {
    //     if(s1.isEmpty()==1)
    //     {
    //         cout<<"It is an empty sequence!"<<endl;
    //     }
    //     else
    //     {
    //         for(auto* temp = s1.head; temp != nullptr; temp = temp->next)
    //         {
    //             os<<"<"<<temp->k<<","<<temp->i<<"> ";
    //             temp=temp->temp;
    //         }
    //     }
        
    // }
};

template<typename key,typename info>
bool sequence<key,info>::swap(sequence<key,info>& otherList)
{
    node *tempHead=head;
    node *tempTail=tail;
    head=otherList.head;
    tail=otherList.tail;
    otherList.head=tempHead;
    otherList.tail=tempTail;
    return true;
}

template<typename key,typename info>
int sequence<key,info>::size() const
{
    int len=0;
    node *current=head;
    if(this->isEmpty())
    {
        return 0;
    }
    while(current!=nullptr)
    {
        len++;
        current=current->next;
    }
    return len;
}

template<typename key,typename info>
bool sequence<key,info>::remove(const key& which,int occurance)
{
    node *before=head; //a node just before the current node
    node *current=before->next;
    if(head->k==which)   //when the first note is the one we are looking for
    {
        head=head->next;
        before->~node();
        return true;
    }
    while(current!=nullptr)
    {
        if(current->k==which)
        {
            if(tail==current)
            {
                tail=before;
            }
            else
            {
                before->next=current->next;
            }
            current->~node();
            return true;   
        }
        current=current->next;
        before=before->next;
    }
    return false;
}

template<typename key,typename info>
bool sequence<key,info>::removePair(const key& which)
{
    node* before=head;
    node* current=head->next;
    if(isEmpty())
    {
        return false;
    }
    if(head->k==which)
    {
        head=head->next;
        delete before;
        return true;
    }
    while(current)
    {
        if(current->k==which)
        {
            before->next=current->next->next;
            node *temp=current;
            delete current;
            delete temp->next;
            return true;
        }
        current=current->next;
        before=before->next;
    }
    return false;
}
template<typename key,typename info>
bool sequence<key,info>::searchInfo(const info& what,int occurance) const
{
    node *current=head;
    while(current!=nullptr)
    {
        if(current->i==what)
        {
            return true;
        }
        current=current->next;
    }
    return false;
}

template<typename key,typename info>
bool sequence<key,info>::searchKey(const key& what,int occurance) const
{
    node *current=head;
    while(current!=nullptr)
    {
        if(current->k==what)
        {
            return true;
        }
        current=current->next;
    }
    return false;
}

template<typename key,typename info>
bool sequence<key,info>::insertAfter(const key& k,const info& i,const key& where,int occurance)
{
        node *current=head;
        node *newNode= new node(k,i,nullptr);
        if(this->isEmpty())
        {
            tail=head=newNode;
            return true;
        }
        while(current!=nullptr)
        {
            
            if(current->k==where)
            {
                if(current==tail)
                {
                    pushBack(k,i);
                    return true;
                }
                else
                {
                    newNode->next=current->next;
                    current->next=newNode;
                    return true;
                }
            }
            current=current->next;
        }
        return false;
}

template<typename key,typename info>
bool sequence<key,info>::insertPair(const key& k1,const info& i1,const key& k2,const info& i2,const key& where,int occurance) 
{
    node *newNode1=new node(k1,i1,nullptr);
    node *newNode2=new node(k2,i2,nullptr);
    if(isEmpty())
    {
        head=newNode1;
        newNode1->next=newNode2;
        tail=newNode2;
    }
    node *current=this->head;
    while(current)
    {
        if(current->k==where)
        {
            if(current==tail||current==head)
            {
            current->next=newNode1;
            newNode1->next=newNode2;
            tail=newNode2;
            return true;
            }
            if(current->next==tail)
            {
            current->next=newNode1;
            newNode1->next=newNode2;
            newNode2->next=tail;
            return true;

            }
            node *temp=current->next;
            current->next=newNode1;
            newNode1->next=newNode2;
            newNode2->next=temp;
            return true;
        }
        current=current->next;
    }
    return false;
}
template<typename key,typename info>
bool sequence<key,info>::insertBefore(const key& k,const info& i,const key& where,int occurance) 
{
    node *before=head;
    node *current=before->next;
    node *newNode=new node(k,i,nullptr);
    if(this->isEmpty())
    {
        tail=head=newNode;
        return true;
    }
    if(head->k==where)
    {
        newNode->next=head;
        head=newNode;
        return true;
    }
    while(current!=nullptr)
    {
        if(current->k==where)
        {
            before->next=newNode;
            newNode->next=current;
            return true;
        }
        current=current->next;
        before=before->next;
    }
    return false;

}

template<typename key,typename info>
key sequence<key,info>::getKey(const info& i,int occurance) const
{
    node *current=head;
    while(current!=nullptr)
    {
        if(current->i==i)
        {
            current->get_key();
        }
        current=current->next;
    }
    return -1;//can not find the element
}

template<typename key,typename info>
info sequence<key,info>::getInfo(const key& k,int occurance) const
{
    node *current=head;
    while(current!=nullptr)
    {
        if(current->k==k)
        {
            return current->get_info();
        }
        current=current->next;
    }
    return -1;//can not find the element
    
}


template<typename key,typename info>
sequence<key,info> sequence<key,info>::copyList(const sequence<key,info>& otherList)
{
    if(this->isEmpty()!=1)
    {
        deleteList(*this);
    }
    if(otherList.isEmpty())
    {
        head=nullptr;
        tail=nullptr;
        return *this;
    }
    else
    {
        node *current=otherList.head;
        node *newNode=new node(current->k,current->i,nullptr);
        head=tail=newNode;
        current=current->next;
        while(current!=nullptr)
        {
            this->pushBack(current->k,current->i);
            current=current->next;

        }
        return *this;
    }
}
template<typename key,typename info>
sequence<key,info>::node::node(const key& kk, const info& ii, node* nex)
{
    k=kk;
    i=ii;
    next=nex;
}

template<typename key,typename info>
sequence<key,info>::node::~node()
{
    delete this;
}

template<typename key,typename info>
bool sequence<key,info>::isEmpty() const
{
    return (head==nullptr);
}

template<typename key,typename info>
void sequence<key,info>::deleteList(sequence<key,info>& s1)
{
    node* current;
    current=s1.head;
    while(s1.head!=nullptr)
    {
        current->~node();
        current=current->next;
    }
    s1.tail=nullptr;
}

template<typename key,typename info>
sequence<key,info>::~sequence()
{
    deleteList(*this);
}

template<typename key,typename info>
sequence<key,info>::sequence()
{
    head=nullptr;
    tail=nullptr;
}

template<typename key,typename info>
void sequence<key,info>::pushBack(const key& kk, const info& ii)
{
    if(isEmpty())
    {
        node *newNode1=new node(kk,ii,nullptr);
        tail=head=newNode1;
    }
    else
    {
        node *newNode2=new node(kk,ii,nullptr);
        tail->next=newNode2;
        tail=newNode2;
    }
}

template<typename key,typename info>
void sequence<key,info>::print() const
{
    if(isEmpty()==1)
    {
        cout<<"It is an empty sequence!"<<endl;
    }
    else
    {
        node *current=head;
        while(current!=nullptr)
        {
            cout<<'<'<<current->get_key()<<','<<current->get_info()<<'>'<<' ';
            current=current->next;
        }
        cout<<endl;
    }
    
}

template<typename key,typename info>
bool sequence<key,info>::operator==(const sequence<key,info>& otherList) const
{
    node *current1=head;
    node *current2=otherList.head;
    
    while(current1!=nullptr&&current2!=nullptr)
    {
        if(current1->get_key()!=current2->get_key()||current1->get_info()!=current2->get_info())
        {
            return false;
        }
        current1=current1->next;
        current2=current2->next;
    }
    return true;
}

template<typename key,typename info>
sequence<key,info>& sequence<key,info>::operator+=(const sequence<key,info>& otherList)
{
    for(node* temp = otherList.head; temp != nullptr; temp = temp->next)
        this->pushBack(temp->k, temp->i);
    return *this;
}

template<typename key,typename info>
info sequence<key,info>::getInfoByIndex(int i)
{
    node *current=head;
    for(int m=0;m<i;m++)
    {
        current=current->next;
    }
    return current->i;
}

template<typename key,typename info>
key sequence<key,info>::getKeyByIndex(int j)
{
    node *current=head;
    for(int m=0;m<j;m++)
    {
        current=current->next;
    }
    return current->k;
}


            //shuffle function!!!
template<typename key,typename info>
sequence<key,info> shuffle(const sequence<key,info> &s1,int len1,const sequence<key,info> &s2,int len2,int repeat)
{
    int s1Len=s1.size();
    int s2Len=s2.size();
    sequence<key,info> resultSeq;
    key num1,num3;
    info num2,num4;
    int index1=0,index2=0;
    if(len1>s1Len||len2>s2Len||repeat<=0||repeat>s1Len||repeat>s2Len)
    {
        cout<<"Invaild value!!"<<endl;
        return resultSeq;
        //return an empty sequence
    }
    for(int i=0;i<repeat;i++)
    {
        for(int j=0;j<len1;j++)
        {
            if(s1Len!=0)
            {
            resultSeq.pushBack(s1.getKeyByIndex(index1),s1.getInfoByIndex(index1));
            s1Len--;
            index1++;
            }
            else
            {
                break;
            }
        }
        for(int m=0;m<len2;m++)
        {
            if(s2Len!=0)
            {
            resultSeq.pushBack(s2.getKeyByIndex(index2),s2.getInfoByIndex(index2));
            s2Len--;
            index2++;
            }
            else
            {
                break;
            }
        }
        if(s1Len==0&&s2Len==0)
        {
            break;
        }
    }
    return resultSeq;
}