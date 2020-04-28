#include<string>
#include<iostream>
#include"printer.cpp"

using namespace std;
struct tuplet
{
    int A1=-1, T1_KC=-1, A2=-1, T1_TC=-1, B1=-1, T2_KC=-1, B2=-1, B3=-1, T2_TC=-1, C1=-1, T3_KC=-1, C2=-1, C3=-1, C4=-1, T3_TC=-1;
};


class DB
{
public:
    int A1[500];
    int T1_KC[500];
    int A2[500];
    int T1_TC[500];
    int T1size;

    int B1[500];
    int T2_KC[500];
    int B2[500];
    int B3[500];
    int T2_TC[500];
    int T2size;

    int C1[500];
    int T3_KC[500];
    int C2[500];
    int C3[500];
    int C4[500];
    int T3_TC[500];
    int T3size;

    int expressions[10];
    int numbExpress = 0;

    int tablesselected[3]={0};
    int selectedColumns[9]={0};

    void convert(string expression);

    void interpreter(int columnsSelected[]);


    void join(int allcolumns, int clearance);

    
};

void DB::convert(string expression)//LAST FUNCTION NEEDED
{
    
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
                cout << "     T1.KC", columnDividers++;
                if(selectedColumns[1] == 1) cout << "        A2 ", columnDividers++;
                if(selectedColumns[2] == 1) cout << "        B1 ", columnDividers++;
                if(KCProject == 1) cout << "     T2.KC ", columnDividers++;                
                if(selectedColumns[3] == 1) cout << "        B2 ", columnDividers++;
                if(selectedColumns[4] == 1) cout << "        B3 ", columnDividers++;
                if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
                if(KCProject == 1) cout << "     T3.KC ", columnDividers++;
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
                            if((T1_KC[i] == T2_KC[j] == T3_KC[k])&&(T3_TC[k] <= clearance)&&(T2_TC[j] <= clearance)&&(T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance))
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
                        if((T1_KC[i] == T2_KC[j])&&(T2_TC[j] <= clearance)&&(T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance))
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
                selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8], KCProject = 1;
            }
            if(selectedColumns[0] == 1) cout << "        A1 ", columnDividers++;
            cout << "     T1.KC", columnDividers++;
            if(selectedColumns[1] == 1) cout << "        A2 ", columnDividers++;
            if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
            if(KCProject == 1) cout << "     T3.KC ", columnDividers++;                
            if(selectedColumns[6] == 1) cout << "        C2 ", columnDividers++;
            if(selectedColumns[7] == 1) cout << "        C3 ", columnDividers++;
            if(selectedColumns[8] == 1) cout << "        C4 ", columnDividers++;
            cout << "        TC" << endl;
            printDividers(columnDividers);
            for (int i = 0; i < T1size; i++)
            {
                for (int j = 0; j < T3size; j++)
                {
                    if((T1_KC[i] == T3_KC[j])&&(T3_TC[j] <= clearance)&&(T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance))
                    {
                        if(selectedColumns[0] == 1) print(A1[i]);
                        print(T1_KC[i]);
                        if(selectedColumns[1] == 1) print(A2[i]);
                        if(selectedColumns[5] == 1) print(C1[j]);
                        if(KCProject == 1) print(T3_KC[j]);
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
                if((T1_TC[i] <= clearance)&&(T1_KC[i] <= clearance))
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
                selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8], KCProject = 1;
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
                    if((T3_KC[i] == T2_KC[j])&&(T2_TC[j] <= clearance)&&(T3_TC[i] <= clearance)&&(T3_KC[i] <= clearance))
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
            if(selectedColumns[3] = 1) cout << "        B2 ", columnDividers++;
            if(selectedColumns[4] = 1) cout << "        B3 ", columnDividers++;
            cout << "        TC" << endl;
            printDividers(columnDividers);
            for (int i = 0; i < T2size; i++)
            {
                if((T2_TC[i] <= clearance)&&(T2_KC[i] <= clearance))
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
        if(allcolumns == 1) selectedColumns[5] = 1, selectedColumns[6] = 1, selectedColumns[7] = 1, selectedColumns[8], KCProject = 1;
        if(selectedColumns[5] == 1) cout << "        C1 ", columnDividers++;
        if(KCProject == 1) cout << "        KC ", columnDividers++;
        if(selectedColumns[6] == 1) cout << "        C2 ", columnDividers++;
        if(selectedColumns[7] == 1) cout << "        C3 ", columnDividers++;
        if(selectedColumns[8] == 1) cout << "        C4 ", columnDividers++;
        cout << "        TC" << endl;
        printDividers(columnDividers);
        for (int i = 0; i < T3size; i++)
        {
            if((T3_TC[i] <= clearance)&&(T3_KC[i] <= clearance))
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