#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans1 = 0,ans2 = 0,ans=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='x'&&s[i+1]=='y'){
                ans1++;
                i++;
            }
            else if(s[i]=='y'&&s[i+1]=='x'){
                ans1++;
                i++;
            }
        }
        cout<<ans1<<endl;
    }
    return 0;
}