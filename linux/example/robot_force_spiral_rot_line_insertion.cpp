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

    //Constant force parameter
    uint8_t status = 1;  //Constant force control open sign, 0- off, 1- on
    int sensor_num = 1; //Force sensor number
    float gain[6] = {0.0001,0.0,0.0,0.0,0.0,0.0};  //Maximum threshold
    uint8_t adj_sign = 0;  //Adaptive start-stop state, 0- off, 1- on
    uint8_t ILC_sign = 0;  //ILC control start stop state, 0- stop, 1- training, 2- real operation
    float max_dis = 100.0;  //Maximum adjustment distance
    float max_ang = 5.0;  //Maximum adjustment Angle

    ForceTorque ft;
    memset(&ft, 0, sizeof(ForceTorque));

    //Helix explore parameters
    int rcs = 0;  //Reference frame, 0- tool frame, 1- base frame
    float dr = 0.7;  //Radius feed per turn, unit: mm
    float fFinish = 1.0; //Force or torque threshold (0 to 100), unit: N or Nm
    float t = 60000.0; //Maximum exploration time, unit: ms
    float vmax = 5.0; //The maximum linear velocity, unit: mm/s

    //Linear insertion parameter
    float force_goal = 50.0;  //Force or torque threshold (0 to 100), unit: N or Nm
    float lin_v = 3.0; //Linear velocity, unit: mm/s
    float lin_a = 0.0; //Linear acceleration, unit: mm/s^2, not used yet
    float disMax = 100.0; //Maximum insertion distance, in mm
    uint8_t linorn = 1; //Insert direction, 1- positive, 2- negative

    //Rotational insertion parameter
    float angVelRot = 2.0;  //Angular velocity of rotation, in °/s
    float forceInsertion = 1.0; //Force or torque threshold (0 to 100), in N or Nm
    int angleMax= 45; //Maximum rotation Angle, unit: °
    uint8_t orn = 1; //Direction of force，1-fz,2-mz
    float angAccmax = 0.0; //Maximum angular acceleration of rotation, unit: °/s^2, not in use
    uint8_t rotorn = 2; //Rotation direction, 1- clockwise, 2- counterclockwise

    uint8_t select0[6] = {1,1,1,0,0,0};  //Six degrees of freedom options [fx,fy,fz,mx,my,mz], 0- does not work, 1- works
    gain[0] = 0.0001;
    ft.fz = -20.0;
    status = 1;
    robot.FT_Control(status,sensor_num,select0,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);
    robot.FT_LinInsertion(rcs,force_goal,lin_v,lin_a,disMax,linorn);
    status = 0;
    robot.FT_Control(status,sensor_num,select0,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);

    uint8_t select1[6] = {1,1,1,0,0,0}; //Six degrees of freedom options [fx,fy,fz,mx,my,mz], 0- does not work, 1- works
    ft.fz = -10.0;
    robot.FT_Control(status,sensor_num,select1,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);
    robot.FT_SpiralSearch(rcs,dr,fFinish,t,vmax);
    status = 0;
    robot.FT_Control(status,sensor_num,select1,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);

    uint8_t select2[6] = {1,1,1,0,0,0};  //Six degrees of freedom options [fx,fy,fz,mx,my,mz], 0- does not work, 1- works
    gain[0] = 0.00005;
    ft.fz = -30.0;
    status = 1;
    robot.FT_Control(status,sensor_num,select2,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);
    robot.FT_LinInsertion(rcs,force_goal,lin_v,lin_a,disMax,linorn);
    status = 0;
    robot.FT_Control(status,sensor_num,select2,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);

    uint8_t select3[6] = {0,0,1,1,1,0};  //Six degrees of freedom options [fx,fy,fz,mx,my,mz], 0- does not work, 1- works
    ft.fz = -10.0;
    gain[0] = 0.0001;
    status = 1;
    robot.FT_Control(status,sensor_num,select3,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);
    robot.FT_RotInsertion(rcs,angVelRot,forceInsertion,angleMax,orn,angAccmax,rotorn);
    status = 0;
    robot.FT_Control(status,sensor_num,select3,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);

    uint8_t select4[6] = {1,1,1,0,0,0};  //Six degrees of freedom options [fx,fy,fz,mx,my,mz], 0- does not work, 1- works
    ft.fz = -30.0;
    status = 1;
    robot.FT_Control(status,sensor_num,select4,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);
    robot.FT_LinInsertion(rcs,force_goal,lin_v,lin_a,disMax,linorn);
    status = 0;
    robot.FT_Control(status,sensor_num,select4,&ft,gain,adj_sign,ILC_sign,max_dis,max_ang);

    return 0;
}