//
//  main.cpp
//  16234
//
//  Created by 이운형 on 11/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int map[50][50];
bool visit[50][50];
int clan[50][50];
int clan_num = 1;
int N, L, R;

bool possible(int a, int b) {
    int diff = a-b < 0 ? b-a : a-b;
    if (diff >= L && diff <= R) {
        return true;
    } else return false;
}

void bind(int x1, int y1, int x2 ,int y2) {
    if (clan[x1][y1] == 0 && clan[x2][y2] == 0) {
        clan[x1][y1] = clan_num;
        clan[x2][y2] = clan_num;
        clan_num += 1;
    } else if (clan[x1][y1] == 0 && clan[x2][y2] != 0) {
        clan[x1][y1] = clan[x2][y2];
    } else if (clan[x1][y1] != 0 && clan[x2][y2] == 0 ) {
        clan[x2][y2] = clan[x1][y1];
    }
}

void solve(int x, int y) {
    // 상 하 좌 우
    if (x-1 >= 0 && !visit[x-1][y] && possible(map[x-1][y], map[x][y])) {
        visit[x-1][y] = true;
        bind(x, y, x-1, y);
        solve(x-1, y);
    }
    
    if (x+1 < N && !visit[x+1][y] && possible(map[x+1][y], map[x][y])) {
        visit[x+1][y] = true;
        bind(x, y, x+1, y);
        solve(x+1, y);
    }
    
    if (y-1 >= 0 && !visit[x][y-1] && possible(map[x][y-1], map[x][y])) {
        visit[x][y-1] = true;
        bind(x, y, x, y-1);
        solve(x, y-1);
    }
    
    if (y+1 < N && !visit[x][y+1] && possible(map[x][y+1], map[x][y])) {
        visit[x][y+1] = true;
        bind(x, y, x, y+1);
        solve(x, y+1);
    }
}

void move() {
    for (int i = 1; i < clan_num; i++) {
        int sum = 0, num = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (clan[j][k] == i) {
                    sum += map[j][k];
                    num ++;
                }
            }
        }
        
        int avg = (sum / num);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (clan[j][k] == i) {
                    map[j][k] = avg;
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i<N; i++) {
        for (int k = 0; k<N; k++) {
            visit[i][k] = false;
        }
    }
    for (int i = 0; i<N; i++) {
        for (int k = 0; k<N; k++) {
            clan[i][k] = 0;
        }
    }
    clan_num = 1;
}

void input() {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> map[i][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L >> R;
    input();

    int ans = 0;
    while (true) {
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (!visit[i][k]) {
                    visit[i][k] = true;
                    solve(i,k);
                }
            }
        }
        
        if (clan_num == 1) {
            break;
        } else ans+=1;
        
        move();
        init();
    }
    
    cout << ans << endl;
}
