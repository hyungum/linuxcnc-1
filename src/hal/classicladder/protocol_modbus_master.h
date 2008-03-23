
#ifndef _PROTOCOL_MODBUS_MASTER_H
#define _PROTOCOL_MODBUS_MASTER_H

/* To set/reset single coil with function 5 */
#define MODBUS_BIT_OFF 0x0000
#define MODBUS_BIT_ON 0xFF00

#define LGT_MODBUS_IP_HEADER 7

/* Function codes list */
#define MODBUS_FC_READ_COILS 1
#define MODBUS_FC_READ_INPUTS 2
#define MODBUS_FC_READ_HOLD_REGS 3
#define MODBUS_FC_READ_INPUT_REGS 4
#define MODBUS_FC_FORCE_COIL 5
#define MODBUS_FC_WRITE_REG 6
#define MODBUS_FC_FORCE_COILS 15
#define MODBUS_FC_WRITE_REGS 16
#define MODBUS_FC_EXCEPTION_BIT 0x80

/* Exceptions list */
#define MODBUS_ILLEGAL_FUNCTION 0x01 
#define MODBUS_ILLEGAL_DATA_ADDRESS 0x02 
#define MODBUS_ILLEGAL_DATA_VALUE 0x03 
#define MODBUS_SLAVE_DEVICE_FAILURE 0x04 
#define MODBUS_SLAVE_DEVICE_BUSY 0x06 
#define MODBUS_NEGATIVE_ACKNOWLEDGE 0x07 
#define MODBUS_MEMORY_PARITY_ERROR 0x08 



#define MODBUS_REQ_INPUTS_READ 0
#define MODBUS_REQ_COILS_WRITE 1
#define MODBUS_REQ_REGISTERS_READ 2
#define MODBUS_REQ_REGISTERS_WRITE 3

#define LGT_SLAVE_ADR 25

#define NBR_MODBUS_MASTER_REQ 20 /*50: problem with GTK config window: adding vertical scroll else required*/

typedef struct StrModbusMasterReq
{
	/* IP address or IP:port or slave number for serial */
	/* if '\0' => req not defined */
	char SlaveAdr[ LGT_SLAVE_ADR ]; 
	char TypeReq; /* see MODBUS_REQ_ list */
	int FirstModbusElement;
	int NbrModbusElements;
	char LogicInverted;
	int OffsetVarMapped;
}StrModbusMasterReq;

void InitModbusMasterBeforeReadConf( void );
void InitModbusMasterParams( void );
int GetModbusResponseLenghtToReceive( void );
int ModbusMasterAsk( unsigned char * SlaveAddressIP, unsigned char * Question );
char TreatModbusMasterResponse( unsigned char * Response, int LgtResponse );

void SetVarFromModbus( StrModbusMasterReq * ModbusReq, int ModbusNum, int Value );
int GetVarForModbus( StrModbusMasterReq * ModbusReq, int ModbusNum );
#endif
