#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> computeSuffixMax(const vector<pair<int, int>> &people)
{
    int n = people.size();
    vector<int> suffix_max(n);
    suffix_max[n - 1] = people[n - 1].first;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_max[i] = max(people[i].first, suffix_max[i + 1]);
    }
    return suffix_max;
}

int getTallest(const vector<int> &suffix_max, const vector<int> &times, int query)
{
    auto it = upper_bound(times.begin(), times.end(), query);
    int idx = distance(times.begin(), it);
    return suffix_max[idx];
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> people(n);
    for (int i = 0; i < n; i++)
    {
        cin >> people[i].first >> people[i].second;
    }

    sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b)
    { return a.second < b.second; });

    vector<int> times(n);
    for (int i = 0; i < n; i++)
        times[i] = people[i].second;

    vector<int> suffix_max = computeSuffixMax(people);

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        cout << getTallest(suffix_max, times, t) << "\n";
    }

    return 0;
}