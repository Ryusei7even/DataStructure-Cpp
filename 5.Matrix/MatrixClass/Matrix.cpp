#include "Matrix.h"

void Matrix::init()
{
	data = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
	}
}

//初始化为全0矩阵
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	init();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;
		}
	}
}

//构造一个对角矩阵，value=1时为单位矩阵
Matrix::Matrix(int rows, int cols, int value)
{
	this->rows = rows;
	this->cols = cols;
	init();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j)
			{
				data[i][j] = value;
			}
			else
			{
				data[i][j] = 0;
			}
		}
	}
}

Matrix::Matrix(const Matrix &m)
{
	rows = m.rows;
	cols = m.cols;
	init();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = m.data[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

//数组构造
Matrix &Matrix::operator=(int *arr)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = *(arr + i * cols + j);
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix &m)
{
	if (cols != m.rows) //如果第一个矩阵的列和第二个矩阵的行不等则无法相乘
	{
		cout << "Cannot multiply!" << endl;
	}
	Matrix temp(rows, m.cols);
	for (int i = 0; i < temp.rows; i++)
	{
		for (int j = 0; j < temp.cols; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				temp.data[i][j] += (data[i][k] * m.data[k][j]);
			}
		}
	}
	return temp;
}

Matrix &Matrix::operator+=(const Matrix &m)
{
	if (rows != m.rows || cols != m.cols)
	{
		cout << "Not the same size!" << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] += m.data[i][j];
		}
	}
	return *this;
}

Matrix &Matrix::operator+=(int value)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] += value;
		}
	}
	return *this;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
	if (rows != m.rows || cols != m.cols)
	{
		cout << "Not the same size!" << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] -= m.data[i][j];
		}
	}
	return *this;
}

Matrix &Matrix::operator-=(int value)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] -= value;
		}
	}
	return *this;
}

Matrix &Matrix::operator*=(const Matrix &m)
{
	if (cols != m.rows) //如果第一个矩阵的列和第二个矩阵的行不等则无法相乘
	{
		cout << "Cannot multiply!" << endl;
	}
	Matrix temp(rows, m.cols);
	for (int i = 0; i < temp.rows; i++)
	{
		for (int j = 0; j < temp.cols; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				temp.data[i][j] += (data[i][k] * m.data[k][j]);
			}
		}
	}
	*this = temp;
	return *this;
}

Matrix &Matrix::operator*=(int value)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i][j] *= value;
		}
	}
	return *this;
}

int Matrix::getValue(int i, int j)
{
	return data[i][j];
}

Matrix Matrix::Trans()
{
	Matrix newMatrix(cols, rows); //转置后行列大小交换
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newMatrix.data[j][i] = data[i][j];
		}
	}
	*this = newMatrix;
	return *this;
}

//输入矩阵
istream &operator>>(istream &in, Matrix &m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			in >> m.data[i][j];
		}
	}
	return in;
}

//格式化输出矩阵
void Matrix::Print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Matrix A(3, 3); //构造3*3的零矩阵
	cout << "Zero matrix" << endl;
	A.Print();

	cout << "Input matrix: (e.g. 1 2 3 4 5 6 7 8 9)" << endl;
	//e.g. 1 2 3 4 5 6 7 8 9
	cin >> A;

	cout << endl;
	cout << "A:" << endl;
	A.Print();
	Matrix B = A; //拷贝构造

	/* 初等行、列变换 */

	int arr[][3] = {{0, 0, 1},
					{0, 1, 0},
					{1, 0, 0}};
	Matrix temp(3, 3); //初等矩阵1
	temp = *arr;
	Matrix A1 = temp * A;
	cout << "Matrix A swap row 1 and 3:" << endl;
	A1.Print(); //行变换，A互换1、3行

	int arr2[][3] = {{0, 1, 0},
					 {1, 0, 0},
					 {0, 0, 1}};
	Matrix temp2(3, 3); //初等矩阵2
	temp2 = *arr2;
	Matrix A2 = A * temp2;
	cout << "Matrix A swap column 1 and 2:" << endl;
	A2.Print(); //列变换，A互换1、2列

	Matrix M(3, 3); //3*3零矩阵
	M += 1;
	int arr3[][3] = {{1, 0, 0},
					 {0, 3, 0},
					 {0, 0, 2}};
	Matrix N(3, 3);
	N = *arr3;

	Matrix Q = N * M;
	cout << "Q:\n"
		 << endl; //矩阵M第二行乘以3，第三行乘以2
	Q.Print();

	Matrix R = M * N;
	cout << "R:\n"
		 << endl; //矩阵M第二列乘以3，第三列乘以2
	R.Print();

	cout << endl;

	/* 行、列向量 */
	int vec1[][1] = {{1},
					 {2},
					 {3}};
	Matrix alpha(3, 1);
	alpha = *vec1; //列向量

	int vec2[][3] = {{2, 2, 2}};
	Matrix beta(1, 3);
	beta = *vec2; //行向量

	cout << "alpha multiply beta: " << endl;
	Matrix isMatrix = alpha * beta; //列在前，行在后，乘出来是矩阵
	isMatrix.Print();

	cout << endl;

	cout << "beta multiply alpha: " << endl;
	Matrix isNumber = beta * alpha; //行在前，列在后，乘出来是数
	isNumber.Print();

	Matrix gamma = alpha; //gamma为原alpha
	alpha.Trans();   //alpha转置
	
	// gamma.Print();
	// alpha.Print();
	cout << "alpha multiply alphaT: " << endl;
	gamma*=alpha;
	gamma.Print();   //对称矩阵

	cout << "--------------------------------" << endl;

	A -= 1;
	A -= B;
	cout << "After A-B: " << endl;
	A.Print();

	Matrix E(3, 3, 1); //构造一个3*3的单位矩阵
	cout << "Identity matrix" << endl;
	E.Print();

	B *= E;
	cout << "B mutliply identity matrix:" << endl;
	B.Print(); //B乘以单位矩阵还是B本身

	int arr5[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	Matrix C(3, 4);
	C = *arr5; //数组构造3*4矩阵
	cout << "C[0][3]: " << C.getValue(0, 3) << endl;
	C.Print();
	C.Trans(); //D转置后为4行3列

	cout << "Transpose C:" << endl;
	C.Print();

	E *= 2;
	Matrix CmE(3, 4);
	CmE = C * E;
	cout << "C multiply E: " << endl;
	CmE.Print();

	// int arr4[][3] = {{2, 0, 0},
	// 				 {6, 0, 0},
	// 				 {-4, 0, 0}};
	// Matrix Z(3, 3);
	// Z = *arr4;
	// Z *= Z;
	// Z.Print();

	return 0;
}