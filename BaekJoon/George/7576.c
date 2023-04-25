#include <stdio.h>
#include <stdbool.h>
#define SIZE 1005
#define Qu_SIZE 1000050

int tomato[1500][1500];
int queue_x[Qu_SIZE];
int queue_y[Qu_SIZE];

int IsFull(int x, int y)
{
    int sum=0;
    for(int i=0; i<=y; i++){
        for(int j=0; j<=x; j++){
            if(tomato[i][j]==1 || tomato[i][j]==-1){
                sum++;
            }
        }
    }
    if(sum==(x+1)*(y+1))
        return true;
    else
        return false;
}

void BFS(int x, int y,int r)
{
    int here=0,there=0,count=0,check,re,fr;
    int rear=r;
    int front=-1;
    while(rear>front){
        re=rear; fr=front;
        check=0;
        while(re>fr) {
            ++fr;
            here=queue_y[++front];
            there=queue_x[front];
            if(tomato[here-1][there]==0 && here-1>=0){
                tomato[here-1][there]=1;
                queue_x[++rear]=there;
                queue_y[rear]=here-1;
                check++;
            }
            if(tomato[here+1][there]==0 && here+1<=y){
                tomato[here+1][there]=1;
                queue_x[++rear]=there;
                queue_y[rear]=here+1;
                check++;
            }
            if(tomato[here][there-1]==0 && there-1>=0){
                tomato[here][there-1]=1;
                queue_x[++rear]=there-1;
                queue_y[rear]=here;
                check++;
            }
            if(tomato[here][there+1]==0 && there+1<=x){
                tomato[here][there+1]=1;
                queue_x[++rear]=there+1;
                queue_y[rear]=here;
                check++;
            }
        }
        if(check>0)
            count++;
    }
    if(IsFull(x,y)==true)
        printf("%d\n", count);
    else
        printf("-1\n");
}

int main(void)
{
    int M,N,rear=-1;
    scanf("%d %d", &M, &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j]==1){
                queue_x[++rear]=j;
                queue_y[rear]=i;
            }
        }
    }
    if(IsFull(M-1,N-1)==true)
        printf("0\n");
    else
        BFS(M-1,N-1,rear);

    return 0;
}
