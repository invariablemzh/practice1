#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> calc(ll n,ll m){
    if(n==0) return make_pair(0,0);
    ll len = 1ll<<(n-1),cnt = 1ll<<(2*n-2);
    pair<ll,ll> pos = calc(n-1,m%cnt);//得到n-1时的坐标
    ll x = pos.first,y = pos.second;
    ll z = m/cnt;
    if(z==0) return make_pair(y,x);//顺时针，用矩阵，（0，0）为起点
    else if(z==1) return make_pair(x,y+len);
    else if(z==2) return make_pair(x+len,y+len);
    else return make_pair(2*len-y-1,len-x-1);//旋转+翻转，
}


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        auto ac = calc(n,a-1);
        auto bc = calc(n,b-1);
        ll dx = ac.first-bc.first;
        ll dy = ac.second-bc.second;
        double ans = sqrt(dx*dx+dy*dy)*10;
        printf("%.0lf\n",ans);
    }
    return 0;
}
