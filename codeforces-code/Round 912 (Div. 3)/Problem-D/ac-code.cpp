#include<bits/stdc++.h>

using namespace std;
using Section = pair<int, int>;


bool judge(const vector<Section> & sections, int k){
    Section currentSection = make_pair(0, 0);
    for(const Section & x: sections){
        currentSection = make_pair(max(currentSection.first - k, x.first), min(currentSection.second + k, x.second));
        if(currentSection.first > currentSection.second){
            return false;
        }
    }
    return true;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int sectionNum;
        cin >> sectionNum;
        vector<Section> sections(sectionNum);
        for(int i = 0; i < sectionNum; i++)
            cin >> sections[i].first >> sections[i].second;
        
        int left = 0, right = 1e9;
        while(left < right){
            int mid = (left + right) / 2;
            if(judge(sections, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        printf("%d\n", left);
    }
}
