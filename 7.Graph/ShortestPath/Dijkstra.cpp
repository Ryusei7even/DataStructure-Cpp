#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define maxSize 10000
#define INF 9999999
bool visited[maxSize];
int path[maxSize];          //记录路径
int cost[maxSize][maxSize]; //边权
int dist[maxSize];          //最短路值
int vNum, eNum;             //顶点和边
int u, v, c;                //边的端点，权值

void printPath(int *path, int b)
{
    stack<int> st;
    //叶节点到根结点的顺序入栈
    while (path[b] != -1)
    {
        st.push(b);
        b = path[b];
    }
    st.push(b);
    while (!st.empty())
    {
        cout << st.top() << " "; //顶点逆序打印
        st.pop();
    }
    cout << endl;
}

void Dijkstra(int cost[][maxSize], int dist[], int n, int start)
{
    //初始化
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = false; //visited置否
        path[i] = -1;       //初始无路径
    }
    //初始化
    dist[start] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = -1;
        int Min = INF; //为了更新最小值，设为INF
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < Min) //未访问过且长度小于当前最小值
            {
                Min = dist[j]; //更新最短路径和顶点
                k = j;
            }
        }
        if (k == -1)
            break;
        visited[k] = true; //已访问
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[k] + cost[k][j] < dist[j])   //顶点k的加入是否会出现通往顶点j的更改路径
            {
                dist[j] = dist[k] + cost[k][j];
                path[j] = k;
            }
        }
    }
}

/*
测试输入样例
5 9

1 2 60
1 3 11  
1 4 24
2 3 20
2 4 30
2 5 617
3 4 100
3 5 9
4 5 18

1 5
*/

int main(void)
{

    cout << "Input number of vertices and edges:" << endl;
    cin >> vNum >> eNum;

    cout << "Input vertex and cost:" << endl;
    //cost初始化为最大值
    memset(cost, INF, sizeof(cost));
    for (int i = 0; i < eNum; i++)
    {
        cin >> u >> v >> c;
        cost[u][v] = c;
        cost[v][u] = c;
    }
    int a, b;
    cout << "Input two vertices which you want to calculate" << endl;
    cin >> a >> b;
    Dijkstra(cost, dist, vNum, a);
    cout << "The shortest distance from " << a << " to " << b << " is: " << dist[b] << endl;
    cout << "Path: " << endl;
    printPath(path, b);
    return 0;
}