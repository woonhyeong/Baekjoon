//
//  main.cpp
//  14806
//
//  Created by 이운형 on 25/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool flag;
char p_color[6] = {'R','Y','B'};

bool match_color(int l_color, int r_color) {
    switch (l_color) {
        case 0:
            return (r_color == 1 || r_color == 2);
        case 1:
            return (r_color == 0 || r_color == 2);
        case 2:
            return (r_color == 0 || r_color == 1);
        default:
            break;
    }
    return false;
}

void print_color(vector<int> color) {
    for (int i = 0; i < color.size(); i++) {
        cout << p_color[color[i]];
    }
    cout << '\n';
}

bool check(vector<int> ans) {
    for (int i = 0; i < ans.size()-1; i++) {
        if (!match_color(ans[i-1<0?ans.size()-1:i-1], ans[i]) || !match_color(ans[i+1], ans[i])) return false;
    }
    return true;
}

void solve(int N, vector<int> color, int idx, vector<int> ans) {
    if (idx == N && !flag) {
        if(check(ans)) {
            flag = true;
            print_color(ans);
        }
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        if (color[i]) {
            color[i]--;
            ans.push_back(i);
            solve(N, color, idx+1, ans);
            if(flag) return;
            color[i]++;
            ans.pop_back();
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, round = 1;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int idx = 0;
        vector<int> color(3);
        for (int i = 0; i< 6; i++) {
            if (i == 1 || i == 3 || i == 5) {
                int temp;
                cin >> temp;
                continue;
            }
            cin >> color[idx];
            idx ++;
        }
        vector<int> ans;
        flag = false;
        cout << "Case #" << round << ": ";
        solve(N, color, 0, ans);
        
        if (!flag) {
            cout << "IMPOSSIBLE\n";
        }
        round++;
    }
}
