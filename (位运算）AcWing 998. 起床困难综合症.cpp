#include <bits/stdc++.h>
using namespace std;
pair<string,int> a[100005];
int n,m;

//每个a[i]中的数都取其在bit位的二进制数进行运算
int calc(int bit,int now){
    for(int i = 1;i<=n;i++){
        int x = a[i].second>>bit&1;
        if(a[i].first=="AND") now&=x;
        else if(a[i].first=="OR") now|=x;
        else now^=x;
    }
    return now;
}

int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int val = 0,ans = 0;
    for(int bit = 30;bit>=0;bit--){
        int res0 = calc(bit,0);
        int res1 = calc(bit,1);
        if(res0<res1&&val+(1<<bit)<=m){
            val+=(1<<bit),ans+=(res1<<bit);//除了多少，还回去多少
        }
        else ans+=(res0<<bit);
    }
    cout<<ans<<endl;
    return 0;
}
