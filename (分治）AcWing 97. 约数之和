//取余要到位，最好啥后面都放个取余，取余的优先级和*/一样
//约数之和为（p1^0 + p1^1 + p1^2+……+p1^b*c1）*（p2^0 + p2^1 + p2^2+……+p2^b*c2)*。。。 （^0）是不选的情况，每个数总共有有c1*B种变化
//分治能求出等比数列的和

#include <bits/stdc++.h>
using namespace std;
#define m 9901

long long power(long long a,long long b){
    long long ans = 1%m;
    for(;b;b>>=1){
        if(b&1) ans=(ans%m)*(a%m);
        a=(a%m)*(a%m);
    }
    return ans;
}

long long sum(long long p,long long c){
    if(c==0) return 1;
    if(c&1){
        return ((1+power(p,(c+1)/2))*sum(p,(c-1)/2))%m;
    }
    else{
        return ((1+power(p,c/2))*sum(p,c/2-1)+power(p,c))%m;
    }
}

vector<int> vec;

int main(){
    long long a,b;
    cin>>a>>b;
    long long ans = 1;
    for(long long i = 2;i<=a;i++){   //找出所有的最小的因数，再求可以多少幂（24 = 2^3 + 3^1）
        long long s = 0;
        while(a%i==0){
            s++;
            a/=i;
        }
        if(s) ans = ans%m*sum(i,s*b)%m;
    }
    if(a==0) cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
    
    
}
