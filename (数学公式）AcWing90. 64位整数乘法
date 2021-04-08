//a * b mod p = a * b -(a*b/p)向下取整*p

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull mul(ull a,ull b,ull p){
    long long ans = 0;
    ull c = (long double) a*b/p;
    ans =(long long)((ull)a*b%p - (ull)c*p%p);
    if(ans<0) ans+=p;
    return ans;
}

int main(){
    ull a,b,p;
    cin>>a>>b>>p;
    ull ans = mul(a,b,p);
    cout<<ans<<endl;
    return 0;
}
