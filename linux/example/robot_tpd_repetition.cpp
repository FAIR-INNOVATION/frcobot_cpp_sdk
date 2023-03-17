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

    char name[30] = "tpd2023";
    int tool = 1;
    int user = 0;
    float vel = 100.0;
    float acc = 100.0;
    float ovl = 100.0;
    float blendT = -1.0;
    int config = -1;
    uint8_t blend = 1;

    DescPose desc_pose;
    memset(&desc_pose, 0, sizeof(DescPose));   

    desc_pose.tran.x = -378.9;
    desc_pose.tran.y = -340.3;
    desc_pose.tran.z = 107.2;
    desc_pose.rpy.rx = 179.4;
    desc_pose.rpy.ry = -1.3;
    desc_pose.rpy.rz = 125.0;

    robot.LoadTPD(name);
    robot.MoveCart(&desc_pose, tool, user, vel, acc, ovl, blendT, config);
    robot.MoveTPD(name, blend, ovl);

    return 0;
}