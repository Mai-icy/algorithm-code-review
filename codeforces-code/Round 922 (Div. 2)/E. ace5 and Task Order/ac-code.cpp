#include <bits/stdc++.h>

using namespace std;

int ask(int index){
    char response;
    cout << "? " << index << endl;
    cin >> response;
    switch (response)
    {
    case '=':
        return 0;
    case '>':
        return 1;
    case '<':
        return -1;
    }
    return response;
}

void solve(){
    int n;
    cin >> n;

    vector<int> result(n + 1);
    
    int maxIndex = 1, minIndex = 1;
    for(int i = 1; i <= n; i++){
        if(ask(i) < 0){
            ask(maxIndex);
        }else{
            while(ask(i) == 1) { }
            maxIndex = i;
        }
    }

    for(int i = 1; i <= n; i++){
        if(ask(i) > 0){
            ask(minIndex);
        }else{
            while(ask(i) == -1) { }
            minIndex = i;
        }
    }

    int x = 1;
    function<void(int)> MoveXTo = [&](int index){
        while(x != index){
            if(x > index){
                ask(minIndex);
                x--;
            }else{
                ask(maxIndex);
                x++;
            }
                
        }
    };

    function<void(int, int, const vector<int> &)> dfs = [&](int left, int right, const vector<int> &arr){
        if(left > right) return;
        if(left == right) {
            result[arr[0]] = left;
            return;
        }
        int mid = (left + right) / 2;
        vector<int> moreTo;
        vector<int> downTo;
        for(int t: arr){
            MoveXTo(mid);
            int res = ask(t);
            if(res > 0){
                x++;
                moreTo.push_back(t);
            }else if(res < 0){
                x--;
                downTo.push_back(t);
            }else{
                result[t] = mid;
            }
        }
        dfs(left, mid - 1, downTo);
        dfs(mid + 1, right, moreTo);
        return;
    };

    vector<int> input(n);
    for(int i = 1; i <= n; i++){
        input[i - 1] = i;
    }

    dfs(1, n, input);
    cout << "!";
    for(int i = 1; i <= n; i++){
        cout << ' ' << result[i];
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
