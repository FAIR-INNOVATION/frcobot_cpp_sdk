#include "FRRobot.h"
#include <string.h>
#include <windows.h>

//Note: Before running this program, please confirm that the end load is configured correctly and can switch to drag teach-in mode
int main(void)
{
	FRRobot robot;                 //Instantiate the robot object
	robot.RPC("192.168.58.2");     //Establish a communication connection with the robot controller

	int type = 1;
	char name[30] = "tpd2023";
	int period_ms = 4;
	uint16_t di_choose = 0;
	uint16_t do_choose = 0;

	robot.SetTPDParam(type, name, period_ms, di_choose, do_choose);

	robot.Mode(1);
	Sleep(1000);
	robot.DragTeachSwitch(1);
	robot.SetTPDStart(type, name, period_ms, di_choose, do_choose);
	Sleep(30000);
	robot.SetWebTPDStop();
	robot.DragTeachSwitch(0);

	//robot.SetTPDDelete(name);

	return 0;
}