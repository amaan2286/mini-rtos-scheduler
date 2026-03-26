Mini RTOS Scheduler (C)
Overview

This project implements a lightweight, cooperative RTOS-style task scheduler in C.
It demonstrates core operating system concepts such as task control blocks, task states, blocking delays, and scheduler ticks in a simplified, educational form.

Why this project

Most embedded systems rely on an RTOS, but the internals are often hidden.
This project was built to understand how schedulers actually work, not just how to use them.

Features

-Task Control Blocks (TCB)

-Task states: READY, RUNNING, BLOCKED

-Cooperative scheduling

-Tick-based task delay mechanism

-Clean modular structure (scheduler / task / application)
