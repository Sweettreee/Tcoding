#include <stdio.h>
#include <stdlib.h>
#define SIZE 55

int population[SIZE][SIZE];
int discovered[SIZE][SIZE]={0,};
int queue_x[2600];
int queue_y[2600];
int movement = 0;

void init_discoered(int N) // initialising discovered for checking all array again
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            discovered[i][j]=0;
        }
    }
}

void BFS(int x, int y, int N, int L, int R)
{
    int here, there;
    int rear=-1,front=-1;
    int sum=0,count=0,avg;
    int up,down,left,right;
    
    queue_x[++rear] = x;
    queue_y[rear] = y;
    discovered[y][x]=1;
    sum += population[y][x];
    count++;

    while(rear>front){
        here = queue_y[++front];
        there = queue_x[front];
        if(there-1>=0){
            left = abs(population[here][there-1]-population[here][there]); // checking left
            if(left>=L && left<=R && discovered[here][there-1]==0){
                discovered[here][there-1]=1;
                queue_x[++rear]= there-1;
                queue_y[rear] = here;
                sum += population[here][there-1];
                count++;
            }
        }
        if(there+1<N){
            right = abs(population[here][there+1]-population[here][there]); // checking right
            if(right>=L && right<=R && discovered[here][there+1]==0){
                discovered[here][there+1]=1;
                queue_x[++rear] = there+1;
                queue_y[rear] = here;
                sum += population[here][there+1];
                count++;
            }
        }
        if(here-1>=0){
            up = abs(population[here-1][there]-population[here][there]); // checking up
            if(up>=L && up<=R && discovered[here-1][there]==0){
                discovered[here-1][there]=1;
                queue_x[++rear] = there;
                queue_y[rear] = here-1;
                sum += population[here-1][there];
                count++;
            }
        }
        if(here+1<N){
            down = abs(population[here+1][there]-population[here][there]); // checking down
            if(down>=L && down<=R && discovered[here+1][there]==0){
                discovered[here+1][there]=1;
                queue_x[++rear] = there;
                queue_y[rear] = here+1;
                sum += population[here+1][there];
                count++;
            }
        }
    }
    avg = sum/count; // average of connected parts
    for(int i=0; i<=rear; i++){
        population[queue_y[i]][queue_x[i]] = avg;
    } // making equal to average 
    if(count>1) movement++; // for checking if there's more to excute
}

int main(void)
{
    int N,L,R,result=1,pop_move=0;
    scanf("%d %d %d", &N, &L, &R);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &population[i][j]);
        }
    }
    do{
        init_discoered(N);
        movement=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(discovered[i][j]==0){
                    BFS(j,i,N,L,R);
                }
            }
        }
        if(movement>0) pop_move++;
    } while(movement>0); // movement : excute more

    printf("%d\n", pop_move);

    return 0;
}
