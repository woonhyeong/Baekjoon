//
//  main.cpp
//  1541
//
//  Created by 이운형 on 19/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {
    char op;
    int r,m,s=0;
    
    for (scanf("%d", &r); scanf("%c",&op),op!=10;) {
        scanf("%d", &m);
        if (op == '-') s = -1;
        r += s<0?-m:m;
    }
    
    cout << r << endl;
    return 0;
}


