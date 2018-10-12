#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

struct Peak
{
    Peak()
    {
    }
    Peak(int a, int b)
    {
        row = a;
        column = b;
    }
    int row;
    int column;
};

int main(int argc, char* argv[])
{
    int n, m;
    long Peak_value = 0;
    queue<Peak> Peak_List;
    ifstream fin;
    ofstream fout;
    string number = argv[1];
    //cout << number << endl;
    string Input_name(number + "/matrix.data");
    string Output_name(number + "/final.peak");
    //cout << Input_name << endl;
    fin.open(Input_name);
    if(!fin)
    {
        cout << "Fail to open!";
        return -1;
    }
    else cout << "Open" <<" " << Input_name << " " << "succeed!"<< endl;

    fout.open(Output_name);
    if(!fout)
    {
        cout << "Fail to open!";
        return -1;
    }
    else cout << "Open" <<" " << Output_name << " " << "succeed!"<< endl;
    fin >> n >> m;
    //cout << n <<" " << m << endl;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            long In;
            fin >> In;
            //cout<< In << endl;
            if(In > Peak_value)
            {
                while(!Peak_List.empty())
                    Peak_List.pop();
                Peak_List.push(Peak(i,j));
                Peak_value = In;
            }
            else if(In == Peak_value)
            {
                Peak_List.push(Peak(i,j));
            }
        }
    }
    //cout << Peak_value << endl;
    fout << Peak_List.size() << endl;
    //cout << Peak_List.size() << endl;
    while(!Peak_List.empty())
    {
        fout << Peak_List.front().row << " " << Peak_List.front().column << endl;
        //cout << Peak_List.front().row << " " << Peak_List.front().column << endl;
        Peak_List.pop();
    }
    return 0;
}

