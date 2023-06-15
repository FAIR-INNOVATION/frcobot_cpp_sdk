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

    int i;
    float value;
    int id;
    int type;
    int install;

    DescTran coord;
    DescPose t_coord, etcp, etool, w_coord;
    memset(&coord, 0, sizeof(DescTran));
    memset(&t_coord, 0, sizeof(DescPose));
    memset(&etcp, 0, sizeof(DescPose));
    memset(&etool, 0, sizeof(DescPose));
    memset(&w_coord, 0, sizeof(DescPose));

    robot.SetSpeed(20);

    for(i = 1; i < 21; i++)
    {
        robot.SetSysVarValue(i, i+0.5);
        robot.WaitMs(1000);
    }

    for(i = 1; i < 21; i++)
    {
        robot.GetSysVarValue(i, &value);
        printf("sys value:%f\n", value);
    }

    robot.SetLoadWeight(2.5);

    coord.x = 3.0;
    coord.y = 4.0;
    coord.z = 5.0;

    robot.SetLoadCoord(&coord);

    id = 10;
    t_coord.tran.x = 1.0;
    t_coord.tran.y = 2.0;
    t_coord.tran.z = 3.0;
    t_coord.rpy.rx = 4.0;
    t_coord.rpy.ry = 5.0;
    t_coord.rpy.rz = 6.0;
    type = 0;
    install = 0;
    robot.SetToolCoord(id, &t_coord, type, install);
    robot.SetToolList(id, &t_coord, type, install);

    etcp.tran.x = 1.0;
    etcp.tran.y = 2.0;
    etcp.tran.z = 3.0;
    etcp.rpy.rx = 4.0;
    etcp.rpy.ry = 5.0;
    etcp.rpy.rz = 6.0;
    etool.tran.x = 11.0;
    etool.tran.y = 22.0;
    etool.tran.z = 33.0;
    etool.rpy.rx = 44.0;
    etool.rpy.ry = 55.0;
    etool.rpy.rz = 66.0;
    id = 11;
    robot.SetExToolCoord(id, &etcp, &etool);
    robot.SetExToolList(id, &etcp, &etool);

    w_coord.tran.x = 11.0;
    w_coord.tran.y = 12.0;
    w_coord.tran.z = 13.0;
    w_coord.rpy.rx = 14.0;
    w_coord.rpy.ry = 15.0;
    w_coord.rpy.rz = 16.0;   
    id = 12;
    robot.SetWObjCoord(id, &w_coord);
    robot.SetWObjList(id, &w_coord);

    robot.SetRobotInstallPos(0);
    robot.SetRobotInstallAngle(15.0,25.0);

    return 0;
}