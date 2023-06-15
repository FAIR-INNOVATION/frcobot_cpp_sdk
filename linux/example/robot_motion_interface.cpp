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

    JointPos j1,j2,j3,j4;
    DescPose desc_pos1,desc_pos2,desc_pos3,desc_pos4,offset_pos;
    ExaxisPos  epos;

    memset(&j1, 0, sizeof(JointPos));
    memset(&j2, 0, sizeof(JointPos));
    memset(&j3, 0, sizeof(JointPos));
    memset(&j4, 0, sizeof(JointPos));
    memset(&desc_pos1, 0, sizeof(DescPose));
    memset(&desc_pos2, 0, sizeof(DescPose));
    memset(&desc_pos3, 0, sizeof(DescPose));
    memset(&desc_pos4, 0, sizeof(DescPose));
    memset(&offset_pos, 0, sizeof(DescPose));
    memset(&epos, 0, sizeof(ExaxisPos));

    j1 = {114.578,-117.798,-97.745,-54.436,90.053,-45.216};
    desc_pos1.tran.x = -140.418;
    desc_pos1.tran.y = 619.351;
    desc_pos1.tran.z = 198.369;
    desc_pos1.rpy.rx = -179.948;
    desc_pos1.rpy.ry = 0.023;
    desc_pos1.rpy.rz = 69.793;

    j2 = {121.381,-97.108,-123.768,-45.824,89.877,-47.296};
    desc_pos2.tran.x = -127.772;
    desc_pos2.tran.y = 459.534;
    desc_pos2.tran.z = 221.274;
    desc_pos2.rpy.rx = -177.850;
    desc_pos2.rpy.ry = -2.507;
    desc_pos2.rpy.rz = 78.627;

    j3 = {138.884,-114.522,-103.933,-49.694,90.688,-47.291};
    desc_pos3.tran.x = -360.468;
    desc_pos3.tran.y = 485.600;
    desc_pos3.tran.z = 196.363;
    desc_pos3.rpy.rx = -178.239;
    desc_pos3.rpy.ry = -0.893;
    desc_pos3.rpy.rz = 96.172;

    j4 = {159.164,-96.105,-128.653,-41.170,90.704,-47.290};
    desc_pos4.tran.x = -360.303;
    desc_pos4.tran.y = 274.911;
    desc_pos4.tran.z = 203.968;
    desc_pos4.rpy.rx = -176.720;
    desc_pos4.rpy.ry = -2.514;
    desc_pos4.rpy.rz = 116.407;   

    int tool = 0;
    int user = 0;
    float vel = 100.0;
    float acc = 100.0;
    float ovl = 100.0;
    float blendT = 0.0;
    float blendR = 0.0;
    uint8_t flag = 0;
    uint8_t search = 0;

    robot.SetSpeed(20);
    
    int err1 = robot.MoveJ(&j1, &desc_pos1, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos);
    printf("movej errcode:%d\n", err1);

    int err2 = robot.MoveL(&j2, &desc_pos2, tool, user, vel, acc, ovl, blendR, &epos,search,flag, &offset_pos);
    printf("movel errcode:%d\n", err2);   

    int err3 = robot.MoveC(&j3,&desc_pos3,tool,user,vel,acc,&epos,flag,&offset_pos,&j4,&desc_pos4,tool,user,vel,acc,&epos,flag,&offset_pos,ovl,blendR);
    printf("movec errcode:%d\n", err3); 

    int err4 = robot.MoveJ(&j2, &desc_pos2, tool, user, vel, acc, ovl, &epos, blendT,flag, &offset_pos);
    printf("movej errcode:%d\n", err4);

    int err5 = robot.Circle(&j3,&desc_pos3,tool,user,vel,acc,&epos,&j4,&desc_pos4,tool,user,vel,acc,&epos,ovl,flag,&offset_pos);
    printf("circle errcode:%d\n", err5);
    
    return 0;
}