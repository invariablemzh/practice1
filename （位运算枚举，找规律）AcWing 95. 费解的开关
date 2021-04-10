#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
char a[10][10],b[10][10];
int dx[5] = {0,1,0,-1,0}, dy[5] = {0,0,1,0,-1};

void turn(int x,int y){
    for(int i = 0;i<5;i++){
        int xx = x+dx[i],yy = y+dy[i];
        if(xx<0||xx>=5||yy<0||yy>=5) continue;
        a[xx][yy] ^= 1;
    }
}

int main(){
    int n;
    cin>>n;
    while(n--){
        for(int i = 0;i<5;i++) cin>>a[i];
        int res = INF;
        memcpy(b,a,sizeof(a));
        for(int k = 0;k<32;k++){
            int step = 0;
            for(int i = 0;i<5;i++){
                if((k>>i)&1){
                    step++;
                    turn(0,i);
                }
            }
            for(int i = 0;i<4;i++){
                for(int j = 0;j<5;j++){
                    if(a[i][j]=='0') {
                        turn(i+1,j);
                        step++;
                    }
                }
            }
            bool flag = true;
            for(int i = 0;i<5;i++){
                for(int j = 0;j<5;j++){
                    if(a[i][j]=='0') {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                res = min(res,step);
            }
            memcpy(a,b,sizeof(a));
        }
        if(res>6) res = -1;
        cout<<res<<endl;
    }
    return 0;
}
