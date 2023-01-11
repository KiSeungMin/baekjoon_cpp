#include<iostream>
#include<string>
#define sync_with_stdio(false)
using namespace std;

int answer  = 0;

int recursion(string& s, int start, int end){

    answer++;

    if(start >= end) 
        return 1;

    else if(s[start] != s[end]) 
        return 0;

    else{
        return recursion(s, start + 1, end - 1);
    }
    
}

int isPalindrome(string& s){
    return recursion(s, 0, static_cast<int>(s.length()) - 1);
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    for(int t{0};  t < T; t++){

        string input_str;
        cin>>input_str;

        cout<<isPalindrome(input_str)<<" " << answer<<"\n";

        answer = 0;
    }

    return 0;
}