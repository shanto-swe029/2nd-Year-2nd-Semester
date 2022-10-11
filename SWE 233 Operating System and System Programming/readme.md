
# SWE 233 Operating System and System Progeamming


### Lecture-01: 22nd August, 2022

#### What is OS?
higibigi

<br> <br>

### Lecture-02: 30th August, 2022

#### Operating System Services
(from slide)

(.......)

* communications
* error detection
* resource allocation
* accounting
* protection and security
  - protection
  - security

#### A view of operating system services

#### System Call Implementation

#### API - SYstem Call - OS Relationship

#### System call parameter passing

#### Types of system call

* Process control
* File management
* Device management
* Information maintenance
* Communcations
* Protection

#### System Programs

#### Operating System Design and Implementation

<br> <br>

### Lecture-03, 04: 5th September, 2022 & 11th October, 2022

**Chapter-03 : Process**

#### Process Concepts
Process is a program in execution, process execution must progress in sequential fashion.
A process has multiple parts-
* The program code
* current activity including program counter
* Stack containing temp data
* Data section containing global variables
* Heap containing memory dynamically allocated during run time.

Program is passive entity stored on disk(executable file), process is active.

#### Process in Memory

#### Process State
As a process executes, it changes **state**:
* **new:** the process is being created
* **running:** instructions are being executed
* **waiting:** the process is waiting for some event to occur
* **ready:** the process is waiting to be assigned to a processor
* **terminated:** the process has finished execution

#### Diagram of process state

#### Process Control Block (PCB)
Also called **Task Control Block**.
**PCB** is the information associated with each process.
* **Process state** - running, waiting, etc
* **Program counter** - location of next instruction to be executed
* **CPU registers** - contents of all process-centric registers
* **CPU scheduling information** - priorities, scheduling queue pointers
* **Memory-management information** - memory allocated to the process
* **Accounting information** - CPU used, clock time elapsed since start, time limits
* **I/O status information** - I/O devices allocated to process, list of open files

#### CPU switch from process to process

#### Threads
* So far, process has a single thread of execution
* Consider having multiple program counters per process
	- Multiple locations can execute at once
		- Multiple threads of control -> **threads**
* Must then save storage for thread details, multiple program counters in PCB

#### Process Scheduling
* Maximize CPU use, quickly switch processes onto CPU for time sharing
* **Process Scheduler** selects among available processes for next execution on CPU

(...)

#### Representation of Process Scheduling

#### Multiprocess Architecture - Chrome Browser
Google Chrome Browser is multiprocess with 3 categories:
* Browser process
* Render process
* Plug-in process

#### Interprocess Communication

#### Communications Models
* Shared Memory
* Message Queue

#### Cooperating Processes



















