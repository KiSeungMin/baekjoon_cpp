#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int N;
int counter = 0;
int answer = 0;
vector<int>parent;

vector<pair<int, int>>x;
vector<pair<int, int>>y;
vector<pair<int, int>>z;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

void input();
void getAnswer();

// x, y, z배열을 정렬한 후에, 인접한 값들만 priority_queue에 삽입하면 된다.

int main(){

  input();

  return 0;
}

void input(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  if(N == 1){
    cout<<0<<"\n";
    return;
  }

  for(int i{0}; i < N; i++){

    int num1, num2, num3;
    cin>>num1>>num2>>num3;

    x.push_back({num1, i});
    y.push_back({num2, i});
    z.push_back({num3, i});

    parent.push_back(-1);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());

  for(int i{1}; i < N; i++){
    pair<int, pair<int, int>> tmp;

    tmp = {abs(x[i].first - x[i - 1].first) , {x[i].second, x[i - 1].second}};
    pq.push(tmp);
    tmp = {abs(y[i].first - y[i - 1].first), {y[i].second , y[i - 1].second}};
    pq.push(tmp);
    tmp = {abs(z[i].first - z[i - 1].first), {z[i].second , z[i - 1].second}};
    pq.push(tmp);
  }

  while(counter < N - 1)
    getAnswer();

  cout<<answer<<"\n";
}

void getAnswer(){

  pair<int, pair<int, int>> arr = pq.top();
  pq.pop();

  int res = arr.first;

  int index1 = arr.second.first;
  int index2 = arr.second.second;

  int pointer1 = index1;
  int pointer2 = index2;

  if(parent[index1] == -1)
    pointer1 = -1;

  else{
    while(parent[pointer1] != pointer1)
      pointer1 = parent[pointer1];

    parent[index1] = pointer1;
  }

  if(parent[index2] == -1)
    pointer2 = -1;

  else{
    while(parent[pointer2] != pointer2)
      pointer2 = parent[pointer2];

    parent[index2] = pointer2;
  }

  if(pointer1 == -1 && pointer2 == -1){
    parent[index1] = index1;
    parent[index2] = index1;

    answer += res;
    counter++;
    return;
  }

  else if(pointer1 != -1 && pointer2 == -1){
    parent[index2] = pointer1;

    answer += res;
    counter++;
    return;
  }

  else if(pointer1 == -1 && pointer2 != -1){
    parent[index1] = pointer2;

    answer += res;
       counter++;
    return;
  }

  else if(pointer1 == pointer2){
    return;
  }

  else{
    parent[pointer2] = pointer1;

    answer += res;
    counter++;
    return;
  }
}