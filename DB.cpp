#include<string>
#include<iostream>
#include<sstream>
#include"printer.cpp"

using namespace std;
struct tuplet
{
    int A1=-1, T1_KC=-1, A2=-1, T1_TC=-1, B1=-1, T2_KC=-1, B2=-1, B3=-1, T2_TC=-1, C1=-1, T3_KC=-1, C2=-1, C3=-1, C4=-1, T3_TC=-1;
};


class DB
{
public:
    //Table 1
    int A1[500];
    int T1_KC[500];
    int A2[500];
    int T1_TC[500];
    int T1size;
    //Table 2
    int B1[500];
    int T2_KC[500];
    int B2[500];
    int B3[500];
    int T2_TC[500];
    int T2size;
    //Table 3
    int C1[500];
    int T3_KC[500];
    int C2[500];
    int C3[500];
    int C4[500];
    int T3_TC[500];
    int T3size;
    //Querry Specific
    int columnCompares[10][10]={0};
    int valCompares[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int tablesselected[3]={0};
    int selectedColumns[9]={0};
    //Functions
    void convert(string expression);
    void interpreter(int columnsSelected[]);
    void join(int allcolumns, int clearance);
    bool compare(int i, int j, int k, int clearance);
};

void DB::convert(string expression)//Convert text expression into usable comparison
{
    int x = 0;
    int y = 0;
    string value;
    //Finding first half of comparison
    switch (expression[0])
    {
    case 'A':
        if(expression[1] == '1')x=0;
        else if(expression[1] == '2')x=1;
        break;
    case 'B':
        if(expression[1] == '1')x=2;
        else if(expression[1] == '2')x=3;
        else if(expression[1] == '3')x=4;
        break;
    case 'C':
        if(expression[1] == '1')x=5;
        else if(expression[1] == '2')x=6;
        else if(expression[1] == '3')x=7;
        else if(expression[1] == '4')x=8;
        break;
    default:
        x=9;
        break;
    }
    //Finding second half of comparison
    switch (expression[3])
    {
    case 'A':
        if(expression[4] == '1')y=0;
        else if(expression[4] == '2')y=1;
        break;
    case 'B':
        if(expression[4] == '1')y=2;
        else if(expression[4] == '2')y=3;
        else if(expression[4] == '3')y=4;
        break;
    case 'C':
        if(expression[4] == '1')y=5;
        else if(expression[4] == '2')y=6;
        else if(expression[4] == '3')y=7;
        else if(expression[4] == '4')y=8;
        break;
    default:
        //Column to Value Comparison
        for (int i = 3; i < expression.size(); i++)
        {
            if(isdigit(expression[i]))
            {
                value+=expression[i];
            }
        }
        istringstream(value) >> valCompares[x];
        break;
    }
    //If it is not a column to value comparison
    if(value.empty()) columnCompares[x][y] = 1;
    value.clear();
}
bool DB::compare(int i, int j, int k, int clearance)
{
    if(i!=-1)//T1...
    {
        if(j!=-1)//T1 to T2 column compares
        {
            if((columnCompares[0][2] == 1)||(columnCompares[2][0] == 1)) if(A1[i]!=B1[j]) return false;
            if((columnCompares[1][2] == 1)||(columnCompares[2][1] == 1)) if(A2[i]!=B1[j]) return false;
            if((columnCompares[0][3] == 1)||(columnCompares[3][0] == 1)) if(A1[i]!=B2[j]) return false;
            if((columnCompares[1][3] == 1)||(columnCompares[3][1] == 1)) if(A2[i]!=B2[j]) return false;
            if((columnCompares[0][4] == 1)||(columnCompares[4][0] == 1)) if(A1[i]!=B3[j]) return false;
            if((columnCompares[1][4] == 1)||(columnCompares[4][1] == 1)) if(A2[i]!=B3[j]) return false;
            
        }
        if(k!=-1)//T1 to T3 column compares
        {
            if((columnCompares[0][5] == 1)||(columnCompares[5][0] == 1)) if(A1[i]!=C1[k]) return false;
            if((columnCompares[1][5] == 1)||(columnCompares[5][1] == 1)) if(A2[i]!=C1[k]) return false;
            if((columnCompares[0][6] == 1)||(columnCompares[6][0] == 1)) if(A1[i]!=C2[k]) return false;
            if((columnCompares[1][6] == 1)||(columnCompares[6][1] == 1)) if(A2[i]!=C2[k]) return false;
            if((columnCompares[0][7] == 1)||(columnCompares[7][0] == 1)) if(A1[i]!=C3[k]) return false;
            if((columnCompares[1][7] == 1)||(columnCompares[7][1] == 1)) if(A2[i]!=C3[k]) return false;
            if((columnCompares[0][8] == 1)||(columnCompares[8][0] == 1)) if(A1[i]!=C4[k]) return false;
            if((columnCompares[1][8] == 1)||(columnCompares[8][1] == 1)) if(A2[i]!=C4[k]) return false;

        }
        if(valCompares[0] != -1) if(A1[i] != valCompares[0]) return false;
        if(valCompares[1] != -1) if(A2[i] != valCompares[1]) return false;
        if(valCompares[9] != -1) if(T1_TC[i] != valCompares[9]) return false;
            
        
    }
    if(j!=-1)//T2...
    {
        if(k!=-1)//T2 to T3 column compares
        {
            if((columnCompares[2][5] == 1)||(columnCompares[5][2] == 1)) if(B1[j]!=C1[k]) return false;
            if((columnCompares[3][5] == 1)||(columnCompares[5][3] == 1)) if(B2[j]!=C1[k]) return false;
            if((columnCompares[4][5] == 1)||(columnCompares[5][4] == 1)) if(B3[j]!=C1[k]) return false;
            if((columnCompares[2][6] == 1)||(columnCompares[6][2] == 1)) if(B1[j]!=C2[k]) return false;
            if((columnCompares[3][6] == 1)||(columnCompares[6][3] == 1)) if(B2[j]!=C2[k]) return false;
            if((columnCompares[4][6] == 1)||(columnCompares[6][4] == 1)) if(B3[j]!=C2[k]) return false;
            if((columnCompares[2][7] == 1)||(columnCompares[7][2] == 1)) if(B1[j]!=C3[k]) return false;
            if((columnCompares[3][7] == 1)||(columnCompares[7][3] == 1)) if(B2[j]!=C3[k]) return false;
            if((columnCompares[4][7] == 1)||(columnCompares[7][4] == 1)) if(B3[j]!=C3[k]) return false;
            if((columnCompares[2][8] == 1)||(columnCompares[8][2] == 1)) if(B1[j]!=C4[k]) return false;
            if((columnCompares[3][8] == 1)||(columnCompares[8][3] == 1)) if(B2[j]!=C4[k]) return false;
            if((columnCompares[4][8] == 1)||(columnCompares[8][4] == 1)) if(B3[j]!=C4[k]) return false;
        }
        if(valCompares[2] != -1) if(B1[j] != valCompares[2]) return false;
        if(valCompares[3] != -1) if(B2[j] != valCompares[3]) return false;
        if(valCompares[4] != -1) if(B3[j] != valCompares[4]) return false;
        if(valCompares[9] != -1) if(T2_TC[j] != valCompares[9]) return false;
    }
    if(k!=-1)//T3
    {
        if(valCompares[5] != -1) if(C1[k] != valCompares[5]) return false;
        if(valCompares[6] != -1) if(C2[k] != valCompares[6]) return false;
        if(valCompares[7] != -1) if(C3[k] != valCompares[7]) return false;
        if(valCompares[8] != -1) if(C4[k] != valCompares[8]) return false;
        if(valCompares[9] != -1) if(T3_TC[k] != valCompares[9]) return false;
    }
    return true;
}

void DB::join(int allcolumns, int clearance)
{
    
    int KCProject = 0;
    int columnDividers = 1;
    if(tablesselected[0] == 1)//T1...
    {
        if (tablesselected[1] == 1)//T1, T2...
        {
            if(tablesselected[2] == 1)//T1, T2, T3
            {
                if(allcolumns == 1) 
                {
                    selectedColumns[0] = 1, selectedColumns[1] = 1, selectedColumns[2] = 1;
                    selectedColumns[3] = 1, selectedColumns[4] = 1, selectedColumns[5] = 1;
                    selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8] = 1;
                    KCProject = 1;
                }
                if(selectedColumns[0] == 1) cout << "        A1 ", columnDividers++;
                if(KCProject == 1) cout << "     T1.KC ", columnDividers++;
                if(selectedColumns[1] == 1) cout << "        A2 ", columnDividers++;
                if(selectedColumns[2] == 1) cout << "        B1 ", columnDividers++;
                if(KCProject == 1) cout << "     T2.KC ", columnDividers++;                
                if(selectedColumns[3] == 1) cout << "        B2 ", columnDividers++;
                if(selectedColumns[4] == 1) cout << "        B3 ", columnDividers++;
                if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
                cout << "     T3.KC ", columnDividers++;
                if(selectedColumns[6] == 1) cout << "        C2 ", columnDividers++;
                if(selectedColumns[7] == 1) cout << "        C3 ", columnDividers++;
                if(selectedColumns[8] == 1) cout << "        C4 ", columnDividers++;
                cout << "        TC" << endl;
                printDividers(columnDividers);
                for (int i = 0; i < T1size; i++)
                {
                    for (int j = 0; j < T2size; j++)
                    {
                        for (int k = 0; k < T3size; k++)
                        {
                            if(((T1_KC[i] == T2_KC[j]) == T3_KC[k])&&(T3_TC[k] <= clearance)&&(T2_TC[j] <= clearance)&&(T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance)&&(compare(i,j,k,clearance)))
                            {
                                if(selectedColumns[0] == 1) print(A1[i]);
                                print(T1_KC[i]);
                                if(selectedColumns[1] == 1) print(A2[i]);
                                if(selectedColumns[2] == 1) print(B1[j]);
                                if(KCProject == 1) print(T2_KC[j]);
                                if(selectedColumns[3] == 1) print(B2[j]);
                                if(selectedColumns[4] == 1) print(B3[j]);
                                if(selectedColumns[5] == 1) print(C1[k]);
                                if(KCProject == 1) print(T3_KC[k]);
                                if(selectedColumns[6] == 1) print(C2[k]);
                                if(selectedColumns[7] == 1) print(C3[k]);
                                if(selectedColumns[8] == 1) print(C4[k]);
                                print( max(T3_TC[k], max(T1_TC[i], T2_TC[j]) ) );
                                cout << endl;
                            }
                        }
                        
                        
                    }
                }
            }
            else//T1 and T2
            {
                if(allcolumns == 1) 
                {
                    selectedColumns[0] = 1, selectedColumns[1] = 1, selectedColumns[2] = 1;
                    selectedColumns[3] = 1, selectedColumns[4] = 1, KCProject = 1;
                }
                if(selectedColumns[0] == 1) cout << "        A1 ", columnDividers++;
                cout << "     T1.KC", columnDividers++;
                if(selectedColumns[1] == 1) cout << "        A2 ", columnDividers++;
                if(selectedColumns[2] == 1) cout << "        B1 ", columnDividers++;
                if(KCProject == 1) cout << "     T2.KC ", columnDividers++;                
                if(selectedColumns[3] == 1) cout << "        B2 ", columnDividers++;
                if(selectedColumns[4] == 1) cout << "        B3 ", columnDividers++;
                cout << "        TC" << endl;
                printDividers(columnDividers);
                for (int i = 0; i < T1size; i++)
                {
                    for (int j = 0; j < T2size; j++)
                    {
                        if((T1_KC[i] == T2_KC[j])&&(T2_TC[j] <= clearance)&&(T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance)&&(compare(i,j,-1,clearance)))
                        {
                            if(selectedColumns[0] == 1) print(A1[i]);
                            print(T1_KC[i]);
                            if(selectedColumns[1] == 1) print(A2[i]);
                            if(selectedColumns[2] == 1) print(B1[j]);
                            if(KCProject == 1) print(T2_KC[j]);
                            if(selectedColumns[3] == 1) print(B2[j]);
                            if(selectedColumns[4] == 1) print(B3[j]);
                            print(max(T1_TC[i], T2_TC[j]));
                            cout << endl;
                        }
                    }
                }
                
            }
            
        }
        else if(tablesselected[2] == 1)//T1 and T3
        {
            if(allcolumns == 1) 
            {
                selectedColumns[0] = 1, selectedColumns[1] = 1, selectedColumns[5] = 1;
                selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8] = 1, KCProject = 1;
            }
            if(selectedColumns[0] == 1) cout << "        A1 ", columnDividers++;
            if(KCProject == 1) cout << "     T1.KC ", columnDividers++;
            if(selectedColumns[1] == 1) cout << "        A2 ", columnDividers++;
            if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
            cout << "     T3.KC ", columnDividers++;                
            if(selectedColumns[6] == 1) cout << "        C2 ", columnDividers++;
            if(selectedColumns[7] == 1) cout << "        C3 ", columnDividers++;
            if(selectedColumns[8] == 1) cout << "        C4 ", columnDividers++;
            cout << "        TC" << endl;
            printDividers(columnDividers);
            for (int i = 0; i < T1size; i++)
            {
                for (int j = 0; j < T3size; j++)
                {
                    if((T1_KC[i] == T3_KC[j])&&(T3_TC[j] <= clearance)&&(T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance)&&(compare(i,-1,j,clearance)))
                    {
                        if(selectedColumns[0] == 1) print(A1[i]);
                        if(KCProject == 1) print(T1_KC[i]);
                        if(selectedColumns[1] == 1) print(A2[i]);
                        if(selectedColumns[5] == 1) print(C1[j]);
                        print(T3_KC[j]);
                        if(selectedColumns[6] == 1) print(C2[j]);
                        if(selectedColumns[7] == 1) print(C3[j]);
                        if(selectedColumns[8] == 1) print(C4[j]);
                        print(max(T1_TC[i], T3_TC[j]));
                        cout << endl;
                    }
                }
            }
        }
        else//T1
        {
            if(allcolumns == 1) selectedColumns[0] = 1, selectedColumns[1] = 1, KCProject = 1;
            if(selectedColumns[0] == 1) cout << "        A1 ", columnDividers++;
            if(KCProject == 1) cout << "        KC ", columnDividers++;
            if(selectedColumns[1] == 1) cout << "        A2 ", columnDividers++;
            cout << "        TC" << endl;
            printDividers(columnDividers);
            for (int i = 0; i < T1size; i++)
            {
                if((T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance)&&(compare(i,-1,-1,clearance)))
                {
                    if(selectedColumns[0] == 1) print(A1[i]);
                    if(KCProject == 1) print(T1_KC[i]);
                    if(selectedColumns[1] == 1) print(A2[i]);
                    print(T1_TC[i]);
                    cout << endl;
                }
            }
        }
    }
    else if(tablesselected[1] == 1)//T2...
    {
        if(tablesselected[2] == 1)//T2 and T3
        {
            if(allcolumns == 1) 
            {
                selectedColumns[2] = 1, selectedColumns[3] = 1, selectedColumns[4] = 1, selectedColumns[5] = 1;
                selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8] = 1, KCProject = 1;
            }
            if(selectedColumns[2] == 1) cout << "        B1 ", columnDividers++;
            cout << "     T2.KC ", columnDividers++;
            if(selectedColumns[3] == 1) cout << "        B2 ", columnDividers++;
            if(selectedColumns[4] == 1) cout << "        B3 ", columnDividers++;
            if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
            if(KCProject == 1) cout << "     T3.KC ", columnDividers++;                
            if(selectedColumns[6] == 1) cout << "        C2 ", columnDividers++;
            if(selectedColumns[7] == 1) cout << "        C3 ", columnDividers++;
            if(selectedColumns[8] == 1) cout << "        C4 ", columnDividers++;
            cout << "        TC" << endl;
            printDividers(columnDividers);
            for (int i = 0; i < T3size; i++)
            {
                for (int j = 0; j < T2size; j++)
                {
                    if((T3_KC[i] == T2_KC[j])&&(T2_TC[j] <= clearance)&&(T3_TC[i] <= clearance)&&(T3_KC[i] <= clearance)&&(compare(-1,j,i,clearance)))
                    {
                        if(selectedColumns[2] == 1) print(B1[j]);
                        print(T2_KC[j]);
                        if(selectedColumns[3] == 1) print(B2[j]);
                        if(selectedColumns[4] == 1) print(B3[j]);
                        if(selectedColumns[5] == 1) print(C1[i]);
                        if(KCProject == 1) print(T3_KC[i]);
                        if(selectedColumns[6] == 1) print(C2[i]);
                        if(selectedColumns[7] == 1) print(C3[i]);
                        if(selectedColumns[8] == 1) print(C4[i]);
                        print(max(T3_TC[i], T2_TC[j]));
                        cout << endl;
                    }
                }
            }

        }
        else//T2
        {
            if(allcolumns == 1) selectedColumns[2] = 1, selectedColumns[3] = 1, selectedColumns[4] = 1, KCProject = 1;
            if(selectedColumns[2] == 1) cout << "        B1 ", columnDividers++;
            if(KCProject == 1) cout << "        KC ", columnDividers++;
            if(selectedColumns[3] == 1) cout << "        B2 ", columnDividers++;
            if(selectedColumns[4] == 1) cout << "        B3 ", columnDividers++;
            cout << "        TC" << endl;
            printDividers(columnDividers);
            for (int i = 0; i < T2size; i++)
            {
                if((T2_TC[i] <= clearance)&&(T2_KC[i] <= clearance)&&(compare(-1,i,-1,clearance)))
                {
                    if(selectedColumns[2] == 1) print(B1[i]);
                    if(KCProject == 1) print(T2_KC[i]);
                    if(selectedColumns[3] == 1) print(B2[i]);
                    if(selectedColumns[4] == 1) print(B3[i]);
                    print(T2_TC[i]);
                    cout << endl;
                }
            }
        }
    }
    else if(tablesselected[2] == 1)//T3
    {
        if(allcolumns == 1) selectedColumns[5] = 1, selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8] = 1, KCProject = 1;
        if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
        if(KCProject == 1) cout << "        KC ", columnDividers++;
        if(selectedColumns[6] == 1) cout << "        C2 ", columnDividers++;
        if(selectedColumns[7] == 1) cout << "        C3 ", columnDividers++;
        if(selectedColumns[8] == 1) cout << "        C4 ", columnDividers++;
        cout << "        TC" << endl;
        printDividers(columnDividers);

        for (int i = 0; i < T3size; i++)
        {
            if((T3_TC[i] <= clearance)&&(T3_KC[i] <= clearance)&&(compare(-1,-1,i,clearance)))
            {
                if(selectedColumns[5] == 1) print(C1[i]);
                if(KCProject == 1) print(T3_KC[i]);
                if(selectedColumns[6] == 1) print(C2[i]);
                if(selectedColumns[7] == 1) print(C3[i]);
                if(selectedColumns[8] == 1) print(C4[i]);
                print(T3_TC[i]);
                cout << endl;
            }
        }
            
    }
    
}