## Your Main Tasks:

### Time Measurement:

>>**Measure the execution time for each command to assess their performance.

``` bash
   I will use $time {command}
```
### System Interaction Identification:

>>**Identify which system stack (e.g., file system, network) each command
	  interacts with during execution.
``` bash
  I will use $ strace -c -e trace={stack} {command}
```
### Syscall Time Breakdown:

>>**Break down the total execution time of each command into time per
	  system call to understand their resource consumption.

``` bash
  I will use $ strace -c {command}
```
### Performance Evaluation:

>>**Analyze the results to determine which command performs better than the
    other based on execution time, system interaction, and syscall breakdown.

# ls vs. find
 ![time-ls](Images/time-ls.png)
 ![trace-ls](Images/trace-ls.png)
 ![trace-find](Images/trace-find.png)
 
# cp vs. rsync
 ![time-cp](Images/time-cp.png)
 ![trace-cp](Images/trace-cp.png)
 ![trace-rsync](Images/trace-rsync.png)
 
# diff vs. cmp
 ![time-cmp](Images/time-cmp.png)
 ![trace-diff](Images/trace-diff.png)
 ![trace-cmp](Images/trace-cmp.png)
 
# sort vs. uniq
 ![time-sort](Images/time-sort.png)
 ![time-uniq](Images/time-uniq.png)
 ![trace-sort](Images/trace-sort.png)
 ![trace-uniq](Images/trace-uniq.png)
 
# grep vs. sed

 ![time-grep](Images/time-grep.png)
 ![trace-grep](Images/trace-grep.png)
 ![trace-sed](Images/trace-sed.png)


| Command       | Time       | No.of Stacks | Time break down | Performance |
| ------------- | ---------- | ------------ | --------------- | ----------- |
| ls vs. find   | ls         | same number  | ls              | ls          |
| cp vs. rsync  | cp         | rsync        | cp              | cp          |
| diff vs. cmp  | same time  | same number  | cmp             | cmp         |
| sort vs. uniq | sort       | same number  | sort            | sort        |
| grep vs. sed  | sed        | same number  | grep            | grep        |

| Filesystem Stack | Network Stack | Memory management Stack | Process Stack |
| ---------------- | ------------- | ----------------------- | ------------- |
| ls, find         | rsync         | ls, find                | ls, find      |
| cp, rsync        | ------        | cp, rsync               | cp, rsync     |
| diff, cmp        | ------        | diff, cmp               | diff, cmp     |
| sort, uniq       | ------        | sort, uniq              | sort, uniq    |
| grep, sed        | ------        | grep, sed               | grep, sed     |
