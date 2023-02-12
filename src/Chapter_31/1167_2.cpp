#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int node_cnt;
int max_node;
int max_dist{0};
vector<vector<pair<int, int>>>graph;

void getInput(){

    cin.tie(NULL);
    cin >> node_cnt;
    
    for(int i{0}; i <= node_cnt; i++){
        vector<pair<int, int>>tmp;
        graph.push_back(tmp);
    }

    for(int i{1}; i <= node_cnt; i++){
        int index; cin >> index;

        int num1, num2;
        cin >> num1;

        while(num1 != -1){
            cin >> num2;

            graph[index].push_back({num1, num2});

            cin >> num1;
        }
    }
}

void DFS(int node_now, int parent_node, int dist_before){

    for(auto next_node : graph[node_now]){
        int child_node = next_node.first;
        int dist_sum = next_node.second + dist_before;

        if(child_node == parent_node)
            continue;

        if(dist_sum > max_dist){
            max_node = child_node;
            max_dist = dist_sum;
        }

        DFS(child_node, node_now, dist_sum);
    }
}

int main(){

    getInput();

    DFS(1, 0, 0);

    DFS(max_node, 0, 0);

    cout<<max_dist<<"\n";
}