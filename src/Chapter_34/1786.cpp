#include<iostream>
#include<vector>
#include<string>
using namespace std;

string T;
string P;
vector<int>fail;
vector<int>result;

void input();
void getFail();
void KMP();


// KMP 알고리즘 -> fail함수와 KMP 알고리즘을 이용

int main(){
	
	input();
	
	return 0;
}

void input(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	getline(cin, T);
	getline(cin, P);
	
	getFail();
}


// 실패 함수를 만드는 함수 
void getFail(){
	
	for(int i{0}; i < P.length(); i++)
		fail.push_back(0);
	
	int dist = 0;
	
	for(int i{1}; i < P.length(); i++){
		
		while(dist > 0 && P.at(i) != P.at(dist))
			dist = fail[dist - 1];

		if(P.at(i) == P.at(dist))
			fail[i] = ++dist;
	
	}

	KMP();
}

// KMP 알고리즘
// 찾기에 실패할 경우, 실패한 인덱스로부터 fail[실패한 인덱스 -1]만큼 이전으로 감(그 이전은 볼 필요가 없으므로)
void KMP(){
	
	int answer = 0;
	int index = 0;
	int failBefore = 0;
	
	bool flag = true;
	
	
	while(index + P.length() - 1 < T.length()){
			
		flag = true;
		
		for(int i{failBefore}; i < P.length(); i++){
			
			if(T[index + i] != P[i]){
				
				index += i > 0 ? i - fail[i - 1] : 1;
				
				failBefore = i > 0 ? fail[i - 1] : 0;
				
				flag = false;
				break;
			}
		}
		
		if(flag){
			result.push_back(index + 1);
			answer++;
			
			index = P.length() >= 2 ? index + P.length() - 1 - fail[P.length() - 2] : index + 1;
			failBefore = P.length() >= 2 ? fail[P.length() - 2] : 0;
		}	
	}
	
	cout<<answer<<"\n";
	
	for(auto j : result)
		cout<<j<<" ";
	
	cout<<"\n";
	
}