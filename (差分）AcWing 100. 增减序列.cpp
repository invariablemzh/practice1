//出现区间变化，由区间变化转换成单点变化
//在区间[l,r]中加d，B[l]+d,B[r+1]-d,其它不变

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int b[N];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i]-a[i-1];
    }
    long long cnt = 0;
    long long f = 0, z = 0;
    for(int i = 2;i<=n;i++){
        if(b[i]<0) f+=b[i];
        if(b[i]>0) z+=b[i];
    }
    f = -f;
    cnt = min(f,z);
    long long s = abs(f-z);
    long long sum = s+1;
    cnt = cnt+s;
    cout<<cnt<<endl<<sum<<endl;
}
