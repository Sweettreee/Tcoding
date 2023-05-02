#include <stdio.h>
#define SIZE 100

int N;

void DFS(char grid[SIZE][SIZE], int x, int y, char var)
{
    grid[y][x] = 'A';
    if(grid[y-1][x]==var && y-1>=0) DFS(grid,x,y-1,var);
    if(grid[y+1][x]==var && y+1<N) DFS(grid,x,y+1,var);
    if(grid[y][x-1]==var && x-1>=0) DFS(grid,x-1,y,var);
    if(grid[y][x+1]==var && x+1<N) DFS(grid,x+1,y,var);

}

int main(void)
{
    char grid[SIZE][SIZE];
    char grid2[SIZE][SIZE];
    int count_non=0,count_yes=0;
    char var;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1s", &grid[i][j]);
            if(grid[i][j]=='G' || grid[i][j]=='R'){
                grid2[i][j] = 'R';
            }
            else
                grid2[i][j] = 'B';
        }
    }
    var='R';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]==var){
                DFS(grid,j,i,var);
                count_non++;
            }
            if(grid2[i][j]==var){
                DFS(grid2,j,i,var);
                count_yes++;
            }
        }
    }
    var='G';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]==var){
                DFS(grid,j,i,var);
                count_non++;
            }
        }
    }
    var='B';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]==var){
                DFS(grid,j,i,var);
                count_non++;
                count_yes++;
            }
        }
    }
    
    printf("%d %d\n", count_non, count_yes);

    return 0;
}
