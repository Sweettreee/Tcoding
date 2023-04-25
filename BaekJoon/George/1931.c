#include <stdio.h>
#define SIZE 10000

int I_x[SIZE];
int I_y[SIZE];

void merge(int l, int mid, int r)
{
    int left,k,q;
    int I_temp_x[SIZE];
    int I_temp_y[SIZE];
    left=l;
    k=l;
    q=mid+1;
    while(left<=mid && q<=r){
        if(I_y[left]<I_y[q]){
            I_temp_y[k]=I_y[left];
            I_temp_x[k++]=I_x[left++];
        }
        else if(I_y[left]==I_y[q]){
            if(I_x[left]<=I_x[q]){
                I_temp_y[k]=I_y[left];
                I_temp_x[k++]=I_x[left++];
            }
            else{
                I_temp_y[k]=I_y[q];
                I_temp_x[k++]=I_x[q++];
            }
        }
        else{
            I_temp_y[k]=I_y[q];
            I_temp_x[k++]=I_x[q++];
        }
    }
    if(left>mid){
        for(int i=q; i<=r; i++){
            I_temp_y[k]=I_y[i];
            I_temp_x[k++]=I_x[i];
        }
    }
    else{
        for(int i=left; i<=mid; i++){
            I_temp_y[k]=I_y[i];
            I_temp_x[k++]=I_x[i];
        }
    }
    for(int i=l; i<=r; i++){
        I_y[i]=I_temp_y[i];
        I_x[i]=I_temp_x[i];
    }
}

void merge_sort(int l, int r)
{
    int mid;
    if(l<r){
        mid = (l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,mid,r);
    }
}

int main(void)
{
    int N,avail_time=1,time;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &I_x[i], &I_y[i]);
    }
    merge_sort(0,N-1);
    time=I_y[0];
    for(int i=1; i<N; i++){
        if(time<=I_x[i]){
            time = I_y[i];
            avail_time++;
        }
    }
    printf("%d\n", avail_time);

    return 0;
}
