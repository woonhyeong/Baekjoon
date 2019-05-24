//
//  main.cpp
//  ChessMetric
//
//  Created by 이운형 on 23/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 size = 3~100, start와 end = 2개의 요소를 갖는 배열, numMoves = 1~50 ( 경로의 총합으로 최대 2^63-1)
 */

int dir[16][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
class ChessMetric {
public:
    long long howMany(int size, vector<int> start, vector<int> end, int numMoves) {
        int sy = start[0], sx = start[1];
        int ey = end[0], ex = end[1];
        
        int dp[101][101][51] = {0,};
        dp[sy][sx][0] = 0;
        
        for (int move = 1; move <= numMoves; move++) {
            for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                    for (int i = 0; i < 16; i++) {
                        int ny = y + dir[i][0], nx = x + dir[i][1];
                        
                        if (nx < 0 || nx >= size || ny <0 || ny >= size) continue;
                        
                        dp[ny][nx][move] += dp[y][x][move-1] + 1;
                    }
                }
            }
        }
        
        return dp[ey][ex][numMoves];
    }
};

int main() {
    ChessMetric c = ChessMetric();
    cout << c.howMany(3, {0,0}, {1,2}, 1) << '\n';
}
