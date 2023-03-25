#include <stdio.h>
#define MAX 27

int N,count_per=0;
int graph[MAX][MAX];
int per[676];

void init_graph(void)
{
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            graph[i][j]=0;
        }
    }
}

void DFS(int x, int y)
{
    graph[y][x]=0;
    count_per++;

    if(graph[y+1][x]==1 && y+1<=N) DFS(x,y+1);
    if(graph[y-1][x]==1 && y-1>=1) DFS(x,y-1);
    if(graph[y][x-1]==1 && x-1>=1) DFS(x-1,y);
    if(graph[y][x+1]==1 && x+1<=N) DFS(x+1,y);
}

void merge(int l, int mid, int r)
{
    int left,k,q;
    int temp[676];
    left=l;
    k=l;
    q=mid+1;
    while(left<=mid && q<=r){
        if(per[left]<=per[q]){
            temp[k++]=per[left++];
        }
        else{
            temp[k++]=per[q++];
        }
    }
    if(left>mid){
        for(int i=q; i<=r; i++){
            temp[k++]=per[i];
        }
    }
    else{
        for(int i=left; i<=mid; i++){
            temp[k++]=per[i];
        }
    }
    for(int i=l; i<=r; i++){
        per[i]=temp[i];
    }
}

void merge_sort(int l, int r)
{
    int m;
    if(l<r){
        m=(l+r)/2;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,m,r);
    }
}

int main(void)
{
    int count=0,k=0;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(graph[i][j]==1){
                DFS(j,i);
                per[k++]=count_per;
                count_per=0;
                count++;
            }
        }
    }
    printf("%d\n", count);
    merge_sort(0,k-1);
    for(int i=0; i<k; i++){
        printf("%d\n", per[i]);
    }

    return 0;
}
