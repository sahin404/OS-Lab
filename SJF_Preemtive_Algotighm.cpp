#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int ind1[N], ind2[N];

int main()
{
	int n;
	cin>>n;
	vector<pair<int,int>> v1, v2;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		v1.push_back({x, i}); //arival time
		v2.push_back({y, i}); //burst time
	}

	sort(v1.begin(), v1.end()); 


	//Preemptive Part
	priority_queue <int, vector<int>, greater<int>> q;
	q.push(v2[v1[0].second].first);
	int time = 0;
	cout<<"0 "<<"p"<<v1[0].second+1<<" ";
	for(int i=1; i<n; i++){
		cout<<v1[i].first<<" ";
		time = v1[i].first-time;
		int temp = q.top();
		temp-=time;
		time = v1[i].first;
		for(int j=0; j<n; j++){
			if(v2[j].first==q.top()){
				v2[j].first = temp;
				break;
			}
		}

		q.pop();
		q.push(temp);
		q.push(v2[v1[i].second].first);

		if(i<n-1){
			cout<<"p";
			for(auto j:v2){
				if(j.first==q.top()){
					cout<<j.second+1<<" ";
					break;
				}
			}
		}

	}


	//Non-Preemtive Part
	
	sort(v2.begin(),v2.end());

	for(auto i:v2){
		if(i.first!=0){
			cout<<"p"<<i.second+1<<" "<<time+i.first<<" ";
			time+=i.first;
		}
	}

	

}