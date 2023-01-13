#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){

    string input_str;
    cin>>input_str;

    set<string> result_set;

    for(int length{1}; length <= input_str.length(); length++){
        for(int start{0}; start + length <= input_str.length(); start++){
            result_set.insert(input_str.substr(start, length));
        }
    }

    cout<<result_set.size()<<"\n";

    return 0;
}