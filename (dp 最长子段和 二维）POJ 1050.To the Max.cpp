
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N];
int n,maxx;

//把一列看作一个，当作一维来做
//h为所取的高度，k为h高度的起点
void solve(int h,int k){
    int tmp = 0;
    for(int j = 1;j<=n;j++){
        tmp += a[k+h-1][j] - a[k-1][j];
        if(tmp<0) tmp = 0;
        else if(tmp>maxx) maxx = tmp;
    }
}

int main(){
    while(~scanf("%d",&n)){
        memset(a,0,sizeof(a));
        maxx =0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++) {
                scanf("%d",&a[i][j]);
                a[i][j] += a[i-1][j];//a数组为列的前缀和
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n-i+1;j++){//防止高度超出数组
                solve(i,j);
            }
        }
        printf("%d\n",maxx);
    }
}
