#include <iostream>
using namespace std;

int main()
{
    int len{};
    char ch{};
    cin >> len >> ch;
    int req{ch - 'A'};
    // cout << req;
    bool seatAvailable{false};

    for (int idx = 0; idx < len; idx++)
    {
        string s;
        cin >> s;
        if (s[req] == 'o')
            seatAvailable = true;
    }
    if (seatAvailable)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}