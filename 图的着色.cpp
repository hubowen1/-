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
    for(int i=1; i<=m; i++){ //��cur��㳢��ʹ��ÿһ����ɫ����Ϳɫ 
    
        bool flag = 1;
        //cur֮ǰ�Ľ��ر�Ϳɫ
        for(int j=1; j<cur; j++){
            if(G[j][cur] == 1 && color[j] == i){
                flag = 0;//ֻҪ��һ����ͻ������ 
                break;
            }
        } 
        //�������Ϳ��i��ɫ��������һ��������� 
        if(flag){
            color[cur] = i;
            dfs(cur + 1);
            
        } 
        //�������һ����cur������޷���ɫ���򷵻�̽Ѱ�������� 
        else color[cur] = 0;//���� ;
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
