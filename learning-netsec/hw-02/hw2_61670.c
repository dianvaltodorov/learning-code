#include<pcap.h>
#include<stdio.h>
#include<stdlib.h> // for exit()
#include<string.h> //for memset
#include <netinet/ip.h>

#include<sys/socket.h>
#include<arpa/inet.h> // for inet_ntoa()
#include<net/ethernet.h>

struct sockaddr_in source, dest;

void packet_handler(
        u_char *args,
        const struct pcap_pkthdr *header,
        const u_char *packet
);

int main(int argc, char *argv[]) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    char file_name[1 << 8];
    scanf("%s", file_name);

    pcap_t *handle;
    handle = pcap_open_offline(file_name, error_buffer);
    if (handle == NULL) {
        printf("Could not open %s: %s\n", file_name, error_buffer);
        return 1;
    }

    if (pcap_loop(handle, 0, packet_handler, NULL) < 0) {
        printf("pcap_loop() failed: %s", pcap_geterr(handle));
        return 1;
    }

    return 0;
}

void packet_handler(
        u_char *args,
        const struct pcap_pkthdr *packet_header,
        const u_char *packet_body
) {
    const struct ether_header *eth_header;
    const struct ip *ip_header;
    char source_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];
    eth_header = (struct ether_header *) packet_body;

    ip_header = (struct ip *) (packet_body + sizeof(struct ether_header));
    inet_ntop(AF_INET, &(ip_header->ip_src), source_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

    printf("%s %s %x\n", source_ip, dest_ip, eth_header->ether_type);
}
