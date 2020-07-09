#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;

public:
    Matrix() {}

    ~Matrix() {}

    Matrix(vector<vector<int>> matrix) : matrix(matrix) {}

    void setMatrix(vector<vector<int>> &matrix)
    {
        this->matrix = matrix;
    }

    vector<vector<int>> getMatrix()
    {
        return this->matrix;
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
        int rowSize = matrix.size(), colSize = 0;
        if (rowSize)
            colSize = matrix[0].size();

        cout << "{\n";
        for (int row = 0; row < rowSize - 1; row++)
        {
            cout << "  { ";
            for (int col = 0; col < colSize - 1; col++)
            {
                cout << matrix[row][col] << ", ";
            }
            cout << matrix[row][colSize - 1] << " },\n";
        }
        cout << "  { ";
        for (int col = 0; col < colSize - 1; col++)
        {
            cout << matrix[rowSize - 1][col] << ", ";
        }
        cout << matrix[rowSize - 1][colSize - 1] << " }\n";
        cout << "}\n";
    }

    //Overloaded : 1
    void addMatrix(vector<vector<int>> arg)
    {
        if (matrix.size() == 0)
        {
            matrix = arg;
            return;
        }
        if (arg.size() == 0)
        {
            return;
        }
        if (matrix.size() != arg.size() || matrix[0].size() != arg.size())
        {
            cout << "Error: Addition not possible, dimensions does not match\n";
            return;
        }

        int rowSize = matrix.size(), colSize = matrix[0].size();

        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                matrix[row][col] += arg[row][col];
            }
        }
    }

    //Overloaded : 2
    void addMatrix(Matrix &argMatrix)
    {
        vector<vector<int>> arg = argMatrix.getMatrix();
        if (matrix.size() == 0)
        {
            matrix = arg;
            return;
        }
        if (arg.size() == 0)
        {
            return;
        }
        if (matrix.size() != arg.size() || matrix[0].size() != arg[0].size())
        {
            cout << "Error: Addition not possible, dimensions does not match\n";
            return;
        }

        int rowSize = matrix.size(), colSize = matrix[0].size();

        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                matrix[row][col] += arg[row][col];
            }
        }
    }
};

int main()
{
    Matrix m({{1, 2, 3}, {4, 5, 6}, {1, 2, 3}, {4, 5, 6}});
    Matrix m2({{6, 2, 13}, {4, 2, 10}, {1, 4, 3}, {10, 1, 4}});
    m.printMatrix();
    m2.printMatrix();
    m.addMatrix(m2);
    m.printMatrix();
    /* Output:
{
  { 1, 2, 3 },
  { 4, 5, 6 },
  { 1, 2, 3 },
  { 4, 5, 6 }
}
{
  { 6, 2, 13 },
  { 4, 2, 10 },
  { 1, 4, 3 },
  { 10, 1, 4 }
}
{
  { 7, 4, 16 },
  { 8, 7, 16 },
  { 2, 6, 6 },
  { 14, 6, 10 }
}
    return 0;
}