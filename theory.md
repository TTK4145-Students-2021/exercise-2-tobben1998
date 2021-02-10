Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
> *An atomic operation is a opreation that executes fully with no interruption, so that nothing can write or read the memory,untilthe operation is complete.

### What is a critical section?
> A critical section is a a protected section that only can be executet of on process at the time. An atomic action is required in a critical section.

### What is the difference between race conditions and data races?
> A data race is a race betweentwo or morethread that tryies to access the same variable, and at least on of them try to modify the variable. A race conditions is a situatin where the result of the data race affects certain operations.

### What are the differences between semaphores, binary semaphores, and mutexes?
>   Mutex is a locking mechanism that makes sure only one thread can enter the critical section.
    a semaphore is a signaliing mechanism that is used to controll acess, and to prevent critical section problem
    binary semaphores are like semaphores, but their values is restricted to 0 and 1

### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), and queues (as used by Python)? 
> channels: sends and receives block until the other side is ready. This allows goroutines to synchronize without explicit locks or condition variables.
queue: is a linear data structure that store items in FIFO, and does not care about if other sides are ready, or does not add some kind of synchronization. 
mailboxes: You can have many different mailboxes and  they are quite similar to queues, but you can add som functionallity if you want. like blocking or binding, to limit the things that can be qued

### List some advantages of using message passing over lock-based synchronization primitives.
> *Your answer here* ?????????????????????????????????

### List some advantages of using lock-based synchronization primitives over message passing.
> *Your answer here*??????????????????????????????????????????++