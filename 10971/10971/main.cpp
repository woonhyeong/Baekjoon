//
//  main.cpp
//  10971
//
//  Created by 이운형 on 04/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
#include <stdio.h>
#include <algorithm>
int a[11][11];

int main() {
    int n, r = 11000001;
    scanf("%d",&n);
    
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<n; k++) {
            scanf("%d",&a[i][k]);
        }
    }
    
    int d[10];
    for (int i = 0; i<n; i++) d[i] = i;
    
    do {
        int sum = 0;
        bool check = true;
        for (int i = 0; i<n-1; i++) {
            if (a[d[i]][d[i+1]] == 0) {
                check = false;
                break;
            }
            sum += a[d[i]][d[i+1]];
        }

        if (check && a[d[n-1]][d[0]]!=0) {
            sum+=a[d[n-1]][d[0]];
            if (sum < r) r = sum;
        }
    } while (std::next_permutation(d+1,d+n));
    
    printf("%d\n",r);
    return 0;
}
//#include <stdio.h>
//int a[11][11];
//bool check[11];
//int n,m = 20000001;
//
//void dfs(int start, int next, int sum, int cnt) {
//    if (cnt == n && start == next) {
//        if (m > sum) m = sum;
//        return;
//    }
//
//    for (int i = 0; i < n; i++) {
//        if(a[next][i] == 0) continue;
//        if (!check[next]) {
//            check[next] = true;
//            sum += a[next][i];
//            if (sum < m) {
//                dfs(start, i, sum, cnt+1);
//            }
//            check[next] = false;
//            sum -= a[next][i];
//        }
//    }
//}
//
//int main() {
//    scanf("%d",&n);
//
//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k < n; k++) {
//            scanf("%d",&a[i][k]);
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        dfs(i,i,0,0);
//    }
//    printf("%d\n",m);
//}
