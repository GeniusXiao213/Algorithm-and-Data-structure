#include<algorithm>
#include<vector>
#include<iterator>
#include<iostream>
using namespace std;

int main()
{
    int array[]={5,6,8,4,40,36};
    vector<int> veclist(6);
    ostream_iterator<int> screen(cout," ");
    copy(array,array+6,screen);
    return 0;
}