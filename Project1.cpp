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

long points[1001][1001];
int main(int argc, char* argv[])
{
    int n, m;
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
            fin >> points[i][j];
            //cout << i << " " << j << " " << points[i][j] << endl;
        }
    }

    for(int k = 1; k<=n; k++)
    {
        for(int l = 1; l<=m; l++)
        {
            long This = points[k][l];
            long Left;
            if(l>1)
                Left = points[k][l-1];
            else
                Left = -2147483648;
            long Right;
            if(l<m)
                Right = points[k][l+1];
            else
                Right = -2147483648;
            if(This >= Left && This >= Right)
            {
                long Up;
                if(k>1)
                    Up = points[k-1][l];
                else
                    Up = -2147483648;
                long Down;
                if(k<n)
                    Down = points[k+1][l];
                else
                    Down = -2147483648;
                if(This >= Up && This >= Down)
                    Peak_List.push(Peak(k,l));
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

