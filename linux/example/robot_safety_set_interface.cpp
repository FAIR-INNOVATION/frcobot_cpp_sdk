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

    int mode = 0;
    int config = 1;
    float level1[6] = {1.0,2.0,3.0,4.0,5.0,6.0};
    float level2[6] = {50.0,20.0,30.0,40.0,50.0,60.0};

    robot.SetAnticollision(mode, level1, config);
    mode = 1;
    robot.SetAnticollision(mode, level2, config);
    robot.SetCollisionStrategy(1);

    float plimit[6] = {170.0,80.0,150.0,80.0,170.0,160.0};
    robot.SetLimitPositive(plimit);
    float nlimit[6] = {-170.0,-260.0,-150.0,-260.0,-170.0,-160.0};
    robot.SetLimitNegative(nlimit);

    robot.ResetAllError();

    float lcoeff[6] = {0.9,0.9,0.9,0.9,0.9,0.9};
    float wcoeff[6] = {0.4,0.4,0.4,0.4,0.4,0.4};
    float ccoeff[6] = {0.6,0.6,0.6,0.6,0.6,0.6};
    float fcoeff[6] = {0.5,0.5,0.5,0.5,0.5,0.5};
    robot.FrictionCompensationOnOff(1);
    robot.SetFrictionValue_level(lcoeff);
    robot.SetFrictionValue_wall(wcoeff);
    robot.SetFrictionValue_ceiling(ccoeff);
    robot.SetFrictionValue_freedom(fcoeff);

    return 0;
}