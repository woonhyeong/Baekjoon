//
//  main.cpp
//  1260
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool visit[1001];
vector<int> vertex[1001];
int n, m, v;

void input() {
    cin >> n >> m >> v;
    
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        vertex[from].push_back(to);
        vertex[to].push_back(from);
    }
    
    for (int i = 0; i < n; i++) {
        sort(vertex[i].begin(), vertex[i].end());
    }
}

void dfs(int idx) {
    
    cout << idx << ' ';
    for (int i = 0; i < vertex[idx].size(); i++) {
        if (visit[vertex[idx][i]]) continue;
        
        visit[vertex[idx][i]] = true;
        dfs(vertex[idx][i]);
    }
}

void bfs() {
    queue<int> q;
    q.push(v);
    visit[v] = true;
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        
        cout << top << ' ';
        
        for (int i = 0; i < vertex[top].size(); i++) {
            if (visit[vertex[top][i]]) continue;
            
            visit[vertex[top][i]] = true;
            q.push(vertex[top][i]);
        }
    }
    cout << '\n';
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    
    visit[v] = true;
    dfs(v);
    cout << '\n';
    
    for (int i = 0; i <= n; i++) {
        visit[i] = false;
    }
    
    bfs();
    
    return 0;
}
