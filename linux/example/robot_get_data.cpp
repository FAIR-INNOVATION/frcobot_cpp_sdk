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

    float yangle, zangle;
    int flag = 0;
    JointPos j_deg, j_rad;
    DescPose tcp, flange, tcp_offset, wobj_offset;
    DescTran cog;
    int id;
    float torques[6] = {0.0};
    float weight;
    float neg_deg[6]={0.0},pos_deg[6]={0.0};
    float t_ms;
    int config;
    float vel;

    memset(&j_deg, 0, sizeof(JointPos));
    memset(&j_rad, 0, sizeof(JointPos));
    memset(&tcp, 0, sizeof(DescPose));
    memset(&flange, 0, sizeof(DescPose));
    memset(&tcp_offset, 0, sizeof(DescPose));
    memset(&wobj_offset, 0, sizeof(DescPose));
    memset(&cog, 0, sizeof(DescTran));

    robot.GetRobotInstallAngle(&yangle, &zangle);
    printf("yangle:%f,zangle:%f\n", yangle, zangle);

    robot.GetActualJointPosDegree(flag, &j_deg);
    printf("joint pos deg:%f,%f,%f,%f,%f,%f\n", j_deg.jPos[0],j_deg.jPos[1],j_deg.jPos[2],j_deg.jPos[3],j_deg.jPos[4],j_deg.jPos[5]);

    robot.GetActualJointPosRadian(flag, &j_rad);
    printf("joint pos rad:%f,%f,%f,%f,%f,%f\n", j_rad.jPos[0],j_rad.jPos[1],j_rad.jPos[2],j_rad.jPos[3],j_rad.jPos[4],j_rad.jPos[5]);   

    robot.GetActualTCPPose(flag, &tcp);
    printf("tcp pose:%f,%f,%f,%f,%f,%f\n", tcp.tran.x, tcp.tran.y, tcp.tran.z, tcp.rpy.rx, tcp.rpy.ry, tcp.rpy.rz); 

    robot.GetActualToolFlangePose(flag, &flange);
    printf("flange pose:%f,%f,%f,%f,%f,%f\n", flange.tran.x, flange.tran.y, flange.tran.z, flange.rpy.rx, flange.rpy.ry, flange.rpy.rz); 

    robot.GetActualTCPNum(flag, &id);
    printf("tcp num:%d\n", id);

    robot.GetActualWObjNum(flag, &id);
    printf("wobj num:%d\n", id);  

    robot.GetJointTorques(flag, torques);
    printf("torques:%f,%f,%f,%f,%f,%f\n", torques[0],torques[1],torques[2],torques[3],torques[4],torques[5]); 

    robot.GetTargetPayload(flag, &weight);
    printf("payload weight:%f\n", weight);

    robot.GetTargetPayloadCog(flag, &cog);
    printf("payload cog:%f,%f,%f\n",cog.x, cog.y, cog.z);

    robot.GetTCPOffset(flag, &tcp_offset);
    printf("tcp offset:%f,%f,%f,%f,%f,%f\n", tcp_offset.tran.x,tcp_offset.tran.y,tcp_offset.tran.z,tcp_offset.rpy.rx,tcp_offset.rpy.ry,tcp_offset.rpy.rz);

    robot.GetWObjOffset(flag, &wobj_offset);
    printf("wobj offset:%f,%f,%f,%f,%f,%f\n", wobj_offset.tran.x,wobj_offset.tran.y,wobj_offset.tran.z,wobj_offset.rpy.rx,wobj_offset.rpy.ry,wobj_offset.rpy.rz);

    robot.GetJointSoftLimitDeg(flag, neg_deg, pos_deg);
    printf("neg limit deg:%f,%f,%f,%f,%f,%f\n",neg_deg[0],neg_deg[1],neg_deg[2],neg_deg[3],neg_deg[4],neg_deg[5]);
    printf("pos limit deg:%f,%f,%f,%f,%f,%f\n",pos_deg[0],pos_deg[1],pos_deg[2],pos_deg[3],pos_deg[4],pos_deg[5]);

    robot.GetSystemClock(&t_ms);
    printf("system clock:%f\n", t_ms);

    robot.GetRobotCurJointsConfig(&config);
    printf("joint config:%d\n", config);

    robot.GetDefaultTransVel(&vel);
    printf("trans vel:%f\n", vel);

    return 0;
}