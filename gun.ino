
#include "RobotSerialComm.h"
#include "DynamixelTable.h"

RobotSerialComm port;

void setup(){
  Dxl.begin(1);
  SerialUSB.begin();
}



void loop(){
  int arg[5];

  int action = port.getMsg(arg); 

  switch(action)
  {
    case DXL_SINGLE_POS_MOVE:
      Dxl.writeWord(arg[0],AX_GOAL_POSITION_L,arg[1]);
    break;
  }
  
  delay(10);
}
