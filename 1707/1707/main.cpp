//
//  main.cpp
//  1707
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int color[20001]; // 1: red, 2: blue
vector<int> edge[20001];

int T, v, e;

void dfs(int idx, int c) {
    color[idx] = c;
    for (int i = 0; i < edge[idx].size(); i++) {
        int next = edge[idx][i];
        if (color[next] == 0) {
            dfs(next, 3-c);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    
    while (T--) {
        cin >> v >> e;
        
        // initialize
        for (int i = 1; i <= v; i++) {
            edge[i].clear();
            color[i] = 0;
        }
        
        // input
        for (int i = 0; i < e; i++) {
            int from, to;
            cin >> from >> to;
            edge[from].push_back(to);
            edge[to].push_back(from);
        }
                
        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                dfs(i, 1);
            }
        }
        
        bool flag = true;
        
        for (int i = 1; i <= v; i++) {
            for (int k = 0; k < edge[i].size(); k++) {
                int child = edge[i][k];
                
                if (color[i] == color[child]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        
        if (flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}
