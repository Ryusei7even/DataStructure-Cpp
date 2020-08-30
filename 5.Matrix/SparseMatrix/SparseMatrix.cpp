#include <iostream>
#include <algorithm>
#include "SparseMatrix.h"
using namespace std;

SparseMatrix::SparseMatrix()
{
    data = new TripleNode[maxSize];
    rows = cols = numbers = 0;
}

SparseMatrix::~SparseMatrix()
{
    delete[] data;
    data = NULL;
}

void SparseMatrix::InputCreate()
{
    cout << "Input the number of rows, columns, and non-zero elements" << endl;
    cin >> rows >> cols >> numbers;
    cout << "Enter row index, column index, and value of nonzero elements" << endl;
    for (int i = 0; i < numbers; i++)
    {
        cin >> data[i].row >> data[i].col >> data[i].value;
    }
}

void SparseMatrix::Create(int m, int n, int *arr)
{
    rows = m, cols = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //存储非0元素
            if (*(arr + i * cols + j) != 0)
            {
                //记录三元组的行列下标及值
                data[numbers].row = i;
                data[numbers].col = j;
                data[numbers].value = *(arr + i * cols + j);
                numbers++;
            }
        }
    }
}

//打印矩阵
void SparseMatrix::Print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool flag = false;
            for (int k = 0; k < numbers; k++)
            {
                if (i == data[k].row && j == data[k].col)
                {
                    cout << data[k].value << " ";
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

//打印三元组
void SparseMatrix::PrintTriple()
{
    if (!numbers)
    {
        cout << "No non-zero elements" << endl;
        return;
    }
    for (int i = 0; i < numbers; i++)
    {
        cout << "No." << i + 1 << " row: " << data[i].row+1 << " column: " << data[i].col+1 << " value: " << data[i].value << endl;
    }
}

int main()
{
    SparseMatrix A;
    int arr[][4] = {{0, 0, 0, 0},
                    {1, 0, 0, 0},
                    {0, 0, 0, 2},
                    {0, 3, 0, 0}};
    A.Create(4, 4, *arr);
    A.Print();

    SparseMatrix B;
    B.InputCreate();
    /* 输入样例 
    第一行 行数、列数、非零元素数k
    4 5 6
    接下来k行：行下标、列下标、元素值
    0 4 6
    1 0 1
    1 4 4
    2 3 2
    3 1 3
    3 4 1
    */
    cout << endl;
    B.PrintTriple(); //打印三元组
    cout << endl;
    B.Print();
    /*
    0 0 0 0 6
    1 0 0 0 4
    0 0 0 2 0
    0 3 0 0 1
    */
    return 0;
}