// Edit distance with dynamic programming with optimum space
// Time Complexity : O(P*Q)
// Space Complexity : O(P)
 
#include<bits/stdc++.h>
using namespace std;
 
#define fo(i,n) for(i=0;i<n;i++)
#define lli long long int
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "," << #y << " = " << y << endl
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
//=======================
const int MOD = 1000000007;
 
int editDistance(string s1, string s2, int p, int q)
{
	int dp[p+1][q+1];

	for(int i=0; i<=p; i++)
	{	for(int j=0; j<=q; j++)
		{
			if(i==0)
				dp[i%2][j] = j;
			else if(j==0)
				dp[i%2][j] = i;
			else
			{
				if(s1[i-1]==s2[j-1])
					dp[i%2][j] = dp[(i-1)%2][j-1];
				else
				{
					dp[i%2][j] = 1 + min( dp[(i-1)%2][j], min( dp[i%2][j-1], dp[(i-1)%2][j-1] ) );
				}
			
			}
		}
	}
	return dp[p%2][q];
	
}
 
 
void solve()
{
	int p, q;
	cin>>p>>q;
	string s1, s2;
	cin>>s1>>s2;
 
	cout<<editDistance(s1, s2, p, q)<<endl;    
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin) ;
        freopen("output.txt", "w", stdout) ;    
    #endif
        
    int test;
    cin >> test;
    while(test--)
    {
      solve();
    }
 
    return 0;
} 