#include <stdio.h>
#define SIZE 55

char treasure[SIZE][SIZE]={0,};
int sum[SIZE][SIZE]={0,};
int queue_x[2600];
int queue_y[2600];

void init_sum(int N, int M)
{
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            sum[i][j]=0;
        }
    }
}

int BFS(int x, int y, int N, int M)
{
    int here,there;
    int rear=-1, front=-1;
    int max=0;

    sum[y][x]=1;
    queue_x[++rear] = x;
    queue_y[rear] = y;

    while(rear>front){
        here = queue_y[++front];
        there = queue_x[front];
        if(treasure[here][there+1]=='L' && sum[here][there+1]==0 && there+1<M){
            sum[here][there+1] = sum[here][there] + 1;
            queue_x[++rear] = there+1;
            queue_y[rear] = here;
            if(max < (sum[here][there] + 1)) max = sum[here][there] + 1;
        }
        if(treasure[here][there-1]=='L' && sum[here][there-1]==0 && there-1>=0){
            sum[here][there-1] = sum[here][there] + 1;
            queue_x[++rear] = there-1;
            queue_y[rear] = here;
            if(max < (sum[here][there] + 1)) max = sum[here][there] + 1;
        }
        if(treasure[here+1][there]=='L' && sum[here+1][there]==0 && here+1<N){
            sum[here+1][there] = sum[here][there] + 1;
            queue_x[++rear] = there;
            queue_y[rear] = here+1;
            if(max < (sum[here][there] + 1)) max = sum[here][there] + 1;
        }
        if(treasure[here-1][there]=='L' && sum[here-1][there]==0 && here-1>=0){
            sum[here-1][there] = sum[here][there] + 1;
            queue_x[++rear] = there;
            queue_y[rear] = here-1;
            if(max < (sum[here][there] + 1)) max = sum[here][there] + 1;
        }
    }

    return max;
}

int main(void)
{
    int N,M,tmp,max=0;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1s", &treasure[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(treasure[i][j]=='L'){
                tmp = BFS(j,i,N,M);
                if(max<tmp) max = tmp;
                init_sum(N,M);
            }
        }
    }
    printf("%d\n", max-1);

    return 0;
}
