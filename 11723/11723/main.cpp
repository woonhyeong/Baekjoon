//
//  main.cpp
//  11723
//
//  Created by 이운형 on 01/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main() {
    int m;
    scanf("%d",&m);
    char op[7];
    int s = 0, x;
    for(int i = 0; i < m; i++) {
        scanf("%s", op);
        if (op[2] == 'd') {
            scanf("%d",&x);
            s = s|(1<<(x-1));
        }
        else if(op[2] == 'm') {
            scanf("%d",&x);
            s = s & ~(1<<(x-1));
        }
        else if(op[2] == 'e') {
            scanf("%d",&x);
            (s&(1<<(x-1))) ? printf("1\n") : printf("0\n");
        }
        else if (op[2] == 'g') {
            scanf("%d",&x);
            s = s^(1<<(x-1));
        }
        else if (op[2] == 'l') {
            s = (1<<20)-1;
        }
        else if (op[2] == 'p') {
            s = 0;
        }
    }
}
