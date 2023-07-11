#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mat vector<vector<ll>>
const ll MOD=1e9+7;
const ll MOD2=MOD*MOD;
mat resize(int n, int m)
{
    return mat(n, vector<ll> (m));
}
mat mul(mat x, mat y)
{
    mat cur=resize(x.size(),y[0].size());
    for (int i=0;i<x.size();i++)
    {
        for (int j=0;j<y[0].size();j++)
        {
            for (int k=0;k<y.size();k++)
            {
                cur[i][j]+=x[i][k]*y[k][j];
                if (cur[i][j]>=MOD2) cur[i][j]-=MOD2;
            }
        }
    }
    for (int i=0;i<x.size();i++)
        for (int j=0;j<y[0].size();j++)
            cur[i][j]%=MOD;
    return cur;
}
int main()
{
    ll n;
    cin>>n;
    mat f0={{0,1},{1,1}};
    mat ans={{0,1}};
    while (n>0)
    {
        if (n&1) ans=mul(ans,f0);
        f0=mul(f0,f0);
        //cout<<ans[0][0]<<endl;
        n>>=1;
    }
    cout<<ans[0][0]<<endl;
}
