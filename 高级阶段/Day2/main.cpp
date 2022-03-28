//完成有向图的邻接表初始化，完成深度优先遍历，广度优先遍历

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

//图的结构体，三个，图，顶点，顶点的边
// 邻接表中表对应的链表的顶点
typedef struct _ENode
{
    int ivex;                   // 该边所指向的顶点的位置,是数组的下标
    struct _ENode* next_edge;   // 指向下一条弧的指针
}ENode, * PENode;

// 邻接表中表的顶点
typedef struct _VNode
{
    char data;              // 顶点信息
    ENode* first_edge;      // 指向第一条依附该顶点的弧
}VNode;

// 邻接表
typedef struct _LGraph
{
    int vexnum;             // 图的顶点的数目
    int edgnum;             // 图的边的数目
    VNode vexs[MAX];        // 图的顶点有7个
}LGraph;

//返回对应顶点的下标
static int get_position(LGraph g, char ch)
{
    int i;
    for (i = 0; i < g.vexnum; i++)//去顶点结构体数组中遍历每个顶点0-6
        if (g.vexs[i].data == ch)
            return i;//返回的是对应顶点的下标
    return -1;
}

static void link_last(ENode* list, ENode* node)
{
    ENode* p = list;

    //找到最后一个节点
    while (p->next_edge)
    {
        p = p->next_edge;
    }
    //连接到最后一个节点
    p->next_edge = node;
}

LGraph* CreateGraphDirected()
{
    //图的初始化：顶点数组，边的二维数组，顶点个数，边的个数
    char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };//顶点数组
    char edges[][2] = {{'A', 'B'},{'B', 'C'},{'B', 'E'},{'B', 'F'},{'C', 'E'},
                        {'D', 'C'},{'E', 'B'},{'E', 'D'},{'F', 'G'} };//边的二维数组
    int vlen = sizeof(vexs) / sizeof(vexs[0]);//顶点个数
    int elen = sizeof(edges) / sizeof(edges[0]);//边的个数

    //创建有向图，采用邻接表法存储
    int i;//遍历循环
    int p1, p2;//p1,起点的下标 p2 终点的下标
    char c1, c2;//c1：边的起点 c2：边的终点
    ENode* node;
    LGraph* pG;


    pG = (LGraph*)malloc(sizeof(LGraph));//为图申请空间
    memset(pG, 0, sizeof(LGraph));//空间内数值初始化为0

    // 初始化"顶点数"和"边数"
    pG->vexnum = vlen;//7
    pG->edgnum = elen;//9
    // 初始化"邻接表"的顶点
    for (i = 0; i < pG->vexnum; i++)//0-6
    {
        pG->vexs[i].data = vexs[i];
        pG->vexs[i].first_edge = NULL;
    }

    // 初始化"邻接表"的边
    for (i = 0; i < pG->edgnum; i++)//0-8
    {
        // 读取边的起始顶点和结束顶点
        c1 = edges[i][0];//A
        c2 = edges[i][1];//B

        p1 = get_position(*pG, c1);//0
        p2 = get_position(*pG, c2);//1

        // 初始化node，node就是顶点链表中的节点 A->B node是B; B->C->E->F node是C，E，F
        node = (ENode*)calloc(1, sizeof(ENode));
        node->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if (pG->vexs[p1].first_edge == NULL)
        {
            pG->vexs[p1].first_edge = node;
        }
        else//不为空，连接到最后一个
        {
            link_last(pG->vexs[p1].first_edge, node);
        }
    }
    return pG;
}

 //深度优先搜索遍历图的递归实现
static void DFS(LGraph G, int i, int visited[])
{
    ENode* node;

    visited[i] = 1;//要访问当前结点了，所以打印
    printf("%2c", G.vexs[i].data);
    node = G.vexs[i].first_edge;//拿当前顶点的后面一个顶点,此时为B
    while (node != NULL)
    {
        if (!visited[node->ivex])//只要对应顶点没有访问过，深入到下一个顶点访问
            DFS(G, node->ivex, visited);
        node = node->next_edge;//某个顶点的下一条边，B<-E->D ,B被访问过，node为D，访问下一条边
    }
}
//深度优先搜索遍历图
//思想：访问到最后一位，回退到有分支的节点，继续访问，直至全部访问
void DFSTraverse(LGraph G)
{
    int i;
    int visited[MAX];       // 顶点访问标记，1：已经被访问

    // 初始化所有顶点都没有被访问
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    //从顶点A开始深度优先遍历
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])//0为假，！0为真
        {
            DFS(G, i, visited);
        }     
    }
    printf("\n");
}


//广度优先搜索（类似于树的层次遍历）
void BFS(LGraph G)
{
    int head = 0;       //辅助队列头
    int rear = 0;       //辅助队列尾
    int queue[MAX];     // 辅组队列
    int visited[MAX];   // 顶点访问标记
    int i, j, k;
    ENode* node;

    //每个顶点未被访问
    for (i = 0; i < G.vexnum; i++)//0-6
        visited[i] = 0;

    //从零号顶点开始遍历
    for (i = 0; i < G.vexnum; i++)//对每个连同分量均调用一次BFS
    {
        if (!visited[i])//如果没访问过，就打印，同时入队,最初是A
        {
            visited[i] = 1;//标记已经访问过
            printf("%2c", G.vexs[i].data);
            queue[rear] = i;  // 入队列
            rear++;             //head=0，rear=1
        }
        while (head != rear) //第一个进来的是A，遍历A的每一条边
        {
            j = queue[head];  // 出队列
            head++;             //head=1，rear=1
            node = G.vexs[j].first_edge;  //B
            while (node != NULL)    
            {
                k = node->ivex;         //B的边中下一个节点的下标
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%2c", G.vexs[k].data);
                    queue[rear] = k;//类似于树的层次遍历，遍历到的同时入队
                    rear++;
                }
                node = node->next_edge;
            }
        }
    }
    printf("\n");
}

int main()
{
    LGraph* pG;//声明图
    //pG存储的是地址 *pG结构体

    pG = CreateGraphDirected();//创建有向图
    DFSTraverse(*pG);//深度优先遍历
    BFS(*pG);//广度优先遍历
    return 0;
}