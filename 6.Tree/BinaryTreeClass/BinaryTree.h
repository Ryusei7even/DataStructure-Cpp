#ifndef BinaryTree_H
#define BinaryTree_H

class Node
{
public:
    Node() { lchild = rchild = NULL; }
    friend class BinaryTree;
    char data;
    Node *lchild;
    Node *rchild;
};

//二叉链表存储二叉树
class BinaryTree
{
public:
    BinaryTree() { root = NULL; };
    ~BinaryTree() { delete root; };
    Node *Create();                     //使用字符数组先序序列创建二叉树
    void PreOrder(Node *p);             //先序遍历打印
    void PreOrderNonRecursive(Node *p); //用栈实现非递归遍历
    void InOrder(Node *p);              //中序遍历打印
    void InOrderNonRecursive(Node *p);
    void PostOrder(Node *p); //后序遍历打印
    void PostOrderNonRecursive(Node *p);
    void LevelOrder(Node *p); //循环队列实现层次遍历
    bool IsEmpty(Node *p);
    Node *Search(Node *p, char ch);   //判断节点是否存在
    bool IsLeafNode(Node *p);         //判断是否为叶子结点
    bool IsFull(Node *p);             //判断是否为满二叉树
    bool IsComplete(Node *p);         //判断是否为完全二叉树
    int GetDepth(Node *p);            //求树深度
    int CountAllNodes(Node *p);       //求树的所有结点数
    int CountLeafNodes(Node *p);      //求树的叶结点数
    int CountDoubleBranches(Node *p); //求树的双分支数
    int CountBranches(Node *p);       //求树的总分支数
    void PrintAllPath(Node *p);       //输出从根节点到所有叶节点的路径
    void Clear(Node *p);
    Node *GetRoot();

private:
    Node *root; //树根节点
};

#endif