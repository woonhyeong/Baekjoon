//
//  main.cpp
//  15649
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool visit[8];
vector<int> que;
int n, m;

void input() {
    cin >> n >> m;
}

void cprint() {
    for (int i = 0; i < que.size(); i++) {
        cout << que[i] << ' ';
    }
    cout << '\n';
}

void brute(int cnt) {
    if (cnt == m) {
        cprint();
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;
        
        visit[i] = true;
        que.push_back(i+1);
        brute(cnt+1);
        visit[i] = false;
        que.pop_back();
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        visit[i] = true;
        que.push_back(i+1);
        brute(1);
        visit[i] = false;
        que.pop_back();
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
