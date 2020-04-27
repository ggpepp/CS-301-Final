#include<iostream>
#include<fstream>
#include<string>
#include"printer.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    fstream T1;
    fstream T2;
    fstream T3;
    T1.open("Tables/T1.txt", ios::in);
    T2.open("Tables/T2.txt", ios::in);
    T3.open("Tables/T3.txt", ios::in);
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
    int A1[500];
    int T1_KC[500];
    int A2[500];
    int T1_TC[500];

    int B1[500];
    int T2_KC[500];
    int B2[500];
    int B3[500];
    int T2_TC[500];

    int C1[500];
    int T3_KC[500];
    int C2[500];
    int C3[500];
    int C4[500];
    int T3_TC[500];

    int T1size = 0;
    while (T1 >> A1[T1size])
    {
        T1 >> T1_KC[T1size];
        T1 >> A2[T1size];
        T1 >> T1_TC[T1size];
        T1size++;
    }

    int T2size = 0;
    while (T2 >> B1[T2size])
    {
        T2 >> T2_KC[T2size];
        T2 >> B2[T2size];
        T2 >> B3[T2size];
        T2 >> T2_TC[T2size];
        T2size++;
    }
    
    int T3size = 0;
    while (T3 >> C1[T3size])
    {
        T3 >> T3_KC[T3size];
        T3 >> C2[T3size];
        T3 >> C3[T3size];
        T3 >> C4[T3size];
        T3 >> T3_TC[T3size];
        T3size++;
    }

    T1.close();
    T2.close();
    T3.close();
    cout << "Enter your classification" << endl;
    int clearance = 0;
    string query = "1";
    while(cin >> clearance)
    {
        cout << "Enter you Query" << endl;
        cin.ignore();
        getline(cin,  query); 
        cout << query << endl;
        print(100);
        cout << endl;


        clearance = 0;
        cout << "Enter your classification" << endl;

    }

    return 0;
}
