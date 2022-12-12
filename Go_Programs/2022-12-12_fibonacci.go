package main

import "fmt"

func main() {
	var num = 0
	var next = 1
	fibonacci(num, next)
}

func fibonacci(num int, next int) {
	fmt.Println(num)
	var temp = num
	num = next
	next += temp
	fibonacci(num, next)
}
