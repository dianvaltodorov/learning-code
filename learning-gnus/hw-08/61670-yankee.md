# Homework 8


## Intro

We decided that Miroslav Lalev will be the  master for `yankee.gnus.fccf.net` I
will be the master for `dido.yankee.gnus.fccf.net`. and Radoslav Georgiev will
be the master for `rado.yankee.gnus.fccf.net`.

## TLDR

Restart the bind9 daemon with the following configurations:

named.conf.local

        zone "yankee.gnus.fccf.net" IN {
                type slave;
                file "db.yankee.gnus.fccf.net";
                masters { 185.117.82.71; };
        };

        zone "dido.yankee.gnus.fccf.net" IN {
                type master;
                file "/etc/bind/zones/db.dido.yankee.gnus.fccf.net";
                allow-transfer { 185.117.82.71; 185.117.82.80; 185.117.82.81; };
        };

        zone "rado.yankee.gnus.fccf.net" IN{
                type slave;
                file "db.rado.yankee.gnus.fccf.net";
                masters { 185.117.82.80; };
        };


zones/db.dido.yankee.fccf.net

        $TTL    604800
        @       SOA     charlie.gnus.fccf.net.    dianvaltodorov.gmail.com (
                                3         ; Serial
                                604800    ; Refresh
                                86400     ; Retry
                                2419200   ; Expire
                                604800 )  ; Negative Cache TTL

                IN      NS      charlie.gnus.fccf.net.
                IN      NS      foxtrot.gnus.fccf.net.
                IN      NS      oscar.gnus.fccf.net.
                IN      NS      papa.gnus.fccf.net.

        www.dido.yankee.gnus.fccf.net. IN A 127.0.0.1


## Slave to yankee.gnus.fccf.net

Add yankee /etc/bind/named.conf.local:

        zone "yankee.gnus.fccf.net" {
                type slave;
                file "db.yankee.gnus.fccf.net";
                masters { 185.117.82.71; };
        };

## Delegate subdomains dido.yankee.gnus.fccf.net. and rado.yankee.gnus.fccf.net inside the zone .

Add glue records inside the yankee.gnus.fccf.net. This was done by Miro in foxtrot but we did it together.

        rado.yankee.gnus.fccf.net.  IN    NS    charlie.gnus.fccf.net.
        rado.yankee.gnus.fccf.net.  IN    NS    oscar.gnus.fccf.net.
        rado.yankee.gnus.fccf.net.  IN    NS    foxtrot.gnus.fccf.net.

        dido.yankee.gnus.fccf.net.  IN    NS    charlie.gnus.fccf.net.
        dido.yankee.gnus.fccf.net.  IN    NS    oscar.gnus.fccf.net.
        dido.yankee.gnus.fccf.net.  IN    NS    foxtrot.gnus.fccf.net.

        oscar.gnus.fccf.net.        IN     A    185.117.82.80
        foxtrot.gnus.fccf.net.      IN     A    185.117.82.71
        charlie.gnus.fccf.net.      IN     A    185.117.82.68
        november.gnus.fccf.net.     IN     A    185.117.82.79
        juliett.gnus.fccf.net.      IN     A    185.117.82.75

        praimgo.yankee.gnus.fccf.net.  IN    NS    november.gnus.fccf.net.
        praimgo.yankee.gnus.fccf.net.  IN    NS    juliett.gnus.fccf.net.
        praimgo.yankee.gnus.fccf.net.  IN    NS    charlie.gnus.fccf.net.

## Slave to rado.yankee.gnus.fccf.net

Add rado to /etc/bind/named.conf.local:

        zone "rado.yankee.gnus.fccf.net" {
                type slave;
                file "db.rado.yankee.gnus.fccf.net";
                masters { 185.117.82.71; };
        };

## Master dido.yankee.gnus.fccf.net

Add to /etc/bind/named.conf.local

        zone "dido.yankee.gnus.fccf.net" {
                type master;
                file "zones/db.dido.yankee.gnus.fccf.net";
                allow-transfer { 185.117.82.71; 185.117.82.80;};
        };

Had problems loading the zone files. The log said file not found and thus had to
hardcode the absolute path.

        zone "dido.yankee.gnus.fccf.net" {
                type master;
                file "etc/bind/zones/db.dido.yankee.gnus.fccf.net";
                allow-transfer { 185.117.82.71; 185.117.82.80;};
        };

 The content of zones/db.dido.yankee.gnus.fccf.net.

        $TTL    604800
        @       SOA     charlie.gnus.fccf.net.    dianvaltodorov.gmail.com. (
                                3            ; Serial
                                604800       ; Refresh
                                86400        ; Retry
                                2419200      ; Expire
                                604800 )     ; Negative Cache TTL

                IN      NS      charlie.gnus.fccf.net.
                IN      NS      foxtrot.gnus.fccf.net.
                IN      NS      oscar.gnus.fccf.net.
                IN      NS      papa.gnus.fccf.net.

        www.dido.yankee.gnus.fccf.net. IN A 127.0.0.1

## Make papa authoritive

First we thaught that it is necessary to ask for and edit inside nimbus.


        yankee.gnus.fccf.net. IN	NS	papa.gnus.fccf.net.


However, we remebered that it is not necessary to change anything in nimbus. We
only had to make papa slave by editing it's etc/bind/named.conf.local


        zone "yankee.gnus.fccf.net." IN {
                type slave;
                file "db.yankee.gnus.fccf.net.";
                masters { 185.117.82.71; };
        };


        zone "dido.yankee.gnus.fccf.net." IN {
                type slave;
                file "db.dido.yankee.gnus.fccf.net.";
                masters { 185.117.82.68; };
        };

        zone "rado.yankee.gnus.fccf.net." IN {
                type slave;
                file "db.rado.yankee.gnus.fccf.net.";
                masters { 185.117.82.80; };
        };

## Tests

### Test yankee.gnus.fccf.net.

* `dig ns @foxtrot.gnus.fccf.net. +short yankee.gnus.fccf.net.`
* `dig ns @charlie.gnus.fccf.net. +short yankee.gnus.fccf.net.`
* `dig ns @oscar.gnus.fccf.net. +short yankee.gnus.fccf.net.`

All of them produce

        ;; ANSWER SECTION:
        yankee.gnus.fccf.net.   86399   IN      NS      oscar.gnus.fccf.net.
        yankee.gnus.fccf.net.   86399   IN      NS      papa.gnus.fccf.net.
        yankee.gnus.fccf.net.   86399   IN      NS      charlie.gnus.fccf.net.
        yankee.gnus.fccf.net.   86399   IN      NS      foxtrot.gnus.fccf.net.

### Test rado.yankee.gnus.fccf.net.

* `dig ns rado.yankee.gnus.fccf.net. @papa.gnus.fccf.net.`
* `dig ns rado.yankee.gnus.fccf.net. @charlie.gnus.fccf.net.`
* `dig ns rado.yankee.gnus.fccf.net. @foxtrot.gnus.fccf.net.`
* `dig ns rado.yankee.gnus.fccf.net. @charlie.gnus.fccf.net.`

All of them produce

        ;; ANSWER SECTION:
        rado.yankee.gnus.fccf.net. 604800 IN    NS      foxtrot.gnus.fccf.net.
        rado.yankee.gnus.fccf.net. 604800 IN    NS      charlie.gnus.fccf.net.
        rado.yankee.gnus.fccf.net. 604800 IN    NS      oscar.gnus.fccf.net.
        rado.yankee.gnus.fccf.net. 604800 IN    NS      papa.gnus.fccf.net.

### Test dido.yankee.gnus.fccf.net.

* `dig ns dido.yankee.gnus.fccf.net. @papa.gnus.fccf.net.`
* `dig ns dido.yankee.gnus.fccf.net. @charlie.gnus.fccf.net.`
* `dig ns dido.yankee.gnus.fccf.net. @foxtrot.gnus.fccf.net.`
* `dig ns dido.yankee.gnus.fccf.net. @charlie.gnus.fccf.net.`

All of them produce

        ;; ANSWER SECTION:
        dido.yankee.gnus.fccf.net. 604800 IN    NS      foxtrot.gnus.fccf.net.
        dido.yankee.gnus.fccf.net. 604800 IN    NS      charlie.gnus.fccf.net.
        dido.yankee.gnus.fccf.net. 604800 IN    NS      oscar.gnus.fccf.net.
        dido.yankee.gnus.fccf.net. 604800 IN    NS      papa.gnus.fccf.net.

``` bash
$ dig a www.dido.yankee.gnus.fccf.net @charlie.gnus.fccf.net.
www.dido.yankee.gnus.fccf.net. 85205 IN A       127.0.0.1
```


