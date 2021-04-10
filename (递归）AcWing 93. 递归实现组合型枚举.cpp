//递归输出要注意vector放入放出顺序，若由小到大要先选x，再不选x

#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> chosen;
void calc(int x){
    if(chosen.size()>m||chosen.size()+n-x+1<m) return;
    if(x==n+1){
        for(int i = 0;i<chosen.size();i++){
            cout<<chosen[i]<<" ";
        }
        cout<<endl;
        return;
    }
    chosen.push_back(x);
    calc(x+1);
    chosen.pop_back();
    calc(x+1);
    
}

int main(){
    cin>>n>>m;
    calc(1);
}
