#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    string s;
    int num;
    deque<int> deq;

    for(int i{0}; i < N; i++){

        cin>>s;

        if(s == "push_front"){

            cin>>num;
            deq.push_front(num);
        }

        else if(s == "push_back"){

            cin>>num;
            deq.push_back(num);
        }

        else if(s == "pop_front"){

            if(deq.empty()){
                cout<<-1<<"\n";
                continue;
            }

            cout<<deq.front()<<"\n";
            deq.pop_front();
            continue;
        }

        else if(s == "pop_back"){

            if(deq.empty()){

                cout<<-1<<"\n";
                continue;
            }

            cout<<deq.back()<<"\n";
            deq.pop_back();
            continue;
        }

        else if(s == "size"){

            cout<<deq.size()<<"\n";
            continue;
        }

        else if(s == "empty"){

            if(deq.empty()){

                cout<<1<<"\n";
                continue;
            }

            cout<<0<<"\n";
            continue;
        }

        else if(s == "front"){

            if(deq.empty()){

                cout<<-1<<"\n";
                continue;
            }

            cout<<deq.front()<<"\n";
            continue;
        }

        else if (s== "back"){

            if(deq.empty()){

                cout<<-1<<"\n";
                continue;
            }

            cout<<deq.back()<<"\n";
            continue;
        }
    }

    return 0;
}