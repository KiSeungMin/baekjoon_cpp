#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int node_cnt;
vector<pair<int, int>> binary_tree;

void getInput(){
    cin.tie(NULL);
    cin >> node_cnt;

    for(int i{0}; i < node_cnt; i++){
        binary_tree.push_back({0, 0});
    }

    for(int i{0}; i < node_cnt; i++){

        char c1; cin >> c1;

        int parent_node = c1 - 'A';

        char c2, c3;
        cin >> c2 >> c3;

        int child_node1, child_node2;

        child_node1 = (c2 == '.' ? -1 : c2 - 'A');
        child_node2 = (c3 == '.' ? -1 : c3 - 'A');

        binary_tree[parent_node] = {child_node1, child_node2};
    }
}

void preOrder(int node_now){

    if(node_now == -1)
        return;
    
    int child_node1 = binary_tree[node_now].first;
    int child_node2 = binary_tree[node_now].second;

    cout<<static_cast<char>(node_now + 65);
    preOrder(child_node1);
    preOrder(child_node2);
}

void inOrder(int node_now){

    if(node_now == -1)
        return;

    int child_node1 = binary_tree[node_now].first;
    int child_node2 = binary_tree[node_now].second;

    inOrder(child_node1);
    cout<<static_cast<char>(node_now + 65);
    inOrder(child_node2);
}

void postOrder(int node_now){
    
    if(node_now == -1)
        return;

    int child_node1 = binary_tree[node_now].first;
    int child_node2 = binary_tree[node_now].second;

    postOrder(child_node1);
    postOrder(child_node2);
    cout<<static_cast<char>(node_now + 65);
}

int main(){

    getInput();

    cout.tie(NULL);

    preOrder(0);
    cout<<"\n";
    inOrder(0);
    cout<<"\n";
    postOrder(0);
    cout<<"\n";

    return 0;
}