#include "FRRobot.h"
#include <string.h>
#include <windows.h>

int main(void)
{
	FRRobot robot;                 //Instantiate the robot object
	robot.RPC("192.168.58.2");     //Establish a communication connection with the robot controller

	char name[30] = "tpd2023";
	int tool = 0;
	int user = 0;
	float vel = 100.0;
	float acc = 100.0;
	float ovl = 100.0;
	float blendT = -1.0;
	int config = -1;
	uint8_t blend = 1;

	DescPose desc_pose;
	memset(&desc_pose, 0, sizeof(DescPose));

	desc_pose.tran.x = -403.1899;
	desc_pose.tran.y = 351.9440;
	desc_pose.tran.z = 276.6716;
	desc_pose.rpy.rx = 178.4468;
	desc_pose.rpy.ry = 1.0294;
	desc_pose.rpy.rz = 122.3688;

	robot.LoadTPD(name);
	robot.MoveCart(&desc_pose, tool, user, vel, acc, ovl, blendT, config);
	robot.MoveTPD(name, blend, ovl);

	return 0;
}