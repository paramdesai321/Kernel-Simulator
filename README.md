# Kernel-Simulator

This project aims to demostrate various functions of operating systems through a simulator written in a well documented code in C, to educate undergraduate students. 

## Processes 

A **process** is an instance of a program being executed by an OS.

The OS keeps track of each process using a **process control block (PCB)**: A data structure that holds information for a process, including the current instruction address, the execution stack, the set of resources used by the process, and the program being executed. The PCB is the concrete representation of a process.

Functions included in my Process Control Block:
--------------------------------
1) Enter parameters
2) Create a new child process
3) Destroy all descendants of a process
4) Quit program and free memory

Directions to code : 
```
cd/ProcessControlBlock/PCB.c

```
## Batch Scheduling 

A **batch** process performs a long-running and generally repetitive task that does not require any intervention from the user.

I have used 3 algorithms to schedule a batch process:  **First in First out(FIFO)**, **Shortest Job First(SJF)** and **Shortest Remaining Time(SRT)**.

Functions included for Batch Scheduling
----------------
1) Enter parameters
2) Schedule processes with FIFO algorithm
3) Schedule processes with SJF algorithm
4) Schedule processes with SRT algorithm
5) Quit and free memory

Directions to code: 
```
cd/BatchProcessing/Batch.c
```

## Deadlock 

A process is **deadlocked** in a state s if the process is blocked in s and if no matter what state transitions occur in the future, the process remains blocked.

For effective execution of processes it is important to resolve Deadlock, and it can be done using several algoritms. 
Banker's Algorithm is one of the most famous algorithms to resolve deadlock, the algorithm can be broken down into three simple steps:
1. Given a resource request in a state s, temporarily grant the request by changing the request edges to allocation edges.
2. Execute a graph reduction on the new state s'. (Claim edges are treated as request edges.)
3. If the graph of state s' is completely reducible then accept s' as the new state. Otherwise disallow the acquisition by reverting to state s.

Furthermore my program includes the following option for resolving deadlock using Banker's Algorithm:
------------------------------------------------------------------------------------------------------
1) Enter resource claim graph data
2) Request resource by a process
3) Release resource from a process
4) Determine safe sequence of processes
5) Quit program

Directions to code: 
```
cd/DeadLock/BankerAlgorithm.c
```

## Memory Management in a Magentic Disk

As programs are moved into and out of memory at runtime, the memory space becomes a checkerboard of free and occupied areas of different sizes. The OS keeps track of all free spaces, referred to as **holes**, using a linked list and must find a hole of appropriate size whenever a new program component is to be loaded into memory.

To manage memory for new processes, several **Hole-Fitting Algorithms** are used, I have used three hole fitting algorithms in my program:
1. First-Fit
2. Best-Fit
3. Worst-Fit

Additionally, there are one more approaches that I have used to manage the memory in magnetic disk:
1. **Defragmentation/Compaction**: the systematic shifting of modules in memory, generally in one direction, to consolidate multiple disjoint holes into one larger hole.

Lastly, there is a **Deallocation** feature that removes or deletes the memory allocation of a process.

List of feature in the program:
-------------------------------
1) Enter parameters
2) Allocate memory for block using First-fit
3) Allocate memory for block using Best-fit
4) Allocate memory for block using Worst-fit
5) Deallocate memory for block
6) Defragment memory
7) Quit program

Directions to code: 
```
cd/memorymanagement/holefittingalgorithms.c
```

**NOTE**: These algorithms are only designed for a Magnetic Disk, and would not work for the state-of-the-art Solid State Drives, beacuse they do not have moving parts.







