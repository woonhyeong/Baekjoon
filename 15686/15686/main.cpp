//
//  main.cpp
//  15686
//
//  Created by 이운형 on 11/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M;
int map[50][50];
int chicken[13][2];
int c_idx;
int ANS = 99999999;


int absolute(int x1, int y1, int x2, int y2) {
    int sum = 0;
    sum += (x1-x2)<0? x2-x1 : x1-x2;
    sum += (y1-y2)<0? y2-y1 : y1-y2;
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> map[i][k];
            if (map[i][k] == 2) {
                chicken[c_idx][0] = i;
                chicken[c_idx][1] = k;
                c_idx++;
            }
        }
    }
    
    int full = 1 << c_idx;
    
    for (int b = 1; b < full; b++) {
        int cnt = 0;
        vector<int> idx;
        for (int k = 0; k < c_idx; k++) {
            if (b & (1 << k)) {
                cnt++;
                idx.push_back(k);
            }
        }
        
        if (cnt != M) continue;
        
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (map[i][k] == 1) {
                    int min_dist = 101;
                    for (int j = 0; j < (int)idx.size(); j++) {
                        int dist = absolute(i,k,chicken[idx[j]][0], chicken[idx[j]][1]);
                        if (dist < min_dist) min_dist = dist;
                    }
                    sum += min_dist;
                }
            }
        }
        if (ANS > sum) ANS = sum;
    }
    
    cout << ANS << endl;
}
