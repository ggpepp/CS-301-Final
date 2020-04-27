#include<iostream>
using namespace std;

void print(int value)
{
    if(value < 10) cout << "         " << value << " ";
    else if(value < 100) cout << "        " << value << " ";
    else if(value < 1000) cout << "       " << value << " ";
    else if(value < 10000) cout << "      " << value << " ";
    else if(value < 100000) cout << "     " << value << " ";
    else if(value < 1000000) cout << "    " << value << " ";
    else if(value < 10000000) cout << "   " << value << " ";
    else if(value < 100000000) cout << "  " << value << " ";
    else if(value < 1000000000) cout << " " << value << " ";
    else cout << value << " ";
}