#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 500005, INF = 0x3f3f3f3f;
int ta, tb, n, T;
ll t[maxn], t1[maxn];
int main (void)
{
    cin>>n>>ta>>tb>>T;
    string s;
    char a; cin>>a;
    if(a=='w') T-=tb;
    T--;
    if(T<0){
        cout<<0<<endl;
        return 0;
    }
    cin>>s;
    for(int i = 0; i < n - 1; i++){
        t[i] = t[i -1] + 1 + ta;
        if(s[i] == 'w') t[i] += tb;
    }
    reverse(s.begin(), s.end());
    for(int i = 0; i < n - 1; i++){
        t1[i] = t1[i -1] + 1 +ta;
        if(s[i] == 'w') t1[i] += tb;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(t1[i - 1] > T) break;
        int l = 0, r = n - i ;
        while(l < r - 1){
           int mid = (l + r)/2;
           if(mid > 0 && t1[i - 1]+ t[mid - 1] + i * ta <= T) l = mid;
           else r = mid;
        }
      res = max(res, l + i);
    }
 
    for(int i = 0; i < n; i++){
        if(t[i - 1] > T) break;
        int l = 0, r = n - i;
        while(l < r - 1){
            int mid = (l + r)/2;
            if(mid > 0 && t[i - 1]+ t1[mid - 1] + i * ta <= T) l = mid;
            else r = mid;
        }
      res = max(res, l + i);
    }
 
    cout<<res + 1<<endl;
    return 0;
}
