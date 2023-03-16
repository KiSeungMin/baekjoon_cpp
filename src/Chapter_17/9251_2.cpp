#include<iostream>
#include<vector>
#include<string>
using namespace std;

int getMax(int num1, int num2){
    return (num1 > num2 ? num1 : num2);
}

int main(){

    string s1, s2;
    cin>>s1>>s2;

    int length1 = s1.length();
    int length2 = s2.length();

    vector<int>row(length1 + 1, 0);
    vector<vector<int>>board(length2 + 1, row);

    for(int i{1}; i <= length2; i++){
        for(int j{1}; j <= length1; j++){

            if(s2[i - 1] == s1[j - 1])
                board[i][j] = board[i - 1][j - 1] + 1;
            else
                board[i][j] = getMax(board[i - 1][j], board[i][j - 1]);
                
        }
    }
    
    cout<<board[length2][length1]<<"\n";

    return 0;
}