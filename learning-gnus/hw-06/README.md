# usest

This is a daemon for tracking sessions of a particular user.
The username is supplied from a config file containging a username.

## Language and Deps

The program is written in C and uses the standard library

## Setup

### Binary

``` bash
gcc usest.c
mv a.out /usr/sbin/usest
```

Running the binary creates `/tmp/usestdaemon.pid` which the process id of the
new daemon. The working directory of the new process is set by default to be
`/tmp/`

### Logging

Add this line to `/etc/rsyslog.conf` to filter the logs.

```bash
:programname, isequal, "user_session_tracker" /var/log/user_session_tracker.log
& ~
```

Restart the logging service:

```bash
service restart rsyslogd
```


### Init instances

```bash
echo <username> > /etc/usest.conf
mv usest /etc/init.d
update-rc.d usest defaults
update-rc.d usest enable
service usest start
```


