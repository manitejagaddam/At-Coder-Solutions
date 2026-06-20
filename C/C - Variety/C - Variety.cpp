#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;



int main(){
    int n{}, k{}, m{};
    cin >> n >> k >> m;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pair<int, int>> pq;
    long long sum {0LL};
    for(int idx = 0 ; idx < n ; idx++){
        int index {}, val{};
        cin >> index >> val;
        pq.push({val, index});
    }
    unordered_set<int> st;
    
    while(k && !pq.empty()){
        if(k < m){
            auto [val, index] = pq.top();
            pq.pop();
            if(st.count(index)) continue;
            else m--;
            st.insert(index);
        }
        auto [val, index] = pq.top();
        pq.pop();
        sum += val;
        if(!st.count(index)){
            st.insert(index);
            m--;
        }
        k--;
    }

    cout << sum;
    return 0;

}