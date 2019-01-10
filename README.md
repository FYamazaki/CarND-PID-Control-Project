# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Introduction
The simulator will provide you the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.  We implement a PID controller in C++ for the car to go around the track safely!

## Implementation
1. I set parameters Kp=0.1, Ki=0.0, and Kd=9.0 (main.cpp:line 39).
2. I added 2 methods called GetSteering (PID.cpp:line 49) and GetThrottle (PID.cpp:line 60) in PID class to rerutn steering angle and throttle.
3. This is a final result.
[![PID Control](https://github.com/FYamazaki/CarND-PID-Control-Project/blob/master/PID_Control.PNG?raw=true)](https://github.com/FYamazaki/CarND-PID-Control-Project/blob/master/PID_Control.mp4?raw=true)

## Reflection

1. In order to tune Kp, Ki, and Kd, I tried to use Twiddle at first.  But it didn't work well, because the car pop up onto ledges even after tuning by twiddle.  So I decided to tune manually.  At first, I started Kp=0, Ki=0, Kd=0, then I the car goes to right.  I increased or decreased only Kp first, and I chose Kp=0.1 because it looks going straight.  But it started oscillating later.  Then I tuned Kd without changing Kp.  If I increase Kd too much, the steering angle change too quickly.  But if I decrease Kd too much, the car cannot turn a sharp turn.  The final parameters are Kp=0.1, Ki=0.0, and Kd=9.0 (main.cpp:line 39).  With this parameter, the car can go around the track barely.
2. If I increase throttle, the car sometimes go off the track.  So I decided to change the throttle depending on the steering angle (PID.cpp:Line 63).  This reduce the throttle when the steering angle increase.  This only helped a little bit.

## Discussion
I think that twiddle still works in this project, but twiddle has to be able to start and stop the car.  That means we need to adjust twiddle in this paradigm.  I thought that I did, but it didn't work to me.  I would like to know how other student implemented twiddle in this project.  Also I am not still sure how we can run smoothly with high throttle?  There is a trade off between throttle and Kd.  If I increase the throttle, that car cannot turn at sharp turn.  But if I increase the Kd, it oscillates a lot.