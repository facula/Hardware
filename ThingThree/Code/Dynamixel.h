#ifndef DYNAMIXEL_H_
#define DYNAMIXEL_H_

#include <wiringPi.h>
#include <string>
#include <map>

#define AX_MODEL_NUMBER_L 0
#define AX_MODEL_NUMBER_H 1
#define AX_VERSION 2
#define AX_ID 3
#define AX_BAUD_RATE 4
#define AX_RETURN_DELAY_TIME 5
#define AX_CW_ANGLE_LIMIT_L 6
#define AX_CW_ANGLE_LIMIT_H 7
#define AX_CCW_ANGLE_LIMIT_L 8
#define AX_CCW_ANGLE_LIMIT_H 9
#define AX_SYSTEM_DATA2 10
#define AX_LIMIT_TEMPERATURE 11
#define AX_DOWN_LIMIT_VOLTAGE 12
#define AX_UP_LIMIT_VOLTAGE 13
#define AX_MAX_TORQUE_L 14
#define AX_MAX_TORQUE_H 15
#define AX_RETURN_LEVEL 16
#define AX_ALARM_LED 17
#define AX_ALARM_SHUTDOWN 18
#define AX_OPERATING_MODE 19
#define AX_DOWN_CALIBRATION_L 20
#define AX_DOWN_CALIBRATION_H 21
#define AX_UP_CALIBRATION_L 22
#define AX_UP_CALIBRATION_H 23

#define AX_TORQUE_STATUS 24
#define AX_LED_STATUS 25
#define AX_CW_COMPLIANCE_MARGIN 26
#define AX_CCW_COMPLIANCE_MARGIN 27
#define AX_CW_COMPLIANCE_SLOPE 28
#define AX_CCW_COMPLIANCE_SLOPE 29
#define AX_GOAL_POSITION_L 30
#define AX_GOAL_POSITION_H 31
#define AX_GOAL_SPEED_L 32
#define AX_GOAL_SPEED_H 33
#define AX_TORQUE_LIMIT_L 34
#define AX_TORQUE_LIMIT_H 35
#define AX_PRESENT_POSITION_L 36
#define AX_PRESENT_POSITION_H 37
#define AX_PRESENT_SPEED_L 38
#define AX_PRESENT_SPEED_H 39
#define AX_PRESENT_LOAD_L 40
#define AX_PRESENT_LOAD_H 41
#define AX_PRESENT_VOLTAGE 42
#define AX_PRESENT_TEMPERATURE 43
#define AX_REGISTERED_INSTRUCTION 44
#define AX_PAUSE_TIME 45
#define AX_MOVING 46
#define AX_LOCK 47
#define AX_PUNCH_L 48
#define AX_PUNCH_H 49

#define AX_RETURN_NONE 0
#define AX_RETURN_READ 1
#define AX_RETURN_ALL 2

#define AX_PING 1
#define AX_READ_DATA 2
#define AX_WRITE_DATA 3
#define AX_REG_WRITE 4
#define AX_ACTION 5
#define AX_RESET 6
#define AX_SYNC_WRITE 131

#define AX_RESET_LENGTH 2
#define AX_ACTION_LENGTH 2
#define AX_ID_LENGTH 4
#define AX_LR_LENGTH 4
#define AX_SRL_LENGTH 4
#define AX_RDT_LENGTH 4
#define AX_LEDALARM_LENGTH 4
#define AX_SHUTDOWNALARM_LENGTH 4
#define AX_TL_LENGTH 4
#define AX_VL_LENGTH 6
#define AX_AL_LENGTH 7
#define AX_CM_LENGTH 6
#define AX_CS_LENGTH 5
#define AX_COMPLIANCE_LENGTH 7
#define AX_CCW_CW_LENGTH 8
#define AX_BD_LENGTH 4
#define AX_TEM_LENGTH 4
#define AX_MOVING_LENGTH 4
#define AX_RWS_LENGTH 4
#define AX_VOLT_LENGTH 4
#define AX_LOAD_LENGTH 4
#define AX_LED_LENGTH 4
#define AX_TORQUE_LENGTH 4
#define AX_POS_LENGTH 4
#define AX_GOAL_LENGTH 5
#define AX_MT_LENGTH 5
#define AX_PUNCH_LENGTH 5
#define AX_SPEED_LENGTH 5
#define AX_GOAL_SP_LENGTH 7

#define AX_BYTE_READ 1
#define AX_INT_READ 2
#define AX_ACTION_CHECKSUM 250
#define AX_BROADCAST_ID 254
#define AX_START 255
#define AX_CCW_AL_L 255
#define AX_CCW_AL_H 3
#define AX_LOCK_VALUE 1
#define LEFT 0
#define RIGTH 1
#define RX_TIME_OUT 10
#define TX_DELAY_TIME 20

#define RPI_DIRECTION_PIN 18
#define RPI_DIRECTION_TX 1
#define RPI_DIRECTION_RX 0
#define RPI_DIRECTION_SWITCH_DELAY 100

class Dynamixel {
public:
	Dynamixel();

	void direction(int d);
	int readData(int id);
	int ping(int id);
	int factoryReset(id);
	int setID(id, newID);

	std::vector<int> connectedServos;
private:
	int port;
	std::vector<char> getSerial(int bytes);
	std::map<int, string> dictErrors = {
	    { 1, "Input Voltage" },
	    { 2, "Angle Limit" },
		{ 4, "Overheating" },
		{ 8, "Range" },
		{ 16, "Checksum" },
		{ 32, "Overload" },
		{ 64, "Instruction" }
	};
};

#endif /* DYNAMIXEL_H_ */
