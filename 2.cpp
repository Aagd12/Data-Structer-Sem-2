#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
		int t=1;
		cin>>t;
		while(--t>=0){
			int n;
			cin>>n;
		bool neg=false;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x<0)
				neg=true;
		}
		if(neg)
			cout<<"NO\n";
		else{
				cout<<"YES\n"<<101<<endl;
				for(int i=0;i<=100;i++)
					cout<<i<<' ';
				cout<<endl;
			}

		}
		return 0;
}


