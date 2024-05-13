## First: Trace System call for [ ps & cd & ls ] commands.
```bash
use $ strace -c {{command}}
```
>strace: `trace system calls and signals
   -c: `Count time, calls, and errors for each system call and report a summary on   program exit.`
## Second: extract files of interactions. Identify all the system        calls that have been used.
```bash
From $ strace -c {{command}}
```
>-c: `Count time, calls, and errors for each system call and report a summary on   program exit.`

| 1) read                | 2) openat         | 3) close            | 4)newfstatat     | 5) mmap            | 6)getdents64   |
| ---------------------- | ----------------- | ------------------- | ---------------- | ------------------ | -------------- |
| **7) mprotect**        | **8) execve**     | **9) rt_sigaction** | **10) write**    | **11) prctl**      | **12)pread64** |
| **13) brk**            | **14)munmap**     | **15) lseek**       | **16) ioctl**    | **17) arch_prctl** | **18) access** |
| **19)set_robust_list** | **20)getdents64** | **21)prlimit64**    | **22)getrandom** | **23)geteuid**     | **24) futex**  |
| **25)set_tid_address** | **26) rseq**      | **27) statfs**      |                  |                    |                |
## Third: Measure system calls performance in terms of time.
  ```bash
  Use $ strace -T {{Command}}
```
> -T:  `Show the time spent in system calls.` 