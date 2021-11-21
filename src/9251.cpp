#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int alphabet=26;

int getMax(int a, int b);

int main(){

    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    int answer=0;

    vector<int>tmp;
    vector<vector<int>>arr(s1.length(), tmp);
    vector<vector<int>>board(s1.length(), tmp);

    for(int i{0}; i < s1.length(); i++){

        for(int j{0}; j<s2.length(); j++){

            if(s1[i] == s2[j]){

                arr[i].push_back(j); 
                board[i].push_back(1);
            }
        }
    }

    for(int i{0}; i < s1.length(); i++){

        for(int j{0}; j < arr[i].size(); j++){

            int res=0;

            for(int k{i-1}; k >=0; k--){

                for(int s{0}; s < arr[k].size(); s++){

                    if(arr[i][j] > arr[k][s])
                        res=getMax(res, board[k][s]);
                    
                    else
                        break;
                }
            }

            board[i][j] +=res;

            answer=getMax(answer, board[i][j]);
        }
    }

    cout<<answer<<endl;

    return 0;
}

int getMax(int a, int b){

    if(a > b)
        return a;

    return b;
}