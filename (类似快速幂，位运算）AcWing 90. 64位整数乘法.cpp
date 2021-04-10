#include <bits/stdc++.h>
using namespace std;

long long mul(long long a,long long b,long long p){
    long long ans = 0;
    for(;b;b>>=1) {
        if(b&1) ans = (ans+a)%p;
        a = a*2%p;
    }
    return ans;
}

int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    long long ans = mul(a,b,p);
    cout<<ans<<endl;
    return 0;
}
