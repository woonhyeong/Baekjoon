//
//  main.swift
//  1009
//
//  Created by 이운형 on 03/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
//  a의 1의 자릿수만 계산하고, b는 4마다 수가 같으므로 4로 나눈 나머지를 이용해 1~4만 사용하여 계산하였다.
//  다만, b의 4의 나머지는 0이지만 4가 되야하므로 pow()에서 count변수에 조건문을 사용하여 값을 변경했다.
//  이렇게 하면 5의 경우 b는 1이 되어 알고리즘이 잘 성립한다.
//
func pow(_ a:Int, _ b:Int) -> Int {
    var result = 1
    let count = (b == 0 ? 4 : b)
    for _ in 0..<count {
        result *= a
    }
    result %= 10
    return (result == 0 ? 10 : result)
}

let testCount = Int(readLine()!)!

for _ in 1...testCount {
    let input = readLine()!.split(separator: " ").map{Int($0)!}
    let (a, b) = (input[0]%10, input[1]%4)

    if a == 0 {
        print(10)
    } else {
        print(pow(a,b))
    }
}
