#include <stdio.h>
#define SIZE 60

int graph[SIZE][SIZE];
int M,N,K; // width,height
    
void DFS(int x, int y)
{
    graph[x][y]=0;

    if(x+1<M && graph[x+1][y]==1) DFS(x+1,y);
    if(x-1>=0 && graph[x-1][y]==1) DFS(x-1,y);
    if(y+1<N && graph[x][y+1]==1) DFS(x,y+1);
    if(y-1>=0 && graph[x][y-1]==1) DFS(x,y-1);
}

int main(void)
{
    int T,x,y,count;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        count=0;
        scanf("%d %d %d", &M, &N, &K);
        for(int i=0; i<K; i++){
            scanf("%d %d", &x, &y);
            graph[x][y]=1;
        }
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j]==1){
                    DFS(i,j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}