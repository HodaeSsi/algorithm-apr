#include <bits/stdc++.h>
using namespace std;


long long n,k,m;

vector<long long> a_route, b_route;

void to_root(long long num, bool is_a){
    if(num == 1){
        if(is_a) a_route.push_back(1);
        else b_route.push_back(1);
        return;
    }

    to_root((num + k - 2) / k, is_a);
    if(is_a) a_route.push_back(num);
    else b_route.push_back(num);
}

void solve(){
    cin >> n >> k >> m;

    for(long long i=0;i<m;i++){
        long long a,b; cin >> a >> b;
        if(k == 1){cout << max(a,b) - min(a,b) << "\n"; continue;}
        a_route.clear();
        b_route.clear();
        to_root(a, true);
        to_root(b, false);

        int size1 = a_route.size(), size2 = b_route.size();
        int cnt = 0; // 공통 경로
        for(int i=0;i<min(size1, size2);i++){
            if(a_route[i] != b_route[i]) break;
            cnt++;
        }
        cout << size1 + size2 - cnt * 2 << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}