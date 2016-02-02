
#define APP_NAME "sniffex"
#define APP_DESC "Sniffer example using libpcap"
#define APP_COPYRIGHT "Copyright (c) 2005 The Tcpdump Group"
#define APP_DISCLAIMER "THERE IS ABSOLUTELY NO WARRANTY FOR THIS PROGRAM."

#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/ethernet.h>

/* default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 1518

/* ethernet headers are always exactly 14 bytes [1] */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN 6

/* Ethernet header */
struct sniff_ethernet
{
    u_char ether_dhost[ETHER_ADDR_LEN]; /* destination host address */
    u_char ether_shost[ETHER_ADDR_LEN]; /* source host address */
    u_short ether_type;                 /* IP? ARP? RARP? etc */
};

/* IP header */
struct sniff_ip
{
    u_char ip_vhl;                 /* version << 4 | header length >> 2 */
    u_char ip_tos;                 /* type of service */
    u_short ip_len;                /* total length */
    u_short ip_id;                 /* identification */
    u_short ip_off;                /* fragment offset field */
#define IP_RF 0x8000               /* reserved fragment flag */
#define IP_DF 0x4000               /* dont fragment flag */
#define IP_MF 0x2000               /* more fragments flag */
#define IP_OFFMASK 0x1fff          /* mask for fragmenting bits */
    u_char ip_ttl;                 /* time to live */
    u_char ip_p;                   /* protocol */
    u_short ip_sum;                /* checksum */
    struct in_addr ip_src, ip_dst; /* source and dest address */
};
#define IP_HL(ip) (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip) (((ip)->ip_vhl) >> 4)

/* TCP header */
typedef u_int tcp_seq;

struct sniff_tcp
{
    u_short th_sport; /* source port */
    u_short th_dport; /* destination port */
    tcp_seq th_seq;   /* sequence number */
    tcp_seq th_ack;   /* acknowledgement number */
    u_char th_offx2;  /* data offset, rsvd */
#define TH_OFF(th) (((th)->th_offx2 & 0xf0) >> 4)
    u_char th_flags;
#define TH_FIN 0x01
#define TH_SYN 0x02
#define TH_RST 0x04
#define TH_PUSH 0x08
#define TH_ACK 0x10
#define TH_URG 0x20
#define TH_ECE 0x40
#define TH_CWR 0x80
#define TH_FLAGS (TH_FIN | TH_SYN | TH_RST | TH_ACK | TH_URG | TH_ECE | TH_CWR)
    u_short th_win; /* window */
    u_short th_sum; /* checksum */
    u_short th_urp; /* urgent pointer */
};

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

void print_payload(const u_char *payload, int len);

void print_hex_ascii_line(const u_char *payload, int len, int offset);

void print_app_banner(void);

void print_app_usage(void);

/*
 * app name/banner
 */
void print_app_banner(void)
{

    printf("%s - %s\n", APP_NAME, APP_DESC);
    printf("%s\n", APP_COPYRIGHT);
    printf("%s\n", APP_DISCLAIMER);
    printf("\n");

    return;
}

/*
 * print help text
 */
void print_app_usage(void)
{

    printf("Usage: %s [interface]\n", APP_NAME);
    printf("\n");
    printf("Options:\n");
    printf("    interface    Listen on <interface> for packets.\n");
    printf("\n");

    return;
}

/*
 * print data in rows of 16 bytes: offset   hex   ascii
 *
 * 00000   47 45 54 20 2f 20 48 54  54 50 2f 31 2e 31 0d 0a   GET / HTTP/1.1..
 */
void print_hex_ascii_line(const u_char *payload, int len, int offset)
{

    int i;
    int gap;
    const u_char *ch;

    /* offset */
    printf("%05d   ", offset);

    /* hex */
    ch = payload;
    for (i = 0; i < len; i++)
    {
        printf("%02x ", *ch);
        ch++;
        /* print extra space after 8th byte for visual aid */
        if (i == 7)
            printf(" ");
    }
    /* print space to handle line less than 8 bytes */
    if (len < 8)
        printf(" ");

    /* fill hex gap with spaces if not full line */
    if (len < 16)
    {
        gap = 16 - len;
        for (i = 0; i < gap; i++)
        {
            printf("   ");
        }
    }
    printf("   ");

    /* ascii (if printable) */
    ch = payload;
    for (i = 0; i < len; i++)
    {
        if (isprint(*ch))
            printf("%c", *ch);
        else
            printf(".");
        ch++;
    }

    printf("\n");

    return;
}

/*
 * print packet payload data (avoid printing binary data)
 */
void print_payload(const u_char *payload, int len)
{

    int len_rem = len;
    int line_width = 16; /* number of bytes per line */
    int line_len;
    int offset = 0; /* zero-based offset counter */
    const u_char *ch = payload;

    if (len <= 0)
        return;

    /* data fits on one line */
    if (len <= line_width)
    {
        print_hex_ascii_line(ch, len, offset);
        return;
    }

    /* data spans multiple lines */
    for (;;)
    {
        /* compute current line length */
        line_len = line_width % len_rem;
        /* print line */
        print_hex_ascii_line(ch, line_len, offset);
        /* compute total remaining */
        len_rem = len_rem - line_len;
        /* shift pointer to remaining bytes to print */
        ch = ch + line_len;
        /* add offset */
        offset = offset + line_width;
        /* check if we have line width chars or less */
        if (len_rem <= line_width)
        {
            /* print last line and get out */
            print_hex_ascii_line(ch, len_rem, offset);
            break;
        }
    }

    return;
}
uint16_t checksum(const u_char *data, size_t length)
{
    // Initialise the accumulator.
    uint32_t acc = 0xffff;

    // Handle complete 16-bit blocks.
    for (size_t i = 0; i + 1 < length; i += 2)
    {
        uint16_t word;
        memcpy(&word, data + i, 2);
        acc += ntohs(word);
        if (acc > 0xffff)
        {
            acc -= 0xffff;
        }
    }

    // Handle any partial block at the end of the data.
    if (length & 1)
    {
        uint16_t word = 0;
        memcpy(&word, data + length - 1, 1);
        acc += ntohs(word);
        if (acc > 0xffff)
        {
            acc -= 0xffff;
        }
    }

    // Return the checksum in network byte order.
    return htons(~acc);
}

uint16_t tcp_checksum(const void *buff, size_t len)
{
    uint16_t x = checksum(buff, len);
    return x;
}

/*
 * dissect/print packet
 */
void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    /* declare pointers to packet headers */
    const struct sniff_ethernet *ethernet; /* The ethernet header [1] */
    const struct sniff_ip *ip;             /* The IP header */
    const struct sniff_tcp *tcp;           /* The TCP header */
    const char *payload;                   /* Packet payload */

    int size_ip;
    int size_tcp;
    int size_payload;

    /* define ethernet header */
    ethernet = (struct sniff_ethernet *)(packet);

    /* define/compute ip header offset */
    ip = (struct sniff_ip *)(packet + SIZE_ETHERNET);
    size_ip = IP_HL(ip) * 4;
    if (size_ip < 20)
    {
        printf("   * Invalid IP header length: %u bytes\n", size_ip);
        return;
    }

    /* define/compute tcp header offset */
    tcp = (struct sniff_tcp *)(packet + SIZE_ETHERNET + size_ip);
    size_tcp = TH_OFF(tcp) * 4;
    if (size_tcp < 20)
    {
        printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
        return;
    }

    if (checksum(packet + SIZE_ETHERNET, size_ip) != 0)
    {
        printf("%s %s 0x%02X bad_csum\n",
               ether_ntoa((struct ether_addr *)ethernet->ether_shost),
               ether_ntoa((struct ether_addr *)ethernet->ether_dhost),
               ethernet->ether_type);
    }

    printf("%s %s 0x%04x %s %s %x %d %d",
           ether_ntoa((struct ether_addr *)ethernet->ether_shost),
           ether_ntoa((struct ether_addr *)ethernet->ether_dhost),
           ntohs(ethernet->ether_type),
           inet_ntoa(ip->ip_src),
           inet_ntoa(ip->ip_dst),
           ip->ip_p,
           tcp->th_sport,
           tcp->th_dport);

    if ((tcp->th_flags & TH_PUSH) == TH_PUSH &&
        (tcp->th_flags & TH_FIN) == TH_FIN &&
        (tcp->th_flags & TH_URG) == TH_URG)
    {
        printf(" XMAS\n");
    } 
    else
    {
        printf(" NULL\n");
    } 
    return;
}

int main(int argc, char *argv[])
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    char file_name[1 << 8];
    scanf("%s", file_name);

    pcap_t *handle;
    handle = pcap_open_offline(file_name, error_buffer);
    if (handle == NULL)
    {
        printf("Could not open %s: %s\n", file_name, error_buffer);
        return 1;
    }

    if (pcap_loop(handle, 0, got_packet, NULL) < 0)
    {
        printf("pcap_loop() failed: %s", pcap_geterr(handle));
        return 1;
    }

    return 0;
}
