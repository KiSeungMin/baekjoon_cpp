#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int node_cnt;
vector<int>inOrderIndex;
vector<int>postOrderIndex;
vector<int>inOrder = {0};
vector<int>postOrder = {0};

void getInput(){
    cin >> node_cnt;

    for(int i{0}; i <= node_cnt; i++){
        inOrderIndex.push_back(0);
        postOrderIndex.push_back(0);
    }

    for(int i{1}; i <= node_cnt; i++){
        int num; cin >> num;
        inOrderIndex[num] = i;
        inOrder.push_back(num);
    }

    for(int i{1}; i <= node_cnt; i++){
        int num; cin >> num;
        postOrderIndex[num] = i; 
        postOrder.push_back(num);
    }
}

void getAnswer(int parent_node, int start, int end){

    cout<<parent_node<<" ";

    if(start == end)
        return;

    int inOrIndex = inOrderIndex[parent_node];
    int postIndex = postOrderIndex[parent_node];

    int count_left_child = inOrIndex - start;
    int count_right_child = end - inOrIndex;

    if(count_left_child != 0){
        int left_child = postOrder[postIndex - count_right_child - 1];
        getAnswer(left_child, start, inOrIndex - 1);
    }

    if(count_right_child != 0){
        int right_child = postOrder[postIndex - 1];
        getAnswer(right_child, inOrIndex + 1, end);
    }
}

int main(){

    getInput();

    getAnswer(postOrder[node_cnt], 1, node_cnt);

    cout<<"\n";

    return 0;
}