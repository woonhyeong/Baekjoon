//
//  main.swift
//  1016
//
//  Created by 이운형 on 15/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
//  주석은 맨 처음 풀었던 풀이이고, 현 코드는 백준의 다른 풀이를 참고하였다.
//  첫 번째는 i = 2부터 max의 제곱근까지 i*i를 나눠지는 수로 max범위 가지 더해가며 result 배열을 변경한다.
//  근데, i 를 2부터 max의 제곱근까지하면 겹치는 수가 너무 많다. ex) i는 4일 때 수는 i = 2일 때 이미 다 처리되었다.
//
//  그래서 두 번째 방법은 소수의 배열을 만든 다음에 i = 소수로 해서 i*i max범위 까지 더해가며 result 배열을 변경한다.
//

let input = readLine()!.split(separator: " ").map{Int($0)!}
let (min, max) = (input[0], input[1])

var result: [Bool] = Array(repeating: false, count: max-min+1)
var isPrime: [Bool] = Array(repeating: true, count: 1_000_001)
var primeNumber = [Int]()

var resultValue = 0

for i in 2...1_000_000 {
    if isPrime[i] {
        primeNumber.append(i)
        
        if 1_000_000/i > 2 {
            for k in 2...1_000_000/i {
                isPrime[i*k] = false
            }
        }
    }
}

for i in primeNumber {
    let snum = i*i
    let target = min%snum == 0 ? min : (min/snum + 1)*snum
    
    for k in stride(from: target, through: max, by: snum) {
        if !result[k-min] {
            result[k-min] = true
        }
    }
}

for i in 0 ..< result.count {
    if result[i] {
        resultValue += 1
    }
}

print(result.reduce(0){ $0 + ($1 ? 0 : 1)})


//import Foundation
//
//let input = readLine()!.split(separator: " ").map{Int($0)!}
//let (min, max) = (input[0], input[1])
//
//var result: [Bool] = Array(repeating: false, count: max-min+1)
//var resultValue = 0
//
//let maxSnum = Int(sqrt(Double(max)))
//
//if maxSnum >= 2 {
//    for i in 2...maxSnum {
//        let snum = i*i
//        var target = min
//
//        if target % snum != 0 {
//            target = (target/snum + 1) * snum
//        }
//
//        for k in stride(from: target, through: max, by: snum) {
//            if !result[k-min] {
//                result[k-min] = true
//            }
//
//        }
//    }
//    for i in 0 ..< result.count {
//        if result[i] {
//            resultValue += 1
//        }
//    }
//}
//
//print(max - min + 1 - resultValue)
