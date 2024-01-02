#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using Zone = pair<int, int>;

int main(){
    int T;
    cin >> T;
    while(T--){
        int peopleNum;
        long long result = 0;
        cin >> peopleNum;
        vector<Zone> zones(peopleNum);
        ordered_set<int> loaded;
        for(int i = 0; i < peopleNum; i++)
            cin >> zones[i].first >> zones[i].second;
        
        sort(zones.begin(), zones.end());

        for(auto zone:zones){
            loaded.insert(zone.second);
            result += loaded.size() - loaded.order_of_key(zone.second) - 1;
        }
        cout << result << endl;
    }    
}






