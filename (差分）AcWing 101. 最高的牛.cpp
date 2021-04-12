//让数组C中下标为Ai+1到Bi-1的数都减去1的操作<->新建一个数组D，对于每对Ai，Bi，令D[Ai+1]减去1，D[Bi]加上1，C等于D的前缀和
//把对一个区间的操作转化为左右两个端点上的操作

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int c[N],d[N];
map<pair<int,int>,bool> existed;//判断是否两个数同时出现

int main(){
    int n,p,h,m;
    cin>>n>>p>>h>>m;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(existed[make_pair(a,b)]) continue;
        d[a+1]--,d[b]++;
        existed[make_pair(a,b)] = true;
    }
    for(int i = 1;i<=n;i++){
        c[i] = c[i-1] + d[i];
        cout<<h+c[i]<<endl;
    }
    return 0;

}
