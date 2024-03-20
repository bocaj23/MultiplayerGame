#ifndef PACKET_H
#define PACKET_H

#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long long

//Packet Types
#define PING 0
#define MSG 1

typedef struct{

	//type of packet
	u8 pkt_type;

	//which client sent it
	u8 client_id;

	//payload
	char payload[256];
	
} Packet;
#endif
