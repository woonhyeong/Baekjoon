//
//  main.cpp
//  10430
//
//  Created by 이운형 on 2019/10/08.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int d = (a+b)%c, e = (a*b)%c;
    printf("%d\n%d\n%d\n%d\n",d,d,e,e);
    return 0;
}
