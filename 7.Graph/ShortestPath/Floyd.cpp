#include <iostream>
#include <algorithm>
using namespace std;

#define maxSize 1000
#define MAX 9999999
int vNum, eNum;
int vertex[maxSize];        //顶点
int edge[maxSize][maxSize]; //边
int dist[maxSize][maxSize]; //存放最短路径长度


void initGraph(int vNum, int eNum)
{
    int i, j, k;
    for (int i = 0; i < vNum; i++)
    {
        cin >> vertex[i];
    }

    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            edge[i][j] = 0; //初始化邻接矩阵
        }
    }

    cout << "input adjacency matrix:" << endl;
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            cin >> edge[i][j];
        }
    }
}

int Floyd(int vNum, int a, int b)
{
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            dist[i][j] = edge[i][j]; //初始化矩阵dist
        }
    }

    //Floyd核心代码
    for (int k = 0; k < vNum; k++)
    {
        for (int i = 0; i < vNum; i++)
        {
            for (int j = 0; j < vNum; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    //更新值
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist[a - 1][b - 1];
}

/* 输入样例:
4 5
1 2 3 4
0 2 4 7
9 0 9 6
7 9 0 2
-3 4 6 0
1 4
*/

int main()
{
    cout << "input number of vertices and edges:" << endl;
    cin >> vNum >> eNum;
    cout << "input vertex:" << endl;
    initGraph(vNum, eNum);
    int a, b;
    cout << "input two vertices which you want to calculate" << endl;
    cin >> a >> b;
    int res = Floyd(vNum, a, b);
    cout << "The shortest distance from " << a << " to " << b << " is: " << res << endl;
    return 0;
}