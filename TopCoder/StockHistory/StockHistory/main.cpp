//
//  main.cpp
//  StockHistory
//
//  Created by 이운형 on 31/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

class StockHistory {
public:
    vector<string> split(string str, char delimeter) {
        vector<string> internal;
        stringstream ss(str);
        string temp;
        while (getline(ss, temp, delimeter)) {
            internal.push_back(temp);
        }
        return internal;
    }
    
    int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices) {
        int stock[50][50];
        int slen = 0;
        
        // convert string of stockPrices to int value
        for (int i = 0; i < stockPrices.size(); i++) {
            string s = stockPrices[i];
            vector<string> sline = split(s,' ');
            
            for (slen = 0; slen < sline.size(); slen++) {
                stock[i][slen] = stoi(sline[slen]);
            }
        }
    
        bool buy[50] = {false,};
        double inc[50];
        double ans = 0.0;
        double cur_max = 0;
        int eidx = (int)stockPrices.size()-1;
        
        for (int i = eidx-1; i >= 0; i--) {
            for (int k = 0; k < slen; k++) {
                double p = 1.0*stock[eidx][k]/stock[i][k] - 1;
                
                if (0 < p && cur_max < p) {
                    buy[i] = true;
                    cur_max = p;
                    inc[i] = p;
                }
            }
        }
        
        int money = initialInvestment;
        for (int i = 0; i < stockPrices.size(); i++) {
            if (buy[i]) {
                ans += money*inc[i];
                money = 0;
            }
            money += monthlyContribution;
        }
        
        return (int)round(ans);
    }
};

int main(){
    StockHistory s = StockHistory();
    printf("%d\n",s.maximumEarnings(100, 20, {"40 50 60","37 48 55","100 48 50","105 48 47","110 50 52","110 50 52","110 51 54","109 49 53"}));
}
