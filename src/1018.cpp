#include<iostream>
#include<climits>
#include<string>
#include<vector>
using namespace std;

int main(){
	
	int answer=INT_MAX;

	int row, col;
	cin>>row>>col;
	
	vector<string>table;
	for(int i{0}; i<row; i++){
		string s;
		cin>>s;
		table.push_back(s);
	}
	
	int rowLimit=8;
	int colLimit=8;
	
	vector<string>arr;
	for(int i{0}; i<8; i++){
		string s="00000000";
		arr.push_back(s);
	}

	while(true){
		for(int i{0}; i<8; i++){
			for(int j{0}; j<8; j++){
				arr[i][j]=table[rowLimit-8+i][colLimit-8+j];
			}
		}
		
		char black='B';
		char white='W';
		int result1=0;
		int result2=0;
		
		for(int i{0}; i<8; i++){
			for(int j{0}; j<8; j++){
				if(arr[i][j]!=black){
					result1++;
				}
				if(arr[i][j]!=white){
					result2++;
				}
				char tmp='0';
				tmp=black;
				black=white;
				white=tmp;
			}
			char tmp='0';
			tmp=black;
			black=white;
			white=tmp;
		}
		
		if(result1==0 || result2==0){
			cout<<0<<endl;
			return 0;
		}
		
		if(result1 < answer)
			answer=result1;
		
		if(result2 < answer)
			answer=result2;
		
		colLimit++;
		if(colLimit>col){
			if(rowLimit+1 > row){
				break;
			}
			else{
				rowLimit++;
				colLimit=8;
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}