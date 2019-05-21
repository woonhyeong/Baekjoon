//
//  main.cpp
//  MazeMaker
//
//  Created by 이운형 on 19/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class MazeMaker {
public:
    bool isInRange(int x, int y, int mazeRow, int mazeCol) {
        if(x < 0 || x >= mazeCol || y < 0 || y >= mazeRow) return false;
        return true;
    }
    
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
        int dirLength = (unsigned int)moveRow.size();
        int mazeRow = (unsigned int)maze.size();
        int mazeCol = (unsigned int)maze[0].size();
        int moveNum[50][50];
        for (int i = 0; i < 50; i++) {
            for (int k = 0; k < 50; k++) {
                moveNum[i][k] = -1;
            }
        }
        
        moveNum[startRow][startCol] = 0;
        
        queue<pair<int,int>> q;
        q.push(make_pair(startRow,startCol));
        
        while (!q.empty()) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            
            for (int i = 0; i < dirLength; i++) {
                int nextX = x + moveCol[i];
                int nextY = y + moveRow[i];
                
                if (isInRange(nextX, nextY,mazeRow,mazeCol) && maze[nextY][nextX] == '.'  && moveNum[nextY][nextX] == -1) {
                    moveNum[nextY][nextX] = moveNum[y][x] + 1;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < maze.size(); i++) {
            for (int k = 0; k < maze[i].size(); k++) {
                if (maze[i][k] == '.' && moveNum[i][k] == -1) {
                    return -1;
                }
                
                ans = max(ans, moveNum[i][k]);
            }
        }
        
        return ans;
    }
};

int main() {
    vector<string> maze = {"...","...","..."};
    int startRow = 0;
    int startCol = 1;
    vector<int> moveRow = {1,0,-1,0};
    vector<int> moveCol = {0,1,0,-1};
    
    MazeMaker m = MazeMaker();
    printf("%d\n",m.longestPath(maze, startRow, startCol, moveRow, moveCol));
}
