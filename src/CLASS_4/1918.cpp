#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

void printAnswer(string str){

    vector<char>operands = {'+', '-', '*', '/', '(', ')'};
    stack<char> stk;
    string result;

    for(auto c : str){

        bool is_operand = false;
        for(auto operand : operands){
            if(c == operand){
                is_operand = true;
                break;
            }
        }

        if(is_operand){

            if(c == '+' || c == '-'){
                while(true){

                    if(stk.empty()){
                        break;
                    }

                    char top_char = stk.top();
                    if(top_char == '('){
                        break;
                    }

                    stk.pop();
                    result += top_char;
                }
                stk.push(c);
            }
            else if(c == '*' || c == '/'){
                while(true){

                    if(stk.empty()){
                        break;
                    }

                    char top_char = stk.top();
                    if(top_char == '+' || top_char == '-' || top_char == '('){
                        break;
                    }                

                    stk.pop();
                    result+=top_char;
                }
                stk.push(c);
            } 
            else if(c == '('){
                stk.push(c);
            }
            else if(c == ')'){
                while(true){
                    char top_char = stk.top(); stk.pop();

                    if(top_char == '('){
                        break;
                    }
                    else{
                        result += top_char;
                    }
                }
            }
        } else{
            result += c;
        }
    }

    while(!stk.empty()){
        result += stk.top(); stk.pop();
    }
    cout<<result<<endl;
}

int main(){

    string input_str; cin >> input_str;
    printAnswer(input_str);

    return 0;
}