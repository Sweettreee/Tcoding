#include <stdio.h>
#define SIZE 100

int tree[SIZE][SIZE]={0,};
int visited[SIZE]={0,};
int head[SIZE]={0,};
int count=0;

void DFS(int cur, int n)
{
    int check=0;
    visited[cur]=1;
    for(int i=0; i<=n; i++){
        if(tree[cur][i]==1 && visited[i]==0){
            check=1;
            DFS(i,n);
        }
    }
    if(check==0)
        count++;
}

void Erase_DFS(int cur, int n)
{
    visited[cur]=1;
    for(int i=0; i<=n; i++){
        if(tree[cur][i]==1 && visited[i]==0 && i!=head[cur]){
            tree[cur][i]=0;
            Erase_DFS(i,n);
        }
    }
}

int main(void)
{
    int N,temp,h=0,remove,root;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &temp);
        if(temp>=0)
        {
            tree[temp][h]=1;
            head[h]=temp;
            tree[h++][temp]=1;   
        }
        else{
            root=h;
            head[h]=50;
            tree[h][h]=2;
            h++;
        }
    }
    scanf("%d", &remove);
    Erase_DFS(remove,h-1);
    if(remove!=root)
        DFS(root,h-1);
    printf("%d\n", count);

    return 0;
}
