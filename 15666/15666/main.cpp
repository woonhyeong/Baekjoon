//
//  main.cpp
//  15666
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input[8];
int num[8];
vector<int> que;
int n, m, curr;

void func_input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
}

void func_convert() {
    sort(input, input+n);
    
    num[0] = input[0];
    for (int i = 1; i < n; i++) {
        if (input[i] == input[i-1]) continue;
        
        num[++curr] = input[i];
    }
}

void func_brute(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << que[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = idx; i <= curr; i++) {
        que.push_back(num[i]);
        func_brute(i, cnt+1);
        que.pop_back();
    }
}

void func_solve() {
    
    for (int i = 0; i <= curr; i++) {
        que.push_back(num[i]);
        func_brute(i, 1);
        que.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    func_input();
    func_convert();
    func_solve();
    
    return 0;
}
