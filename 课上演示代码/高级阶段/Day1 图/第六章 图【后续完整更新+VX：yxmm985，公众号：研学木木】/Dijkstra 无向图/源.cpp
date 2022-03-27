#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"cstring"
#include"cstdio"

using namespace std;
#define INF 0x7f7f7f7f

const int N = 5; //点的个数上限

int maze[N][N];
int dis[N];
bool vis[N];

//点的个数和边的条数
int n, m;

void init()
{
    memset(maze, INF, sizeof(maze));
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++)
    {
        maze[i][i] = 0;
    }
}

void dijkstra(int st)
{
    dis[st] = 0;
    for (int i = 0; i < n; i++)
    {
        //找到和起点距离最短的点
        int minx = INF;
        int minmark;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && dis[j] <= minx)
            {
                minx = dis[j];
                minmark = j;
            }
        }
        //并标记
        vis[minmark] = true;
        //更新所有和它连接的点的距离
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && dis[j] > dis[minmark] + maze[minmark][j])
                dis[j] = dis[minmark] + maze[minmark][j];
        }
    }
}


int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        //每组数据都要初始化
        init();
        for (int i = 1; i <= m; i++)
        {
            int x, y, len;
            scanf("%d %d %d", &x, &y, &len);
            if (x != y && maze[x][y] > len)
            {
                maze[y][x] = len;
                maze[x][y] = len;
            }
        }
        //以0为起点跑一次dij
        dijkstra(0);

    }
}
