local config

when we take the next zone, the root zone knows which name servers are authorithive for the zone
In this case they are a..k.gtld-servers.net

KRKEY      CLASS  RRTYOPE RRDATA
fccf.net    IN      A      77.77.144.55

Delegating means  на по горно нива е описано че ей за този ключ има rr ns, който казва, че name server-ите са ето тези

единият name server единя master.
За .net има SOA NS



ROOT ZONE
NET.   IN NS S1.
          NS S2.

COM. IN  NS S3.
         NS S4.

ORG. IN  NS S5.
         NS S6.
...


NET zone
NET.     SOA ....
         NS  S1.
         NS  S2.
         NS  S10.
         NS  S20.

В net zone може да има повече NS записи за зона. В . има 2, а във нет имам 4. Мога да патам за net. и получавам s1, s2. Питам s1 за SOA, питам за ns


искаме AA запис pd

$ dig +norec a alpha.gnus.fccf.net @198.41.0.4
$ dig +norec a alpha.gnus.fccf.net @192.54.112.38
$ dig +norec a alpha.gnus.fccf.net @77.77.44

TTL specifies how long a cache server caches.
]