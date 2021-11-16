#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int answer=0;
int N;

// 체스판의 각 셀에 0,1,2,3,4... 순으로 숫자를 메긴 벡터
vector<vector<int>>number;

// 각 셀 별로 공격할 수 없는 셀을 판단하도록 하는 벡터
vector<vector<bool>>findNumber;

vector<vector<int>>table;

void getAnswer(int, vector<int>, vector<int>);

void getTable(vector<vector<bool>>&);

int main(){

	cout.tie(NULL);
	cin.tie(NULL);
	
	cin>>N;
	
	for(int i{0}; i<N; i++){
		
		vector<int>row1={};
		vector<bool>row2={};
		
		for(int j{0}; j<N; j++){
			row1.push_back(i*N + j);
			row2.push_back(true);
		}
		
		number.push_back(row1);
		findNumber.push_back(row2);
	}
	
	// 각 셀 별로 어느 셀을 공격 못하는지 저장해놓은 테이블
	vector<int>tmpVec={};
	for(int i{0}; i<N*N; i++){
		table.push_back(tmpVec);
	}
	
	vector<vector<bool>>findNumberCopy=findNumber;
	
	// 테이블의 값을 구한다.
	getTable(findNumberCopy);
	
	// 모든 셀에 대하여 경우의 수 도출
	for(int i{0}; i<=N; i++){
		vector<int>tmpArr={};
		getAnswer(i, table[i], tmpArr);
	}
	
	/*
	if(N%2==0){
		cout<<answer*2;
	}
	else{
		answer=answer*2;
		vector<int>tmpArr={};
		getAnswer((N-1)/2, table[(N-1)/2], tmpArr);
		cout<<answer;
	}	
	*/

	return 0;
}

void getAnswer(int numberNow, vector<int> possibleToMove, vector<int> result){
	
	// 벡터의 사이즈가 N을 만족하면 정답에 1을 더하고 재귀함수 종료
	result.push_back(numberNow);
	if(result.size()==N){
		answer++;
		for(int i{0}; i<result.size(); i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	// 이전 셀들과 현재 셀 모두와 겹치지 않는 셀을 저장하는 벡터
	vector<int> possibleToMoveNow={};
	
	for(size_t i{0}; i<possibleToMove.size(); i++){
		if(binary_search(table[numberNow].begin(), table[numberNow].end(), possibleToMove[i])){
			possibleToMoveNow.push_back(possibleToMove[i]);
		}
	}
	
	if(possibleToMoveNow.size()==0 || possibleToMoveNow.size() + result.size() < N)
		return;
	
	for(size_t i{0}; i<possibleToMoveNow.size(); i++){
		getAnswer(possibleToMoveNow[i], possibleToMoveNow, result);
	}
	
}

void getTable(vector<vector<bool>>& findNumberCopy2){
	for(int i{0}; i<N; i++){
		for(int j{0}; j<N; j++){
			
			findNumber=findNumberCopy2;
			
			for(int col{j}; col<N; col++){
				findNumber[i][col]=false;
			}
			
			for(int row{i}; row<N; row++){
				findNumber[row][j]=false;
			}
			
			int row=i;
			int col=j;			

			// 왼쪽 아래 대각선에 있는 셀 false로 변환

			while(row < N && col >= 0){
				findNumber[row][col]=false;
				row++;
				col--;
			}
			
			// 오른쪽 아래 대각선에 있는 셀 false로 변환
			row=i;
			col=j;
			while(row < N && col < N){
				findNumber[row][col]=false;
				row++;
				col++;
			}
			
			//findNumber의 셀 값이 현재 셀 값보다 크고, true(공격 불가)일 경우 해당 셀의 숫자 값을 table에 삽입
			for(int a{i}; a<N; a++){
				for(int b{0}; b<N; b++){
					if(findNumber[a][b] == true && number[a][b] > number[i][j]){
						table[ i*N + j ].push_back(number[a][b]);
					}
				}
			}
		}
	}
}
