#include<iostream>
#include<fstream>
#include<string>
#include"DB.cpp"

using namespace std;
int main(int argc, char const *argv[])
{
    DB db;

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

    int T1size = 0;
    while (T1 >> db.A1[T1size])
    {
        T1 >> db.T1_KC[T1size];
        T1 >> db.A2[T1size];
        T1 >> db.T1_TC[T1size];
        T1size++;
    }
    db.T1size = T1size;
    int T2size = 0;
    while (T2 >> db.B1[T2size])
    {
        T2 >> db.T2_KC[T2size];
        T2 >> db.B2[T2size];
        T2 >> db.B3[T2size];
        T2 >> db.T2_TC[T2size];
        T2size++;
    }
    db.T2size = T2size;
    
    int T3size = 0;
    while (T3 >> db.C1[T3size])
    {
        T3 >> db.T3_KC[T3size];
        T3 >> db.C2[T3size];
        T3 >> db.C3[T3size];
        T3 >> db.C4[T3size];
        T3 >> db.T3_TC[T3size];
        T3size++;
    }
    db.T3size = T3size;

    T1.close();
    T2.close();
    T3.close();
    cout << "Enter your classification" << endl;
    int clearance = 0;
    string query = "1";
    while(cin >> clearance)
    {
        int i = 7;
        cout << "Enter you Query" << endl;
        cin.ignore();
        getline(cin, query);
        for (int i = 0; i < 9; i++)
        {
            db.selectedColumns[i] = 0;
        }
        for (int i = 0; i < 3; i++)
        {
            db.tablesselected[i] = 0;
        }
        
        int allcolumns = 0;
        if(query[i] == '*') //SELECT ALL COLUMNS
        {
            allcolumns = 1;
            i = 14;
        }
        else //SELECT CERTAIN COLUMNS
        {
            while (query[i] != 'T')//Finding which columns that are requested
            {
                if(query[i] == 'A')//For the A columns
                {
                    i++;
                    if(query[i] == '1')
                    {
                        db.selectedColumns[0] = 1;
                    }
                    else if(query[i] == '2')
                    {
                        db.selectedColumns[1] = 1;
                    }
                }
                else if(query[i] == 'B')//For the B columns
                {
                    i++;
                    if(query[i] == '1')
                    {
                        db.selectedColumns[2] = 1;
                    }
                    else if(query[i] == '2')
                    {
                        db.selectedColumns[3] = 1;
                    }
                    else if(query[i] == '3')
                    {
                        db.selectedColumns[4] = 1;
                    }
                }
                else if(query[i] == 'C')//For the C columns
                {
                    i++;
                    if(query[i] == '1')
                    {
                        db.selectedColumns[5] = 1;
                    }
                    else if(query[i] == '2')
                    {
                        db.selectedColumns[6] = 1;
                    }
                    else if(query[i] == '3')
                    {
                        db.selectedColumns[7] = 1;
                    }
                    else if(query[i] == '4')
                    {
                        db.selectedColumns[8] = 1;
                    }
                }
                else //for the , and the space in the select statement
                {
                    i++;
                }
            }
        }
        int tablesselected[3] = {0};
        while ((query[i] != 'W')&&(i < query.size()))//Selecting tables
        {
            if(query[i] == 'T')//Start of new table select
            {
                i++;
                if(query[i] == '1')//Table 1
                {
                    db.tablesselected[0] = 1;
                    i++;
                }
                else if(query[i] == '2')//Table 2
                {
                    db.tablesselected[1] = 1;
                    i++;
                }
                else if(query[i] == '3')//Table 3
                {
                    db.tablesselected[2] = 1;
                    i++;
                }
            }
            else //Commas and Spaces
            {
                i++;
            }
            
        }
        if (query[i] == 'W')
        {
            i+=6;
        }
        
        string expression;
        while(i < query.size())//create where expressions
        {
            if(query[i] == ';') 
            {
                if(!expression.empty()) db.convert(expression);
                cout << expression << endl;
                break;
            }
            else if((query[i] == ' ')&& !(expression.empty()))
            {
                db.convert(expression);
                cout << expression << endl;
                expression.clear();
                i++;
            }
            else if(query[i] == 'a')
            {
                i = i + 4;
            }
            else
            {
                expression += query[i];
                i++;
            }
            
        }
        db.join(allcolumns, clearance);
        
        clearance = 0;
        cout << "Enter your classification" << endl;

    }

    return 0;
}
