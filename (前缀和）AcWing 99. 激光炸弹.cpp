#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int s[N][N];

int main(){
    int n,r;
    cin>>n>>r;
    int a = r,b= r;
    for(int i = 1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x++,y++;
        s[x][y] += z;//防止出现1 1 1两次
        a = max(x,a);//长可以作为循环限制
        b = max(y,b);//宽可以作为循环限制
    }
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];//根据公式求大小
        }
    }
    int ans = 0;
    for(int i = r;i<=a;i++){
        for(int j = r;j<=b;j++){
            ans = max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);//公式
        }
    }
    cout<<ans<<endl;
    return 0;
}
