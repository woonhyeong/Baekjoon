//
//  main.cpp
//  2873
//
//  Created by 이운형 on 22/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int m[1000][1000];
void mark(char direction, string &dest, int num) {
    for (int i = 0; i< num; i++) {
        dest += direction;
    }
}

int main() {
    int r,c;
    string l = "";
    
    cin >> r >> c;
    
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            cin >> m[i][k];
        }
    }
    
    if(r%2 != 0) {
        for (int i = 0; i < r/2; i++) {
            mark('R', l, c-1);
            l += 'D';
            mark('L', l, c-1);
            l += 'D';
        }
        mark('R', l, c-1);
    }
    
    else if(c%2 != 0) {
        for (int i = 0; i < c/2; i++) {
            mark('D', l, r-1);
            l+='R';
            mark('U', l, r-1);
            l+='R';
        }
        mark('D', l, r-1);
    }
    
    else {
        int x = 0, y = 0, min = 1005;
        
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k ++) {
                if ((i+k)%2 != 0 && m[i][k] < min) {
                    min = m[i][k];
                    x = i; y = k;
                }
            }
        }
        
        int cut = (x%2? x-1 : x);
        for (int i = 0; i < cut; i ++) {
            if (i%2 == 0) {
                mark('R', l, c-1);
                l+='D';
            } else {
                mark('L', l, c-1);
                l+='D';
            }
        }
        
        for (int i = 0; i < y; i++) {
            if (i%2 == 0) {
                l += "DR";
            } else {
                l += "UR";
            }
        }
        
        for (int i = y; i < c-1; i++) {
            if (i%2 == 0) {
                l += "RD";
            } else {
                l += "RU";
            }
        }
        
        if (x%2 == 0) {
            cut = r - (x+2);
        } else {
            cut = r - (x+1);
        }
        
        for (int i = 0; i < cut; i++) {
            l += 'D';
            if (i%2 == 0) {
                mark('L', l, c-1);
            }else {
                mark('R', l, c-1);
            }
        }
    }
    cout << l << endl;
    return 0;
}
