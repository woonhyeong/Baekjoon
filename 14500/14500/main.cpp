//
//  main.cpp
//  14500
//
//  Created by 이운형 on 06/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int map[501][501];
int s01[3][2] = {{0,1},{0,2},{0,3}}; // 일자
int s02[3][2] = {{0,1},{1,0},{1,1}}; // 네모
int s03[3][2] = {{1,0},{2,0},{2,1}}; // ㄴ
int s04[3][2] = {{1,0},{1,1},{2,1}}; // 꺾임
int s05[3][2] = {{0,1},{0,2},{1,1}}; // ㅜ

int s901[3][2] = {{1,0},{2,0},{3,0}}; // 일자
int s903[3][2] = {{0,1},{0,2},{1,0}}; // ㄴ
int s904[3][2] = {{0,1},{-1,1},{-1,2}}; // 꺾임
int s905[3][2] = {{0,1},{-1,1},{1,1}}; // ㅓ

int s1803[3][2] = {{0,1},{1,1},{2,1}}; // ㄱ
int s1805[3][2] = {{1,0},{1,-1},{1,1}}; // ㅗ

int s2703[3][2] = {{0,1},{0,2},{-1,2}}; // ㄴ
int s2705[3][2] = {{1,0},{1,1},{2,0}};

int sr01[3][2] = {{0,1},{-1,1},{-2,1}};
int sr02[3][2] = {{1,0},{1,1},{1,2}};
int sr03[3][2] = {{0,1},{1,0},{2,0}};
int sr04[3][2] = {{0,1},{0,2},{1,2}};

int sr05[3][2] = {{1,0},{0,1},{-1,1}};
int sr06[3][2] = {{0,1},{1,1},{1,2}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    
    long long max = 0;
    int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s01[0][0];y2=y1+s01[0][1];
            x3=x1+s01[1][0];y3=y1+s01[1][1];
            x4=x1+s01[2][0];y4=y1+s01[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s02[0][0];y2=y1+s02[0][1];
            x3=x1+s02[1][0];y3=y1+s02[1][1];
            x4=x1+s02[2][0];y4=y1+s02[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s03[0][0];y2=y1+s03[0][1];
            x3=x1+s03[1][0];y3=y1+s03[1][1];
            x4=x1+s03[2][0];y4=y1+s03[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s04[0][0];y2=y1+s04[0][1];
            x3=x1+s04[1][0];y3=y1+s04[1][1];
            x4=x1+s04[2][0];y4=y1+s04[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s05[0][0];y2=y1+s05[0][1];
            x3=x1+s05[1][0];y3=y1+s05[1][1];
            x4=x1+s05[2][0];y4=y1+s05[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s901[0][0];y2=y1+s901[0][1];
            x3=x1+s901[1][0];y3=y1+s901[1][1];
            x4=x1+s901[2][0];y4=y1+s901[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s903[0][0];y2=y1+s903[0][1];
            x3=x1+s903[1][0];y3=y1+s903[1][1];
            x4=x1+s903[2][0];y4=y1+s903[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s904[0][0];y2=y1+s904[0][1];
            x3=x1+s904[1][0];y3=y1+s904[1][1];
            x4=x1+s904[2][0];y4=y1+s904[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s905[0][0];y2=y1+s905[0][1];
            x3=x1+s905[1][0];y3=y1+s905[1][1];
            x4=x1+s905[2][0];y4=y1+s905[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s1803[0][0];y2=y1+s1803[0][1];
            x3=x1+s1803[1][0];y3=y1+s1803[1][1];
            x4=x1+s1803[2][0];y4=y1+s1803[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }

    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s1805[0][0];y2=y1+s1805[0][1];
            x3=x1+s1805[1][0];y3=y1+s1805[1][1];
            x4=x1+s1805[2][0];y4=y1+s1805[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s2703[0][0];y2=y1+s2703[0][1];
            x3=x1+s2703[1][0];y3=y1+s2703[1][1];
            x4=x1+s2703[2][0];y4=y1+s2703[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+s2705[0][0];y2=y1+s2705[0][1];
            x3=x1+s2705[1][0];y3=y1+s2705[1][1];
            x4=x1+s2705[2][0];y4=y1+s2705[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+sr01[0][0];y2=y1+sr01[0][1];
            x3=x1+sr01[1][0];y3=y1+sr01[1][1];
            x4=x1+sr01[2][0];y4=y1+sr01[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+sr02[0][0];y2=y1+sr02[0][1];
            x3=x1+sr02[1][0];y3=y1+sr02[1][1];
            x4=x1+sr02[2][0];y4=y1+sr02[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+sr03[0][0];y2=y1+sr03[0][1];
            x3=x1+sr03[1][0];y3=y1+sr03[1][1];
            x4=x1+sr03[2][0];y4=y1+sr03[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+sr04[0][0];y2=y1+sr04[0][1];
            x3=x1+sr04[1][0];y3=y1+sr04[1][1];
            x4=x1+sr04[2][0];y4=y1+sr04[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+sr05[0][0];y2=y1+sr05[0][1];
            x3=x1+sr05[1][0];y3=y1+sr05[1][1];
            x4=x1+sr05[2][0];y4=y1+sr05[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    
    x1=0;y1=0;x2=0;y2=0;x3=0;y3=0;x4=0;y4=0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            x1=i;y1=k;
            x2=x1+sr06[0][0];y2=y1+sr06[0][1];
            x3=x1+sr06[1][0];y3=y1+sr06[1][1];
            x4=x1+sr06[2][0];y4=y1+sr06[2][1];
            if (x1<0 || x2<0 || x3<0 || x4<0 || x1>=n || x2>=n || x3>=n || x4>=n || y1<0 || y2<0 || y3<0 || y4<0 || y1>=m || y2>=m || y3>=m || y4>=m) {
                continue;
            }
            int sum = map[x1][y1] + map[x2][y2] + map[x3][y3] + map[x4][y4];
            if (sum > max) max = sum;
        }
    }
    printf("%lld\n",max);
}
