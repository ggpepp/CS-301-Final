#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    fstream T1;
    fstream T2;
    fstream T3;
    T1.open(argv[1], ios::in);
    T2.open(argv[2], ios::in);
    T3.open(argv[3], ios::in);
    string dump;
    if(T1.is_open() && T2.is_open() && T3.is_open())
    {
        cout << "Files tables accessed" << endl;
        getline(T1,dump);
        getline(T2,dump);
        getline(T3,dump);
    }
    else
    {
        cout << "One or more files were not opened properly, check the file paths." << endl;
        T1.close();
        T2.close();
        T3.close();
        return 0;
    }
    
    while (!EOF)
    {
        
    }
    return 0;
}
