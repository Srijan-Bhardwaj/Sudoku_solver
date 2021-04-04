//Sudok solver using backtracking----------
#include<bits/stdc++.h>
using namespace std;

class sudoku
{
    private:
    int grid[9][9];
    public:
    sudoku(){}
    sudoku(int arr[9][9])
    {
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        grid[i][j]=arr[i][j];
    }
    bool isSafe(int row,int col,int num);
    bool isEmpty(int &row,int &col);
    bool solve();
    void print();
};

bool sudoku::solve()
{
    int row,col;

    if(!isEmpty(row,col))
    return true;

    for(int num=1;num<10;num++)
    {
        if(!isSafe(row,col,num))
        continue;

        grid[row][col]=num;
        if(solve())
        return true;

        grid[row][col]=0;
    }
    return false;    
}

bool sudoku::isEmpty(int &row,int &col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            {
                row=i;col=j;
                return true;
            }
        }
    }
    return false;
}

bool sudoku::isSafe(int row,int col,int num)
{
    //Check in same column
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num)
        return false;
    }

    //Check in same row
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
        return false;
    }

    //Check in same box
    for(int i=row-row%3;i<(row+3-row%3);i++)
    {
        for(int j=col-col%3;j<(col+3-col%3);j++)
        {
            if(grid[i][j]==num)
            return false;
        }
    }
    return true;
}

void sudoku::print()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        cout<<grid[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{
    int arr[9][9]={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    sudoku s(arr);
    if(s.solve())
    {
        s.print();
    }
    else
    cout<<"No solution found!";
    return 0;
}