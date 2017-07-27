/************************************************************************/
/*
*
* Filename     :  GVCP_Status_Codes.h
* Revision     :  10.20.0517
* Content      :  This file contains definitions of the GigE Vision ®
*                 status codes.
*
* Copyright © Matrox Electronic Systems Ltd., 1992-2016.
* All Rights Reserved
*************************************************************************/

#ifndef _GVCP_STATUS_CODES_
#define _GVCP_STATUS_CODES_

//////////////////////////////////////////////////////////////////////////
// Status codes
//////////////////////////////////////////////////////////////////////////
#define GEV_STATUS_SUCCESS                               0x0000
#define GEV_STATUS_PACKET_RESEND                         0x0100
#define GEV_STATUS_NOT_IMPLEMENTED                       0x8001
#define GEV_STATUS_INVALID_PARAMETER                     0x8002
#define GEV_STATUS_INVALID_ADDRESS                       0x8003
#define GEV_STATUS_WRITE_PROTECT                         0x8004
#define GEV_STATUS_BAD_ALIGNMENT                         0x8005
#define GEV_STATUS_ACCESS_DENIED                         0x8006
#define GEV_STATUS_BUSY                                  0x8007

#define GEV_STATUS_PACKET_UNAVAILABLE                    0x800C
#define GEV_STATUS_DATA_OVERRUN                          0x800D
#define GEV_STATUS_INVALID_HEADER                        0x800E
#define GEV_STATUS_PACKET_NOT_YET_AVAILABLE              0x8010
#define GEV_STATUS_PACKET_AND_PREV_REMOVED_FROM_MEMORY   0x8011
#define GEV_STATUS_PACKET_REMOVED_FROM_MEMORY            0x8012
#define GEV_STATUS_NO_REF_TIME                           0x8013
#define GEV_STATUS_PACKET_TEMPORARILY_UNAVAILABLE        0x8014
#define GEV_STATUS_OVERFLOW                              0x8015
#define GEV_STATUS_ACTION_LATE                           0x8016
#define GEV_STATUS_ERROR                                 0x8FFF

//////////////////////////////////////////////////////////////////////////
// Deprecated status codes
//////////////////////////////////////////////////////////////////////////
#define GEV_STATUS_LOCAL_PROBLEM                         0x8008
#define GEV_STATUS_MSG_MISMATCH                          0x8009
#define GEV_STATUS_INVALID_PROTOCOL                      0x800A
#define GEV_STATUS_NO_MSG                                0x800B
#define GEV_STATUS_WRONG_CONFIG                          0x800F

//////////////////////////////////////////////////////////////////////////
// GigE Vision Stream Protocol Flags
//////////////////////////////////////////////////////////////////////////
#define GEV_FLAG_PACKET_RESEND                           0x0001
#define GEV_FLAG_PREVIOUS_BLOCK_DROPPED                  0x0002
#define GEV_FLAG_RESEND_RANGE_ERROR                      0x0004

//////////////////////////////////////////////////////////////////////////
// USB3 Vision Stream Protocol Status codes.
//////////////////////////////////////////////////////////////////////////
#define U3V_STATUS_RESEND_NOT_SUPPORTED 0xA001
/*
This status code must be used in an Acknowledge Packet in response to a 
Command Packet where:
- Prefix is valid
- command_id is valid
- Flags field is set to 0xC000
(CommandResend)
*/
#define U3V_STATUS_DSI_ENDPOINT_HALTED 0xA002
/*
This status code must be used in an Acknowledge Packet in response to a 
Command Packet when Stream Enable flag of SI Control Register is set to 
1 and the endpoint of the Device Streaming Interface is halted.
*/

#define U3V_STATUS_SI_PAYLOAD_SIZE_NOT_ALIGNED 0xA003
/*
This status code must be used in an Acknowledge Packet in response to a 
Command Packet when:
The value written to the SI streaming size registers is not aligned to 
Payload Size Alignment value of the SI Info register.
Applicable registers:
- SI Payload Transfer Size
- SI Payload Final Transfer1 Size
- SI Payload Final Transfer2 Size
- SI Maximum Leader Size
- SI Maximum Trailer Size
*/

#define U3V_STATUS_SI_REGISTERS_INCONSISTENT 0xA004
/*
This status code must be used in an Acknowledge Packet in response to a 
Command Packet trying to set the Stream Enable bit in the SI Control 
Register which was not successful because values within the stream 
interface registers were not consistent or legal.
*/

#define U3V_STATUS_DEI_ENDPOINT_HALTED 0xA005
/*
This status code must be used in an Acknowledge Packet in response to a 
Command Packet when Event Enable flag of EI Control Register is set to 1 
and the endpoint of the Device Event Interface is halted.
*/

#define U3V_STATUS_DATA_DISCARDED 0xA100
/*
Data discarded in the current block.
This status code must be used in the trailer when:
- Some data in the block has been discarded.
*/

#define U3V_STATUS_DATA_OVERRUN 0xA101
/*
Device is unable to send all data.
This status code must be used in the trailer when the Device cannot send 
all data because the data does not fit within the programmed SIRM 
register settings.
*/
#endif
