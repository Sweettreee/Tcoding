#include <stdio.h>
#define SIZE 105

int safe[SIZE][SIZE];
int graph[SIZE][SIZE];
int N,count=0;

void init_graph(void)
{
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            graph[i][j]=safe[i][j];
        }
    }
}

void DFS(int x, int y,int k)
{
    graph[y][x]=0;

    if(graph[y+1][x]-k>=1 && y+1<=N) DFS(x,y+1,k);
    if(graph[y-1][x]-k>=1 && y-1>=1) DFS(x,y-1,k);
    if(graph[y][x-1]-k>=1 && x-1>=1) DFS(x-1,y,k);
    if(graph[y][x+1]-k>=1 && x+1<=N) DFS(x+1,y,k);
}

int main(void)
{
    int max=1,MAX=1;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &safe[i][j]);
            if(max<safe[i][j]) max=safe[i][j];
        }
    }
    for(int k=1; k<max; k++){
        init_graph();
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(graph[i][j]-k>=1){
                    DFS(j,i,k);
                    count++;
                }
            }
        }
        if(MAX<count) MAX=count;
        count=0;
    }
    printf("%d\n", MAX);
    
    return 0;
}
