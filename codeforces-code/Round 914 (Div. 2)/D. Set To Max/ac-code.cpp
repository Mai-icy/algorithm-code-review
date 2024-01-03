#include<bits/stdc++.h>

using namespace std;

class SparseTableMin {
public:
    SparseTableMin(const vector<int>& arr) {
        buildSTTable(arr);
    }

    int query(int l, int r) {
        int k = log2(r - l + 1);
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }

private:
    vector<vector<int>> st;

    void buildSTTable(const vector<int>& arr) {
        int n = arr.size();
        int k = log2(n) + 1;
        st.resize(n, vector<int>(k));

        for (int i = 0; i < n; ++i) {
            st[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
};

class SparseTableMax {
public:
    SparseTableMax(const vector<int>& arr) {
        buildSTTable(arr);
    }

    int query(int l, int r) {
        int k = log2(r - l + 1);
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }

private:
    vector<vector<int>> st;

    void buildSTTable(const vector<int>& arr) {
        int n = arr.size();
        int k = log2(n) + 1;
        st.resize(n, vector<int>(k));

        for (int i = 0; i < n; ++i) {
            st[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
};


void solveProblem(){
    int size;
    cin >> size;
    vector<int> arrA(size);
    vector<int> arrB(size);
    vector<int> numShow[size];

    int hashSize = 0;
    map<int, int> hashValue;

    int canTrans = true;
    
    for(int i = 0; i < size; i++){
        cin >> arrA[i];
        if(hashValue.find(arrA[i]) == hashValue.end()){
            hashValue[arrA[i]] = hashSize;
            numShow[hashSize].push_back(i);
            hashSize ++;
        }else{
            numShow[hashValue[arrA[i]]].push_back(i);
        }
    }
    vector<int> needChange;
    for(int i = 0; i < size; i++){
        cin >> arrB[i];
        if(arrB[i] < arrA[i]){
            canTrans = false;
        }else if (arrB[i] > arrA[i]){
            needChange.push_back(i);
        }
    }

    if(not canTrans){
        cout << "NO" << endl;
        return;
    }

    SparseTableMax STMax(arrA);
    SparseTableMin STMin(arrB);

    for(int x:needChange){
        
        if(hashValue.find(arrB[x]) == hashValue.end()){
            cout << "NO" << endl;
            return;
        }

        vector<int> & arr = numShow[hashValue[arrB[x]]];

        auto target = lower_bound(arr.begin(), arr.end(), x);
        bool success = false;
        if(target != arr.end()){
            if(STMax.query(x, *target) <= arrB[x] and STMin.query(x, *target) >= arrB[x])
                success = true;
        }
        if(target != arr.begin()){
            target--;
            if(STMax.query(*target, x) <= arrB[x] and STMin.query(*target, x) >= arrB[x])
                success = true;
        }
        if(not success){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        solveProblem();
    }
}

