#include <stdio.h>

DataType FindMaxPoint() // 적절하게 매개변수를 선언하여 배열을 call by reference 로 전달받아 문제 해결을 위한 로직을 작성해주세요
{
    
}

int main(void)
{
    int n,m;
    int card[1000];
    int sum=0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &card[i]);
    }
    
    FindMaxPoint(배열을 전달해주세요); // 빈 칸안에 적절하게 채워넣어 배열을 포인터로 전달하세요
    // 그 합 또한 여기서는 계산하면 안됩니다. 전역변수로는 선언하지 마세요
    // 제가 적어놓은 것을 변형시켜서 문제를 풀어주세요


    printf("%d\n",sum);
    
    return 0;
}
