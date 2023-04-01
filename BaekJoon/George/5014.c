#include <stdio.h>
#include <stdbool.h>
#define SIZE 1000009

int sum[SIZE];

void init_sum(int F)
{
    for(int i=0; i<=F; i++){
        sum[i]=0;
    }
}

typedef struct Queue
{
    int front, rear;
    int data[SIZE];
}Queue;

int BFS(int F, int S, int G, int U, int D)
{   
    Queue q;
    q.front = -1;
    q.rear = -1;

    int here;
    q.data[++q.rear] = S;
    sum[S]=0;
    
    while(q.front<q.rear){
        here = q.data[++q.front];

        if(here+U<=F && here!=G && (sum[here+U]==0 && here+U!=S)){
            q.data[++q.rear] = here+U;
            sum[here+U] = sum[here] + 1;
        }
        if(here-D>=1 && here!=G && (sum[here-D]==0 && here-D!=S)){
            q.data[++q.rear] = here-D;
            sum[here-D] = sum[here] + 1;
        }
        if(here==G) break;
    }
    if(here==G)
        return true;
    else
        return false;
}

int main(void)
{
    int F,S,G,U,D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    init_sum(F);
    if(BFS(F,S,G,U,D)==true)
        printf("%d\n", sum[G]);
    else
        printf("use the stairs\n");

    return 0;
}
