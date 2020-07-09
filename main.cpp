#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;

public:
    Matrix() {}
    ~Matrix() {}
    Matrix(vector<vector<int>> matrix)
    {
        this->matrix = matrix;
    }
    void setMatrix(vector<vector<int>> matrix)
    {
        this->matrix = matrix;
    }
    void inputMatrix()
    {
        int rowSize, colSize;
        cin >> rowSize >> colSize;
        matrix.resize(rowSize, vector<int>(colSize));
        for (auto &row : matrix)
            for (auto &num : row)
                cin >> num;
    }
    void printMatrix()
    {
        int rowSize=matrix.size(),colSize=0;
        if(rowSize)colSize=matrix[0].size();
        
        cout<<"{\n";
        for(int row=0;row<rowSize-1;row++)
        {
            cout<<"  { ";
            for(int col=0;col<colSize-1;col++)
            {
                cout<<matrix[row][col]<<", ";
            }
            cout<<matrix[row][colSize-1]<<" },\n";
        }
        cout<<"  { ";
        for(int col=0;col<colSize-1;col++)
        {
            cout<<matrix[rowSize-1][col]<<", ";
        }
        cout<<matrix[rowSize-1][colSize-1]<<" }\n";
        cout<<"}\n";
    }
};

int main()
{
    Matrix m({{1,2,3},{4,5,6},{1,2,3},{4,5,6}});
    m.printMatrix();
/* Output:
{
  { 1, 2, 3 },
  { 4, 5, 6 },
  { 1, 2, 3 },
  { 4, 5, 6 }
}

*/
    return 0;
}