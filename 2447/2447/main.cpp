//
//  main.cpp
//  2447
//
//  Created by 이운형 on 25/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> map;

void draw(int n, int x, int color) {
    if (color == 0) {
        for (int i = x; i < x+n; i++) {
            for (int k = 0; k < n; k++) {
                map[i] += ' ';
            }
        }
    } else {
        if (n == 3) {
            map[x] += "***";
            map[x+1] += "* *";
            map[x+2] += "***";
        } else {
            for (int i = x; i < x+n; i+=n/3) {
                for (int j = 0; j < 3; j++) {
                    if (j == 1 && i == x+n/3) {
                        draw(n/3, i, 0);
                    }else {
                        draw(n/3, i, 1);
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i< n; i++) {
        map.push_back("");
    }
    
    if (n == 1) {
        cout << "*" << endl;
    } else {
        draw(n,0,1);
        for (int i = 0; i < n; i++) {
            cout << map[i] << endl;
        }
    }
}
