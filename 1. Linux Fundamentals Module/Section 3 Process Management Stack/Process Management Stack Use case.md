# Process Management Stack: Use case
---
 **1- We use this commands:**
``` bash
g++ main.cpp -g -o process
```
* -g : adds debugging information to executable, adding debugging process with tools like GDB. 
``` bash
ulimit -c unlimited
```
* ulimit -c unlimited sets core files size limit to unlimited, allowing creation of core dumps.
 ```bash
 sudo sysctl -w kernel.core_pattern=./core.%e.%p.%t
```
* sets core dump  in the current directory where I run the process  as name of process , PID, and timestamp.
---
**2- Lets Go with the first task to check the CPU load for the file system, after running the      process software.**
  * We can use `$ top` command.
    

    ![process](Image/process.png)
*  We can use also `$ ps -C process -o %cpu` 
	 * `-C` : This select the processes whose executable name is given in.
	 * `-o %cpu`: Specifies the output format to display only the CPU.
	
    ![ps](Image/ps.png)
---
**3- The second Task: is extract core-dump file for this process.**
* To get the core-dump file we should use the `$ kill` command with the signal `SIGABRT` as it requests controlled termination with core-dump file.
```bash
kill -ABRT <PID>
```
* After run this command we show 
    ![after-kill](Imagea/fter-kill.png)
* And we get the core-dump file `core.process.5584.1715422295`

	![core-dump](Image/core-dump.png)
* Lets debug the core-dump file by using 
```bash
gdb ./process core.process.5584.1715422295
```	
  ![gdb-3](Image/gdb-3.png)
