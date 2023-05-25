#include <iostream>

using namespace std;

long long remainder=1e9 + 7;

long long pow(int a, int b)
{
    long long temp;
    if(b==0) return 1;
    else if(b%2==0){
        temp = pow(a,b/2);
        return temp*temp%remainder;
    }
    else
        return a*pow(a,b-1)%remainder;
}

int main(void)
{
    int n,r;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> r;
        if(r==1 || r==2) cout << 1 << endl;
        else if(r==3) cout << 2 << endl;
        else cout << pow(2,r-2) << endl;
    }

    return 0;
}
