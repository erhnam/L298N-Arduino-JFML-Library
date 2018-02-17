/*
  L298N.h - Library for L298N motor driver
  Created by Francisco Arcos, 17 Feb 2018
  Released into the public domain.
*/

#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N{

  public:
    L298N(int ena, int in1, int in2, int in3, int in4, int enb);
    void setSpeed(int speed);
    void forward();
    void stop();
    void turn_right();
    void turn_left();
    void backward();

  private:
    int _speed;
    int _motorA, _pinA1, _pinA2;
    int _motorB, _pinB1, _pinB2;
};

#endif