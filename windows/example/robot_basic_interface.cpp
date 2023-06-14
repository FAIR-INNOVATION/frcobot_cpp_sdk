#include "FRRobot.h"
#include <string.h>
#include <windows.h>


int main(void)
{
	FRRobot robot;                 //实例化机器人对象
	robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

	char ip[64] = "";
	char version[64] = "";
	uint8_t state;

	robot.GetSDKVersion(version);
	printf("SDK version:%s\n", version);
	robot.GetControllerIP(ip);
	printf("controller ip:%s\n", ip);

	robot.Mode(1);
	Sleep(1000);   //单位ms
	robot.DragTeachSwitch(1);
	robot.IsInDragTeach(&state);
	printf("drag state :%u\n", state);
	Sleep(3000);
	robot.DragTeachSwitch(0);
	Sleep(1000);
	robot.IsInDragTeach(&state);
	printf("drag state :%u\n", state);
	Sleep(3000);

	robot.RobotEnable(0);
	Sleep(3000);
	robot.RobotEnable(1);

	robot.Mode(0);
	Sleep(1000);
	robot.Mode(1);

	return 0;
}