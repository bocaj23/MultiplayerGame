#include "packet.h"

void read(){}

Packet create(u8 type, u8 clientid, char payload[256])
{
	Packet* pkt = malloc(sizeof(Packet));

	pkt->pkt_type = type;
	pkt->client_id = clientid;
	memcpy(pkt->payload, payload, sizeof(pkt->payload));

	return pkt;	
}

void vaporize(){}
