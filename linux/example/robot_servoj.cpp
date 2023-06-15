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

    memset(&j, 0, sizeof(JointPos));

    float vel = 0.0;
    float acc = 0.0;
    float cmdT = 0.008;
    float filterT = 0.0;
    float gain = 0.0;
    uint8_t flag = 0;
    int count = 500;
    float dt = 0.1;

    int ret = robot.GetActualJointPosDegree(flag, &j);
    if(ret == 0)
    {
        while (count)
        {
            robot.ServoJ(&j, acc, vel, cmdT, filterT, gain);
            j.jPos[0] += dt;
            count -= 1;
            robot.WaitMs(cmdT*1000);
        }
    }
    else
    {
        printf("GetActualJointPosDegree errcode:%d\n", ret);
    }

    return 0;
}