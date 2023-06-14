#include "FRRobot.h"
#include <string.h>
#include <windows.h>

int main(void)
{
	FRRobot robot;                 //实例化机器人对象
	robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

	int company = 4;
	int device = 0;
	int softversion = 0;
	int bus = 1;
	int index = 1;
	int act = 0;
	int max_time = 30000;
	uint8_t block = 0;
	uint8_t status, fault;

	robot.SetGripperConfig(company, device, softversion, bus);
	Sleep(1000);
	robot.GetGripperConfig(&company, &device, &softversion, &bus);
	printf("gripper config:%d,%d,%d,%d\n", company, device, softversion, bus);

	robot.ActGripper(index, act);
	Sleep(1000);
	act = 1;
	robot.ActGripper(index, act);
	Sleep(2000);

	robot.MoveGripper(index, 100, 50, 50, max_time, block);
	Sleep(3000);
	robot.MoveGripper(index, 0, 50, 0, max_time, block);

	robot.GetGripperMotionDone(&fault, &status);
	printf("motion status:%u,%u\n", fault, status);

	return 0;
}