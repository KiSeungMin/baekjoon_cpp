#include<iostream>
#include<string>
#include<vector>
using namespace std;

int getScore(string strCopy){
	
	int result=0;
	int count=0;
	
	for(size_t i{0}; i<strCopy.length(); i++){
		if(strCopy[i]=='O'){
			count++;
			result+=count;
		}
		else if(strCopy[i]=='X'){
			count=0;
		}
	}
	
	return result;
}

int main(){
	
	int size;
	cin>>size;
	cin.ignore();
	
	vector<int>answer;
	
	for(int i{0}; i<size; i++){
		string str="";
		cin>>str;
		
		answer.push_back(getScore(str));
	}
	
	for(size_t s{0};s<answer.size(); s++){
		cout<<answer[s]<<endl;
	}
	
	return 0;
}