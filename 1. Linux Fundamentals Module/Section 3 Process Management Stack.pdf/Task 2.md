Task
Assignment one for kernel module
Check how many cores do you have using top command.
I have two cores.
 

Create number of cores + 2 processes dd if=/dev/zero of=/dev/null run in background.
 
 
Change priority for them:
-20, -10, 0, .. , 19
Monitor them using top command, did you notice any changes ?
Yes,there are changes.
 

Kill them all using killall command.
 
All commands used:
top.
dd if=/dev/zero of=/dev/null &.
renice -n {{number of priority}} -p {PID}.
Killall {name of process}.