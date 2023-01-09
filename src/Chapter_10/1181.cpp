#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2){
	if(s1.length() == s2.length()){
		int index=0;

		while(index<s1.length() && ((s1[index]-'0')==(s2[index]-'0')))
			index++;

        return s1[index] - '0' < s2[index] - '0';
	}

    else
        return s1.length() < s2.length();
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

	int N;
	cin>>N;
	
	vector<string>input_str_arr;
	
	for(int i{0}; i<N; i++){
		string s;
		cin>>s;
		input_str_arr.push_back(s);
	}
	
	sort(input_str_arr.begin(), input_str_arr.end(), compare);
	
	for(int i{0}; i<N; i++){
		if(i==0)
			cout<<input_str_arr[i]<<endl;

		else{
			if(input_str_arr[i]!=input_str_arr[i-1]){
                cout<<input_str_arr[i]<<"\n";
            }
		}
	}
	
	return 0;
}