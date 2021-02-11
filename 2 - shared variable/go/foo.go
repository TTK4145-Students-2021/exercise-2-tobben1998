// cd " " in powrshell to navigate not just cd
// Use `go run foo.go` to run your program

package main

import (
	"fmt"
	"runtime"
)

func numberServer(add <-chan int, sub <-chan int, read chan<- int) {
	var number = 0

	// This for-select pattern is one you will become familiar with...
	for {
		select {
		case <-add:
			number++
		case <-sub:
			number--
		case read <- number:
			return
		}
	}
}

func incrementer(add chan<- int, finished chan<- bool) {
	for j := 0; j < 1000000; j++ {
		add <- 1
	}
	finished <- true //DONE: signal that the goroutine is finished
}

func decrementer(sub chan<- int, finished chan<- bool) {
	for j := 0; j < 1000002; j++ {
		sub <- 1
	}
	finished <- true //DONE: signal that the goroutine is finished
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())

	// DONE: Construct the remaining channels
	read := make(chan int)
	add := make(chan int)
	sub := make(chan int)
	finished := make(chan bool)

	// DONE: Spawn the required goroutines
	go numberServer(add, sub, read)
	go incrementer(add, finished)
	go decrementer(sub, finished)

	<-finished
	<-finished
	// DONE: block on finished from both "worker" goroutines

	fmt.Println("The magic number is:", <-read)
}
