//
//  main.cpp
//  15633
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> que;
int over[8], c[8], num[8];
int n, m, curr;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> over[i];
    }
    sort(over, over+n);
}

void change() {
    num[0] = over[0];
    c[0] = 1;
    
    for (int i = 1; i < n; i++) {
        if (over[i] == over[i-1]) {
            c[curr]++;
        } else {
            curr++;
            c[curr] = 1;
            num[curr] = over[i];
        }
    }
}

void brute(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << que[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i <= curr; i++) {
        if (c[i] <= 0) continue;
        
        c[i]--;
        que.push_back(num[i]);
        brute(cnt+1);
        c[i]++;
        que.pop_back();
    }
}

void solve() {
    
    for (int i = 0; i <= curr; i++) {
        c[i]--;
        que.push_back(num[i]);
        brute(1);
        c[i]++;
        que.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    change();
    solve();
    
    return 0;
}
