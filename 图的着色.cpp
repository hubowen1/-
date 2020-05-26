#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 105;
int G[maxn][maxn];
int color[maxn];
bool ans;
int n,m,k;
void init(){
    ans = 0;
    memset(G, 0 , sizeof G);
    memset(color, 0 , sizeof color);
}

void dfs(int cur){
    if(cur > n) {
        ans = 1;
        return;    
    } 
    for(int i=1; i<=m; i++){ //对cur结点尝试使用每一种颜色进行涂色 
    
        bool flag = 1;
        //cur之前的结点必被涂色
        for(int j=1; j<cur; j++){
            if(G[j][cur] == 1 && color[j] == i){
                flag = 0;//只要有一个冲突都不行 
                break;
            }
        } 
        //如果可以涂上i颜色，则考虑下一个结点的情况 
        if(flag){
            color[cur] = i;
            dfs(cur + 1);
            
        } 
        //如果到这一步第cur个结点无法着色，则返回探寻其他方案 
        else color[cur] = 0;//回溯 ;
    }
    
}


int main(){
    while(cin>>n>>k>>m){
        init(); 
        for(int i=1; i<=k; i++){
            int x,y;
            cin>>x>>y;
            G[x][y] = G[y][x] = 1;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
