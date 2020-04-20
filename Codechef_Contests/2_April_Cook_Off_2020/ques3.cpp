#include<bits/stdc++.h>

/*Author - Silent Knight
Institution - Birla Institute Of Technology, Mesra
*/

using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back

ll modInverse(ll n,ll p) 
{ 
    ll x = n;
    ll y = p-2;
    ll res = 1;   
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res;  
} 
  

ll nCrModPFermat(ll n,ll r,ll p)  //if mod value is prime 
{ 
   if (r == 0) 
      return 1; 
    
    ll fac[n+1]; 
    fac[0] = 1; 

    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]*modInverse(fac[r], p) % p*modInverse(fac[n-r], p) % p) % p; 
} 

ll nCrModP(ll n,ll r,ll p)          //normal iterative solution for all values of mod
{
    r = min(r,n-r);
    ll c[r+1];
    memset(c,0,sizeof(c));
    c[0] = 1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=min(i,r);j>0;j--)
        {
            c[j] = (c[j] + c[j-1])%p;
        }
    }
    return c[r];
}

void PacalCombinations(ll size)
{
    ll a[size][size];
    for(ll i=0;i<size;i++)
    {
        for(ll j=0;j<size;j++)
            a[i][j] = 0;
    }
    a[0][0] = 1;
    for(ll i=1;i<size;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            if(j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
}

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     
    x = x % p; 
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}

//////////////////////////   UPSOLVED

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        string s,r;
        cin>>s>>r;
        ll n = s.length();
        ll index1 = -1,index2 = -1;
        for(ll i=0;i<n;i++) //left check
        {
            if(s[i] != r[i])
                {
                    index1 = i;
                    break;
                }
        }
        for(ll i=(n-1);i>=0;i--) // right check
        {
            if(s[i] != r[i])
                {
                    index2 = i;
                    break;
                }
        }
        vector <ll> equal,unequal;
        ll temp1 = 0,temp2 = 0;
        if(index1 == -1)
        {
            cout<<0;
        }
        else
        {
            for(ll i=index1;i<=index2;i++)
            {
                if(s[i] != r[i])
                {
                    if(temp2 != 0)
                        {
                            equal.push_back(temp2);
                            temp2 = 0;
                        }
                    temp1 += 1;
                }
                else
                {
                    if(temp1 != 0)
                    {
                        unequal.push_back(temp1);
                        temp1 = 0;
                    }
                    temp2 += 1;
                }
            }
            if(temp1 != 0)
                unequal.push_back(temp1);
            if(temp2 != 0)
                equal.push_back(temp2);
            ll sum_unequal = 0;
            for(auto it : unequal)
                sum_unequal += it;
            ll ans = sum_unequal*unequal.size();
            sort(equal.begin(),equal.end());
            ll k = unequal.size();
            ll res = sum_unequal;
            for(auto it : equal)
            {
                res += it;
                k -= 1;
                ll prod = res*k;
                ans = min(ans,prod);
            }
            cout<<ans;
        }
    cout<<"\n";
    }
    return 0;
}