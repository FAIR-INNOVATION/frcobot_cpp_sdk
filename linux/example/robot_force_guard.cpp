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

    uint8_t flag = 1;
    uint8_t sensor_id = 1;
    uint8_t select[6] = {1,1,1,1,1,1};
    float max_threshold[6] = {10.0,10.0,10.0,10.0,10.0,10.0};
    float min_threshold[6] = {5.0,5.0,5.0,5.0,5.0,5.0};

    ForceTorque ft;
    DescPose desc_p1, desc_p2, desc_p3;
    memset(&ft, 0, sizeof(ForceTorque));
    memset(&desc_p1, 0, sizeof(DescPose));
    memset(&desc_p2, 0, sizeof(DescPose));
    memset(&desc_p3, 0, sizeof(DescPose));

    desc_p1.tran.x = -160.619;
    desc_p1.tran.y = -586.138;
    desc_p1.tran.z = 384.988;
    desc_p1.rpy.rx = -170.166;
    desc_p1.rpy.ry = -44.782;
    desc_p1.rpy.rz = 169.295;

    desc_p2.tran.x = -87.615;
    desc_p2.tran.y = -606.209;
    desc_p2.tran.z = 556.119;
    desc_p2.rpy.rx = -102.495;
    desc_p2.rpy.ry = 10.118;
    desc_p2.rpy.rz = 178.985;

    desc_p3.tran.x = 41.479;
    desc_p3.tran.y = -557.243;
    desc_p3.tran.z = 484.407;
    desc_p3.rpy.rx = -125.174;
    desc_p3.rpy.ry = 46.995;
    desc_p3.rpy.rz = -132.165;

    robot.FT_Guard(flag, sensor_id, select, &ft, max_threshold, min_threshold);
    robot.MoveCart(&desc_p1,9,0,100.0,100.0,100.0,-1.0,-1);
    robot.MoveCart(&desc_p2,9,0,100.0,100.0,100.0,-1.0,-1);
    robot.MoveCart(&desc_p3,9,0,100.0,100.0,100.0,-1.0,-1);
    flag = 0;
    robot.FT_Guard(flag, sensor_id, select, &ft, max_threshold, min_threshold);

    return 0;
}