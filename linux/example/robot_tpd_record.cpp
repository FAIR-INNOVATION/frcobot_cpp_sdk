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
    FRRobot robot;                 //实例化机器人对象
    robot.RPC("192.168.58.2");     //与机器人控制器建立通信连接

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