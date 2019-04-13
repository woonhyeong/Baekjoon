//
//  main.cpp
//  1767
//
//  Created by 이운형 on 13/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int map[12][12];
int core[12][2];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int N;
int CORE_NUM, MAX_CORE;
int MIN_LINE = 987654321;

bool is_line(int x, int y, int d) {
    if (d == 0) {
        for (int i = x-1; i >= 0; i--) {
            if (map[i][y] != 0) return false;
        }
    } else if (d == 1) {
        for (int i = x+1; i < N; i++) {
            if (map[i][y] != 0) return false;
        }
    } else if (d == 2) {
        for (int i = y-1; i >= 0; i--) {
            if (map[x][i] != 0) return false;
        }
    } else if (d == 3) {
        for (int i = y+1; i < N; i++) {
            if (map[x][i] != 0) return false;
        }
    }
    return true;
}

int draw_line(int x, int y, int d, int c){
    int sum = 0;
    if (d == 0) {
        for (int i = x-1; i >= 0; i--) {
            map[i][y] = (c?0:2); sum++;
        }
    } else if (d == 1) {
        for (int i = x+1; i < N; i++) {
            map[i][y] = (c?0:2); sum++;
        }
    } else if (d == 2) {
        for (int i = y-1; i >= 0; i--) {
            map[x][i] = (c?0:2); sum++;
        }
    } else if (d == 3) {
        for (int i = y+1; i < N; i++) {
            map[x][i] = (c?0:2); sum++;
        }
    }
    return sum;
}

// 상 하 좌 우 안씀
void dfs(int cnt, int num, int line) {
    if (cnt == CORE_NUM) {
        if (MAX_CORE < num) {
            MAX_CORE = num;
            MIN_LINE = line;
        } else if (MAX_CORE == num && MIN_LINE > line) {
            MIN_LINE = line;
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (is_line(core[cnt][0], core[cnt][1], i)) {
                dfs(cnt+1, num+1, line + draw_line(core[cnt][0], core[cnt][1], i, 0));
                draw_line(core[cnt][0], core[cnt][1], i, 1);
            }
        }
        dfs(cnt+1, num, line);
    }
}

int main(){
    int test_cnt;
    cin >> test_cnt;
    
    vector <int> ans;
    for(int test_case = 0; test_case < test_cnt; test_case++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                cin >> map[i][k];
                if (map[i][k] == 1) {
                    if (i == 0 || i == N-1 || k == 0 || k == N-1) continue;
                    core[CORE_NUM][0] = i;
                    core[CORE_NUM][1] = k;
                    CORE_NUM++;
                }
            }
        }
        
        dfs(0,0,0);
        ans.push_back(MIN_LINE);
        CORE_NUM = 0; MAX_CORE = 0; MIN_LINE = 987654321;
    }
    
    int round = 1;
    for (int i = 0; i < ans.size(); i++) {
        cout << '#' << round << ' ' << ans[i] << endl;
        round++;
    }
}
