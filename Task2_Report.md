# Week 2 Practical — Task 2 Report

## Title

Investigation of Hardware Resources and Operating System Services Using Linux Commands

## Objective

The objective of this task is to use Linux commands such as `uname`,
`lscpu`, `ps`, and `top` to examine the relationship between computer
hardware resources and operating system services.

## 1. System and Kernel Information — uname

The following command was used:

```bash
uname -a
The uname command displays information about the operating system kernel,
hostname, kernel version, and system architecture.

The Linux kernel acts as an intermediary between applications and hardware.
Applications request services from the kernel rather than directly accessing
the hardware.

Important observations from my output:

Kernel name:
Kernel version:
System architecture:
Hostname:
2. CPU Information — lscpu

The following command was used:

lscpu

The lscpu command displays information about the processor, including its
architecture, number of logical CPUs, cores, threads, caches, and
virtualization support.

Important observations from my output:

CPU architecture:
Number of logical CPUs:
Cores per socket:
Threads per core:
CPU model:
How the OS abstracts the CPU

The physical CPU can execute only a limited number of instructions at one
time. However, many programs appear to run simultaneously.

The operating system provides a process and thread abstraction. The CPU
scheduler gives each runnable process a small amount of CPU time. It rapidly
switches between processes using context switching.

Therefore, every process appears to have access to the CPU even though the
processor is shared among many processes.

3. Process Information — ps

The following commands were used:

ps
ps aux

The ps command displays information about currently running processes.

Each process is given a unique Process ID called a PID. The operating system
maintains information about every process, including its state, CPU usage,
memory usage, owner, and parent process.

This demonstrates that the OS converts a running program into a managed
process abstraction.

4. Live Resource Monitoring — top

The following command was used:

top

The top command displays continuously updated information about CPU usage,
memory usage, system load, and currently running processes.

Important observations from my output:

System load average:
Total memory:
Used memory:
Free memory:
Number of running processes:

top demonstrates that the operating system monitors resource usage and
distributes CPU and memory among multiple processes.

5. Operating System Abstraction of CPU

The operating system hides the complexity of the physical processor.

It provides processes and threads to programs. The CPU scheduler selects
which process runs and gives each process a time slice. Context switching
allows several processes to share the processor.

6. Operating System Abstraction of Memory

Programs do not directly manage physical RAM.

Each process receives its own virtual address space. The operating system
uses virtual memory, page tables, and memory protection to map virtual
addresses to physical memory.

This prevents one process from directly accessing another process's memory.

7. Operating System Abstraction of Storage

The operating system presents storage devices using files and directories.

A program does not need to know the physical location of data on a disk.
It uses operations such as open, read, write, and close. The file system
organizes the data and the kernel communicates with the storage device.

8. Operating System Abstraction of I/O Devices

Input/output devices include keyboards, displays, printers, network adapters,
and storage devices.

The operating system controls these devices through device drivers. Programs
use system calls instead of directly controlling the hardware.

Linux also provides a common file-descriptor interface for many I/O
operations. This makes different devices easier for programs to use.

Conclusion

The commands uname, lscpu, ps, and top demonstrate how Linux manages
hardware and running programs.

The operating system provides convenient abstractions such as processes,
virtual memory, files, and device interfaces. These abstractions allow
applications to use hardware safely without needing to understand all of the
hardware's internal details.



Kernel name: Linux
Hostname: SSH
Kernel version: 6.18.33.2-microsoft-standard-WSL2
Architecture: x86_64

Total processes: 25
Running processes: 1
Sleeping processes: 24
Zombie processes: 0

Total memory: 6849.7 MiB
Used memory: 557.8 MiB
Free memory: 6228.5 MiB
Swap memory: 2048.0 MiB
Used swap: 0.0 MiB
Load average: 0.00, 0.00, 0.00
The Linux environment is running under WSL2. Therefore, Linux manages the CPU and memory resources made available to it by the Windows virtualization layer.
