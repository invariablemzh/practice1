//  核心代码：
//    sort(a+1,a+n+1);
//    for(int i = 1;i<=n;i++){
//        if(i==1||a[i]!=a[i-1]) b[++m] = a[i];
//    }

//    int query(int x){
//       return lower_bound(b+1,b+m+1,x) - b;
//   }
#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a1[N];//第i个科学家懂得语言的编号，顺序与答案无关，有就行
int a[N],cnt[N];
int cnt1[N],cnt2[N];
struct node{
    int b,c;
}p[N];
//b是第 i 部电影的语音采用的语言的编号
//c是第 i 部电影的字幕采用的语言的编号

int n,m,s=0;
int query(int x){
    return lower_bound(a,a+s,x) - a;//返回第一个大于等于x的数组下标
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a1[i]);
    }
    sort(a1,a1+n);//先排序，
//    for(int i = 0;i<n;i++) cout<<a1[i]<<" ";
//    cout<<endl;
//     bool flag = false;
    for(int i = 0;i<n;i++){//数组离散化，以后可以的话学会map应该会方便点
        if(i==0||a1[i]!=a1[i-1]) {
            if(i==0) {
                a[s] = a1[i];
                while(a1[i+1]==a1[i]){//最好先判断再加
                    i++;
                    cnt[s]++;
                }
            }
            else {
                cnt[++s]++;
                a[s] = a1[i];
            }
        }
        if(i!=0&&a1[i]==a1[i-1]){
            cnt[s]++;
        }
    }
//    for(int i = 0;i<=s;i++) cout<<a[i]<<" ";
//    cout<<endl;
//    for(int i = 0;i<=s;i++) cout<<cnt[i]<<" ";
//    cout<<endl;
    scanf("%d",&m);
    for(int i = 0;i<m;i++) {
        scanf("%d",&p[i].b);
//        cout<<p[i].b<<" ";
        if(a[query(p[i].b)]==p[i].b){
            cnt1[i]+=cnt[query(p[i].b)];
        }
    }
//    for(int i = 0;i<s;i++){
//        cout<<cnt1[i]<<" ";
//    }
//    cout<<endl;
    for(int i = 0;i<m;i++) {
        scanf("%d",&p[i].c);
        if(a[query(p[i].c)]==p[i].c) {
            cnt2[i]+=cnt[query(p[i].c)];
        }
    }

    int tmp = 0,tmp1 = 0,ans = 0;
    for(int i = 0;i<m;i++){
        if(tmp<cnt1[i]) tmp = cnt1[i],tmp1 = cnt2[i],ans = i;
        else if(tmp==cnt1[i]&&cnt2[i]>tmp1) tmp = cnt1[i],tmp1 = cnt2[i],ans = i;
    }
    printf("%d\n",ans+1);
    return 0;
}
