#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string str){

    int start = 0;
    int end = static_cast<int>(str.length() - 1);

    while(start < end){
        if(str[start] != str[end])
            return false;

        start++; end--;
    }

    return true;
}

int main(){

    string str;
    cin >> str;
    while(str != "0"){
        cout<<(checkPalindrome(str) ? "yes\n" : "no\n");
        cin >> str;
    }

    return 0;
}