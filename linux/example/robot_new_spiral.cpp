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

    JointPos j;
    DescPose desc_pos, offset_pos1, offset_pos2;
    ExaxisPos  epos;
    SpiralParam sp;

    memset(&j, 0, sizeof(JointPos));
    memset(&desc_pos, 0, sizeof(DescPose));
    memset(&offset_pos1, 0, sizeof(DescPose));
    memset(&offset_pos2, 0, sizeof(DescPose));
    memset(&epos, 0, sizeof(ExaxisPos));
    memset(&sp, 0, sizeof(SpiralParam));

    j = {127.888,-101.535,-94.860,17.836,96.931,-61.325};
    offset_pos1.tran.x = 50.0;
    offset_pos1.rpy.rx = -30.0;
    offset_pos2.tran.x = 50.0;
    offset_pos2.rpy.rx = -5.0;

    sp.circle_num = 5;
    sp.circle_angle = 5.0;
    sp.rad_init = 50.0;
    sp.rad_add = 10.0;
    sp.rotaxis_add = 10.0;
    sp.rot_direction = 0;

    int tool = 0;
    int user = 0;
    float vel = 100.0;
    float acc = 100.0;
    float ovl = 100.0;
    float blendT = 0.0;
    uint8_t flag = 2;

    robot.SetSpeed(20);

    int ret = robot.GetForwardKin(&j, &desc_pos);  //The forward kinematic interface can be used to solve Cartesian space coordinates with only joint positions

    if(ret == 0)
    {
        int err1 = robot.MoveJ(&j, &desc_pos, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos1);
        printf("movej errcode:%d\n", err1);

        int err2 = robot.NewSpiral(&j, &desc_pos, tool, user, vel, acc, &epos, ovl, flag, &offset_pos2, sp);
        printf("newspiral errcode:%d\n", err2);
    }
    else
    {
        printf("GetForwardKin errcode:%d\n", ret);
    }

    return 0;
}