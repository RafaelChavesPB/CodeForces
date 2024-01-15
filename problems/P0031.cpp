#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	
	int graph[n][n];
	int planets[n];

	for(int i = 0, w; i < n; i++){
		cin >> w;
		planets[i] = w <= 0? INT_MAX: w;
    }
	
	for(int i = 0; i < n; i++)
		for(int  j = 0, w; j < n; j++){
			cin >> w;
			graph[i][j] =  w <= 0? 1'000'000'000: w;
		}

	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(graph[0][i] + graph[i][j] < graph[0][j]){
					graph[0][j] = graph[0][i] + graph[i][j];
					flag = true;
				}
	}
	int answer = INT_MAX;
	for(int i = 0; i < n; i++){
			if(graph[0][i] < planets[i])
				 	answer = min(answer, planets[i]);
    }
	cout << (answer == INT_MAX? -1: answer) << endl;
		

	return 0;
}
