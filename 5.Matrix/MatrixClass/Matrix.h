#include <iostream>
using namespace std;
#define maxSize 100
#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
	int rows, cols;
	int **data;	 //二维数组基址
	void init(); //初始化

public:
	Matrix(int rows, int cols);			   //构造为全0矩阵
	Matrix(int rows, int cols, int value); //构造一个对角矩阵，value=1时为单位矩阵
	Matrix(const Matrix &m);			   //拷贝构造
	~Matrix();
	Matrix &operator=(int *arr);						 //数组赋值
	Matrix operator*(const Matrix &m);					 //矩阵乘
	Matrix &operator+=(const Matrix &m);				 //矩阵加法
	Matrix &operator+=(int value);						 //矩阵数加
	Matrix &operator-=(const Matrix &m);				 //矩阵减法
	Matrix &operator-=(int value);						 //矩阵数减
	Matrix &operator*=(const Matrix &m);				 //矩阵乘法
	Matrix &operator*=(int value);						 //矩阵数乘
	Matrix Trans();										 //矩阵转置
	int getValue(int i, int j);							 //返回第i行，第j列的值
	void Print(); //格式化输出矩阵
	friend istream &operator>>(istream &in, Matrix &m);	 //重载">>"运算符
};

#endif
