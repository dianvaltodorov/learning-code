* Decompose the task:

 - My machine is charlie.fmi.fail
 - my team consists of bravo.fmi.fail and delta.fmi.fail
 - I need to be authoritive master for paganini.nestum.net
 - I need to be auhtoritive slave for both field.nestum.net and weber.nestum.net
 
* for dig ns trace 
```
root@charlie:~# dig +trace ns paganini.nestum.net
; <<>> DiG 9.10.3-P4-Debian <<>> +trace ns paganini.nestum.net
;; global options: +cmd
.			213130	IN	NS	a.root-servers.net.
.			213130	IN	NS	b.root-servers.net.
.			213130	IN	NS	c.root-servers.net.
.			213130	IN	NS	d.root-servers.net.
.			213130	IN	NS	e.root-servers.net.
.			213130	IN	NS	f.root-servers.net.
.			213130	IN	NS	g.root-servers.net.
.			213130	IN	NS	h.root-servers.net.
.			213130	IN	NS	i.root-servers.net.
.			213130	IN	NS	j.root-servers.net.
.			213130	IN	NS	k.root-servers.net.
.			213130	IN	NS	l.root-servers.net.
.			213130	IN	NS	m.root-servers.net.
.			213130	IN	RRSIG	NS 8 0 518400 20171231050000 20171218040000 46809 . HYKSjYljzyaG2pdMw9IjhDYvfx1PWSOoAkchvwC+ND8PKtxKmAzv89VW QReaeWCMXsN+ZQkWubgloGPysDJQtb6ytkvVoiyS1qO2vhFIl6xFDors TQPKdyXKU8Eeqky2nA9+TjdHlMmNdDF1VDgNJzeQN6d+q/4LF8Hr7W1I UPwtD/d2X6fKbSurPCBh69+2+CaaV4128rlP/7ycc/D8wse8ndD0Z1gX AYWn6gmME0BWnZ0pNlrSSIP4t65c4Vk28FV7zKpG8Ee8ClrgvyOok89c HXcJoVtQ8LY/sF32VUI+cDzsEQUcmPNYI1aqpZTKNY4fimZc0KGYjNz6 sTwIQg==
;; Received 525 bytes from 8.8.8.8#53(8.8.8.8) in 0 ms

net.			172800	IN	NS	a.gtld-servers.net.
net.			172800	IN	NS	b.gtld-servers.net.
net.			172800	IN	NS	c.gtld-servers.net.
net.			172800	IN	NS	d.gtld-servers.net.
net.			172800	IN	NS	e.gtld-servers.net.
net.			172800	IN	NS	f.gtld-servers.net.
net.			172800	IN	NS	g.gtld-servers.net.
net.			172800	IN	NS	h.gtld-servers.net.
net.			172800	IN	NS	i.gtld-servers.net.
net.			172800	IN	NS	j.gtld-servers.net.
net.			172800	IN	NS	k.gtld-servers.net.
net.			172800	IN	NS	l.gtld-servers.net.
net.			172800	IN	NS	m.gtld-servers.net.
net.			86400	IN	DS	35886 8 2 7862B27F5F516EBE19680444D4CE5E762981931842C465F00236401D 8BD973EE
net.			86400	IN	RRSIG	DS 8 1 86400 20180101210000 20171219200000 46809 . nBZoNuWXJIjBCL+a+9hk9qZHzhrUB/8+cxITqQilw63A+GaTjcvHXiNK 3fZAczBXmGdETxJkInbnde+314g74g/2BE8PNjFXSvXWqvlyQcL23ZIO QaC9gcd+roCLBW+4/e9L5g5onIpMoxSWXjiWOhA6JH8fqw1g4PPu+/hz +ECANWvugl2tPeWGvEW3ay/0tHpnUAww+UtRwq5MCpx1tX2IhgLfWH0j ad28k2C/yOINY5nujximKVjCcVw/c0L9N0MIl2kOhpGXXb1l2VM8hVPl 7pXqJH2rTvqnXbUNjnrbzsneGjMZPMBXodT+o/5wAERyD85TZtND/fCa EuvOIw==
;; Received 1176 bytes from 192.203.230.10#53(e.root-servers.net) in 0 ms

nestum.net.		172800	IN	NS	nimbus.fccf.net.
nestum.net.		172800	IN	NS	marla.fccf.net.
A1RT98BS5QGC9NFI51S9HCI47ULJG6JH.net. 86400 IN NSEC3 1 1 0 - A1RUUFFJKCT2Q54P78F8EJGJ8JBK7I8B NS SOA RRSIG DNSKEY NSEC3PARAM
A1RT98BS5QGC9NFI51S9HCI47ULJG6JH.net. 86400 IN RRSIG NSEC3 8 2 86400 20171227062609 20171220051609 18737 net. nEhicHLkvsZVirHCoNYYNJKGcJOj9XtL57/ltvpBXqP6a4gnYeui3QOI 2ru7WBgjx7B2Q/rlJN5CYa/5JIrLn1G13uOIU97rsoE93gpyicbxhEb0 sz6NxpTrLlpK7I18Avdvc4u3wsqyMgN/G+fph/fNmk6ZMiIDvSFo5oux lRI=
Q7GVCMC21GE84K89VD2BH8VR132RR7EG.net. 86400 IN NSEC3 1 1 0 - Q7HGLU80K3KRP87ARSTE66MD8VURU5H6 NS DS RRSIG
Q7GVCMC21GE84K89VD2BH8VR132RR7EG.net. 86400 IN RRSIG NSEC3 8 2 86400 20171224062407 20171217051407 18737 net. EkLlTatPR89/M0Kku1yrOqxxcx3i073skRWoukpQvJVaOhBCoUvztiEu YuUsEKp5/JgIgMslJShYRMfoFi5P2XpvzzJID2b7Qp8XoS3OMXu2bHd1 oK9+oFk0tYSVGxpduQcjSZYkAmw/euzxVQnN2JWB5tsAAhV/EiBR16PA rD0=
;; Received 611 bytes from 192.52.178.30#53(k.gtld-servers.net) in 201 ms

paganini.nestum.net.	3600	IN	NS	bravo.fmi.fail.
paganini.nestum.net.	3600	IN	NS	charlie.fmi.fail.
paganini.nestum.net.	3600	IN	NS	delta.fmi.fail.
;; Received 250 bytes from 79.98.105.20#53(marla.fccf.net) in 0 ms

```

* Create a zone file for paganini.nestum.net
The  zone file for paganini.nestum.net.
```
$ORIGIN paganini.nestum.net.
$TTL 3600 
@ IN SOA charlie.fail.fmi dianvaltodorov.gmail.com (
                                             20171219   ; serial number
                                             3600       ; refresh after 1 hours                     
                                             3600       ; retry after 1 hour                     
                                             3600       ; expire after 1 hour                     
                                             3600       ; minimum TTL of 1 hour  
)    

@                               IN  NS     bravo.fmi.fail.
@                               IN  NS     charlie.fmi.fail.
@                               IN  NS     delta.fmi.fail.
```
* The content for named.conf

```
acl team {
	185.117.82.99;  # bravo    
	185.117.82.101;  # delta 
};

zone "paganini.nestum.net" {
   type master;
   file "paganini.nestum.net.zone";
   allow-transfer { team; };
};

zone "field.nestum.net" {   
	type slave;   
	file "field.nestum.net.zone";   
	masters {  185.117.82.99; };  #bravo
};

zone "weber.nestum.net" {
	type slave;   
	file "weber.nestum.net.zone";   
	masters { 185.117.82.101; };  # delta
};
```
* restart
* Tried running `dig +trace paganini.nestum.net` but got(the X.Y.Z.T is an ip of the client)
```
client X.Y.Z.T (.): query (cache) '.IN/NS' denied
```
N

* add allow query to the named.conf.opions to give permissions to fix the above error

```
allow-query{ any; };
```
* do a successful `dig paganini.nestum.net`
```
root@banshee:~# dig +trace  paganini.nestum.net.

; <<>> DiG 9.9.5-9+deb8u14-Debian <<>> +trace paganini.nestum.net.
;; global options: +cmd
.                       9747    IN      NS      i.root-servers.net.
.                       9747    IN      NS      f.root-servers.net.
.                       9747    IN      NS      k.root-servers.net.
.                       9747    IN      NS      l.root-servers.net.
.                       9747    IN      NS      e.root-servers.net.
.                       9747    IN      NS      m.root-servers.net.
.                       9747    IN      NS      j.root-servers.net.
.                       9747    IN      NS      a.root-servers.net.
.                       9747    IN      NS      b.root-servers.net.
.                       9747    IN      NS      c.root-servers.net.
.                       9747    IN      NS      d.root-servers.net.
.                       9747    IN      NS      g.root-servers.net.
.                       9747    IN      NS      h.root-servers.net.
.                       10791   IN      RRSIG   NS 8 0 518400 20180105170000 20171223160000 46809 . i9c0yNnb4xZVCkAWKq5r9VsUiYqUgx/YVL84z0q2Iq/Aj6o9UyvLtGMK qRtHK2lSNgyvFiE2DdDA0CbIPSdAGPUC9Q+T6kvZcLwCORVODfd6zyGb r1fTD8WvPaP98TKNkqoxyCPda/IWTyYDUQ6RYKsHLJ2kb8h05YWuA89p +eF8V++BKc5ZA2AMnN2OxBLPbGzFWV9behlkK+Sd03Zs1ypepZqNwKoy 8nPfyN2qqZ6B75IlKufbsWystczm09BPsp/zdeFSvRSmRK/vpKq7YxNT NSNAgZp2K2fiYKRiFst5xPNLISGAmp6K4KkY2k5TiENHyRDO5jvVFHUf 2E1VvA==
;; Received 1097 bytes from 192.168.0.1#53(192.168.0.1) in 101 ms

net.                    172800  IN      NS      a.gtld-servers.net.
net.                    172800  IN      NS      b.gtld-servers.net.
net.                    172800  IN      NS      c.gtld-servers.net.
net.                    172800  IN      NS      d.gtld-servers.net.
net.                    172800  IN      NS      e.gtld-servers.net.
net.                    172800  IN      NS      f.gtld-servers.net.
net.                    172800  IN      NS      g.gtld-servers.net.
net.                    172800  IN      NS      h.gtld-servers.net.
net.                    172800  IN      NS      i.gtld-servers.net.
net.                    172800  IN      NS      j.gtld-servers.net.
net.                    172800  IN      NS      k.gtld-servers.net.
net.                    172800  IN      NS      l.gtld-servers.net.
net.                    172800  IN      NS      m.gtld-servers.net.
net.                    86400   IN      DS      35886 8 2 7862B27F5F516EBE19680444D4CE5E762981931842C465F00236401D 8BD973EE
net.                    86400   IN      RRSIG   DS 8 1 86400 20180105170000 20171223160000 46809 . pjztqsOI31D9PWL1Gb+gyMB0BI8CkNbZ2JuT08q7e2eQcnRLn+bCkGwZ //912hVJ2Z8qYiQ5P/vfX97c1uGGcx7C0j/8sz8qY4TM3+iyDXeIkSyX MLZFsITa6UjR14ojWNhpvYIlcTGYOL6Zd+rffs90/lS+AmGpFJqjZwHe n9hOVeZQry27I0yhDCDvqVZX40yXplmb9a0ey/a4AUIPgkTblOi14Otm b9nzD4Jtz+Ly4LVq8d/BW/cqNXG7NmbuJxyN1EDVGI+RUOMWRCnkW+6c oXiRMtUV7V01/0fQ+eg4m/TPDrRk5BF4YOF5p5RDUFnr2Pz75oGIcL+/ rOHbtg==
;; Received 1176 bytes from 192.203.230.10#53(e.root-servers.net) in 154 ms

nestum.net.             172800  IN      NS      nimbus.fccf.net.
nestum.net.             172800  IN      NS      marla.fccf.net.
A1RT98BS5QGC9NFI51S9HCI47ULJG6JH.net. 86400 IN NSEC3 1 1 0 - A1RUUFFJKCT2Q54P78F8EJGJ8JBK7I8B NS SOA RRSIG DNSKEY NSEC3PARAM
A1RT98BS5QGC9NFI51S9HCI47ULJG6JH.net. 86400 IN RRSIG NSEC3 8 2 86400 20171227062609 20171220051609 18737 net. nEhicHLkvsZVirHCoNYYNJKGcJOj9XtL57/ltvpBXqP6a4gnYeui3QOI 2ru7WBgjx7B2Q/rlJN5CYa/5JIrLn1G13uOIU97rsoE93gpyicbxhEb0 sz6NxpTrLlpK7I18Avdvc4u3wsqyMgN/G+fph/fNmk6ZMiIDvSFo5oux lRI=
Q7GVCMC21GE84K89VD2BH8VR132RR7EG.net. 86400 IN NSEC3 1 1 0 - Q7HGLU80K3KRP87ARSTE66MD8VURU5H6 NS DS RRSIG
Q7GVCMC21GE84K89VD2BH8VR132RR7EG.net. 86400 IN RRSIG NSEC3 8 2 86400 20171228062510 20171221051510 18737 net. d4WFz2CwdUuL5bOVbI9FCoOjo7tlPXvMEWLM4OHMtbBkQ2cgiR6ugLog ivSXxcbeu/K/nTJ0LtP+UzmWSdPtze7BfWsUTougxAJZMIL3aJkZrrgF 048qY2TrUjhVSgeXXZkA+r4LHpMC78alZI0SXEXbeErT1CfCfn0qp5n5 0yc=
;; Received 611 bytes from 192.55.83.30#53(m.gtld-servers.net) in 65 ms

paganini.nestum.net.    3600    IN      NS      charlie.fmi.fail.
paganini.nestum.net.    3600    IN      NS      bravo.fmi.fail.
paganini.nestum.net.    3600    IN      NS      delta.fmi.fail.
;; Received 250 bytes from 77.77.144.35#53(nimbus.fccf.net) in 37 ms

paganini.nestum.net.    60      IN      SOA     charlie.fail.fmi.paganini.nestum.net. dianvaltodorov.gmail.com.paganini.nestum.net. 20171219 60 60 60 60
;; Received 126 bytes from 185.117.82.100#53(charlie.fmi.fail) in 13 ms
```
* My teammates had to configure their dns server on their side. THis is what i kept getting in the logs

```
Dec 23 19:22:51 charlie named[13162]: zone weber.netsum.net/IN: Transfer started.                                                                                                   
Dec 23 19:22:51 charlie named[13162]: transfer of 'weber.netsum.net/IN' from 185.117.82.101#53: failed to connect: connection refused        
Dec 23 19:22:51 charlie named[13162]: transfer of 'weber.netsum.net/IN' from 185.117.82.101#53: Transfer status: connection refused                                         
Dec 23 19:22:51 charlie named[13162]: transfer of 'weber.netsum.net/IN' from 185.117.82.101#53: Transfer completed: 0 messages, 0 records, 0 bytes, 0.001 secs (0 bytes/sec)
Dec 23 19:25:46 charlie named[13162]: zone field.netsum.net/IN: refresh: retry limit for master 185.117.82.99#53 exceeded (source 0.0.0.0#0) 
Dec 23 19:25:46 charlie named[13162]: zone field.netsum.net/IN: Transfer started.                                                                                           
Dec 23 19:25:46 charlie named[13162]: transfer of 'field.netsum.net/IN' from 185.117.82.99#53: failed to connect: connection refused         
Dec 23 19:25:46 charlie named[13162]: transfer of 'field.netsum.net/IN' from 185.117.82.99#53: Transfer status: connection refused          
Dec 23 19:25:46 charlie named[13162]: transfer of 'field.netsum.net/IN' from 185.117.82.99#53: Transfer completed: 0 messages, 0 records, 0 bytes, 0.001 secs (0 bytes/sec) 
Dec 23 20:08:56 charlie named[13162]: client 88.87.0.2#44194 (paganini.nestum.net): query (cache) 'paganini.nestum.net/A/IN' denied          
```

* Venci went online and he added all things necessary on his machine. My zone file was successfully transfered to his machine. His file was also successfully trnsferd

```
Dec 23 23:17:00 charlie named[26613]: transfer of 'weber.nestum.net/IN' from 185.117.82.101#53: connected using 185.117.82.100#47661
Dec 23 23:17:00 charlie named[26613]: zone weber.nestum.net/IN: transferred serial 2017122306
```

```
root@charlie:~# ls /var/cache/bind
managed-keys.bind  managed-keys.bind.jnl  paganini.nestum.net.zone  weber.nestum.net.zone
```
*  It all works

    - call from delta
    ^[[B^[[Bpaganini.nestum.net.    3600    IN      SOA     charlie.fail.fmi.paganini.nestum.net. dianvaltodorov.gmail.com.paganini.nestum.net. 20171219 60 60 60 60
    paganini.nestum.net.    3600    IN      NS      delta.fmi.fail.
    paganini.nestum.net.    3600    IN      NS      charlie.fmi.fail.
    paganini.nestum.net.    3600    IN      NS      bravo.fmi.fail.
    ;; Received 196 bytes from 185.117.82.101#53(delta.fmi.fail) in 0 ms

    - request from charlie
    paganini.nestum.net.    3600    IN      NS      bravo.fmi.fail.
    paganini.nestum.net.    3600    IN      NS      delta.fmi.fail.
    paganini.nestum.net.    3600    IN      NS      charlie.fmi.fail.
    ;; Received 250 bytes from 77.77.144.35#53(nimbus.fccf.net) in 36 ms

    paganini.nestum.net.    60      IN      SOA     charlie.fail.fmi.paganini.nestum.net. dianvaltodorov.gmail.com.paganini.nestum.net. 20171219 60 60 60 60
    ;; Received 126 bytes from 185.117.82.100#53(charlie.fmi.fail) in 11 ms

Part2 
====
* Venci told me about dnssec
* add to /etc/bind/named.conf.options
```
dnssec-enable yes;
dnssec-validation yes;
dnssec-lookaside auto;
```
* cd /var/cache/bind
* sign the zones
* Create a Zone Signing Key(ZSK) with the following command.
```
dnssec-keygen -a NSEC3RSASHA1 -b 2048 -n ZONE paganini.nestum.net
```
* Create a KEY Signing Key(KSK) with the following command.
```
dnssec-keygen -f KSK -a NSEC3RSASHA1 -b 4096 -n ZONE paganini.nestum.net
```
* run this script to include all the keys in the paganini.nestum.net.zone fie
```
for key in `ls Kpaganini.nestum.net.zone.key`
do
echo "\$INCLUDE $key">> paganini.nestum.net.zone
done
```
* Sign the zone with the dnssec-signzone command.
 dnssec-signzone -A -3 93c35e168d214f4d -N INCREMENT -o paganini.nestum.net -t paganini.nestum.net.zone

* Change the file option inside the zone { } section.
zone "paganini.nestum.net" in{
        type master;
        file "paganini.nestum.net.zone.signed";
        allow-transfer { team; };
};
* restart bind9
* test from another machine. It all works. I am getting RRSIG records

```
root@banshee:~# dig soa paganini.nestum.net.  +multiline +trace

; <<>> DiG 9.9.5-9+deb8u14-Debian <<>> soa paganini.nestum.net. +multiline +trace
;; global options: +cmd
.                       9232 IN NS b.root-servers.net.
.                       9232 IN NS g.root-servers.net.
.                       9232 IN NS d.root-servers.net.
.                       9232 IN NS a.root-servers.net.
.                       9232 IN NS i.root-servers.net.
.                       9232 IN NS l.root-servers.net.
.                       9232 IN NS m.root-servers.net.
.                       9232 IN NS c.root-servers.net.
.                       9232 IN NS j.root-servers.net.
.                       9232 IN NS h.root-servers.net.
.                       9232 IN NS k.root-servers.net.
.                       9232 IN NS f.root-servers.net.
.                       9232 IN NS e.root-servers.net.
.                       9232 IN RRSIG NS 8 0 518400 (
                                20180106050000 20171224040000 46809 .
                                IejP6Rr/X309R2QkWaG0OXTgNrKYS8YnDZNwHXThxRMz
                                N2lrsopbRK57xja4geKSCVf+0ISoP606BUCp4fnT8K8/
                                7Oj5yxfoL8rDFGJpbmpK1p609pO6E5qvV7AJZc1YgTaX
                                4hmJR6uxGNxA4gTum3ijJQJBYhLM0wy1QJ+wenn9Uv94
                                vmFfFlY2P7WvjkfgMl7nLQeKalv2BGXEiTv+1JV+AUGD
                                oqHQPXqkzp9o5RSydfOxI6TEmKiJFGn/8e8P/z0CKrXq
                                rqwgbiIe+hEY9xWPz+fhCHpeDosPB9+/Jn/PNa5C/f5v
                                wEHbaeOXDCYv9qhGlbz910mmIA1mcTP9FQ== )
;; Received 1097 bytes from 192.168.0.1#53(192.168.0.1) in 95 ms

net.                    172800 IN NS k.gtld-servers.net.
net.                    172800 IN NS l.gtld-servers.net.
net.                    172800 IN NS b.gtld-servers.net.
net.                    172800 IN NS e.gtld-servers.net.
net.                    172800 IN NS h.gtld-servers.net.
net.                    172800 IN NS m.gtld-servers.net.
net.                    172800 IN NS c.gtld-servers.net.
net.                    172800 IN NS j.gtld-servers.net.
net.                    172800 IN NS f.gtld-servers.net.
net.                    172800 IN NS a.gtld-servers.net.
net.                    172800 IN NS g.gtld-servers.net.
net.                    172800 IN NS d.gtld-servers.net.
net.                    172800 IN NS i.gtld-servers.net.
net.                    86400 IN DS 35886 8 2 (
                                7862B27F5F516EBE19680444D4CE5E762981931842C4
                                65F00236401D8BD973EE )
net.                    86400 IN RRSIG DS 8 1 86400 (
                                20180106050000 20171224040000 46809 .
                                S5FcU0cQmcy/hBBzkwUbbpcOrYkj3Vh8YR4BPvjEEDIL
                                ysScFC2p1lTI2o7gUNHgnUFLXKqzryvoCKCrmMhWXVUS
                                ot0PdvOeggTjoikb02/LLx9fSrVkDyoySwbzQIYK7e6K
                                wjruMrb3s3sePGmisd2RuwoFcnaCuwjam9eKG+6OChte
                                XH+edV+sn2xQqnOJ3i93tKXCau7tHzpkNJ8CKaw0XzNe
                                8jZg2jKQW4osJE/xEECZc77oxqoFvxYBGlKY+/hpkPzT
                                loZ+ovfjEAY9dwJFbiIQsyhT3sOF14y5t07RhDOgFgD3
                                pP9zcf+JVqAuLrgLftt34uuPUoLjgKsxkw== )
;; Received 1176 bytes from 192.36.148.17#53(i.root-servers.net) in 92 ms

nestum.net.             172800 IN NS nimbus.fccf.net.
nestum.net.             172800 IN NS marla.fccf.net.
A1RT98BS5QGC9NFI51S9HCI47ULJG6JH.net. 86400 IN NSEC3 1 1 0 - (
                                A1RUUFFJKCT2Q54P78F8EJGJ8JBK7I8B
                                NS SOA RRSIG DNSKEY NSEC3PARAM )
A1RT98BS5QGC9NFI51S9HCI47ULJG6JH.net. 86400 IN RRSIG NSEC3 8 2 86400 (
                                20171231062405 20171224051405 18737 net.
                                LT8WsP/wGTHiFOYupqVO0r54zNpOHallP/BzviGmj97n
                                WD/AR6L4FwBheuUdZLCgmsJ+AxjVUlGn6uYnLxBti/SA
                                nt4ec1VWor3JysWpVcHcJIzTwem95SW4Row//b1igoJa
                                kZ+sur2BI+4dgC0x+HG3TZvfl5d8d1iLC6BtNGk= )
Q7GVCMC21GE84K89VD2BH8VR132RR7EG.net. 86400 IN NSEC3 1 1 0 - (
                                Q7HGLU80K3KRP87ARSTE66MD8VURU5H6
                                NS DS RRSIG )
Q7GVCMC21GE84K89VD2BH8VR132RR7EG.net. 86400 IN RRSIG NSEC3 8 2 86400 (
                                20171228062510 20171221051510 18737 net.
                                d4WFz2CwdUuL5bOVbI9FCoOjo7tlPXvMEWLM4OHMtbBk
                                Q2cgiR6ugLogivSXxcbeu/K/nTJ0LtP+UzmWSdPtze7B
                                fWsUTougxAJZMIL3aJkZrrgF048qY2TrUjhVSgeXXZkA
                                +r4LHpMC78alZI0SXEXbeErT1CfCfn0qp5n50yc= )
;; Received 611 bytes from 192.26.92.30#53(c.gtld-servers.net) in 80 ms

paganini.nestum.net.    3600 IN NS delta.fmi.fail.
paganini.nestum.net.    3600 IN NS bravo.fmi.fail.
paganini.nestum.net.    3600 IN NS charlie.fmi.fail.
;; Received 250 bytes from 77.77.144.35#53(nimbus.fccf.net) in 35 ms

paganini.nestum.net.    3600 IN SOA charlie.fail.fmi.paganini.nestum.net. dianvaltodorov.gmail.com.paganini.nestum.net. (
                                20171220   ; serial
                                60         ; refresh (1 minute)
                                60         ; retry (1 minute)
                                60         ; expire (1 minute)
                                60         ; minimum (1 minute)
                                )
paganini.nestum.net.    3600 IN RRSIG SOA 7 3 3600 (
                                20180123110548 20171224110548 32357 paganini.nestum.net.
                                mUIwWCb5v5XzBJrzNIfFbGzQCcgYAVp3pBdBSpFMoVrI
                                nNy5OwPkkwGgWxtBxhsVkJQYPFeJVdkNuePBBIFEvOuv
                                qIlyJdhvFTEmggazIWK9M9qLGgzw8uEo0H7t8IZmofIZ
                                CUznst65chRkPeezNyiC66zWffA06aNFAGLxxledLJyF
                                64EHyY2l/aIXQzYGlqhhMW3qwtzehlTIwV2CzkLCSuuV
                                Py9gA9d+utHh4lUK3b5jpOcqMabVFa7YKfySw5wIABKv
                                YKPL66W4KzxQaf4VaW+3Y6nn+/0bd5ICon/c+Lcr9/hD
                                e/102CDXqMRNbJSZR5qyJhTjLKRdnAQ0zg== )
paganini.nestum.net.    3600 IN NS charlie.fmi.fail.
paganini.nestum.net.    3600 IN NS bravo.fmi.fail.
paganini.nestum.net.    3600 IN NS delta.fmi.fail.
paganini.nestum.net.    3600 IN RRSIG NS 7 3 3600 (
                                20180123110548 20171224110548 32357 paganini.nestum.net.
                                FvuTWk71Tpq0A4ZHt1dZXwztJ0KtomOEQ/enmmFbSZEV
                                JdbS5wSBF69ZpXQOUz9rhSk5UXt5+baUBYDNmUWbESwX
                                gBp0+trvO3uTuo2ykm0Wl+UfD6XjXflYXdrKsLu4AJ6S
                                0hgP2S2MrjOGpdzlsid7OiBrrxyNmEHnxuvcSo/WewdC
                                l5vC6gtnxkQuQmgvCgbslxNfPDEDPYCY7j3vAOQD9qS/
                                9SJc8TIwIKigcM+xjhScP7N7Qa0Fn0eK++mI1fbbJc/c
                                3zmEkPNn4b8CFcskM8ISkvE6UlrewFJpvuG5rJdzrGN/
                                QyslM7bc6zgf13Fn32YIxCGmD94Pitd9Og== )
;; Received 810 bytes from 185.117.82.100#53(charlie.fmi.fail) in 15 ms

```

* become a signed slave for Venci.
* cange the name.conf file

 zone "weber.nestum.net" in{
        type slave;
        file "weber.nestum.net.zone.signed";
        masters { 185.117.82.101; };  # delta
};

* validate it works
```
root@banshee:~# dig soa weber.nestum.net.  +multiline +trace

; <<>> DiG 9.9.5-9+deb8u14-Debian <<>> soa weber.nestum.net. +multiline +trace
.....
weber.nestum.net.       86400 IN NS charlie.fmi.fail.
weber.nestum.net.       86400 IN NS bravo.fmi.fail.
weber.nestum.net.       86400 IN NS delta.fmi.fail.
weber.nestum.net.       86400 IN RRSIG NS 7 3 86400 (
                                20180122201519 20171223201519 19265 weber.nestum.net.
                                aaXB1HY3CkAL4mln4cJDDLwNLZ+YSvIlKWYpXg74Dir7
                                tdGAIG2JArW5kRkLxxaDbgGBqSnzjeXMpls7Gb4C67Hm
                                wtcQmOTTzu0HZe1r4/irgUlv5b5bB3Hzkt96+dlXb1lk
                                Mq90eY9QflSGY6JPPR2uiKA6ySex2n4Mbl0Ho7gnxOe6
                                LTQI7yMiPLlYfRYfyDanSfcb/0Spy+HOZTUP+kiqcq+8
                                BNmes/NzggxEd/CrK764wz+3+spRn969+bt+3LPs/Sp8
                                sh4cm138voDwBUoYUk/00j+fDBcE0Pp9LWLogfNVUGwC
                                cpiuyNimKFBUtuBaxSUyKaTB7plk6loTog== )
;; Received 781 bytes from 185.117.82.100#53(charlie.fmi.fail) in 16 ms

```
* Jorkata could not contact. Did not want to disturb him on Christmas but his configs are done so he only needs to set up the zone files on his side and that is it.