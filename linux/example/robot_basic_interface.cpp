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

    char ip[64]="";
    char version[64] = "";
    uint8_t state;

    robot.GetSDKVersion(version);
    printf("SDK version:%s\n", version);
    robot.GetControllerIP(ip);
    printf("controller ip:%s\n", ip);

    robot.Mode(1);
    sleep(1);
    robot.DragTeachSwitch(1);
    robot.IsInDragTeach(&state);
    printf("drag state :%u\n", state);
    sleep(3);
    robot.DragTeachSwitch(0);
    sleep(1);
    robot.IsInDragTeach(&state);
    printf("drag state :%u\n", state);
    sleep(3);

    robot.RobotEnable(0);
    sleep(3);
    robot.RobotEnable(1);

    robot.Mode(0);
    sleep(1);
    robot.Mode(1);
    
    return 0;
}