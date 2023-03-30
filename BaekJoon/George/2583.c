#include <stdio.h>
#define SIZE 105

int graph[SIZE][SIZE];
int domain[SIZE];
int count=0;

void init_graph(int M, int N)
{
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            graph[i][j]=1;
        }
    }
}

void DFS(int x,int y, int M, int N)
{
    graph[y][x]=0;
    count++;

    if(y-1>=0 && graph[y-1][x]==1) DFS(x,y-1,M,N);
    if(x-1>=0 && graph[y][x-1]==1) DFS(x-1,y,M,N);
    if(y+1<M && graph[y+1][x]==1) DFS(x,y+1,M,N);
    if(x+1<N && graph[y][x+1]==1) DFS(x+1,y,M,N);
}

void merge(int l, int mid, int r)
{
    int temp[SIZE];
    int left,q,k;
    left=l;
    k=l;
    q=mid+1;
    while(left<=mid && q<=r){
        if(domain[left]<domain[q]){
            temp[k++]=domain[left++];
        }
        else{
            temp[k++]=domain[q++];
        }
    }
    if(left>mid){
        for(int i=q; i<=r; i++){
            temp[k++]=domain[i];
        }
    }
    else{
        for(int i=left; i<=mid; i++){
            temp[k++]=domain[i];
        }
    }
    for(int i=l; i<=r; i++){
        domain[i]=temp[i];
    }
}

void merge_sort(int l, int r)
{
    int mid;
    if(l<r){
        mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);
    }
}

int main(void)
{
    int x,y,z,s;
    int M,N,K; // width, length
    int num=0,Num_domain=0;
    scanf("%d %d %d",&M,&N,&K);
    init_graph(M,N);
    for(int i=0; i<K; i++){
        scanf("%d %d %d %d", &x,&y,&z,&s);
        for(int j=M-s; j<M-y; j++){
            for(int l=x; l<z; l++){
                graph[j][l]=0;
            }
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j]==1){
                count=0;
                DFS(j,i,M,N);
                domain[num++]=count;
                Num_domain++;
            }
        }
    }
    merge_sort(0,num-1);
    printf("%d\n", num);
    for(int i=0; i<num; i++){
        printf("%d ", domain[i]);
    }
    printf("\n");

    return 0;
}
