#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, num = 0;
	cin >> N;

	string str;
	queue <int> q;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "pop") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size")
			cout << q.size() << "\n";
		else if (str == "empty")
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		else if (str == "front")
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		else if (str == "back")
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		else if (str == "push") {
			cin >> num;
			q.push(num);
		}
	}

	return 0;
}
/*
#include<iostream>
#include<queue>
#include<string>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin>>N;

    string s;
    queue<int> que;

    for(int i{0}; i < N; i++){

        cin>>s;

        if(s == "push"){
            
            int num;
            cin>>num;
            que.push(num);
            continue;
        }

        else if(s == "pop"){

            if(!que.empty()){
                cout<<que.front()<<"\n";
                que.pop();
                continue;
            }

            else {
                cout<<-1<<"\n";
                continue;
            }
        }

        else if(s == "size")
            cout<<que.size()<<"\n";

        else if(s == "empty"){

            if(!que.empty()){
                cout<<0<<"\n";
                continue;
            }

            else{
                cout<<1<<"\n";
                continue;
            }
        }

        else if(s == "front"){
            
            if(!que.empty()){
                cout<<que.front()<<"\n";
                continue;
            }

            else{
                cout<<-1<<"\n";
                continue;
            }
        }

        else if(s == "back"){

            if(!que.empty()){
                cout<<que.back()<<"\n";
                continue;
            }

            else{
                cout<<-1<<"\n";
                continue;
            }
        }
    }

    return 0;
}
*/