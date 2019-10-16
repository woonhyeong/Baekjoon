//
//  main.cpp
//  13549
//
//  Created by 이운형 on 2019/10/15.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

int n, k;
bool visit[100001];

void solve() {
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(n,0));
    visit[n] = true;
    
    while(!dq.empty()) {
        int x = dq.front().first;
        int time = dq.front().second;
        dq.pop_front();
        
        if (x == k) {
            cout << time << '\n';
            return;
        }
        
        if (x*2 < 100001 && !visit[x*2]) {
            dq.push_front(make_pair(x*2, time));
            visit[x*2] = true;
        }
        
        if (x-1 >= 0 && !visit[x-1]) {
            dq.push_back(make_pair(x-1, time+1));
            visit[x-1] = true;
        }
        
        if (x+1 < 100001 && !visit[x+1]) {
            dq.push_back(make_pair(x+1,time+1));
            visit[x+1] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    solve();
    
    return 0;
}
