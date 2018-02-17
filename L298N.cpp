/*
  L298N.cpp - Library for L298N motor driver
  Created by Francisco Arcos, 17 Feb 2018
  Released into the public domain.
*/

#include "Arduino.h"
#include "L298N.h"

struct Motor {
  int in1;
  int in2;
  int pwn;
};

Motor motors[2];

L298N::L298N(int ena, int in1, int in2, int in3, int in4, int enb) {
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);

  _motorA = ena;
  _pinA1 = in1;
  _pinA2 = in2;
  _pinB1 = en3;
  _pinB2 = en4;
  _motorB = enb;
}

void L298N::setSpeed(int speed) {
  _speed = speed;
  analogWrite(_motorA, _speed);
  analogWrite(_motorB, _speed);
}

void L298N::forward() {
  digitalWrite(_pinB2, HIGH);
  digitalWrite(_pinB1, LOW);

  digitalWrite(_pinA2, HIGH);
  digitalWrite(_pinA1, LOW);
}

void L298N::turn_right() {
  digitalWrite(_pinB2, HIGH);
  digitalWrite(_pinB1, LOW);

  digitalWrite(_pinA2, LOW);
  digitalWrite(_pinA1, HIGH);
}

void L298N::turn_left() {
  digitalWrite(_pinB2, LOW);
  digitalWrite(_pinB1, HIGH);

  digitalWrite(_pinA2, HIGH);
  digitalWrite(_pinA1, LOW);
}

void L298N::backward() {
  digitalWrite(_pinB2, LOW);
  digitalWrite(_pinB1, HIGH);

  digitalWrite(_pinA2, LOW);
  digitalWrite(_pinA1, HIGH);
}

void L298N::stop() {
  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinA2, LOW);
  digitalWrite(_pinB1, LOW);
  digitalWrite(_pinB2, LOW);
}
