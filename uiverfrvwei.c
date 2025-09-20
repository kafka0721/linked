#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* createheadnode()   //创建头节点
{
    node* headnode=(node*)malloc(sizeof(node));
    headnode->data=1;
    headnode->next=NULL;
    return headnode;
}

node* createnode(int value)    //在头节点之后，创建要头节点之后的其他节点
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
 
void printnode(node* headnode)   //对整个链表里面的数据进行打印
{
    node* move=headnode->next;
    while(move)
    {
        printf("%d ",move->data);
        move=move->next;
    }
}

void insertnodebyhead(node* headnode,int data)  //使用头插法来对整个链表进行元素插入
{
    node* newNode=createnode(data);
    newNode->next=headnode->next;
    headnode->next=newNode;

}

void insertnodebytail(node* headnode,int data)  //使用尾插法来对整个链表进行元素插入
{
    node* newNode=createnode(data);
    node* move=headnode;
    while(move->next!=NULL)
    {
        move=move->next;
    }
    move->next=newNode;
    
}

void deletenode(node* headnode,int data)  //删除某个节点操作
{
    node* pre=headnode;
    node* cur=headnode->next;
    while(cur->next!=NULL)
    {
        if(cur->data==data)
        {
            pre->next=cur->next;
            free(cur);
            return;
        }
        pre=cur;
        cur=cur->next;
    }
    printf("未找到该节点，无法删除");
}


int main()
{
    node* list=createheadnode();
    insertnodebyhead(list,1);
    insertnodebyhead(list,2);
    insertnodebyhead(list,3);
    insertnodebytail(list,4);
    insertnodebytail(list,5);
    insertnodebytail(list,6);
    deletenode(list,5);
    printnode(list);
    return 0;
}