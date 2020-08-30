#define maxSize 100
#ifndef ADJMATRIXGRAPH_H
#define ADJMATRIXGRAPH_H

//顶点类
class Vertex
{
public:
    Vertex(char info) { this->info = info; };
    char info;
};

//邻接矩阵无向图
class Graph
{
public:
    Graph();
    ~Graph();
    void AddVertex(char ch);  //增加顶点
    void AddEdge(char ch1, char ch2);   //两顶点间增加一条边
    void DeleteEdge(char ch1, char ch2);   //两顶点间删除一条边
    int Search(char ch);  //查找在顶点数组的下标
    void Print();   //打印邻接矩阵
    friend void DFS(Graph *G, int v);   //深度优先遍历，以顶点下标开始
    friend void DFS(Graph *G, char ch);   //深度优先遍历，以顶点字符开始
    friend void BFS(Graph *G, int v);  //广度优先遍历，以顶点下标开始
 
private:
    int adjMatrix[maxSize][maxSize];
    Vertex *vertices[maxSize]; //存放顶点信息
    int nCount;        //顶点数
};

#endif