cp etc/logrotate.d/logotrack /etc/logrotate.d/logotrack 
cp etc/rsyslog.d/logotrack /etc/rsyslog.d/logotrack
cp etc/logotrack.conf /etc/logotrack.conf

cp etc/init.d/logotrack /etc/init.d/logotrack
chmod +x /etc/init.d/logotrack

cp usr/bin/logotrack /usr/bin/logotrack
chmod +x /usr/bin/logotrack

cd /etc/rc3.d 
update-rc.d logotrack defaults 

service logotrack start
