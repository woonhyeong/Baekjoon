//
//  main.swift
//  1019
//
//  Created by 이운형 on 18/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

var input = Int(readLine()!)!
var result: [Int] = Array(repeating: 0, count: 10)
var digit = 1

func decrease(_ num: Int) {
    var temp = num
    while temp > 0 {
        result[temp%10] += digit
        temp = temp/10
    }
}

while input > 0 {
    while input%10 != 9 && input>0 {
        decrease(input)
        input -= 1
    }
    
    if input == 0 {
        break
    }
    
    for i in 0...9 {
        result[i] += (input/10 + 1)*digit
    }
    
    input /= 10
    digit *= 10
}

if result[0] > 0 {
    while digit > 0 {
        result[0] -= digit/10
        digit = digit/10
    }
}

var output = ""
for element in result {
    output.append(String(element)+" ")
}
print(output)


