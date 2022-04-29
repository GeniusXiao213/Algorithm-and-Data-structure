#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            display(head->next);
            cout << head->data << endl;
        }
    }

    node *insertPair() // insert a pair of nodes after the given node
    {

    }
    node *insertEnd(node* head,int data2) //using recursion
    {
        node *newNode=new node;
        newNode->data=data2;
        if(head==nullptr)
        {
            return newNode;
        }
        head->next=insertEnd(head->next,data2);
        return head;
    }
    node *deleteNode(node *head,int num)
    {
        if(num<1||head==nullptr)
        {
            return head;
            //invalid number
        }
        if(num==1)
        {
            node *after=head->next;
            delete(head);
            return after;
        }
        head->next=deleteNode(head->next,num--);
        return head;
    }
    void deleteList(node *head) //delete the whole list using recursion
    {
        if(head==nullptr)
        {
            return;
        }
        deleteList(head->next);
        free(head);
    }

};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.display(a.gethead());
    return 0;
}