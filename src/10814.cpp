#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

class myObject{
	
private:
	int age;
	string name;
	int order;
	
public:
	myObject(int age, string name, int order){
		this->age=age;
		this->name=name;
		this->order=order;
	}
	
	int getAge(){
		return this->age;
	}
	
	string getName(){
		return this->name;
	}
	
	int getOrder(){
		return this->order;
	}
};

bool compare(myObject o1, myObject o2){
	if(o1.getAge() < o2.getAge()){
		return true;
	}
	else if(o1.getAge() > o2.getAge()){
		return false;
	}
	else if(o1.getAge() == o2.getAge()){
		if(o1.getOrder() < o2.getOrder()){
			return true;
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	
	cout.tie(NULL);
	cin.tie(NULL);
	
	int N;
	cin>>N;
	vector<myObject>table;
	
	for(int i{0}; i<N; i++){
		int age;
		string name;
		cin>>age>>name;
		myObject o(age,name, i);
		table.push_back(o);
	}
	
	sort(table.begin(), table.end(), compare);
	
	for(int i{0}; i<N; i++){
		cout<<table[i].getAge()<<" "<<table[i].getName()<<"\n";
	}
	
	return 0;
}