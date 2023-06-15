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

    int company = 4;
    int device = 0;
    int softversion = 0;
    int bus = 1;
    int index = 1;
    int act = 0;
    int max_time = 30000;
    uint8_t block = 0;
    uint8_t status, fault;

    robot.SetGripperConfig(company, device, softversion, bus);
    sleep(1);
    robot.GetGripperConfig(&company, &device, &softversion, &bus);
    printf("gripper config:%d,%d,%d,%d\n", company, device, softversion, bus);

    robot.ActGripper(index, act);
    sleep(1);
    act = 1;
    robot.ActGripper(index, act);
    sleep(2);

    robot.MoveGripper(index, 100, 50, 50, max_time, block);
    sleep(3);
    robot.MoveGripper(index, 0, 50, 0, max_time, block);

    robot.GetGripperMotionDone(&fault, &status);
    printf("motion status:%u,%u\n", fault, status);

    return 0;
}