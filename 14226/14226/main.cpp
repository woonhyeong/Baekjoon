//
//  main.cpp
//  14226
//
//  Created by 이운형 on 2019/10/15.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

bool visit[1001][1001];
int s;

void solve() {
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    visit[1][0] = true;
    
    int cnt = 0;
    
    while(!q.empty()) {
        
        int size = (int)q.size();
        
        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if (x == s) {
                cout << cnt << '\n';
                return;
            }
            
            // 복사
            if (!visit[x][x]) {
                q.push(make_pair(x,x));
                visit[x][x] = true;
            }
            
            // 붙여넣기
            if (x+y < 1001 && !visit[x+y][y]) {
                q.push(make_pair(x+y,y));
                visit[x+y][y] = true;
            }
            
            // 삭제
            if (x-1 >= 0 && !visit[x-1][y]) {
                q.push(make_pair(x-1,y));
                visit[x-1][y] = true;
            }
        }
        
        cnt++;
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s;
    solve();
    
    return 0;
}
