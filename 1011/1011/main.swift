//
//  main.swift
//  1011
//
//  Created by 이운형 on 05/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 1 2 3 4 3 2 1 과 같이 수가 증가하다 다시 내려가는 수열의 문제이다.
 이 알고리즘은 2가지 방식으로 풀 수 있었다.
 처음에는 규칙을 찾아서 첫 번째 input과 두 번째 input의 차가 어떤 최소의 제곱 수 범위에 있는지 확인하고,
 제곱 수와 input의 차가 같으면 수열의 개 수, 다음 제곱 수와의 반의 범위에 있으면 최고 제곱 수의 수열 개수 + 1, 반을 넘으면 +2 이런 식으로 했는데 알고리즘의 기본적인 원리를 이해하지 못하고 노가다로 해결한 셈이다.
 
 두 번째로 풀 때는 저 수열의 규칙을 좀 더 생각했다. 1 2 3 4 3 2 1 의 경우 전체 수열의 합은 가장 가운데 있는 4^2이다. 그리고 수를 4 증가 시키면 1 2 3 4 4 3 2 1과 같이 나온다. 그래서 가운데 수를 i라 둘 때, input보다 작은 최소의 i를 구하고, input - i^2을 i로 나눈 값을 d라 할 때 d의 같거나 큰 최소의 정수를 d에 저장한다. 왜냐하면, input의 차가 16일 경우 수열은 1 2 3 4 3 2 1 이고, i = 4 이다. 20일 경우 1 2 3 4 4 3 2 1 이 되어 구하려는 결과값에 숫자가 1개 늘어난다. 그리고 21일 경우 1 2 3 4 4 3 2 1 1 로 결과값에 숫자가 2개 늘어난다. 즉 i+1 만큼 늘어 날 때 마다 결과값이 1 씩 증가하게 된다. 그 원리로 문제를 풀었더니 성능이 훨씬 증가하였다.
 */

//let testCount = Int(readLine()!)!
//
//func doublePow(_ radix:Int) -> Int {
//    return radix*radix
//}
//
//func calculateRange(_ number:Int) -> (Int, Int) {
//    var min = 1, max = 2
//
//    while true {
//        if doublePow(min) <= number && number < doublePow(max) {
//            break
//        } else {
//            min += 1
//            max += 1
//        }
//    }
//    return (min,max)
//}
//
//func calculateResult(_ number:Int) -> Int {
//    var value = 0
//    for _ in 0..<number {
//        value += 1
//    }
//    return 2 * value - 1
//}
//
//for _ in 1...testCount {
//    let input = readLine()!.split(separator: " ").map{Int($0)!}
//    let number = input[1] - input[0]
//
//    let (min, max) = calculateRange(number)
//    let middle = (doublePow(min) + doublePow(max))/2
//    var result = calculateResult(min)
//
//    if doublePow(min) == number {
//
//    } else if number <= middle {
//        result += 1
//    } else if number < doublePow(max) {
//        result += 2
//    }
//
//    print(result)
//}

let testCount = Int(readLine()!)!

func calculateRange(_ number:Int) -> Int {
    var value = 1
    
    while true {
        if value*value > number {
            break
        } else {
            value += 1
        }
    }
    return value - 1
}

for _ in 1...testCount {
    let input = readLine()!.split(separator: " ").map{Int($0)!}
    let distance = input[1] - input[0]
    let min = calculateRange(distance)
    var d:Int = 0
    if (distance - min*min)%min == 0 {
        d = (distance - min*min)/min
    } else {
        d = (distance - min*min)/min + 1
    }
    print(2*min - 1 + d)
}

