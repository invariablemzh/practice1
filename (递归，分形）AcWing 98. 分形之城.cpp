#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> calc(long long n,long long m){
    if(n==0) return make_pair(0,0);
    long long len = 1ll<<(n-1),cnt = 1ll << (2*n-2);
    pair<long long,long long> pos = calc(n-1,m%cnt);
    long long x = pos.first,y = pos.second;
    long long z = m/cnt;
    if(z==0) return make_pair(y,x);
    if(z==1) return make_pair(x,y+len);
    if(z==2) return make_pair(x+len,y+len);
    return make_pair(2*len-1-y,len-x-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        pair<long long,long long> x = calc(n,a-1);
        pair<long long,long long> y = calc(n,b-1);
        long long dx = x.first-y.first,dy = x.second-y.second;
        double ans = (sqrt(dx*dx+dy*dy)*10);
        printf("%0.lf\n",ans);
    }
    return 0;
}
