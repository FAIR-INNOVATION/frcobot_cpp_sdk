#include "FRRobot.h"
#include <string.h>
#include <windows.h>

int main(void)
{
	FRRobot robot;                 //实例化机器人对象
	robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

	int i;
	float value;
	int tool_id, etool_id, user_id;
	int type;
	int install;

	DescTran coord;
	DescPose t_coord, etcp, etool, w_coord;
	memset(&coord, 0, sizeof(DescTran));
	memset(&t_coord, 0, sizeof(DescPose));
	memset(&etcp, 0, sizeof(DescPose));
	memset(&etool, 0, sizeof(DescPose));
	memset(&w_coord, 0, sizeof(DescPose));

	robot.SetSpeed(20);

	for (i = 1; i < 21; i++)
	{
		robot.SetSysVarValue(i, i + 0.5);
		Sleep(10);  //单位ms
	}

	for (i = 1; i < 21; i++)
	{
		robot.GetSysVarValue(i, &value);
		printf("sys value:%f\n", value);
	}

	robot.SetLoadWeight(0.1);

	coord.x = 0.1;
	coord.y = 0.1;
	coord.z = 0.1;

	robot.SetLoadCoord(&coord);

	tool_id = 10;
	t_coord.tran.x = 1.0;
	t_coord.tran.y = 2.0;
	t_coord.tran.z = 3.0;
	t_coord.rpy.rx = 4.0;
	t_coord.rpy.ry = 5.0;
	t_coord.rpy.rz = 6.0;
	type = 0;
	install = 0;
	int ret = robot.SetToolCoord(tool_id, &t_coord, type, install);
	printf("ret = %d\n", ret);
	ret = robot.SetToolList(tool_id, &t_coord, type, install);
	printf("ret = %d\n", ret);


	//robot.SetExToolCoord(tool_id, &etcp, &etool);
	//robot.SetExToolList(tool_id, &etcp, &etool);

	w_coord.tran.x = 11.0;
	w_coord.tran.y = 12.0;
	w_coord.tran.z = 13.0;
	w_coord.rpy.rx = 14.0;
	w_coord.rpy.ry = 15.0;
	w_coord.rpy.rz = 16.0;
	user_id = 12;
	robot.SetWObjCoord(user_id, &w_coord);
	robot.SetWObjList(user_id, &w_coord);

	robot.SetRobotInstallPos(0);
	robot.SetRobotInstallAngle(0.0, 0.0);

	return 0;
}