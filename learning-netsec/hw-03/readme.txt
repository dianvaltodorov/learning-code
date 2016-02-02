hw3_61670.c is a program for dissecting packets from a pcap file:

User Guide:
-----
1.Compilation and Running:

$ gcc hw3_61670.c -lpcap
$ ./a.out 

2. Use:

The programs wait for a path to a .pcap file

$ some_file.pcap


How it works:
---
The program is written in C and uses libpcap. It is used dissects every packet by reading the bits.


