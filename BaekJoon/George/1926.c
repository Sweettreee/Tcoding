#include <stdio.h>
#define SIZE 505

int graph[SIZE][SIZE];
int n,m;
int area=0;

void DFS(int x, int y)
{
    graph[y][x] = 0;
    area++;

    if(x+1<m && graph[y][x+1]==1) DFS(x+1,y);
    if(x-1>=0 && graph[y][x-1]==1) DFS(x-1,y);
    if(y+1<n && graph[y+1][x]==1) DFS(x,y+1);
    if(y-1>=0 && graph[y-1][x]==1) DFS(x,y-1);
}

int main(void)
{
    int count=0,max=0,tmp;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==1){
                DFS(j,i);
                max = (area>max) ? area : max;
                area=0;
                count++;
            }
        }
    }
    printf("%d\n%d\n", count, max);

    return 0;
}
