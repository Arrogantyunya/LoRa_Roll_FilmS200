#ifndef _RECEIPT_H
#define _RECEIPT_H

#include <Arduino.h>

#define DEVICE_TYPE_ID  0xC001

#define SOFT_VERSION    0x13 //V1.9

#define HARD_VERSION    0x53//V8.3

enum ReceiptStatus{
  FactoryMode = 0, AskUploadParamsOk, AskUploadParamsErr, AssignGroupIdArrayOk, AssignGroupIdArrayErr, SetSnAndSlaverCountOk, 
  SetSnAndSlaverCountErr, TrunOffOk, TrunOffErr, RestRollerOk, ResetRollerErr, OpenRollerOk, OpenRollerErr, LimitRollerOk,
  LimitRollerErr, SetLoRaModeOk, SetLoRaModeErr,SetLoRaTFREQOk,SetLoRaTFREQErr,SetLoRaRFREQOk,SetLoRaRFREQErr
};

/*电机状态*/
enum MotorStatus{
  MotorFactoryMode = 0, ROLL_OK, HIGH_POSITION_LIMIT_EXCEPTION, LOW_POSITION_LIMIT_EXCEPTION, LOW_POWER, MOTOR_EXCEPTION, MOTOR_CURRENT_EXCEPTION, 
  ROLLING, CMD_EXCEPTION, NOT_INITIALIZED, STORE_EXCEPTION, RESET_ROLLING, RESET_ROLLOK, RS485_EXCEPTION, FORCE_STOP, MANUAL_ROLL_OK, MANUAL_KEY_EXCEPTION, 
  OPEN_ROLL_ERROR
};

extern volatile unsigned char gMotorStatus;

void Set_Motor_Status(unsigned char status);

class Receipt{
public:
    void Report_General_Parameter(void);
    void Request_Set_Group_Number(void);
    void Request_Device_SN_and_Channel(void);
    void Working_Parameter_Receipt(unsigned char times);
    void General_Receipt(unsigned char status, unsigned char send_times);
private:
  void Receipt_Random_Wait_Value(unsigned long int *random_value);
  void Clear_Server_LoRa_Buffer(void);
  void Print_Debug(unsigned char *base_addr, unsigned char len);
};

extern Receipt Message_Receipt;

extern unsigned char gLoRaCSQ[2];

#endif
