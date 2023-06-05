#include <stdio.h>
#define SIZE_map 1005
#define SIZE_q 1000000

int map[SIZE_map][SIZE_map];
int queue_x[SIZE_q];
int queue_y[SIZE_q];

void BFS(int x, int y, int n, int m)
{
    int there,here;
    int rear=-1,front=-1;

    queue_x[++rear] = x;
    queue_y[rear] = y;

    while(rear>front){
        here = queue_y[++front];
        there = queue_x[front];
        if(here-1>=0 && map[here-1][there]==1){
            map[here-1][there] = map[here][there] + 1;
            queue_x[++rear] = there;
            queue_y[rear] = here-1;
        }
        if(here+1<n && map[here+1][there]==1){
            map[here+1][there] = map[here][there] + 1;
            queue_x[++rear] = there;
            queue_y[rear] = here+1;
        }
        if(there-1>=0 && map[here][there-1]==1){
            map[here][there-1] = map[here][there]+ 1;
            queue_x[++rear] = there-1;
            queue_y[rear] = here;
        }
        if(there+1<m && map[here][there+1]==1){
            map[here][there+1] = map[here][there] + 1;
            queue_x[++rear] = there+1;
            queue_y[rear] = here;
        }
    }
}

int main(void)
{
    int n,m,zero_x,zero_y;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==2){
                zero_x = j;
                zero_y = i;
                map[i][j]=0;
            }
        }
    }
    BFS(zero_x,zero_y,n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i==zero_y-1 && j==zero_x) || (i==zero_y+1 &&j==zero_x) || (i==zero_y && j==zero_x-1) || (i==zero_y && j==zero_x+1)){
                if(map[i][j]==0)
                    printf("%d ", map[i][j]);
                else
                    printf("1 ");
            }
            else if(map[i][j]==1)
                printf("-1 ");
            else
                printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
