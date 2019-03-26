//
//  main.cpp
//  2261
//
//  Created by 이운형 on 26/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{
    int x,y;
    bool operator < (const Point &v) const {
        if (x == v.x) {
            return y < v.y;
        } else {
            return x < v.x;
        }
    }
};

int distan(Point i, Point j) {
    return (j.x - i.x)*(j.x - i.x) + (j.y - i.y)*(j.y - i.y);
}

bool cmpY(const Point &i, const Point &j) {
    return i.y < j.y;
}

int brute(int s, int e, vector<Point> &p) {
    int m = INT_MAX;
    
    for (int i = s; i < e; i++) {
        for (int j = s+1; j <= e; j++) {
            int dist = distan(p[i], p[j]);
            if (dist < m) {
                m = dist;
            }
        }
    }
    return m;
}

int closest(int s, int e, vector<Point> &p) {
    if (e-s+1 < 3) {
        return brute(s, e, p);
    }
    
    int mid = (s+e)/2;
    int left = closest(s, mid, p);
    int right = closest(mid+1, e, p);
    int ans = min(left, right);
    
    vector<Point> b;
    
    for (int i = s; i <= e; i++) {
        int d = p[mid].x - p[i].x;
        
        if (d*d < ans) b.push_back(p[i]);
    }
    
    sort(b.begin(), b.end(), cmpY);
    int m = b.size();
    for (int i = 0; i < m-1; i++) {
        for (int j = i+1; j < m; j++) {
            int y = b[j].y - b[i].y;
            if (y*y < ans) {
                int d = distan(b[i], b[j]);
                if (d < ans) {
                    ans = d;
                }
            } else {
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d",&n);
    vector<Point> p(n);
    for (int i = 0; i<n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    sort(p.begin(), p.end());
    printf("%d\n",closest(0, n-1, p));
}
