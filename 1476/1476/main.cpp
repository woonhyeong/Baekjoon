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
    
    int n1=1,n2=1,n3=1;
    for (int i = 1; i <= 15*28*19; i++) {
        if (n1 == e && n2 == s && n3 ==m) {
            printf("%d\n",i);
            return 0;
        }
        n1+=1;
        n2+=1;
        n3+=1;
        if (n1 > 15) n1 = 1;
        if (n2 > 28) n2 = 1;
        if (n3 > 19) n3 = 1;
    }
}
