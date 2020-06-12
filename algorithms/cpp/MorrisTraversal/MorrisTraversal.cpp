//
// Created by 王盟 on 2020/3/28.
//
#include <iostream>

using namespace std;

typedef int dataType;
struct Node
{
    dataType val;
    struct Node *left;
    struct Node *right;

    Node(dataType _val):
            val(_val), left(NULL), right(NULL){}
};

// Morris中序遍历 (左 -> 根 -> 右)
void MorrisInOrderTraverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *p1 = head;
    Node *p2 = NULL;

    while (p1 != NULL)
    {
        p2 = p1->left;
        if (p2 != NULL)
        {
            while(p2->right != NULL && p2->right != p1)
            {
                p2 = p2->right;
            }
            if (p2->right == NULL)
            {
                p2->right = p1;		// 空闲指针
                p1 = p1->left;
                continue;
            }
            else
            {
                p2->right = NULL;
            }
        }
        cout<<p1->val<<" ";
        p1 = p1->right;
    }
}

// Morris前序遍历 (根 -> 左 -> 右)
void MorrisPreOrderTraverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *p1 = head;
    Node *p2 = NULL;

    while (p1 != NULL)
    {
        p2 = p1->left;
        if (p2 != NULL)
        {
            while(p2->right != NULL && p2->right != p1)
            {
                p2 = p2->right;
            }
            if (p2->right == NULL)
            {
                p2->right = p1;		// 空闲指针
                cout<<p1->val<<" ";	// 打印结点值的顺序稍微调整
                p1 = p1->left;
                continue;
            }
            else
            {
                p2->right = NULL;
            }
        }
        else
        {
            cout<<p1->val<<" ";
        }
        p1 = p1->right;
    }
}

// 逆序右边界
Node* reverseEdge(Node *head)
{
    Node *pre = NULL;
    Node *next = NULL;

    while(head != NULL)
    {
        next = head->right;
        head->right = pre;
        pre = head;
        head = next;
    }

    return pre;
}

// 逆序打印左子树右边界
void printEdge(Node *head)
{
    Node *lastNode = reverseEdge(head);
    Node *cur = lastNode;

    while (cur != NULL)
    {
        cout<<cur->val<<" ";
        cur = cur->right;
    }
    reverseEdge(lastNode);
}

// Morris后序遍历 (左 -> 右 -> 根)
void MorrisPostOrderTraverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *p1 = head;
    Node *p2 = NULL;

    while (p1 != NULL)
    {
        p2 = p1->left;
        if (p2 != NULL)
        {
            while(p2->right != NULL && p2->right != p1)
            {
                p2 = p2->right;
            }
            if (p2->right == NULL)
            {
                p2->right = p1;		// 空闲指针
                p1 = p1->left;
                continue;
            }
            else
            {
                p2->right = NULL;
                printEdge(p1->left);
            }
        }
        p1 = p1->right;
    }
    printEdge(head);
}

void buildBinTree(Node **head)
{
    dataType _val;
    cin>>_val;

    if (_val == -1)
    {
        *head = NULL;
    }
    else
    {
        *head = (Node*)malloc(sizeof(Node));
        (*head)->val = _val;
        buildBinTree(&(*head)->left);
        buildBinTree(&(*head)->right);
    }
}

int main(void)
{
    Node *head;
    buildBinTree(&head);
    cout<<"前序遍历序列为:";
    MorrisPreOrderTraverse(head);
    cout<<endl;

    cout<<"中序遍历序列为:";
    MorrisInOrderTraverse(head);
    cout<<endl;

    cout<<"后序遍历序列为:";
    MorrisPostOrderTraverse(head);
    cout<<endl;

    return 0;
}