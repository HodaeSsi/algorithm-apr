#include <bits/stdc++.h>
using namespace std;

long long n,x;
vector<long long> v;
bool used[100000];
void input(){
    cin >> n >> x;
    v.resize(n);
    for(long long i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
}

void solve(){
    long long ans = 0;
    for(long long i=n-1;i>=0;i--){
        if(used[i]) continue;
        if(x <= v[i]){ // 1개로 만들어지는 경우
            ans++;
            used[i] = true;
        }
        else{ // 2개로 만들어지는 경우
            long long temp = x - x / 2 - v[i];
            auto iter = lower_bound(v.begin(), v.end(), temp);
            long long idx = iter - v.begin();
            for(long long j=idx;j<i;j++){
                if(!used[j]){
                    ans++;
                    used[j] = true; 
                    used[i] = true;
                    break;
                }
            
        }
    }
    long long cnt = 0;
    for(long long i=0;i<n;i++){
        if(!used[i]) cnt++;
    }
    ans += cnt / 3; // 3개로는 용량이 어떻든 하나를 만들 수 있음.
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}