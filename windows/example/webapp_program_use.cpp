#include "FRRobot.h"
#include <string.h>
#include <windows.h>


int main(void)
{
	FRRobot robot;                 //实例化机器人对象
	robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

	char program_name[64] = "/fruser/pptest.lua";
	char loaded_name[64] = "";
	uint8_t state;
	int line;

	robot.Mode(0);
	robot.ProgramLoad(program_name);
	robot.ProgramRun();
	Sleep(3000);     //单位ms
	robot.ProgramPause();
	robot.GetProgramState(&state);
	printf("program state:%u\n", state);
	robot.GetCurrentLine(&line);
	printf("current line:%d\n", line);
	robot.GetLoadedProgram(loaded_name);
	printf("program name:%s\n", loaded_name);
	Sleep(5000);
	robot.ProgramResume();
	Sleep(5000);
	robot.ProgramStop();
	Sleep(2000);

	return 0;
}