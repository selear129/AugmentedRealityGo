#ifndef ARGoController_H
#define ARGoController_H

////////////////////////////////////////////////////////////////////


#include <iostream> // for standard I/O
#include <string>

//opencv
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <opencv2/calib3d/calib3d.hpp>

#include <boost/thread.hpp>

#include "ARGraphicController.h"
#include "GamePlayUtils/GoBoard.h"
#include "GamePlayUtils/GoAssistantController.h"

#include "HelperClass/config.h"
#include "HelperClass/Helper.h"
/**
	Main Controller: control the game state, methods switch for ar graphics/vision and assistance. Talk with external programs
*/

class ARGoController
{
public:
	ARGoController(Config* c);
	~ARGoController();

	//The main loop of this app. It spawns the threads to run openGL and goAssistance then it enters a loop to read
	//GTP commands from stdin/stdout
	void startAR();
  
private:

	//thread running openGL and openCV
	ARGraphicController graphic_controller;
	boost::thread* graphic_handler;

	//thread running Assistant controller
	GoAssistantController assistant_controller;
	boost::thread* assistant_handler;

	//board state 
	static GoBoard board;
	static Config* config;
};
	
#endif