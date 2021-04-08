#include <bits/stdc++.h>
using namespace std;

int quick_power(long long a,long long b,long long m){
    long long ans = 1%m;
    for(;b;b>>=1){
        if(b&1){
            ans = ans*a%m;
        }
        a = a*a%m;
    }
    return ans;
}

int main(){
    long long z,m,h;
    cin>>z;
    while(z--){
        cin>>m>>h;
        long long ans = 0;
        while(h--){
            long long a,b;
            cin>>a>>b;
            ans=(ans+quick_power(a,b,m))%m;
        
        }
        cout<<ans<<endl;
    }
}
