# Kernel-Simulator

This project aims to demostrate various functions of operating systems through a simulator written in a well documented code in C, to educate undergraduate students. 

## Processes 

A **process** is an instance of a program being executed by an OS.

The OS keeps track of each process using a **process control block (PCB)**: A data structure that holds information for a process, including the current instruction address, the execution stack, the set of resources used by the process, and the program being executed. The PCB is the concrete representation of a process.

I have created a Process control block in C, with important operations like: **1. Creating Child Processes** **2. Destroying Children Processes**
Directions to code : 
```	cd/ProcessControlBlock/PCB.c
```
## Batch Scheduling 

A **batch** process performs a long-running and generally repetitive task that does not require any intervention from the user.

I have used 3 algorithms to schedule a batch process:  **First in First out(FIFO)**, **Shortest Job First(SJF)** and **Shortest Remaining Time(SRT)**.

Directions to code: 
```
cd/BatchProcessing/Batch.c
```


