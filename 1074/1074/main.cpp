//
//  main.cpp
//  1074
//
//  Created by 이운형 on 25/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int power(int n) {
    return (1<<n);
}

int move(int n, int x, int y) {
    if (n == 1) {
        return 2*x + y;
    } else {
        if (x < power(n-1)) {
            if (y < power(n-1)) {
                return move(n-1, x, y);
            } else {
                return move(n-1, x, y-power(n-1)) + power(2*n-2);
            }
        } else {
            if (y < power(n-1)) {
                return move(n-1, x-power(n-1), y) + 2*power(2*n-2);
            } else {
                return move(n-1, x-power(n-1), y-power(n-1)) + 3*power(2*n-2);
            }
        }
    }
}

int main() {
    int n, r, c;
    scanf("%d %d %d",&n,&r,&c);
    printf("%d\n",move(n, r, c));
}
