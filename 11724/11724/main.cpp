//
//  main.cpp
//  11724
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> vertex[1001];
bool visit[1001];
int n, m;

void input() {
    cin >> n >> m;
    
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        vertex[from].push_back(to);
        vertex[to].push_back(from);
    }
}

int check() {
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) return i;
    }
    return -1;
}

void solve(int idx) {
    
    for (int i = 0; i < vertex[idx].size(); i++) {
        int next = vertex[idx][i];
        
        if (visit[next]) continue;
        
        visit[next] = true;
        solve(next);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    
    int cnt = 0;
    
    while (true) {
        int v = check();
        
        if (v < 0) break;
        cnt++;
        
        visit[v] = true;
        solve(v);
    }
    
    cout << cnt << '\n';
    
    return 0;
}
