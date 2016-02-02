# Questions:

1. Group 1:

    https://access.redhat.com/documentation/en-US/Red_Hat_Enterprise_Linux/3/html/Reference_Guide/s1-bind-zone.html

    What is the relationship between example.com and dns1.example.com.  ?
    Why do we need to repeat the SOA and NS record for dns1.example.com.?
    Do we need always to have a recordz

    ```bash
    $ORIGIN example.com.
    $TTL 86400
    @     IN     SOA    dns1.example.com.     hostmaster.example.com. (
                        2001062501 ; serial
                        21600      ; refresh after 6 hours
                        3600       ; retry after 1 hour
                        604800     ; expire after 1 week
                        86400 )    ; minimum TTL of 1 day

        IN     NS     dns1.example.com.
        IN     NS     dns2.example.com.

        IN     MX     10     mail.example.com.
        IN     MX     20     mail2.example.com.

                IN     A       10.0.1.5

    server1      IN     A       10.0.1.5
    server2      IN     A       10.0.1.7
    dns1         IN     A       10.0.1.2
    dns2         IN     A       10.0.1.3

    ftp          IN     CNAME   server1
    mail         IN     CNAME   server1
    mail2        IN     CNAME   server2
    www          IN     CNAME   server2
    ```
## Batch

    There is one machine identified by example.com., one machine identified by
    ns1.example.com. and one ns1.example.com. ?

    What happens if we don't have a nameserver for 

    ```bash
    $ORIGIN example.com.     ; designates the start of this zone file in the namespace
    $TTL 1h                  ; default expiration time of all resource records without their own TTL value
    example.com.  IN  SOA   ns.example.com. username.example.com. ( 2007120710 1d 2h 4w 1h )
    example.com.  IN  NS    ns                    ; ns.example.com is a nameserver for example.com
    example.com.  IN  NS    ns.somewhere.example. ; ns.somewhere.example is a backup nameserver for example.com
    example.com.  IN  MX    10 mail.example.com.  ; mail.example.com is the mailserver for example.com
    @             IN  MX    20 mail2.example.com. ; equivalent to above line, "@" represents zone origin
    @             IN  MX    50 mail3              ; equivalent to above line, but using a relative host name
    example.com.  IN  A     192.0.2.1             ; IPv4 address for example.com
                IN  AAAA  2001:db8:10::1        ; IPv6 address for example.com
    ns            IN  A     192.0.2.2             ; IPv4 address for ns.example.com
                IN  AAAA  2001:db8:10::2        ; IPv6 address for ns.example.com
    www           IN  CNAME example.com.          ; www.example.com is an alias for example.com
    wwwtest       IN  CNAME www                   ; wwwtest.example.com is another alias for www.example.com
    mail          IN  A     192.0.2.3             ; IPv4 address for mail.example.com
    mail2         IN  A     192.0.2.4             ; IPv4 address for mail2.example.com
    mail3         IN  A     192.0.2.5             ; IPv4 address for mail3.example.com
    ```
How does th local host work

## Group 3

Exaplain again the reverse lookup?
$ORIGIN 1.0.10.in-addr.arpa.
$TTL 86400
@  IN  SOA  dns1.example.com.  hostmaster.example.com. (
       2001062501  ; serial
       21600       ; refresh after 6 hours
       3600        ; retry after 1 hour
       604800      ; expire after 1 week
       86400 )     ; minimum TTL of 1 day
;
@  IN  NS   dns1.example.com.
;
1  IN  PTR  dns1.example.com.
2  IN  PTR  dns2.example.com.
;
5  IN  PTR  server1.example.com.
6  IN  PTR  server2.example.com.
;
3  IN  PTR  ftp.example.com.
4  IN  PTR  ftp.example.com.
example:


## Dido idea

* Zone 1
    ``` bash
    @ORIGIN yankee.gnus.fccf.net.
    $TTL 1h
    @     IN     SOA    charlie.gnus.fccf.net.     hostmaster.example.com. (
                        2001062501 ; serial
                        21600      ; refresh after 6 hours
                        3600       ; retry after 1 hour
                        604800     ; expire after 1 week
                        86400 )    ; minimum TTL of 1 day

    @     IN     NS     charlie.gnus.fccf.net.
    @     IN     NS     foxtrot.gnus.fccf.net.
    @     IN     NS     oscar.gnus.fccf.net.

    charlie.gnus.fccf.net.      IN     A      185.117.82.68
    foxtrot.gnus.fccf.net.      IN     A      185.117.82.71
    oscar.gnus.fccf.net.        IN     A      185.117.82.80
    ```

* Zone 2

    ``` bash
    @ORIGIN z2.yankee.gnus.fccf.net.
    $TTL 1h
    @     IN     SOA    foxtrot.gnus.fccf.net.     hostmaster.example.com. (
                        2001062501 ; serial
                        21600      ; refresh after 6 hours
                        3600       ; retry after 1 hour
                        604800     ; expire after 1 week
                        86400 )    ; minimum TTL of 1 day

    @     IN     NS     charlie.gnus.fccf.net.
    @     IN     NS     foxtrot.gnus.fccf.net.
    @     IN     NS     oscar.gnus.fccf.net.

    charlie.gnus.fccf.net.      IN     A      185.117.82.68
    foxtrot.gnus.fccf.net.      IN     A      185.117.82.71
    oscar.gnus.fccf.net.        IN     A      185.117.82.80
    ```

* Zone 3

    ``` bash
    @ORIGIN z3.yankee.gnus.fccf.net.
    $TTL 1h
    @     IN     SOA    oscar.gnus.fccf.net.     hostmaster.example.com. (
                        2001062501 ; serial
                        21600      ; refresh after 6 hours
                        3600       ; retry after 1 hour
                        604800     ; expire after 1 week
                        86400 )    ; minimum TTL of 1 day

    @     IN     NS     z3.charlie.gnus.fccf.net.
    @     IN     NS     z3.foxtrot.gnus.fccf.net.
    @     IN     NS     z3.oscar.gnus.fccf.net.

    z3.charlie.gnus.fccf.net.      IN     A      185.117.82.68
    z3.foxtrot.gnus.fccf.net.      IN     A      185.117.82.71
    z3.scar.gnus.fccf.net.         IN     A      185.117.82.80
    ```


yankee.gnus.fccf.net.	3600	IN	NS	papa.gnus.fccf.net.


dido.yankee.gnus.fccf.net.

. -> net. -> .fccf.net. -> charlie.gnus.fccf.net. -> www.yankee.gnus.fccf.net. -> 127.0.0.1




