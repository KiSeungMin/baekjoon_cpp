#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    string input_str1, input_str2;
    cin>>input_str1>>input_str2;

    int input_num1 = stoi(input_str1);
    int input_num2 = stoi(input_str2);
    
    for(int i{static_cast<int>(input_str2.length()) - 1}; i >= 0; i--){

        int num = input_str2[i] - '0';
        int result = num * input_num1;

        cout<<result<<"\n";
    }

    cout<<input_num1 * input_num2<<"\n";

    return 0;
}