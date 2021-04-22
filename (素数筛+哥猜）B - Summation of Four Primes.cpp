//其实这道题可取巧，（2，2）和（2，3）
#include <bits/stdc++.h>
using namespace std;
int a[10000100],prim[10001000];
int m = 0,n,cnt,mid;
bool jd[10000100];
void primes(int n){
    memset(a,0,sizeof(a));
    for(int i = 2;i<=n;i++){
        if(a[i]==0) {
            a[i] = i;prim[++m] = i;
            if((2+i)%2==1) jd[2+i] = true;
        };
        for(int j = 1;j<=m;j++){
            if(prim[j]>a[i]||prim[j]>n/i) break;
            a[i*prim[j]] = prim[j];
        }
    }
}

int main(){
    primes(10000100);
//    for(int i = 1;i<=m;i++) cout<<prim[i]<<" ";
    int x1,x2,y1,y2;
    while(~scanf("%d",&n)){
//    for(int n = 9000000;n<=10000000;n++){
//        cout<<n<<"   ";
        bool flag1 = false,flag2 = false;
        if(n<=11) {
            if(n==8) {
                printf("2 2 2 2\n"); continue;
            }
            if(n==9) {
                printf("2 2 2 3\n"); continue;
            }
            if(n==10){
                printf("2 2 3 3\n"); continue;
            }
            if(n==11){
                printf("2 2 2 5\n"); continue;
            }
            printf("Impossible.\n");
            continue;
        }
        double s = (double)n/2.0;
        int l,r;
        int ss = (int)s;//除下来的整数部分
        //如果整除并且为偶数
        if(s-0.5!=ss&&ss%2==0){
            l = ss-2,r = ss+2;
            int p = lower_bound(prim+1,prim+m+1,l)-prim;
            int k = p;
            for(int i = 1;i<=p;i++) {
                int x = prim[i];
                if (x >= l) break;
                while (prim[k] + x < l && k + 1 <= p) k++, cnt++;
                while (prim[k] + x > l && k - 1 >= 1) k--, cnt++;
                if (prim[k] + x == l) {
                    flag1 = true;
                    x1 = x,x2 = prim[k];
                    break;
                }
            }
            p = lower_bound(prim+1,prim+m+1,r)-prim;
            for(int i = 1;i<=p;i++) {
                int x = prim[i];
                if (x >= r) break;
                while (prim[k] + x < r && k + 1 <= p) k++, cnt++;
                while (prim[k] + x > r && k - 1 >= 1) k--, cnt++;
                if (prim[k] + x == r) {
                    flag2 = true;
                    y1 = x,y2 = prim[k];
                    break;
                }
            }
        }
        else if(s-0.5!=ss&&ss%2==1){
            l = ss-1,r = ss+1;
            int p = lower_bound(prim+1,prim+m+1,l)-prim;
            int k = p;
            for(int i = 1;i<=p;i++) {
                int x = prim[i];
                if (x >= l) break;
                while (prim[k] + x < l && k + 1 <= p) k++, cnt++;
                while (prim[k] + x > l && k - 1 >= 1) k--, cnt++;
                if (prim[k] + x == l) {
                    flag1 = true;
                    x1 = x,x2 = prim[k];
                    break;
                }
            }
            p = lower_bound(prim+1,prim+m+1,r)-prim;
            k = p;
            for(int i = 1;i<=p;i++) {
                int x = prim[i];
                if (x >= r) break;
                while (prim[k] + x < r && k + 1 <= p) k++, cnt++;
                while (prim[k] + x > r && k - 1 >= 1) k--, cnt++;
                if (prim[k] + x == r) {
                    flag2 = true;
                    y1 = x,y2 = prim[k];
                    break;
                }
            }
        }
        else if(s-0.5==ss){
            x1 = 2,x2 = 3,flag1 = true;
            r = n-2-3;
            int p = lower_bound(prim+1,prim+m+1,r)-prim;
            int k = p;
            for(int i = 1;i<=p;i++) {
                int x = prim[i];
                if (x >= r) break;
                while (prim[k] + x < r && k + 1 <= p) k++, cnt++;
                while (prim[k] + x > r && k - 1 >= 1) k--, cnt++;
                if (prim[k] + x == r) {
                    flag2 = true;
                    y1 = x,y2 = prim[k];
                    break;
                }
            }
        }

        if(flag1&&flag2) printf("%d %d %d %d\n",x1,x2,y1,y2);
        else printf("Impossible.\n");


    }
    return 0;
}
