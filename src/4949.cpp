#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    string s;
    getline(cin, s);
    
    while(s!="."){

        vector<char>arr;
        bool answer=true;

        for(int i{0}; i <s.length()-1; i++){

            int blank=0;

            if(s[i] == '(' || s[i] == '['){

                arr.push_back(s[i]);
            }

            else if( s[i] == ')' || s[i] ==']'){

                if(arr.size() > 0){

                    if(s[i] == ')'){

                        if(arr[arr.size()-1] != '('){
                            answer=false;
                            break;
                        }

                        else
                            arr.pop_back();
                    }

                    else if(s[i] ==']'){

                        if(arr[arr.size()-1] != '['){
                            answer=false;
                            break;
                        }

                        else
                            arr.pop_back();
                    }
                }

                else if(arr.size() ==0){
                    answer=false;
                    break;
                }
            }

            else
                continue;
        }

        if(arr.size() > 0)
            answer=false;

        if(answer)
            cout<<"yes"<<endl;

        else
            cout<<"no"<<endl;

        getline(cin, s);
    }

    return 0;
}