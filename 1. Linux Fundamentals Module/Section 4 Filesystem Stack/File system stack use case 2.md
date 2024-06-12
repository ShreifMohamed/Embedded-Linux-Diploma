----
## Task A:
**You are a C++ developer in a company, and the integrator provide for you a file-system with the following characteristic:**
1. /etc directory is a read-only directory.
2. /data directory is a read-write directory.
**And for your C++ program in-order to work, you should push some configuration file in the /etc directory, but you don’t have the write permission for that, and you want to test your C++ program in-order to deliver it in time, You asked the integrator to give you a root-file system with /etc directory in read-write mode, but he does not have time for that. Fortunately you are a Linux geek and you heard that there is something called file-system overlay that can save your time.**
### You task:
 Read about overlay and write the steps you need in-order to push the confirmation file in /etc, so that your application can work normally.
### Steps:
1. **Create Necessary Directories:**
   I need a writable directory that will serve as the upper layer and a work directory for overlay file system operations.
```bash
   $ sudo mkdir -p /overlay/upperdir
   $ sudo mkdir -p /overlay/workdir
```
2. **Mount the Overlay File System:**
   Mount an overlay file system that combines the read-only `/etc` directory with your writable upper directory.
```bash
   $ sudo mount -t overlay overlay -o lowerdir=/etc,upperdir=/overlay/upperdir,workdir=/overlay/workdir /mnt/etc
```
   Here,`/mnt/etc` will be the mount point where the combined view of the overlay is available.
   3. **Push My Configuration File:**
    Copy My configuration file to the new overlay-mounted `/etc` directory.
```bash
    $ sudo cp my_configration_file /mnt/etc/my_configuration_file
```

4. **Update My Application to Use the Overlay:**
   Update my C++ program or environment to use the new overlay-mounted `/etc` directory instead of the original `/etc`.
   If my application has the path hard-coded, I may need to create a symbolic link or modify the application's configuration to point to the overlay.
   For example, you can create a symbolic link:
```bash
   $ sudo mv /etc /etc.bak
   $ sudo ls -s /mnt/etc /etc
```
This way, when my application tries to access `/etc`, it will actually be    accessing `/mnt/etc`,     which is your overlay file system.

5. **Testing:**
   Run my C++ application and ensure it reads the configuration file correctly from the overlay-mounted `/etc`.
   
6. **Cleanup (Optional):**
   Once I am done with testing and if I no longer need the overlay, I can unmount it and remove the directories.
```bash
   $ sudo umount /mnt/etc
   $ sudo rm -rf /overlay/upperdir /overlay/workdir /mnt/etc
   $ sudo mv /etc.bak /etc
```
## Task B:
**What is the linux behavior in the following situations ?**
### Context:
**You need to mount a file system onto a directory that already contains some files.**
### Challenge:
**What is the linux behavior in this case ?**

**When you mount a file system onto a directory that already contains files in Linux, the behavior is as follows:**
1. **Existing Files and Directories Before Mounting:**
   Any files or directories that exist in the mount point directory before the mount operation are hidden and inaccessible while the file system is mounted. These files are not deleted; they are just obscured by the contents of the mounted file system.
2. **Mounted File System:**
   The directory will now display the contents of the newly mounted file system. Any operations (like reading, writing, listing) will be performed on the files and directories of the mounted file system.

3. **After Unmounting:**
   Once the file system is unmounted, the original files and directories in the mount point directory will become visible and accessible again.
### Context:
You are tasked with mounting a new file system onto a directory that already contains
files and possibly other data.
### Challenge:
What is the linux behavior in this case ?

**When you mount a new file system onto a directory that already contains files and other data, the behavior in Linux is as follows:
Linux Behavior When Mounting Over a Non-Empty Directory**
1. **Existing Files and Directories Are Hidden:**
    Any files and directories that are present in the mount point directory before the mount operation will be hidden. They are not accessible while the new file system is mounted.
2. **Mounted File System Content:**
    After the mount operation, the contents of the mount point directory will reflect the root of the newly mounted file system. You will see the files and directories from the mounted file system, not the original ones.
3. **Files and Directories Are Not Deleted:**
    The original files and directories in the mount point directory are not deleted or altered. They are simply hidden and become inaccessible while the mount is in place.
4. **Accessing Hidden Files:**
    To access the original contents of the mount point directory, you need to unmount the newly mounted file system.
#### Practical Considerations:

1. **Data Safety: Ensure that no critical operations depend on the files in the mount point directory while the new file system is mounted, as they will be temporarily inaccessible.**
2. **Choosing Mount Points: Select appropriate and possibly empty directories as mount points to avoid unintentional hiding of important data.**
3. **System Administration: Be aware of this behavior to troubleshoot issues related to files that appear to be missing but are simply obscured by a mounted file system.**
#### Summary

**When you mount a new file system onto a directory that already contains files, the original contents of that directory are hidden but not deleted. The mount point will display the contents of the newly mounted file system. To access the original files, you need to unmount the new file system. This behavior allows for flexible file system management but requires careful planning to avoid data access issues.**