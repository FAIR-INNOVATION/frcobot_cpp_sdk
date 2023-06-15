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

    JointPos j1,j2;
    DescPose desc_pos1,desc_pos2,offset_pos,offset_pos1;
    ExaxisPos  epos;

    memset(&j1, 0, sizeof(JointPos));
    memset(&j2, 0, sizeof(JointPos));
    memset(&desc_pos1, 0, sizeof(DescPose));
    memset(&desc_pos2, 0, sizeof(DescPose));
    memset(&offset_pos, 0, sizeof(DescPose));
    memset(&offset_pos1, 0, sizeof(DescPose));
    memset(&epos, 0, sizeof(ExaxisPos));

    j1 = {114.578,-117.798,-97.745,-54.436,90.053,-45.216};
    desc_pos1.tran.x = -140.418;
    desc_pos1.tran.y = 619.351;
    desc_pos1.tran.z = 198.369;
    desc_pos1.rpy.rx = -179.948;
    desc_pos1.rpy.ry = 0.023;
    desc_pos1.rpy.rz = 69.793;

    j2 = {115.401,-105.206,-117.959,-49.727,90.054,-45.222};
    desc_pos2.tran.x = -95.586;
    desc_pos2.tran.y = 504.143;
    desc_pos2.tran.z = 186.880;
    desc_pos2.rpy.rx = 178.001;
    desc_pos2.rpy.ry = 2.091;
    desc_pos2.rpy.rz = 70.585;

    offset_pos1.tran.x = 100.0;
    offset_pos1.tran.y = 100.0;
    offset_pos1.tran.z = 100.0;
    offset_pos1.rpy.rx = 5.0;
    offset_pos1.rpy.ry = 5.0;
    offset_pos1.rpy.rz = 5.0;    

    int tool = 0;
    int user = 0;
    float vel = 100.0;
    float acc = 100.0;
    float ovl = 100.0;
    float blendT = -1.0;
    float blendR = 0.0;
    uint8_t flag = 0;
    int type = 0;

    robot.SetSpeed(20);
    
    robot.MoveJ(&j1, &desc_pos1, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos);
    robot.MoveJ(&j2, &desc_pos2, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos);
    sleep(2);
    robot.PointsOffsetEnable(type, &offset_pos1);
    robot.MoveJ(&j1, &desc_pos1, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos);
    robot.MoveJ(&j2, &desc_pos2, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos);
    robot.PointsOffsetDisable();

    return 0;
}