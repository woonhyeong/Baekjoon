//
//  main.cpp
//  13023
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int connect[2000][2000];
vector<pair<int,int>> node;
vector<int> v[2000];

void input() {
    cin >> n >> m;
    
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        
        node.push_back(make_pair(from, to));
        node.push_back(make_pair(to,from));
        
        connect[from][to] = true;
        connect[to][from] = true;
        
        v[from].push_back(to);
        v[to].push_back(from);
        
    }
}

void solve() {
    
    for (int i = 0; i < node.size(); i++) {
        for (int k = 0; k < node.size(); k++) {
            if (i == k ) continue;
            
            int A = node[i].first;
            int B = node[i].second;
            int C = node[k].first;
            int D = node[k].second;
            
            if (A == C || A == D || B == C || B == D ) {
                continue;
            }
            
            if (!connect[B][C]) {
                continue;
            }
            
            for (int E : v[D]) {
                if (E == A || E == B || E == C) continue;
                
                cout << "1" << '\n';
                return;
            }
        }
    }
    
    cout << "0" << '\n';
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    return 0;
}
