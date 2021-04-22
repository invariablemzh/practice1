#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int prim[1000100];
int a[1000100];

int m = 0;
void primes(int n){
    memset(a,0,sizeof(a));
    for(int i = 2;i<=n;i++){
        if(a[i]==0) {a[i] = i;prim[++m] = i;}
        for(int j = 1;j<=m;j++){
            if(prim[j]>a[i]||prim[j]>n/i) break;
            a[i*prim[j]] = prim[j];
        }
    }
}
bool flag;
int n;

int main(){
    primes(1000090);
    long long cnt = 0;
    while(~scanf("%d",&n)){
        if(n==0) break;
        flag = false;
        int p = lower_bound(prim+1,prim+m+1,n)-prim;//不要漏掉-prim，不-prim是*p，指的是值；-prim是数组下标
        int k = p;
        for(int i = 1;i<=p;i++){
            int x = prim[i];
            if(x>=n) break;
            while(prim[k]+x<n&&k+1<=p) k++,cnt++;
            while(prim[k]+x>n&&k-1>=1) k--,cnt++;
            if(prim[k]+x==n){
                flag = true;
                printf("%d = %d + %d\n",n,x,prim[k]);
                break;
            }
            cnt++;
//        for(int i = 1;i<=*p;i++){
//            int x = prim[i];
//            if(x>=n) break;
//            for(int j = *p;j>=1;j--){
//                int y = prim[j];
//                cnt++;
//                if(y>=n||x+y>n) continue;
//                if(x+y<n) break;
//                if(x+y==n){
//                    flag = true;
//                    printf("%d = %d + %d\n",n,x,y);
//                    break;
//                }
//
//            }
//            if(flag) break;

        }
        if(!flag) printf("Goldbach's conjecture is wrong.\n");        
//         cout<<cnt<<endl;
    }
    return 0;
}
