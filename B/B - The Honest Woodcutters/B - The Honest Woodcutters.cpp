#include <iostream>
#include <vector>
using namespace std;




int main(){
    int n{};
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for(int idx = 0 ; idx < n ; idx++) cin >> a[idx];
    
    for(int idx = 0 ; idx < n ; idx++) cin >> b[idx];

    bool notHonest = false;

    for(int idx = 0 ; idx < n ; idx++){
        if(b[a[idx] - 1] != idx + 1) {
            notHonest = true;
            break;
        }
    }

    if(notHonest) cout << "No";
    else cout << "Yes";

    return 0;
}