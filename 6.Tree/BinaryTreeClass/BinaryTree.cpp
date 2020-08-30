#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include "BinaryTree.h"
#define maxSize 100
using namespace std;

Node *BinaryTree::Create()
{
    Node *bt = NULL;
    char ch;
    cin >> ch;
    // '#'表示空树
    if (ch == '#')
    {
        return NULL;
    }
    else
    {
        bt = new Node();
        bt->data = ch;
        if (this->root == NULL) //当前树的根节点为空就赋值
        {
            this->root = bt;
        }
        // root = (Node *) malloc(sizeof(Node));
        bt->lchild = Create(); //继续遍历左右子树
        bt->rchild = Create();
    }
    return bt;
}

void BinaryTree::PreOrder(Node *p) //”根左右“
{
    if (p) //不为空就继续循环
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void BinaryTree::PreOrderNonRecursive(Node *p)
{
    if (p)
    {
        Node *st[maxSize];
        Node *q;
        int top = -1;     //初始化栈顶指针为-1
        st[++top] = p;    //根结点入栈
        while (top != -1) //栈空即停止循环
        {
            q = st[top--]; //栈顶元素出栈
            cout << q->data << " ";
            if (q->rchild) //先进栈的元素后出栈，所以先进右孩子（先序遍历先访问左孩子再访问右孩子）
            {
                st[++top] = q->rchild;
            }
            if (q->lchild)
            {
                st[++top] = q->lchild;
            }
        }
    }
}

void BinaryTree::InOrder(Node *p) //”左根右“
{
    if (p) //不为空就继续循环
    {

        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void BinaryTree::InOrderNonRecursive(Node *p)
{
    /**
     * 1. 根结点入栈
     * 2. 如果栈顶结点左孩子存在，则左孩子入栈；如果栈顶结点左孩子不存在，则栈顶结点出栈并输出，
     * 同时检查其右孩子是否存在，若存在则右孩子入栈
     * 3. 循环第二步直到栈空
    */
    if (p)
    {
        Node *st[maxSize];
        int top = -1;
        Node *q = p; //q指向根结点
        while (top != -1 || q != NULL)
        { //栈空或根结点的右子树还未遍历完
            while (q)
            { //左孩子存在，则左孩子入栈
                st[++top] = q;
                q = q->lchild;
            }
            if (top != -1)
            { //栈不空则出栈并输出
                q = st[top--];
                cout << q->data << " ";
                q = q->rchild;
            }
        }
    }
}

void BinaryTree::PostOrder(Node *p) //”左右根“
{
    if (p) //不为空就继续循环
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void BinaryTree::PostOrderNonRecursive(Node *p)
{
    if (p)
    {
        Node *st1[maxSize]; //第一个栈存储逆后序遍历结果，并将遍历结果压入第二个栈
        Node *st2[maxSize]; //第二个栈出栈顺序即为后序遍历序列
        int top1 = -1, top2 = -1;
        st1[++top1] = p;
        Node *q = NULL;
        while (top1 != -1)
        {
            q = st1[top1--];
            st2[++top2] = q;
            if (q->lchild) //先序遍历左右子树遍历顺序交换即为逆后序遍历顺序
            {
                st1[++top1] = q->lchild;
            }
            if (q->rchild)
            {
                st1[++top1] = q->rchild;
            }
        }
        while (top2 != -1)
        {
            q = st2[top2--];
            cout << q->data << " ";
        }
    }
}

// void BinaryTree::LevelOrder(Node *p)    //自实现队列
// {
//     int front = 0, rear = 0;
//     Node *qu[maxSize];
//     Node *q;
//     if (p)
//     {
//         rear = (rear + 1) % maxSize;
//         qu[rear] = p; //根结点入队
//         while (front != rear)
//         {
//             front = (front + 1) % maxSize;
//             q = qu[front]; //队头结点出队
//             cout << q->data << " ";
//             if (q->lchild) //左子树不空，则左子树的根结点入队
//             {
//                 rear = (rear + 1) % maxSize;
//                 qu[rear] = q->lchild;
//             }
//             if (q->rchild)
//             {
//                 rear = (rear + 1) % maxSize;
//                 qu[rear] = q->rchild;
//             }
//         }
//     }
// }

void BinaryTree::LevelOrder(Node *p) //STL
{
    queue<Node *> qu;
    Node *q;
    if (p)
    {
        qu.push(p);
        while (!qu.empty())
        {
            q = qu.front();
            qu.pop();
            cout << q->data << " ";
            if (q->lchild) //左子树不空，则左子树的根结点入队
            {
                qu.push(q->lchild);
            }
            if (q->rchild)
            {
                qu.push(q->rchild);
            }
        }
    }
}

bool BinaryTree::IsEmpty(Node *p)
{
    return root == NULL;
}

Node *BinaryTree::Search(Node *p, char ch)
{
    Node *q = NULL;
    if (p) //树空则什么都不做，q保持NULL值
    {
        if (p->data == ch)
        {
            q = p; //找到，q指向值为ch的结点
        }
        else
        {
            if (!q) //根结点未查到，搜左子树
            {
                q = Search(p->lchild, ch);
            }
            if (!q) //左子树未查到，搜右子树
            {
                q = Search(p->rchild, ch);
            }
        }
    }
    return q;
}

bool BinaryTree::IsLeafNode(Node *p)
{
    return (!p->lchild && !p->rchild); //没有左孩子和右孩子
}

bool BinaryTree::IsFull(Node *p)
{
    if (pow(2, GetDepth(p)) - 1 == CountAllNodes(p)) //设高度为k，如果结点数=2的k次方-1，则为满二叉树
    {
        return true;
    }
    return false;
}

bool BinaryTree::IsComplete(Node *p)
{
    bool flag = false;
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        Node *q = qu.front();
        if (!flag)
        {
            //当前节点有左右孩子
            if (q->lchild && q->rchild)
            {
                qu.push(q->lchild);
                qu.push(q->rchild);
            }
            //当前节点只有左孩子，他之后的节点不能有孩子
            else if (q->lchild)
            {
                qu.push(q->lchild);
                flag = true;
            }
            //当前节点只有右孩子
            else if (q->rchild)
            {
                return false;
            }
            //当前节点没有孩子，判断其下一个节点
            else
            {
                flag = true;
            }
        }
        else
        {
            if (q->lchild || q->rchild)
                return false;
        }
        qu.pop();
    }
    return true;
}

int BinaryTree::GetDepth(Node *p)
{
    int leftDepth, rightDepth;
    if (!p)
    {
        return 0; //空树深度为0
    }
    else
    {
        leftDepth = GetDepth(p->lchild);
        rightDepth = GetDepth(p->rchild);
        //返回左、右子树深度的最大值加1即为整棵树的深度
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

int BinaryTree::CountAllNodes(Node *p)
{
    if (!p)
    {
        return 0; //树空，返回0
    }
    int lcount = CountAllNodes(p->lchild);
    int rcount = CountAllNodes(p->rchild);
    return lcount + rcount + 1; //左子树结点数+右子树结点数+根结点
}

int BinaryTree::CountLeafNodes(Node *p)
{
    if (!p)
    {
        return 0; //树空，返回0
    }
    if (IsLeafNode(p))
    { //左右孩子均为空，是叶结点
        return 1;
    }
    else
        return CountLeafNodes(p->lchild) + CountLeafNodes(p->rchild);
}

int BinaryTree::CountDoubleBranches(Node *p)
{
    return CountLeafNodes(p) - 1; //双分枝数=叶结点数-1
}

int BinaryTree::CountBranches(Node *p)
{
    return CountAllNodes(p) - 1; //总分枝数=总结点数-1
}

int i, top;
char pathStack[maxSize];
void BinaryTree::PrintAllPath(Node *p)
{
    if (p)
    {
        pathStack[top] = p->data;
        ++top;
        if (IsLeafNode(p)) //当前结点是叶节点则打印路径
        {
            for (int i = 0; i < top; i++)
            {
                cout << pathStack[i] << " ";
            }
            cout << endl;
        }
        PrintAllPath(p->lchild);
        PrintAllPath(p->rchild);
        --top;
    }
}

void BinaryTree::Clear(Node *p)
{
    if (p)
    {
        Clear(p->lchild);
        Clear(p->rchild);
        delete p;
        p = NULL;
    }
}

Node *BinaryTree::GetRoot()
{
    return root;
}

int main()
{
    BinaryTree T;
    cout << "Input tree: (e.g. ABC##DE#G##F###)" << endl;
    /*
         输入样例的二叉树图形
                A
              /
            B
          /  \
        C     D
            /  \
          E     F
           \
            G
    */
    T.Create();

    cout << endl;
    cout << "Preorder traversal:" << endl;
    // T.PreOrder(T.GetRoot());
    T.PreOrderNonRecursive(T.GetRoot());
    cout << endl;

    cout << "Inorder traversal:" << endl;
    // T.InOrder(T.GetRoot());
    T.InOrderNonRecursive(T.GetRoot());
    cout << endl;

    cout << "Postorder traversal:" << endl;
    // T.PostOrder(T.GetRoot());
    T.PostOrderNonRecursive(T.GetRoot());
    cout << endl;

    cout << "Level order traversal:" << endl;
    T.LevelOrder(T.GetRoot());
    cout << endl;

    cout << endl;
    cout << "AllPath(root node: A):" << endl;
    T.PrintAllPath(T.GetRoot());
    cout << endl;

    cout << "AllPath(root node: D):" << endl;
    T.PrintAllPath(T.Search(T.GetRoot(), 'D')); //以D为根结点的树的所有到叶节点访问路径
    cout << endl;

    cout << "Depth of tree:" << T.GetDepth(T.GetRoot()) << endl;

    char key = 'H';
    if (T.Search(T.GetRoot(), key)) //函数返回不为空则为key在树中
    {
        cout << key << " is in the tree" << endl;
    }
    else
    {
        cout << key << " is not in the tree" << endl;
    }

    // cout << T.IsLeafNode(T.Search(T.GetRoot(), 'G')) << endl;

    cout << "Count of nodes:" << T.CountAllNodes(T.GetRoot()) << endl;
    cout << "Count of leaf nodes:" << T.CountLeafNodes(T.GetRoot()) << endl;
    cout << "Count of double branches:" << T.CountDoubleBranches(T.GetRoot()) << endl;
    cout << "Count of branches:" << T.CountBranches(T.GetRoot()) << endl;

    cout << T.IsComplete(T.GetRoot()) << endl;

    return 0;
}