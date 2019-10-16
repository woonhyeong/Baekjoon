//
//  main.cpp
//  1463
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

bool visit[1000001];
int X;

void solve() {
    queue<pair<int,int>> q;
    q.push({X,0});
    visit[X] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int val = q.front().second;
        q.pop();
        
        if (x == 1) {
            cout << val << '\n';
            return;
        }
        
        if (x%3 == 0 && !visit[x/3]) {
            q.push({x/3, val+1});
            visit[x/3] = true;
        }
        
        if (x%2 == 0 && !visit[x/2]) {
            q.push({x/2, val+1});
            visit[x/2] = true;
        }
        
        if (x-1 >= 1 && !visit[x-1]) {
            q.push({x-1, val+1});
            visit[x-1] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X;
    solve();
    
    return 0;
}
