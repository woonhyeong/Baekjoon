//
//  main.cpp
//  15657
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num[8];
vector<int> que;
int n, m;

void input() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
}

void brute(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < que.size(); i++) {
            cout << que[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = idx; i < n; i++) {
        que.push_back(num[i]);
        brute(i, cnt+1);
        que.pop_back();
    }
}

void solve() {
    
    for (int i = 0; i < n; i++) {
        que.push_back(num[i]);
        brute(i, 1);
        que.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    sort(num, num+n);
    solve();
    
    return 0;
}
