//
//  main.cpp
//  15683
//
//  Created by 이운형 on 09/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
int M;
int cctv_num;
int cctv_loc[8][3];
int ans = 999999;

void arr_copy(int arg1[8][8], int arg2[8][8]) {
    for (int i = 0; i<N; i++) {
        for (int k = 0; k<M; k++) {
            arg1[i][k] = arg2[i][k];
        }
    }
}

void dfs(int idx, int prev_map[8][8]) {
    if (idx == cctv_num) {
        int sum = 0;
        for (int i = 0; i<N; i++) {
            for (int k = 0; k<M; k++) {
                if (prev_map[i][k] == 0) sum += 1;
            }
        }
        if (ans > sum) ans = sum;
        return;
    }

    int cctv = cctv_loc[idx][2];
    
    if (cctv == 1) {
        int temp01[8][8], temp02[8][8], temp03[8][8], temp04[8][8];
        arr_copy(temp01,prev_map);
        arr_copy(temp02,prev_map);
        arr_copy(temp03,prev_map);
        arr_copy(temp04,prev_map);
        
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp01);
    
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp02[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp02[cctv_loc[idx][0]][i] == 0){
                temp02[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp02);
        
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp03[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp03[i][cctv_loc[idx][1]] == 0){
                temp03[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp03);
        
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp04[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp04[i][cctv_loc[idx][1]] == 0){
                temp04[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp04);
    }
    else if (cctv == 2) {
        int temp01[8][8], temp02[8][8];
        arr_copy(temp01,prev_map);
        arr_copy(temp02,prev_map);
        
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp01);
        
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp02[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp02[i][cctv_loc[idx][1]] == 0){
                temp02[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp02[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp02[i][cctv_loc[idx][1]] == 0){
                temp02[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp02);
    }
    else if (cctv == 3) {
        int temp01[8][8], temp02[8][8], temp03[8][8], temp04[8][8];
        arr_copy(temp01,prev_map);
        arr_copy(temp02,prev_map);
        arr_copy(temp03,prev_map);
        arr_copy(temp04,prev_map);
        
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp01[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp01[i][cctv_loc[idx][1]] == 0){
                temp01[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp01);
        
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp02[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp02[cctv_loc[idx][0]][i] == 0){
                temp02[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp02[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp02[i][cctv_loc[idx][1]] == 0){
                temp02[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp02);
        
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp03[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp03[i][cctv_loc[idx][1]] == 0){
                temp03[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp03[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp03[cctv_loc[idx][0]][i] == 0){
                temp03[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp03);
        
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp04[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp04[cctv_loc[idx][0]][i] == 0){
                temp04[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp04[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp04[i][cctv_loc[idx][1]] == 0){
                temp04[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp04);
    }
    else if (cctv == 4) {
        int temp01[8][8], temp02[8][8], temp03[8][8], temp04[8][8];
        arr_copy(temp01,prev_map);
        arr_copy(temp02,prev_map);
        arr_copy(temp03,prev_map);
        arr_copy(temp04,prev_map);
        
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp01[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp01[i][cctv_loc[idx][1]] == 0){
                temp01[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp01);
        
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp02[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp02[i][cctv_loc[idx][1]] == 0){
                temp02[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp02[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp02[cctv_loc[idx][0]][i] == 0){
                temp02[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp02[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp02[i][cctv_loc[idx][1]] == 0){
                temp02[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp02);
        
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp03[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp03[cctv_loc[idx][0]][i] == 0){
                temp03[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp03[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp03[i][cctv_loc[idx][1]] == 0){
                temp03[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp03[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp03[cctv_loc[idx][0]][i] == 0){
                temp03[cctv_loc[idx][0]][i] = 8;
            }
        }
        dfs(idx+1, temp03);
        
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp04[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp04[i][cctv_loc[idx][1]] == 0){
                temp04[i][cctv_loc[idx][1]] = 8;
            }
        }
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp04[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp04[cctv_loc[idx][0]][i] == 0){
                temp04[cctv_loc[idx][0]][i] = 8;
            }
        }
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp04[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp04[i][cctv_loc[idx][1]] == 0){
                temp04[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp04);
    }
    else if (cctv == 5) {
        int temp01[8][8];
        arr_copy(temp01,prev_map);
        
        for (int i = cctv_loc[idx][1]; i>=0; i--) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        
        for (int i = cctv_loc[idx][1]; i<M; i++) {
            if (temp01[cctv_loc[idx][0]][i] == 6) {
                break;
            } else if (temp01[cctv_loc[idx][0]][i] == 0){
                temp01[cctv_loc[idx][0]][i] = 8;
            }
        }
        
        for (int i = cctv_loc[idx][0]; i>=0; i--) {
            if (temp01[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp01[i][cctv_loc[idx][1]] == 0){
                temp01[i][cctv_loc[idx][1]] = 8;
            }
        }
        
        for (int i = cctv_loc[idx][0]; i<N; i++) {
            if (temp01[i][cctv_loc[idx][1]] == 6) {
                break;
            } else if (temp01[i][cctv_loc[idx][1]] == 0){
                temp01[i][cctv_loc[idx][1]] = 8;
            }
        }
        dfs(idx+1, temp01);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    int map[8][8];
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cin >> map[i][k];
            if (map[i][k] != 0 && map[i][k] != 6) {
                cctv_loc[cctv_num][0] = i;
                cctv_loc[cctv_num][1] = k;
                cctv_loc[cctv_num][2] = map[i][k];
                cctv_num += 1;
            }
        }
    }
    
    dfs(0, map);
    cout << ans << endl;
}
