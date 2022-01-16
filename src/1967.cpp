#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;


const int INF =2000000000;


int V;

vector<vector<pair<int, int>>>adj;

vector<vector<int>>result;


int DFS(int parentNode, int childNode, int distance);

int getMax(int a, int b);


int main(){


ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);


cin>>V;


for(int i{0}; i < V + 1; i++){

vector<pair<int, int>>tmp;

adj.push_back(tmp);


vector<int>tmp2;

result.push_back(tmp2);

}


for(int i{0}; i < V - 1; i++){

int num1, num2, num3;

cin>>num1>>num2>>num3;

adj[num1].push_back({num2, num3});
adj[num2].push_back({num1, num3});
}


for(auto j : adj[1]){

result[1].push_back(DFS(1, j.first, j.second));

}


int answer = 0;


for(int i{1}; i <= V; i++){


int num;


if(result[i].size() == 1){

num = result[i][0];

}


else if(result[i].size() == 0)

continue;


else{

sort(result[i].begin(), result[i].end());

num = result[i][result[i].size()-1] + result[i][result[i].size()-2];

}


if(num > answer)

answer = num;

}


cout<<answer<<"\n"; 


return 0;

}


int DFS(int parentNode, int childNode, int distance){


int res = distance;


for(auto j : adj[childNode]){


if(j.first == parentNode)

continue;


int value = DFS(childNode, j.first, j.second);

result[childNode].push_back(value);


res = getMax(res, distance + value);

}


return res;

}


int getMax(int a, int b){

if(a < b)

return b;


return a;

}

