#include "FRRobot.h"
#include <string.h>
#include <windows.h>


int main(void)
{
    FRRobot robot;                 //Instantiate the robot object
    // robot.RPC("192.168.58.2");     //Establish a communication connection with the robot controller

	robot.SetSpeed(50);   //Set global speed

	robot.StartJOG(0, 1, 0, 20.0, 20.0, 30.0);   //For single-joint motion, StartJOG is a non-blocking command. Receiving other motion commands (including StartJOG) while in motion is discarded
	Sleep(1000);   //unit: ms
	//robot.StopJOG(1)  //Robot single axis point deceleration stop
	robot.ImmStopJOG(); //Robot single axis point immediate stop
	robot.StartJOG(0, 2, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(0, 3, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();
	robot.StartJOG(0, 4, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();  
	robot.StartJOG(0, 5, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(0, 6, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 

    robot.StartJOG(2, 1, 0, 20.0, 20.0, 30.0);   //Point in the base coordinate system
    Sleep(1000);
    //robot.StopJOG(3)  //Robot single axis point deceleration stop
    robot.ImmStopJOG();  //The single axis of the robot stops immediately
    robot.StartJOG(2, 2, 1, 20.0, 20.0, 30.0);
    Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(2, 3, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();
	robot.StartJOG(2, 4, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();  
	robot.StartJOG(2, 5, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(2, 6, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 

    robot.StartJOG(4, 1, 0, 20.0, 20.0, 30.0);   //Point in the tool coordinate system
    Sleep(1000);
    //robot.StopJOG(5)  //Robot single axis point deceleration stop
    robot.ImmStopJOG();  //The single axis of the robot stops immediately
    robot.StartJOG(4, 2, 1, 20.0, 20.0, 30.0);
    Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(4, 3, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();
	robot.StartJOG(4, 4, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();  
	robot.StartJOG(4, 5, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(4, 6, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 

    robot.StartJOG(8, 1, 0, 20.0, 20.0, 30.0);   //Point in the workpiece coordinate system
    Sleep(1000);
    //robot.StopJOG(9)  //Robot single axis point deceleration stop
    robot.ImmStopJOG();  //The single axis of the robot stops immediately
    robot.StartJOG(8, 2, 1, 20.0, 20.0, 30.0);
    Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(8, 3, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();
	robot.StartJOG(8, 4, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG();  
	robot.StartJOG(8, 5, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 
	robot.StartJOG(8, 6, 1, 20.0, 20.0, 30.0);
	Sleep(1000);
    robot.ImmStopJOG(); 

    return 0;
}