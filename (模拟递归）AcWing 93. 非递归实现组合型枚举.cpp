//不会做，瞎改改出来的，具体再推一遍
//case是指递归，和call语句一起的是在同一个逻辑里的，若在递归中则是在执行递归前的相关语句
//在switch中运用call来保存下次递归，用ret来返回，用continue来结尾每次case的结束

#include <bits/stdc++.h>
using namespace std;
vector<int> chosen;
int s[100010],top = 0,address = 0,n,m;
void call(int x,int ret_addr){//模拟计算机汇编指令call
    int old_top = top;
    s[++top] = x;//参数x
    s[++top] = ret_addr;//返回地址标号
    s[++top] = old_top;//在栈顶记录以前的top值
}
int ret(){//模拟计算机汇编指令ret
    int ret_addr = s[top-1];
    top = s[top];//恢复以前的top值
    return ret_addr;
}
int main(){
    cin>>n>>m;
    call(1,0);
    while(top){
        int x = s[top-2];//获取参数
        switch(address){
            case 0:
                if(chosen.size()>m||chosen.size()+(n-x+1)<m){
                    address = ret();//return
                    continue;
                }
                if(x==n+1){
                    for(int i = 0;i<chosen.size();i++){
                        printf("%d ",chosen[i]);
                    }
                    puts("");
                    address = ret();//return
                    continue;
                }
                chosen.push_back(x);
                call(x+1,1);//相当于calc（x+1），返回后会从case 1继续，x+1是下一步要做的，1是递归完以后要做的
                address = 0;
                continue;//回到while循环开头，相当于开始新的递归
            case 1:
                chosen.pop_back();
                address = 0;
                call(x+1,2);//相当于calc（x+1），返回后会从case2继续
                continue;//回到while循环开头，相当于开始新的递归
                
            case 2:
                address = ret();//相当于元calc函数结尾，执行return
        }
    }
    return 0;
}
