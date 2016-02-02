# Logotrack

Logotrack is a daemon that tracks user login session for a specified user.

## Getting Started

### Dependecies

* rsyslog (>= 8.0.0)
* logrotate(>= 3.8.0)

### Installing

1. Download the source
2. `cd source`
2. `./install`

## Information

Logotrack is daemon that tracks login sessions for a user. It runs periodically
the `who` command and extracts the number of login sessions for the tracked
user. Logotrack then logs that number to the system log with facility local7 and
priority info. The logs are logged in the file /var/log/logotrack and are
managed by logrotate and the /etc/logrotate.d/logotrack file. The time interval
and the tracked user are specified in the /etc/logotrack.conf file. They default
to the root user and a time interval of 1 second.

## Authors

* **Dian Todorov** - *Initial work* 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
