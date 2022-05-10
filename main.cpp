#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double n, W;
    cin >> n >> W;
    vector<pair<double, double> > items;
    for (int i = 0; i < n; i++) {
        double value, weight;
        cin >> value >> weight;
        items.push_back(make_pair(value, weight));
    }
    sort(items.begin(), items.end(),
    [](const auto& a, const auto& b) {return (((double)a.first) / ((double)a.second))>(((double)b.first) / ((double)b.second));});
    double bag_cost = 0;
    double bag_weight = 0;
    for (auto obj : items) {
        if (bag_weight >= W) {
            break;
        }
        if (obj.second <= W - bag_weight) {
            bag_weight += obj.second;
            bag_cost += obj.first;
        }
    }
    cout << bag_cost << endl;
    return 0;
 }
