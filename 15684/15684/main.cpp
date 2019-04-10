//
//  main.cpp
//  15684
//
//  Created by 이운형 on 10/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int N,M,H;
bool row_line[30][10];

bool check(int x, int y) {
    if (y-1 < 0) {
        if (row_line[x][y+1]) return false;
        else return true;
    } else if (y-1 >= 0 && y+1 >= N-1) {
        if (row_line[x][y-1]) return false;
        else return true;
    } else {
        if (row_line[x][y+1] || row_line[x][y-1]) return false;
        else return true;
    }
}

bool calculate(int row) {
    int iter = row;
    for (int i = 0; i < H; i++) {
        if (iter-1 >= 0 && row_line[i][iter-1]) {
            iter = iter -1;
        }
        else if (row_line[i][iter]) {
            iter = iter + 1;
        }
    }
    
    if (iter == row) {
        return true;
    } else {
        return false;
    }
}

bool solve( ) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!calculate(i)) {
            break;
        } else {
            ans++;
        }
    }
    
    if (ans == N) return true;
    return false;
}

bool solve_02(int idx, int cnt) {
    if (cnt == 2) {
        if (solve()) {
            return true;
        } else return false;
    }
    
    for (int i = idx+1; i < H*(N-1); i++) {
        int x = i/(N-1), y = i%(N-1);
        
        if (!row_line[x][y] && check(x,y)) {
            row_line[x][y] = true;
            if(solve_02(i,cnt+1)) return true;
            row_line[x][y] = false;
        }
    }
    return false;
}

bool solve_03(int idx, int cnt) {
    if (cnt == 3) {
        if (solve()) {
            return true;
        } else return false;
    }
    
    for (int i = idx+1; i < H*(N-1); i++) {
        int x = i/(N-1), y = i%(N-1);
        
        if (!row_line[x][y] && check(x,y)) {
            row_line[x][y] = true;
            if(solve_03(i,cnt+1)) return true;
            row_line[x][y] = false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> H;
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        row_line[x-1][y-1] = true;
    }
    
    // 0개 일 때
    if (solve()) {
        cout << "0" << endl;
        return 0;
    }
    // 1개 일 때
    for (int i = 0; i < H; i++) {
        for (int k = 0; k < N-1; k++) {
            if (!row_line[i][k] && check(i,k)) {
                row_line[i][k] = true;
                if(solve()) {
                    cout << "1" << endl;
                    return 0;
                }
                row_line[i][k] = false;
            }
        }
    }
    // 2개 일 때
    for (int i = 0; i < H*(N-1); i++) {
        int x = i/(N-1), y = i%(N-1);
        
        if (!row_line[x][y] && check(x,y)) {
            row_line[x][y] = true;
            if(solve_02(i,1)) {
                cout << "2" << endl;
                return 0;
            }
            row_line[x][y] = false;
        }
    }
    // 3개 일 때
    for (int i = 0; i < H*(N-1); i++) {
        int x = i/(N-1), y = i%(N-1);
        
        if (!row_line[x][y] && check(x,y)) {
            row_line[x][y] = true;
            if(solve_03(i,1)) {
                cout << "3" << endl;
                return 0;
            }
            row_line[x][y] = false;
        }
    }
    
    cout << "-1" << endl;
}
