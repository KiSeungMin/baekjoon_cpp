#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin>>T;

    string func;
    int N;
    string arr;
    bool answer=true;

    for(int t{0}; t < T; t++){

        deque<int>deq;     
        func="";
        arr="";
        answer=true;
        N=0;

        cin>>func;
        cin>>N;
        cin>>arr;

        string s="";

        for(size_t i{1}; i < arr.length(); i++){

            if(arr[i] != ',' && arr[i] != ']'){
                s=s+arr[i];
                continue;
            }

            if(s.length() == 0)
                continue;

            deq.push_back(stoi(s));
            s="";
        }

        bool rev=false;

        for(size_t i{0}; i <func.length(); i++){

            if(func[i] == 'R'){
                rev = !rev;
                continue;
            }

            if(!deq.empty()){

                if(rev)
                    deq.pop_back();

                else
                    deq.pop_front();

                continue;
            }
             
            answer=false;
            break;
        }

        if(answer){

            cout<<"[";

            if(rev){

                if(deq.empty()){
                    cout<<"]"<<"\n";
                    continue;
                }

                for(int i{0}; i < deq.size()-1; i++){
                    cout<<deq[deq.size()-1-i]<<',';
                }

                cout<<deq[0]<<"]"<<"\n";
            }

            else{

                if(deq.empty()){
                    cout<<"]"<<"\n";
                    continue;
                }

                for(int i{0}; i < deq.size()-1; i ++){
                    cout<<deq[i]<<',';
                }

                cout<<deq[deq.size()-1]<<"]"<<"\n";
            }
        }

        else
            cout<<"error"<<"\n";
    }

    return 0;
}