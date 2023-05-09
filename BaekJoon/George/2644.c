#include <stdio.h>
#define SIZE 105

int fam[SIZE][SIZE]={0,};
int sum[SIZE]={0,};
int discovered[SIZE]={0,};
int queue[SIZE];
int count=0;

int BFS(int n,int x, int y)
{
    int here,there,check=0;
    int front=-1,rear=-1;

    discovered[x]=1;
    sum[x]=0;
    queue[++rear]=x;
    
    while(rear>front){
        here = queue[++front];

        for(int i=0; i<=n; i++){
            if(fam[here][i]==1){
                there = i;

                if(discovered[there]==0){
                    sum[there] = sum[here] + 1;
                    discovered[there]=1;
                    queue[++rear]=there;
                }
            }
            if(there==y){
                check=1;
                break;
            }
        }
        if(check==1)
            break;
    }
    if(check==1)
        return 2;
    else
        return 0;
}

int main(void)
{
    int N,a,b,x,y,mum_child,max=0,possible;
    scanf("%d %d %d %d", &N, &a, &b, &mum_child);
    x = (a>b) ? b : a;
    y = (a>b) ? a : b;
    for(int i=0; i<mum_child; i++){
        scanf("%d %d", &a, &b);
        if(max<b)
            max=b;
        fam[a][b]=1;
        fam[b][a]=1;
    }
    possible = BFS(max,x,y);
    if(possible==2)
        printf("%d\n", sum[y]);
    else
        printf("-1\n");
    
    return 0;
}
