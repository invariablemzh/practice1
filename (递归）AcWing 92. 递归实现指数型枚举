#include <bits/stdc++.h>
using namespace std;
vector<int> chosen;
int n;
void calc(int x){
    if(x==n+1){//问题边界
        for(int i = 0;i<chosen.size();i++){
            cout<<chosen[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //不选x
    calc(x+1);
    //选x
    chosen.push_back(x);
    calc(x+1);
    chosen.pop_back();//还原，准备回溯
}

int main(){
    cin>>n;
    calc(1);
    return 0;
}
