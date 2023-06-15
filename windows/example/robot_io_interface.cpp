#include "FRRobot.h"
#include <string.h>
#include <windows.h>


int main(void)
{
	FRRobot robot;                 //Instantiate the robot object
	robot.RPC("192.168.58.2");     //Establish a communication connection with the robot controller

	uint8_t status = 1;
	uint8_t smooth = 0;
	uint8_t block = 0;
	uint8_t di = 0, tool_di = 0;
	float ai = 0.0, tool_ai = 0.0;
	float value = 0.0;
	int i;

	for (i = 0; i < 16; i++)
	{
		robot.SetDO(i, status, smooth, block);
		robot.WaitMs(1000);
	}

	status = 0;

	for (i = 0; i < 16; i++)
	{
		robot.SetDO(i, status, smooth, block);
		robot.WaitMs(1000);
	}

	status = 1;

	for (i = 0; i < 2; i++)
	{
		robot.SetToolDO(i, status, smooth, block);
		robot.WaitMs(1000);
	}

	status = 0;

	for (i = 0; i < 2; i++)
	{
		robot.SetToolDO(i, status, smooth, block);
		robot.WaitMs(1000);
	}

	value = 50.0;
	robot.SetAO(0, value, block);
	value = 100.0;
	robot.SetAO(1, value, block);
	robot.WaitMs(1000);
	value = 0.0;
	robot.SetAO(0, value, block);
	value = 0.0;
	robot.SetAO(1, value, block);

	value = 100.0;
	robot.SetToolAO(0, value, block);
	robot.WaitMs(1000);
	value = 0.0;
	robot.SetToolAO(0, value, block);

	robot.GetDI(0, block, &di);
	printf("di0:%u\n", di);
	robot.WaitDI(0, 1, 1000, 1);            
	robot.WaitMultiDI(1, 3, 3, 10000, 1);   
	tool_di = robot.GetToolDI(1, block, &tool_di);
	printf("tool_di1:%u\n", tool_di);
	robot.WaitToolDI(1, 1, 0, 2);         

	robot.GetAI(0, block, &ai);
	printf("ai0:%f\n", ai);
	robot.WaitAI(0, 0, 50, 1000, 1);         
	robot.WaitToolAI(0, 0, 50, 1000, 1);       
	tool_ai = robot.GetToolAI(0, block, &tool_ai);
	printf("tool_ai0:%f\n", tool_ai);

	return 0;
}