//
//  main.cpp
//  1929
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

//bool check[1000001];
//
//void era(int n) {
//    check[1] = true;
//    for (int i = 2; i*i <= n; i++) {
//        if (!check[i]) {
//            for (int j = i*i; j <= n; j+=i) {
//                check[j] = true;
//            }
//        }
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    int m, n;
//    scanf("%d %d", &m, &n);
//
//    era(n);
//
//    for (int i = m; i <= n; i++) {
//        if (!check[i]) printf("%d\n",i);
//    }
//
//    return 0;
//}

bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int m, n;
    scanf("%d %d", &m, &n);
    
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) printf("%d\n",i);
    }
    
    return 0;
}
