#include<bits/stdc++.h>
#define ll long long
#define N 200009
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

ll ans;
basic_string<pii> g[N];
int n,q,fa[N],a[N],b[N];

unordered_map<int,ll> mp[N];

void dfs(int u,int f){

    fa[u]=f;

    for(pii v:g[u]){

        if(v.fi==f)continue;

        b[v.fi]=v.se;

        mp[u][a[v.fi]]+=v.se;

        dfs(v.fi,u);

    }

    ans-=mp[u][a[u]];

}

void solve(){
    cin>>n>>q;
    ans=0;
    for(int i=1;i<=n;i++)g[i].clear(),mp[i].clear();
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,x,y,z;i<n;i++){
        cin>>x>>y>>z;
        ans += z;
        g[x] += make_pair(y,z);
        g[y] += make_pair(x,z);
    }

    dfs(1,0);

    for(int i=1,x,y;i<=q;i++){

        cin>>x>>y;

        if(fa[x]){

            mp[fa[x]][a[x]]-=b[x];if(a[x]==a[fa[x]])ans+=b[x];

            mp[fa[x]][y]+=b[x];if(y==a[fa[x]])ans-=b[x];

        }

        ans+=mp[x][a[x]];ans-=mp[x][y];a[x]=y;

        cout<<ans<<"\n";

    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;while(T--)solve();
    return 0;

}