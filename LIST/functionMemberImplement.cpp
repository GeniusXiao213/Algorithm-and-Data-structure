#include <iostream>
#include "list.h"
using namespace std;

template<typename key,typename info>
bool sequence<key,info>::insertAfter(const key& k,const info& i,const key& where,
int accurance=1);