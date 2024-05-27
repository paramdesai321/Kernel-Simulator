# Kernel-Simulator

This project aims to demostrate various functions of operating systems through a simulator written in a well documented code in C, to educate undergraduate students. 

## Processes 

A **process** is an instance of a program being executed by an OS.

The OS keeps track of each process using a **process control block (PCB)**: A data structure that holds information for a process, including the current instruction address, the execution stack, the set of resources used by the process, and the program being executed. The PCB is the concrete representation of a process.

I have created a Process control block in C, that schedules process using 3 algorithms: **First in First out(FIFO)**, **Shortest Job First(SJF)** and **Shortest Remaining Time(SRT)**. 

Directions to code : 
``` cd/ProcessControlBlock/PCB.c ```


