//稀疏矩阵三元组压缩存储
#define maxSize 100
#ifndef MATRIX_H
#define MATRIX_H

//三元组数据结构
typedef struct
{
    int row, col;
    int value; //元素值
} TripleNode;

class SparseMatrix
{
public:
    SparseMatrix();
    ~SparseMatrix();
    void InputCreate();                  //输入创建稀疏矩阵
    void Create(int m, int n, int *arr); //m*n大小的二维数组创建稀疏矩阵
    void Print();                        //打印矩阵
    void PrintTriple();                  //打印三元组

private:
    TripleNode *data; //存储矩阵中所有非0元素的三元组
    int rows, cols;
    int numbers; //非零元素个数
};

#endif