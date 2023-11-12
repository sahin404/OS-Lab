//First Come First Serve (FCFS)
//Mode: FIFO (First in First Out)
//Non Preemptive

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<pair<int, int>> arrival;
	int burst[100];
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		arrival.push_back({x,i});
		burst[i] = y;;
	}
	sort(arrival.begin(), arrival.end());

	//gantt chart print
	int temp = 0;
	cout<<temp<<" ";
	for(int i=0; i<n; i++){
		temp+=burst[arrival[i].second];
		cout<<"p"<<arrival[i].second+1<<" ";
		cout<<temp<<" ";
	}

	
}
