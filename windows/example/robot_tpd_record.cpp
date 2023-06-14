#include "FRRobot.h"
#include <string.h>
#include <windows.h>

//注意：运行此程序前，请确认末端负载是否配置正确以及能否切入拖动示教模式
int main(void)
{
	FRRobot robot;                 //实例化机器人对象
	robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

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