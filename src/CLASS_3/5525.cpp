#include<iostream>
#include<string>
using namespace std;

int main(){

    int N, length;
    cin >> N >>length;

    int answer = 0;
    int count = 0;

    string str; cin >> str;
    char beforeChar = 'X';
    for(int i{0}; i < length; i++){

        if(beforeChar == 'X'){

            if(str[i] == 'O')
                continue;

            else{
                beforeChar = 'I';
            }
        } else if(beforeChar == 'O'){

            if(str[i] == 'I'){
                count++;
                beforeChar = 'I';
                continue;
            }

            else if(str[i] == 'O'){

                if(count >= N){
                    answer += (count - N + 1);
                }

                count = 0;
                beforeChar = 'X';
                continue;
            }

        } else if(beforeChar == 'I'){

            if(str[i] == 'I'){

                if(count >= N){
                    answer += (count - N + 1);
                }

                count = 0;
                beforeChar = 'I';
                continue;
            } 

            else if(str[i] == 'O'){

                beforeChar = 'O';
                continue;
            }
        }
    }

    if(count >= N){
        answer += (count - N + 1);
    }

    cout<<answer<<"\n";

    return 0;
}