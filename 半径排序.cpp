#include<bits/stdc++.h>
using namespace std;


const int maxn =110;
int n;
double r[maxn], ans = 1e9, p[maxn],ans1[maxn];
//���㵱ǰԲ�����г��� 
double compute() {
    double l=0.0,h=0.0;
   for(int i=1;i<=n;i++){
        l=min(l,p[i]-r[i]);
        h=max(h,p[i]+r[i]);
    }
    if(ans>h-l){
        ans=h-l;
        for(int i=1;i<=n;i++){
		  ans1[i]=r[i];
		} 
    }
}


double get(int x) {
    double sum = 0.0;
        //����Բ��λ��
		//�ӵ�һ����ʼ����    
    for (int i = 1; i < x; i++){
	  sum = max(sum, p[i] + 2.0 * sqrt(r[i] * r[x]));
	} 
    return sum;
}


void solve(int x) {
    if (x > n) {
        compute();
        return;
    }
    for (int i = x; i <= n; i++) {
        swap(r[x], r[i]);
        double cnt = get(x);

        if (cnt + r[1] + r[x] < ans) {
            p[x] = cnt;
            solve(x + 1);
        }
        //���� 
        swap(r[x], r[i]);
    }
}


int main() {

    cin >> n;
    for (int i = 1; i <= n; i++){
	 cin >> r[i];
	 } 
    solve(1);
    cout << "��̳���Ϊ" << ans << "\n";
    cout << "��������£�Բ�İ뾶����Ϊ";
    for (int i = 1; i <= n; i++) cout << ans1[i] << (i == n ?  "\n" : " ");
    return 0;
    
}
