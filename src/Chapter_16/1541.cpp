#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){

    string s;
    getline(cin, s);

    int answer=0;

    int index=0;

    while(true){

        if(s[index] ==  '-'){
            
            string num="";
            index++;

            while(index <= s.length() -1){
            
                if(s[index] == '+' || s[index]=='-'){
                    answer=answer-stoi(num);
                    num="";
                }

                else{
                    num.push_back(s[index]);
                }

                index++;
            }

            answer=answer-stoi(num);
            break;
        }

        else{

            string num="";

            while(index <= s.length()-1 && s[index] != '-'){

                if(s[index]=='+'){
                    answer=answer+stoi(num);
                    num="";
                }

                else{
                    num.push_back(s[index]);
                }

                index++;
            }

            answer=answer+stoi(num);
            
            if(index >= s.length())
                break;
        }
    }

    cout<<answer<<endl;

    return 0;
}