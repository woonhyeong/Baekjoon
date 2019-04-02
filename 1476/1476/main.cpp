//
//  main.cpp
//  1476
//
//  Created by 이운형 on 02/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main() {
    int e,s,m;
    scanf("%d %d %d", &e,&s,&m);
    
    for (int i = 1; i <= 15*28*19; i++) {
        if ((i-1)%15+1 == e && (i-1)%28+1 == s && (i-1)%19+1 == m) {
            printf("%d\n",i);
            return 0;
        }
    }
}
