//对于二分，二分是二分性而不是单调性 只要满足可以找到一个值一半满足一半不满足即可 而不用满足单调性
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int cows[N];
double sum[N];
int n,f;

bool check(double avg) {//用非负性找区间
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cows[i] - avg;
    double minv = 0;
    for(int i = 0,j = f;j<=n;i++,j++){//i须从0开始，即开头那f个 //双指针，在i前面找最小值，在j上找终点
        minv = min(sum[i],minv);
        if(sum[j]>=minv) return true;
    }
    return false;

}
int main(){
    cin>>n>>f;
    for(int i = 1;i<=n;i++){
        cin>>cows[i];
    }
    double l = 0,r = 2000;//根据题意，平均值只会在1-2000中出现
    while(r-l>1e-5){//保留三位小数的精确度
        double mid = (l+r)/2;
        if(check(mid)) //判断它是否可行
          l = mid; else r = mid;
    }
    cout<<int(r*1000)<<endl;//直接int下取整
}
