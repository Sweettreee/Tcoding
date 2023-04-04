#include <stdio.h>
#define SIZE 1000

int Hide_Seek[SIZE];

typedef struct Queue{
    int rear,front;
    int data[SIZE];
}Queue;

void BFS(int N, int K)
{
    Queue q; 
    int here;

    q.front = -1;
    q.rear = -1;
    q.data[++q.rear] = N;
    Hide_Seek[q.data[q.rear]] = 0;
    
    while(q.front<q.rear)
    {
        here = q.data[++q.front];

        if(here==K) break;
        if(here+1<=100000 && Hide_Seek[here+1]==0){
            q.data[++q.rear] = here+1;
            Hide_Seek[here+1] = Hide_Seek[here] + 1;
        }
        if(here-1>=0 && Hide_Seek[here-1]==0){
            q.data[++q.rear] = here-1;
            Hide_Seek[here-1] = Hide_Seek[here] + 1;
        }
        if(here*2<=100000 && Hide_Seek[here*2]==0){
            q.data[++q.rear] = 2*here;
            Hide_Seek[2*here] = Hide_Seek[here] + 1;
        }
    }

}

int main(void)
{
    int N,K;
    scanf("%d %d", &N, &K);
    BFS(N,K);
    printf("%d\n", Hide_Seek[K]);

    return 0;
}
