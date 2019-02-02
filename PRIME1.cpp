#include<bits/stdc++.h>
using namespace std;
int main(){
	int len = 100000;
	bool seive[len + 1]={0};
 
	for(int i=2;i<len;i++){
		if(!seive[i]){
			for(int j=i*2;j<len;j += i)
				seive[j] = 1;
		}
	}
 
	int k;
	vector<int> s;
	for(int i=2;i<len;i++){
		if(!seive[i]){
			s.push_back(i);
		}
	}
 
	k = s.size();
 
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n < 2)
			n = 2;
		int l = sqrt(m) + 1;
		int end = m-n+1;
		int hash[end]={0};
 
 
		for(int i=0 ; s[i] <= l ; i++){
 
 
			int q;
			if(s[i]>=n)
				q = 2;
			else if(n%s[i])
				q = n/s[i] + 1;
			else
				q = n/s[i];
 
			for(int j = q*s[i] ; j <= m ; j += s[i]){
 
				hash[j - n] = 1;
			}
 
		}
 
 
		for(int i=0;i<end;i++)
			if(!hash[i])
				cout<<n+i<<endl;
		cout<<endl;
	}
	return 0;
}