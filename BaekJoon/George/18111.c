#include <stdio.h>

int main(void)
{
    int minecraft[501][501]={0,};
    int N,M,B,min=256;
    long long taking_time=0;
    scanf("%d %d %d", &N, &M, &B);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &minecraft[i][j]);
            if(min>minecraft[i][j]) min = minecraft[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            taking_time += (minecraft[i][j]-min)*2;
            B += (minecraft[i][j]-min);
        }
    }
    long long minimum = taking_time;
    int floor = min;
    int t_floor = min;
    while(B>=0){
        if((B-(M*N))>=0){
            floor+=1;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(floor<=minecraft[i][j]){
                        taking_time-=2;
                    }
                    else{
                        taking_time+=1;
                    }
                }
            }
            if(taking_time<=minimum){
                minimum = taking_time;
                t_floor = floor;
            }
            B-=(M*N);
        }
        else
            break;
    }
    printf("%lld %d\n", minimum, t_floor);

    return 0;
}
