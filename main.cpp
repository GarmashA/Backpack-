#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <filesystem>
 #include <fstream>

 using namespace std;
 namespace fs = filesystem;

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
     string path = "C:\Users\garmash\Desktop\backpack";
           auto it = fs::directory_iterator(path);
           vector<fs::path> array_path;
           copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),
               [](const auto& entry) {
                   return fs::is_regular_file(entry);
           });
     for (auto& p : array_path) {
         ifstream fin;
         fin.open(p.string());
         cout << p.string() << endl;
         double n, W;
         fin >> n >> W;
         vector<pair<double, double> > items;
         for (int i = 0; i < n; i++) {
             double value, weight;
             fin >> value >> weight;
             items.push_back(make_pair(value, weight));
         }
         if (obj.second <= W - bag_weight) {
             bag_weight += obj.second;
             bag_cost += obj.first;
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
     }
     cout << bag_cost << endl;
     return 0;
  }
