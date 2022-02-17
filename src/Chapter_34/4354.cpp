#include<iostream>
#include<vector>
#include<string>
using namespace std;

string s;
vector<int>fail;

void getFail();
void getAnswer();

int main(){

  getline(cin, s);

  while(s != "."){
    getFail();
    getline(cin, s);
  }

  return 0;
}

// fail 함수로부터 최소 중복 단위를 도출 (0 부터 fail 함수의 길이 - fail[fail.length-1]의 인덱스까지)

void getFail(){

  fail.clear();

  for(int i{0}; i < s.length(); i++)
    fail.push_back(0);

  int dist = 0;

  for(int i{1}; i < s.length(); i++){

    while(dist > 0 && s[i] != s[dist])
      dist = fail[dist - 1];

    if(s[i] == s[dist])
      fail[i] = ++dist;
  }

  if(fail[fail.size() - 1] == 0){
    cout<<1<<"\n";
    return;
  }

  getAnswer();
}

void getAnswer(){

  string cmp;

  for(int i{0}; i <= fail.size() - 1 - fail[fail.size() - 1]; i++)
    cmp+=s[i];

  int index = 0;

  // s의 길이를 cmp로 나눈 나머지가 0이 아닐경우
  if(s.size() % cmp.size() != 0){
    cout<<1<<"\n";
    return;
  }

  for(int i{0}; i < s.size(); i++){

    if(s[i] == cmp[index]){
      index++;

      if(index == cmp.length())
        index = 0;
    }

    else{
      cout<<1<<"\n";
      return;
    }
  }

  cout<<s.length() / cmp.length()<<"\n";
  return;
}
