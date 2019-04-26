//
//  main.cpp
//  14805
//
//  Created by 이운형 on 26/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<char,int> &A, const pair<char,int> &B) {
    return A.second < B.second;
}

// R O Y G B V
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, round = 1;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> color(6);
        for (int i = 0; i< 6; i++) {
            cin >> color[i];
        }
        
        vector<pair<char, int>> ryb;
        ryb.push_back(make_pair('R', color[0]));
        ryb.push_back(make_pair('Y', color[2]));
        ryb.push_back(make_pair('B', color[4]));
        sort(ryb.begin(), ryb.end(),cmp);
        
        if (ryb[0].second + ryb[1].second < ryb[2].second) {
            cout << "Case #" << round << ": IMPOSSIBLE" << '\n';
            round++;
            continue;
        }
        
        string ans;
        
        while (ryb[0].second > 0) {
            ans += ryb[0].first;
            ryb[0].second--;
            
            if( ryb[0].second > 0 ) {
                if (ryb[2].second >= ryb[1].second) {
                    ans += ryb[2].first;
                    ryb[2].second--;
                } else {
                    ans += ryb[1].first;
                    ryb[1].second--;
                }
            }
        }
        
        sort(ryb.begin(), ryb.end(), cmp);
        
        while (ryb[2].second > 0) {
            ans += ryb[2].first;
            ryb[2].second--;
            if (ryb[1].second > 0) {
                ans += ryb[1].first;
                ryb[1].second--;
            }
        }
        
        cout << "Case #" << round << ": " << ans << '\n';
        round++;
    }
}
