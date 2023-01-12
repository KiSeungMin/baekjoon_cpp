#include<iostream>
#include<queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int>> plus;
    priority_queue<int> minus;

    for(int i{0}; i  < N; i++){

        int num;
        cin>>num;

        if(num == 0){

            // 둘다 비어있을 때
            if(plus.size() == 0 && minus.size() == 0){

                cout<<0<<"\n";
                continue;
            }


            else{

                // 양수 힙만 비어있을 때
                if(plus.size() == 0){

                    cout<<minus.top()<<"\n";
                    minus.pop();
                    continue;
                }

                // 음수 힙만 비어있을 때
                else if(minus.size() == 0){

                    cout<<plus.top() << "\n";
                    plus.pop();
                    continue;
                }

                // 둘 다 비어있지 않을 때
                else{

                    // 절댓값 비교해서 작은 값 출력
                    if(plus.top() > minus.top() * -1){

                        cout<<minus.top()<<"\n";
                        minus.pop();
                        continue;
                    }

                    else if(plus.top() < minus.top() * -1){

                        cout<<plus.top()<<"\n";
                        plus.pop();
                        continue;
                    }

                    // 음수와 양수 힙의 절댓값이 같을 경우 음수 힙의 값 출력
                    else{

                        cout<<minus.top()<<"\n";
                        minus.pop();
                        continue;
                    }
                }
            }
        }

        else{

            if(num < 0)
                minus.push(num);

            else
                plus.push(num);
        }
    }

    return 0;
}