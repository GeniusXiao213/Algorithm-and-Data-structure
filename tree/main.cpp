#include "AVLTree.hpp"
#include "Dictionary.cpp"

#include<string.h>
#include <iostream>
#include <ostream>

using namespace std;

void EXPECT_EQ(string a, string b)
{
    if(a==b)
    {
        cout<<"success!"<<endl;
    }
    else
    {
        cout<<"task fail!"<<endl;
    }
}
 
int main(int argc, char* argv[]){
    //wrapper("dictionary_lexicographical.txt", "dictionary_occurance.txt");
    
	
	//The task results are ejected in text files (in the build directory):

	//dictionary_lexicographical.txt
	//dictionary_occurance.txt
    AVLTree<int, int>* tree;
//test leftroot rotation
    tree->insert(10, 10);
	tree->insert(20, 20);
	string expected = "([10,10],,([20,20],,))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(30, 30);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test left rotation
    tree->insert(60, 60);
	tree->insert(20, 20);
	tree->insert(70, 70);
	tree->insert(10, 10);
	tree->insert(30, 30);
	tree->insert(80, 80);
	tree->insert(25, 25);
	tree->insert(40, 40);
	expected = "([60,60],([20,20],([10,10],,),([30,30],([25,25],,),([40,40],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(50, 50);
	expected = "([60,60],([30,30],([20,20],([10,10],,),([25,25],,)),([40,40],,([50,50],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test rightleft root rotation
    tree->insert(10, 10);
	tree->insert(30, 30);
	expected = "([10,10],,([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(20, 20);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test rightleft rotation
    tree->insert(60, 60);
	tree->insert(20, 20);
	tree->insert(70, 70);
	tree->insert(10, 10);
	tree->insert(30, 30);
	tree->insert(80, 80);
	tree->insert(25, 25);
	tree->insert(40, 40);
	expected = "([60,60],([20,20],([10,10],,),([30,30],([25,25],,),([40,40],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(22, 22);
	expected = "([60,60],([25,25],([20,20],([10,10],,),([22,22],,)),([30,30],,([40,40],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test right root rotation
    tree->insert(30, 30);
	tree->insert(20, 20);
	expected = "([30,30],([20,20],,),)";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(10, 10);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test right rotation
    tree->insert(30, 30);
	tree->insert(20, 20);
	tree->insert(80, 80);
	tree->insert(10, 10);
	tree->insert(60, 60);
	tree->insert(90, 90);
	tree->insert(50, 50);
	tree->insert(70, 70);
	expected = "([30,30],([20,20],([10,10],,),),([80,80],([60,60],([50,50],,),([70,70],,)),([90,90],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(40, 40);
	expected = "([30,30],([20,20],([10,10],,),),([60,60],([50,50],([40,40],,),),([80,80],([70,70],,),([90,90],,))))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test leftright root rotation
    tree->insert(30, 30);
	tree->insert(10, 10);
	expected = "([30,30],([10,10],,),)";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(20, 20);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test left right rotation
    tree->insert(30, 30);
	tree->insert(20, 20);
	tree->insert(80, 80);
	tree->insert(10, 10);
	tree->insert(50, 50);
	tree->insert(90, 90);
	tree->insert(40, 40);
	tree->insert(60, 60);
	expected = "([30,30],([20,20],([10,10],,),),([80,80],([50,50],([40,40],,),([60,60],,)),([90,90],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(70, 70);
	expected = "([30,30],([20,20],([10,10],,),),([60,60],([50,50],([40,40],,),),([80,80],([70,70],,),([90,90],,))))";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
//test find function
    tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
    if(!tree->find(2)&&!tree->find(7)&&!tree->find(12))
    {
        cout<<"task success!"<<endl;
    }
    else
    {
        cout<<"task fail!"<<endl;
    }
    tree->clear();
//test print function
    ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "";
	EXPECT_EQ(s1, s);
    tree->clear();
//test empty tree
    expected = "";
	EXPECT_EQ(expected, tree->toString());
    tree->clear();
};