#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class myObject{
private:
	int num;
	int index;
public:
	myObject(int num, int index){
		this->num=num;
		this->index=index;
	}
	
	int getNum(){
		return this->num;
	}
	
	int getIndex(){
		return this->index;
	}
};

bool compare(myObject o1, myObject o2){
	if(o1.getNum() < o2.getNum())
		return true;
	else
		return false;
}

int main(){
	
	int N;
	cin>>N;
	
	vector<myObject>table;
	vector<int>answer;
	
	for(int i{0}; i<N; i++){
		int n;
		cin>>n;
		myObject o(n, i);
	
		table.push_back(o);
		answer.push_back(0);
	}
	
	sort(table.begin(), table.end(), compare);
	
	vector<int>arr;
	arr.push_back(table[0].getNum());
	answer[table[0].getIndex()]=0;
	
	for(int i{1}; i<N; i++){
		if(table[i].getNum()>arr[arr.size()-1]){
			arr.push_back(table[i].getNum());
		}
		else{}
		answer[table[i].getIndex()]=arr.size()-1;
	}
	
	for(int i{0}; i<N; i++){
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	return 0;
}