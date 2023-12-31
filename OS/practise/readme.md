# Interfaces <br/>
XSM architecture specification	https://exposnitc.github.io/arch_spec.html <br/>
Application Binary Interface (ABI)	https://exposnitc.github.io/abi.html <br/>
Experimental File system specification	https://exposnitc.github.io/os_spec-files/eXpFS.html <br/>
eXpos library	https://exposnitc.github.io/os_spec-files/misc.html#SixcollapseFive <br/>
 <br/>
 1) [SPL](https://exposnitc.github.io/support_tools-files/spl.html) <br/>

#  Expos package : OS development tools <br/>
 1) XFS interface : https://exposnitc.github.io/support_tools-files/xfs-interface.html <br/>

    XFS Interface (eXperimental File System Interface) is an external interface to access the eXpFS filesystem of the eXpOS "from the host (UNIX) system". <br/>
 2) XSM simulator: https://exposnitc.github.io/support_tools-files/xsm-simulator.html <br/>
    XSM instruction set : https://exposnitc.github.io/arch_spec-files/instruction_set.html <br/>
 3) [ExpL](https://exposnitc.github.io/support_tools-files/expl.html) <br/>
    [Expl codes](http://silcnitc.github.io/testprograms.html) <br/>
    [Expl test programs](https://exposnitc.github.io/test_prog.html) <br/>
    [high level libraray interface](https://exposnitc.github.io/os_spec-files/dynamicmemoryroutines.html) <br/>
    [high level system call interface](https://exposnitc.github.io/os_spec-files/systemcallinterface.html)<br/>
 4) compiler for SPL <br/>

# NOTES: <br/>
A bootstrap is the program that initializes the operating system (OS) during startup. Bootloader stands for Bootstrap Loader which is the compact software which is responsible to load the operating system into the memory of the computer. The bootloader will always run whenever the computer system is started or restarted. <br/>
Once the OS modules and application programs are loaded into the XSM machine's disk, the XSM simulator can be used to bootstrap the OS into the machine memory and start execution. <br/>
1) High level system design: https://exposnitc.github.io/os_design.html
2) eXpOS specification: https://exposnitc.github.io/os_spec.html
3) eXpFS format: https://exposnitc.github.io/os_spec-files/eXpFS.html <br/>
   There are 3 types of eXpfs files : <br/>
   a) eXpfs Root (each root entry has name, size, type, username, permission) <br/>
           The operations on the root file are Open, Close, Read and Seek. <br/>
   b) eXpfs Data files <br/>
   eXpOS allows an application program to perform the following operations (by invoking appropriate system calls) on data files: Create, Delete, Open, Close, Read, Write, Seek. <br/>
   c) eXpfs executable files <br/>

   High level system call interface: https://exposnitc.github.io/os_spec-files/systemcallinterface.html <br/>
6) ABI : https://exposnitc.github.io/abi.html <br/>
7) 
8) API : APIs are mechanisms that enable two software components to communicate with each other using a set of definitions and protocols <br/>
* Inode Table contains information such as the file type, file name, file size, userid, permission and the block numbers of the data blocks of the file. <br/>
* XSM provides just three instructions to manipulate the disk – LOAD, LOADI and STORE. <br/>
* eXpOS implementation: https://exposnitc.github.io/os_implementation.html <br/>
* XSM machine's disk contains 512 blocks, each capable of storing 512 words. <br/>
* The eXpFS format specifies that each data/executable file can span across at most four data blocks <br/>
* The Inode table occupies only the first 960 words (60 entries, each of size 16 words) in the disk blocks 3 and 4.
* User table occupies the next 32 words (16 entries, each of size 2 words) and the last 32 words are reserved for future use. <br/>
12) Machine Organisation (Hard disk): https://exposnitc.github.io/arch_spec-files/machine_organisation.html <br/>
13) XSM pagging hardware and address translation: https://exposnitc.github.io/arch_spec-files/paging_hardware.html <br>
14) XSM virtual machine modal : https://exposnitc.github.io/virtual_machine_spec.html <br/>
15) [Memory data staructure : Open file table, File(Inode) status table, Semaphore table, Disk status table, Buffer table, System status table, terminal status table, Memory free list, Access lock table](https://exposnitc.github.io/os_design-files/mem_ds.html) <br/>
    [Pocess table](https://exposnitc.github.io/os_design-files/process_table.html) <br/>
    [Disk data structures: Inode table, Disk free list, Root file, User table](https://exposnitc.github.io/os_design-files/disk_ds.html) <br/>
17) process table : https://exposnitc.github.io/os_design-files/process_table.html <br/>
18) Interrupts and exception handling: https://exposnitc.github.io/arch_spec-files/interrupts_exception_handling.html <br/>
19) Kernal stack management during system calls : https://exposnitc.github.io/os_design-files/stack_smcall.html <br/>
    Debugger : https://exposnitc.github.io/support_tools-files/xsm-simulator.html <br/>
System calls <br/>
1) [Shutdown](https://exposnitc.github.io/os_design-files/shutdown.html) <br/>
2) Semaphores: <br/>
3) FILES: <br/>
    [File system calls](https://exposnitc.github.io/os_spec-files/systemcallinterface.html) <br/>
    [open](https://exposnitc.github.io/os_design-files/open.html) <br/>
    [close](https://exposnitc.github.io/os_design-files/close.html) <br/>
    [read](https://exposnitc.github.io/os_design-files/read.html) <br/>
    [write](https://exposnitc.github.io/os_design-files/write.html) <br/>
    [seek](https://exposnitc.github.io/os_design-files/seek.html) <br/>
4) multi user implementation: <br/>
   [multi-user tutorial](https://exposnitc.github.io/Tutorials/multiuser_implementation.html) <br/>
   [expos shell](https://exposnitc.github.io/os_spec-files/shell_spec.html) <br/>
   [multi-user system calls](https://exposnitc.github.io/os_design-files/multiusersyscalls.html) <br/>

# Doubts <br/>
2) In my laptop test directory is not created, and also in the website there is no related to install it.
3) What is meant by eXpFS is simulated file system?
4) when I write code, I am not worrying about the registers previous values, are they backed up??
