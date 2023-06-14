#include "FRRobot.h"
#include <string.h>


int main(void)
{
	FRRobot robot;                 //实例化机器人对象
	robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

	JointPos j;

	memset(&j, 0, sizeof(JointPos));

	float vel = 0.0;
	float acc = 0.0;
	float cmdT = 0.004;
	float filterT = 0.0;
	float gain = 0.0;
	uint8_t flag = 1;
	int count = 1000;
	double dt = 0.1;

	int ret = robot.GetActualJointPosDegree(flag, &j);
	if (ret == 0)
	{
		while (count)
		{
			int ret = robot.ServoJ(&j, acc, vel, cmdT, filterT, gain);
			j.jPos[0] += dt;
			count -= 1;
		}
	}
	else
	{
		printf("GetActualJointPosDegree errcode:%d\n", ret);
	}
	return 0;
}