#include <bits/stdc++.h>
using namespace std;

struct Job{
	int id;
	int dead;
	int profit;
};

struct comp{
    bool operator()(const Job& j1, const Job& j2){
		return j2.profit < j1.profit;
	}
};


bool cond(const Job& j1, const Job& j2){
	return j1.dead < j2.dead || ((j1.dead == j2.dead) && j1.profit < j2.profit);
}

void JobScheduling(vector <Job>& arr, int n) 
{ 
	// your code here
	sort(arr.begin(), arr.end(), cond);
	priority_queue <Job, vector<Job>, comp> pq;
	int max_deadline = arr[0].dead;
	pq.push(arr[0]);
	int count = 1;
	int tot_profit = arr[0].profit;
	for(int i = 1; i <= n - 1; i++){
		if(max_deadline < arr[i].dead || count < max_deadline){
			max_deadline = arr[i].dead;
			count++;
			pq.push(arr[i]);
			tot_profit += arr[i].profit;
		}else if(pq.top().profit < arr[i].profit){
			tot_profit += (arr[i].profit - pq.top().profit);
			pq.pop();
			pq.push(arr[i]);
		}
	}
	
	while(!pq.empty()){
		cout << pq.top().id << ", " << pq.top().dead << ", " << pq.top().profit << "\n";
		pq.pop();
	}
	cout << "Maximum profit: " << tot_profit << "\n";
}

int main(){

	// n is the number of jobs
	int n;
	cin >> n;

	vector <Job> arr(n);
	int id; int dead; int profit;
	for(int i = 1; i <= n; i++){
		cin >> id >> dead >> profit;
		arr[i-1].id = id;
		arr[i-1].dead = dead;
		arr[i-1].profit = profit;
	}
	JobScheduling(arr, n);
}
