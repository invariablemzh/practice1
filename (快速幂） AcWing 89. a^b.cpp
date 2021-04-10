#include <bits/stdc++.h>
using namespace std;

long long quick_power(long long a,long long b,long long m){
    long long ans = 1%m;//防止m=1
    for(;b;b>>=1){
        if(b&1) ans = ans*a%m;
        a = a*a%m;
    }
    return ans;
}

int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    long long ans = quick_power(a,b,p);
    cout<<ans<<endl;
    return 0;
}
