//
//  main.cpp
//  CorporationSalary
//
//  Created by 이운형 on 22/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 realations : 1~50개, row의 수 == column의 수, 각 문자열은 'N'과 'Y'로 구성
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long salary[50];

class CorporationSalary {
public:
    long long totalSalary(vector <string> realations) {
        long long total = 0;
        
        for (int i = 0; i < realations.size(); i++) {
            total += getSalary(i, realations);
        }
        
        return total;
    }
    
    long long getSalary(int idx, vector<string> realations) {
        if( salary[idx] != 0 ) return salary[idx];
        
        long long ps = 0;
        for (int i = 0; i < realations.size(); i++) {
            if (realations[idx][i] == 'Y') {
                ps += getSalary(i, realations);
            }
        }
        
        if (ps == 0) {
            salary[idx] = 1;
            ps = 1;
        }
        
        return ps;
    }
};

int main() {
    CorporationSalary c = CorporationSalary();
    vector<string> realations = {"NNNNNN","YNYNNY", "YNNNNY", "NNNNNN", "YNYNNN", "YNNYNN"};
    cout << c.totalSalary(realations) << '\n';
}
