#include <iostream>
#include <queue>
#include "AdjMatrixGraph.h"
using namespace std;

Graph::Graph()
{
    nCount = 0;
    for (int i = 0; i < maxSize; i++)
    {
        for (int j = 0; j < maxSize; j++)
        {
            adjMatrix[i][j] = 0; // 0表示无边
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < nCount; i++)
    {
        delete vertices[i];
    }
}

void Graph::AddVertex(char ch)
{
    vertices[nCount++] = new Vertex(ch); //创建一个新顶点
}

void Graph::AddEdge(char ch1, char ch2)
{
    int start = Search(ch1);
    int end = Search(ch2);
    if (start == -1 || end == -1)
    {
        cout << "Vertex not found!" << endl;
        return;
    }
    adjMatrix[start][end] = 1; //无向图的邻接矩阵是对称的
    adjMatrix[end][start] = 1; //有向图没有此句
}

void Graph::DeleteEdge(char ch1, char ch2)
{
    int start = Search(ch1);
    int end = Search(ch2);
    if (start == -1 || end == -1)
    {
        cout << "Vertex not found!" << endl;
        return;
    }
    adjMatrix[start][end] = 0; //0表示无边
    adjMatrix[end][start] = 0;
}

int Graph::Search(char ch)
{
    for (int i = 0; i < nCount; i++)
    {
        if (vertices[i]->info == ch)
        {
            return i; //返回下标
        }
    }
    return -1; //未找到，返回-1
}

void Graph::Print()
{
    cout << "   ";
    for (int i = 0; i < nCount; i++)
    {
        cout << vertices[i]->info << "  ";
    }
    cout << endl;
    for (int i = 0; i < nCount; i++)
    {
        cout << vertices[i]->info << "  ";
        for (int j = 0; j < nCount; j++)
        {
            cout << adjMatrix[i][j] << "  ";
        }
        cout << endl;
    }
}

bool isVisited[maxSize] = {false}; //默认为false
void DFS(Graph *G, int v)
{
    cout << G->vertices[v]->info << " ";
    isVisited[v] = true;                //标识该顶点已访问
    for (int i = 0; i < G->nCount; i++) //遍历顶点
    {
        if (!isVisited[i] && G->adjMatrix[v][i] == 1) //顶点未被访问且两顶点有边
        {
            DFS(G, i); //继续递归
        }
    }
}

bool isVisited2[maxSize]; //默认为false
void DFS(Graph *G, char ch)
{
    int index = G->Search(ch);
    cout << G->vertices[index]->info << " ";
    isVisited2[index] = true;
    for (int i = 0; i < G->nCount; i++)
    {
        if (!isVisited2[i] && G->adjMatrix[index][i] == 1)
        {
            DFS(G, G->vertices[i]->info);
        }
    }
}

void BFS(Graph *G, int v)
{
    bool visited[maxSize];
    queue<int> qu;
    qu.push(v); //当前顶点v入队
    while (!qu.empty())
    { //队不空就继续遍历
        int temp = qu.front();
        qu.pop();
        if (!visited[temp])
        {
            visited[temp] = true;   //设为已访问
            cout << G->vertices[temp]->info << " ";
            for (int i = 0; i < G->nCount; i++)   
            {
                if (!visited[i] && G->adjMatrix[temp][i]) //依次检查出队顶点的所有邻接顶点，未被访问且有边的顶点入队
                {
                    qu.push(i);
                }
            }
        }
    }
}

int main()
{
    Graph G;
    G.AddVertex('A');
    G.AddVertex('B');
    G.AddVertex('C');
    G.AddVertex('D');
    G.AddVertex('E');

    G.AddEdge('A', 'E');
    G.AddEdge('C', 'D');
    G.AddEdge('C', 'E');
    G.AddEdge('B', 'C');
    G.AddEdge('B', 'A');
    G.AddEdge('D', 'X'); //X不在图中，提示错误信息

    G.Print();
    cout << endl;

    DFS(&G, 0);
    cout << endl;
    BFS(&G, 0);
    cout << endl;

    cout << endl;
    G.DeleteEdge('A', 'B');
    G.Print();

    cout << endl;
    DFS(&G, 'A'); //删除A到B的边后，此图仍是连通图


    return 0;
}