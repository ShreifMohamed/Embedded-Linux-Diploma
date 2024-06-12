# File System Stack  : Use Case  
---
---
## Create FHS (File Hierarchy Standard) Directories:
------
* **Create the five most common directories as per the File Hierarchy Standard (FHS) on this file system.**
* **In each directory, create a text file that describes the contents of the directory.**
>   Using `$ mkdir <DIR Name>` to create directory  and `$ touch content.txt`  to create file in each directory.
>   So, I create those directory `bin`  `boot` `etc` `proc` `dev`. 
* ![[tree-directory.png]]
* `/bin`   : Essential ready-to-run programs (binaries), includes the most basic commands such as ls and cp.
* `/boot` : Contains kernel boot loader files.
* `/dev`   : Device files.
* `/etc`   : Core system configuration directory, should hold only configuration files and not any binaries.
* `/proc` : Information about currently running processes.
## Also requested to create a file called rootHard.txt then link this file hard link with another file called secHard.txt:
* **1- Create a directory for links .**
```bash
	$ mkdir links
```
* **2- Create a txt file rootHard.txt using.** 
```bash
	$ touch rootHard.txt
```
* **3- Link the rootHard.txt to another fill called secHard.txt using Hard link.**
	```bash
	$ ln rootHard.txt secHard.txt
```
	`Hard link` : is a tool which replaces copies of a file with hardlinks, therefore saving space. 
* **4- Fill rootHard.txt with Hello World.**
```bash
	$ echo "Hello World" > rootHard.txt
```
	![[Hardlink.png]]
* **5- Copy content of secHard.txt file.**
	![[cat.png]]
* **6- Remove secHard.txt File.**
```bash
	$ rm -r secHard.txt
```
* **7- Link rootHard.txt hard link with secHard2.txt.**
	```bash
	$ ln rootHard.txt secHard2.txt
```
* **8- Move rootHard.txt to another directory.**
	```bash
	$ mv rootHard.txt /Desktop/link2
```
* **9- Fill rootHard.txt with Hello World.**
	```bash
	$ echo "Hello World" > rootHard.txt
```
* **10- Copy content of secHard2.txt File.**
	![[Hardlink2.png]]
## Moreover you’re requested to create a file called rootSoft.txt then link this file symbolic link with another file called secSoft.txt:
* **1- Create a directory for links .**
```bash
	$ mkdir links
```
* **2- Create a txt file rootHard.txt using.** 
```bash
	$ touch rootSoft.txt
```
* **3- Link the rootHard.txt to another fill called secHard.txt using Hard link.**
	```bash
	$ ln -s rootSoft.txt secSoft.txt
```
	`Soft link` : Symbolic links are interpreted at run time as if the contents of the link had been substituted into the path being followed to find a file or directory. 
* **4- Fill rootSoft.txt with Hello World.**
```bash
	$ echo "Hello World" > rootSoft.txt
```
	![[Softlink.png]]
* **5- Copy content of secSoft.txt file.**
	![[catsoft.png]]
* **6- Remove secSoft.txt File.**
```bash
	$ rm -r secSoft.txt
```
* **7- Link rootSoft.txt hard link with secSoft2.txt.**
	```bash
	$ ln  -s rootSoft.txt secSoft2.txt
```
* **8- Move rootHard.txt to another directory.**
	```bash
	$ mv rootSoft.txt /Desktop/link2
```
* **9- Fill rootSoft.txt with Hello World.**
	```bash
	$ echo "Hello World" > rootSoft.txt
```
* **10- Copy content of secSoft2.txt File.**
	![[Softlink2.png]]
## Hardlink VS Softlink:
	![[SoftvsHard.jpg]]
	![[SoftvsHard2.jpg]]