* process ID - unique integer that indentifies the process
* priority - how import is the process. range
* nice value - will make way for other process to take CPU time
* security context
* enviroment - the forked process inherit all the data inside
* file handles - identificator for a file. File descriptors

Process are hei. Thew first process is called init. It has pid = 1. It is started from the kernel.It defines the rest of the OS and the wayu it goes. We can fork a process. Then we have two processes. Other possibility are 'exec' command.

- RUNNUNG - currently using CPU
- INTERRUPTABLE -
- UNINTERRUPTABLE 0
- ZOMBIE - not cleaned
- STOPPED - stop from ctrl + z

ps - uses informantion from process
proc is mounted. It is a virtual file system. It is listed with df command
proc/cpuinfo - info about the cpu
man ps

parent pid

Process State codes:
- D
- R - running or runnable
- S - normal state, interruptable
- T - stopped
- У - paging
- X - dead
- Z - zombie, the parent has not cleaned after this process.

```
ps -ef | grep "velin"
ps -ef | awk '$1 ~= /velin/'
# pgrep = ps + grep
pstree
```

* `top` - info about the machine, number of logged users, up time, load average
* total - cache - bi
* priority nice
* `atop`
* `htop`
* `jobs` - show stopped jobs
* signal - signal handler function. Different UNIX mean different things. One signal handler can ignore or handle a specific signal.
* man signal(7)
* SIGHUP(1)
* SIGQUIT(3)
* SIGKILL(9) - the process is killed by the kernel
* SIGSEGV(11)
* SIGTERM(15) - like a destructor.
* SOTSTOP(19)


SENDING  term signal to all process
SENDING kill signla to all process
* TODO: `kill`, `pkil`,
* ctrl c - SIGINT
* ctr z - SIGSTOP
* TODO: `nice`
* `fg` - wake process and send in foreground
* `bg` - wkae proces and send in background
* If there are several sleeping process, we can choose which to open.
* program & - plays in background.
+
