#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100000;

int histogram[MAX + 1]; // 히스토그램의 높이

int main() {

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> histogram[i];
    }
    
    stack<int> s;
    s.push(0);
    
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (!s.empty() && histogram[i] < histogram[s.top()]) {
            int height = histogram[s.top()];
            s.pop();
            int width = i - s.top() - 1;
            ans = max(ans, height * width);
        }
        s.push(i);
    }
    
    cout << ans << endl;
    
    return 0;
}
