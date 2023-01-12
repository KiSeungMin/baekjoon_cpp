#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
string s;

int answer = 0;

vector<int>fail;

void getAnswer();
void getFail();

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>s;

  getAnswer();

  return 0;
}

void getAnswer(){

  getFail();

  /*
  for(auto j : fail)
    cout<<j<<" ";

  cout<<"\n";
  */

  if(fail[fail.size() - 1] == 0)
    answer = s.length();

  else
    answer = s.length() - fail[fail.size() - 1];
  
  cout<<answer<<"\n";
}

void getFail(){

  int dist = 0;
  for(int i{0}; i < s.length(); i++)
    fail.push_back(0);

  for(int i{1}; i < s.length(); i++){

    while(dist > 0 && s[i] != s[dist])
      dist = fail[dist - 1];

    if(s[i] == s[dist])
      fail[i] = ++dist;
  }
}