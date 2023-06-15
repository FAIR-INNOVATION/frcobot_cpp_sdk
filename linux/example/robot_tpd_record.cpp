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

    int type = 1;
    char name[30] = "tpd2023";
    int period_ms = 4;
    uint16_t di_choose = 0;
    uint16_t do_choose = 0;

    robot.SetTPDParam(type, name, period_ms, di_choose, do_choose);

    robot.Mode(1);
    sleep(1);
    robot.DragTeachSwitch(1);
    robot.SetTPDStart(type, name, period_ms, di_choose, do_choose);
    sleep(30);
    robot.SetWebTPDStop();
    robot.DragTeachSwitch(0);

    //robot.SetTPDDelete(name);

    return 0;
}