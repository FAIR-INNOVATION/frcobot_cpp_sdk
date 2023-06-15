#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>

#include "FRRobot.h"
#include "RobotTypes.h"

using namespace std;

int main(void)
{
    FRRobot robot;                 //Instantiate the robot object
    robot.RPC("192.168.58.2");     //Establish a communication connection with the robot controller

    char program_name[64] = "/fruser/ptps.lua";
    char loaded_name[64] = "";
    uint8_t state;
    int line;

    robot.Mode(0);
    robot.ProgramLoad(program_name);
    robot.ProgramRun();
    sleep(5);
    robot.ProgramPause();
    robot.GetProgramState(&state);
    printf("program state:%u\n", state);
    robot.GetCurrentLine(&line);
    printf("current line:%d\n", line);
    robot.GetLoadedProgram(loaded_name);
    printf("program name:%s\n", loaded_name);
    sleep(5);
    robot.ProgramResume();
    sleep(5);
    robot.ProgramStop();
    sleep(2);

    return 0;
}