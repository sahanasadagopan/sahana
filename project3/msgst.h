/*
 * msgst.h
 *
 *  Created on: Nov 4, 2016
 *      Author: Divya Sampath
 */
#ifndef SOURCES_MSGST_H_
#define SOURCES_MSGST_H_
#define maxdatasize 9
typedef enum Cmds_t
{
	RED = 0x01,
	BLUE= 0X02,
	GREEN= 0X03,
	YELLOW= 0X04,
	CYAN= 0X05,
	VIOLET= 0X06,
	WHITE= 0X07,
	INTENSITY=0X08
}Cmds;

typedef struct
{
	Cmds command;
	uint8_t length;
	uint8_t data[maxdatasize];
	uint8_t inten;
	uint16_t checksum;
}CI_Msg;


#endif /* SOURCES_MSGST_H_ */
