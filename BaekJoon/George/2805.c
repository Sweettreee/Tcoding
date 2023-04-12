#include <stdio.h>

long long tree[1000005]={0,},N,M;

long long sum_tree(long long height)
{
    long long sum=0;
    for(int i=0; i<N; i++){
        if(tree[i]>height)
            sum += (tree[i]-height);
    }
    return sum;
}

int lower_bound(int start, int end)
{
    int s,e;
    long long total;
    s = start;
    e = end;
    while(s<e){
        long long mid = (s+e)/2;
        total = sum_tree(mid);
        if(M<=total){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    total = sum_tree(e);
    while(total<M){
        e-=1;
        total = sum_tree(e);
    }
    return e;
}

int main(void)
{
    long long max=0;
    scanf("%lld %lld", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%lld", &tree[i]);
        if(tree[i]>max) max = tree[i];
    }
    printf("%d\n",lower_bound(0,max));

    return 0;
}
