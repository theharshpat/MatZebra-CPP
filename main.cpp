#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;

public:
    Matrix() {}

    Matrix(const Matrix &arg) : matrix(arg.matrix) {}

    Matrix(vector<vector<int>> arg) : matrix(arg) {}

    ~Matrix() {}

    void setMatrix(Matrix &arg)
    {
        this->matrix = arg.matrix;
    }

    void setMatrix(vector<vector<int>> &arg)
    {
        this->matrix = arg;
    }

    vector<vector<int>> getMatrix()
    {
        return this->matrix;
    }

    void inputMatrix()
    {
        int rowSize, colSize;
        cout << "Enter row and col size, enter data row wise\n";
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

    void subtractMatrix(Matrix &argMatrix)
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
            cout << "Error: Subtraction not possible, dimensions does not match\n";
            return;
        }

        int rowSize = matrix.size(), colSize = matrix[0].size();

        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                matrix[row][col] -= arg[row][col];
            }
        }
    }

    void multiplyMatrix(Matrix &argMatrix)
    {
        vector<vector<int>> arg = argMatrix.getMatrix();
        if (matrix.size() == 0 || matrix[0].size() == 0 || arg.size() == 0 || arg[0].size() == 0)
        {
            cout << "Error: multiplication not possible, some dimension is zero\n";
            return;
        }

        int rowSize = matrix.size(), colSize = matrix[0].size();
        int argRowSize = arg.size(), argColSize = arg[0].size();

        if (colSize != argRowSize)
        {
            cout << "Error: multiplication not possible, row size of first matrix must be equal to col size of second matrix\n";
            return;
        }

        vector<vector<int>> tempVec(rowSize, vector<int>(argColSize, 0));

        for (int rowA = 0; rowA < rowSize; rowA++)
        {
            for (int colB = 0; colB < argColSize; colB++)
            {
                for (int temp = 0; temp < colSize; temp++)
                {
                    tempVec[rowA][colB] += matrix[rowA][temp] * arg[temp][colB];
                }
            }
        }
        matrix = tempVec;
    }

    void multiplyMatrix(int &value)
    {
        for(auto&vec:matrix)
        {
            for(auto&num:vec)num*=value;
        }
    }

    bool isEqual(const Matrix &arg)
    {
        return this->matrix == arg.matrix;
    }

    bool operator==(const Matrix &arg)
    {
        return this->matrix == arg.matrix;
    }

    void setIdentity(int size)
    {
        matrix.resize(size,vector<int>(size,0));
        for(int row=0;row<size;row++)
        {
            matrix[row][row]=1;
        }
    }
};

int main()
{
    Matrix m({{1,1,1},{1,2,3}});
    m.printMatrix();
    int v=3;
    m.multiplyMatrix(v);
    m.printMatrix();
/*
{
  { 1, 1, 1 },
  { 1, 2, 3 }
}
{
  { 3, 3, 3 },
  { 3, 6, 9 }
}
*/
    return 0;
}