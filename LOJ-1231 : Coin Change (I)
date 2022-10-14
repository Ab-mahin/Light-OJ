// Problem: Coin Change (I)
// Contest: LightOJ
// URL: https://lightoj.com/problem/coin-change-i
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long

using namespace std;

void print(ll ok){
	cout << (ok ? "YES" : "No") << '\n';
}

void no(ll t, ll ans){
	cout << "Case " << t << ": " << ans << '\n';
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t = 1, tt = 1;
	cin >> t;
	
	while(t--){
		
		ll n, m;
		cin >> n >> m;
		
		ll a[n + 5], crt[n + 5], mod = 100000007;
		
		for(ll i = 1; i <= n; i++) cin >> a[i];
		for(ll i = 1; i <= n; i++) cin >> crt[i];
		
		ll dp[m + 5]{0};
		
		dp[0] = 1;
		for(ll i = 1; i <= n; i++){
			for(ll j = m; j >= 0; j--){
				for(ll k = 1; k <= crt[i]; k++){
					ll x = k * a[i];
					if(j + x > m) continue;
					dp[j + x] = (dp[j + x] + dp[j]) % mod;
				}
			}
		}
		
		no(tt++, dp[m]);
	}
	return 0;
}
