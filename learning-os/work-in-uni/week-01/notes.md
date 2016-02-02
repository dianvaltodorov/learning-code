unix :: multitasking multiuser OS

unix design principles ::
    * everything is a file, devices are files too, processes too
    * samll single-purpose programs with the ability to pipe them together
    * configuration in ascii

unix philosophy Mike Gancarz 1994

standard streams :: stdin, stdout, stderr

open source, Richard Stallman, GNU :: gcc, dgb, emacs
GNU General public license ::
Free software definition :: to run the program, to modify it, to distribute copies, ...
     Free as in Freedom, orielly

Linux kernel :: reimplementation of the UNIX Api's
GNU OS + linux kernel = GNU/Linux (e.g. GNU / kFreeBDS)

distribution :: collection of components, gnu os tools, linux kernels, and more programs, GUI, packaging, complementary features
    centralized software, easy for use

Standars ::
    POSIX :: portable OS interface for UNIX
    Single UNIX spec.
    FHS :: filesys hierch. stand.
    LSB :: linux standards base

terminal session by login (login as root) ::
    serial terminals
    virtual terminals   (emulates a serial terminal)
    network logins, ssh
    privileged user = root with UID0

man :: `su, sudo, tty, pts, id, whoami, whatis, apropos`
    info is the GNU replacement for man

every process has a group ID and a user ID

man ::
    $MANPATH, -M explicit directory, man config file
    man -f :: search
    whatis command, man -f :: display man page desc.
    man -k, apropos :: search mans

=== FILES ===

root / :: bin, dev, sbin, usr, media, mnt, opt, srv, tmp, var, etc, lib, proc, ...
    bin :: binaries
    boot :: static file of the boot loader
    sbin :: system binaries
        sbin :: most essential
             man :: `getty, halt, fdisk, fsck, mkfs (format partition), init, ifconfig, mkswap, swapon, swapoff`
        usr/sbin
        usr/local/sbin :: things which didn't come with the distro
    mnt :: mounting a FS
    opt :: third-party apps, not from the package manager
    srv :: (new) data for services provided by systems
    usr :: secondary FSH
        bin
        include
        local :: local hierarch, third level FSH
            man
        sbin
        share :: architecture-independent       
    /root :: dir of root
    etc ::
        exports :: NFS
        fstab :: FS table, static info
        group :: ...
        hosts :: hostname mapped to ip addresses
        passwd :: map users ids to passwords
    var :: variable data
        cache, lib, local, lock, log, opt, run, spool, tmp, mail
  virtual hierarchies ::
    proc :: current processes info
    sys :: exposes kernel kobject data structures
    dev/pts

/bin
man :: `cat, chgrp, chmod, chown, cp, date, dd (convert and copy a file), df, dmesg (kernel control message), echo`
            `false, true, hostname, kill, ln, login, mknod, mount`
            `sed, sh, stty, sync, uname`


windows has multiple roots corresponding to each partition

_cd_ ::
    absoulte addressing and relative addressing

ls ::
    . and .. are also files
    permissions, owner, group, size in bytes, date
    d flag treats the argument as a directory
    S sorted by size

df ::
    m - in MB
    i - iNodes
    T - type of the FS :: ext4, vfat are more "human"
    si - the MB is 10^3, not 2^10

du :: disk usage for dir
    s - sum
    x - only this FS, not sub FSs

files have metadata ::
    owner :: chown newUser file
    group :: chgrp
         newgroup changes the group (use id to see)

flags
    first :: -,d dir, b block, l symbolic link, p FIFO named pipe, s socket
    3x3 flags :: rwxrwxrwx when all are on, - when off
        first three :: owner permissions
        second three :: for every one who is not the owner, but a member of the group which the owner is in
            x in directories means that we can access it and its children
        third three :: everyone else
rwx = 421
rwxrwxrwx = 777
rwxr-xr-x = 0755
175 = --xrwxr-x
612 = rw---x-w-

by default
new directories are 777
new files are 666

umask defines which flags will be prohibitted from setting by the default creation
umask 022 on 666 returns 644
umask 075
666 = 42- 42- 42-
075 = --- 421 4-1
-----------------
      42- --- -2-
602
