//
//  main.cpp
//  17143
//
//  Created by 이운형 on 03/06/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

struct fish {
    int x,y,s,d;
};

int R, C, M;
int sea[100][100];
fish fishes[10001];

int capture(int idx) {
    int ans = 0;
    for (int i = 0; i < R; i++) {
        if (sea[i][idx] > 0) {
            ans += sea[i][idx];
            sea[i][idx] = 0;
            break;
        }
    }
    return ans;
}

void move() {
    int newSea[100][100] = {0,};
    
    for (int i = 0; i < R; i++) {
        for (int k = 0; k < C; k++) {
            if (sea[i][k] > 0) {
                int z = sea[i][k];
                int x = fishes[z].x, y = fishes[z].y, s = fishes[z].s, d = fishes[z].d;
                
                // 위
                if (d == 1 || d == 2) {
                    int speed = s%(2*(R-1));
                    while (speed--) {
                        if(d == 1) {
                            if(x-1 >= 0) {
                                x--;
                            } else {
                                x++;
                                d = 2;
                            }
                        } else {
                            if(x+1 < R) {
                                x++;
                            } else {
                                x--;
                                d = 1;
                            }
                        }
                    }
                    
                    fishes[z].d = d;
                    fishes[z].x = x;
                    if(newSea[x][y] > 0) {
                        if (newSea[x][y] < z) newSea[x][y] = z;
                    } else {
                        newSea[x][y] = z;
                    }
                } else if (d == 3 || d == 4) {
                    int speed = s%(2*(C-1));
                    while (speed--) {
                        if(d == 4) {
                            if(y-1 >= 0) {
                                y--;
                            } else {
                                y++;
                                d = 3;
                            }
                        } else {
                            if(y+1 < C) {
                                y++;
                            } else {
                                y--;
                                d = 4;
                            }
                        }
                    }
                    
                    fishes[z].d = d;
                    fishes[z].y = y;
                    if(newSea[x][y] > 0) {
                        if (newSea[x][y] < z) newSea[x][y] = z;
                    } else {
                        newSea[x][y] = z;
                    }
                }
                
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int k = 0; k < C; k++) {
            sea[i][k] = newSea[i][k];
        }
    }
}

void input() {
    cin >> R >> C >> M;
    int x,y,s,d,z;
    
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> s >> d >> z;
        sea[x-1][y-1] = z;
        fishes[z] = {x-1,y-1,s,d};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    int ans = 0;
    for (int i = -1; i < C-1;) {
        i +=1 ;
        ans += capture(i);
        move();
    }
    
    cout << ans << '\n';
}
