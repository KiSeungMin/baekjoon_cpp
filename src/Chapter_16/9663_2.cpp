#include<iostream>
#include<vector>
using namespace std;

int N;
int answer=0;

void getAnswer(int row, int col, vector<int> result);


// 각 행에 무조건 체스 말이 하나가 온다

int main(){

	cin>>N;
	
	for(int i{0}; i<=(N/2)-1; i++){
		vector<int>tmp(N, 0);
		getAnswer(0, i, tmp);
	}
	
	answer*=2;
	
	if(N%2==1){
		vector<int>tmp(N, 0);
		getAnswer(0, N/2, tmp);
	}
	
	cout<<answer;
	return 0;
}

void getAnswer(int row, int col, vector<int> result){
	
	if(row==N-1){
		answer++;		
		return;
	}
	
	result[row]=col;
	
	vector<bool> canMove(N, true);
	vector<int> move;
	
	// 현재 행보다 위의 행에 있는 말들과 공격로가 겹치면 배제
	
	for(int i{0}; i <= row; i++){
		if(result[i] - (row+1-i) >= 0)
			canMove[result[i]-(row+1-i)]=false;
		
		if(result[i] + (row+1-i) < N)
			canMove[result[i]+(row+1-i)]=false;
		
		canMove[result[i]]=false;
	}
	
	for(size_t i{0}; i<canMove.size(); i++){
		if(canMove[i])
			move.push_back(i);
	}	
	
	if(canMove.size() >= N-row){
		for(size_t i{0}; i<move.size();  i++){
			getAnswer(row+1,move[i], result);
		}
	}
	
	return;
}