//
//  main.cpp
//  15650
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int m, n;
char result[22];

void input() {
    cin >> n >> m;
}

void brute(int idx, int cnt) {
    if (cnt == m) {
        cout << result << '\n';
        return;
    }
    
    for (int i = idx+1; i < n; i++) {
        result[2*cnt] = (i+1) + '0';
        result[2*cnt + 1] = ' ';
        brute(i, cnt+1);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        result[0] = (i+1) + '0';
        result[1] = ' ';
        brute(i, 1);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    
    return 0;
}

