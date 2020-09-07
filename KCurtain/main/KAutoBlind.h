// file: KAutoBlind.h

#ifndef _NEWCLASS_h
#define _NEWCLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#pragma once

#define IN1 3
#define IN2 4
#define EN1 2
#define SWUP 7
#define SWDOWN 8
#define SWFUNCTION 10
#define SENSOROPEN 11
#define SENSORCLOSE 12
#define LED 9
#define MAXSPD a255
#define ACC 1
#define SSID "sugarmanwork1"
#define PASS "sugarmanwork_1"

enum enumOperationState
{
    INITIAL,
    STOP,
    OPENNING,
    OPENED,
    CLOSEING,
    CLOSED,
    ERROR
};

class KAutoBlind
{
public:
    bool swFunctionPushed = false;
    bool swUpPushed = false;
    bool swDownPushed = false;
    bool ledState = false;
    enumOperationState operationState;

    unsigned long swFunctionPushedTime;
    unsigned long swUpPushedTime;
    unsigned long swDownPushedTime;
    unsigned long ledOnTime;
    unsigned long ledOffTime;
    unsigned long LONGPUSHTIME = 10000;
    unsigned long LEDBLINKTIME = 1000;

    char ssid[] = "SK_WiFiGIGAC266"; // your network SSID (name)
    char pass[] = "1905000676";      // your network password
    int curspd = 0;

public:
    KAutoBlind();

    int ReadSwitch();
    int ConnectToServer();
    void ChangeOperateState();
    void LEDOn();
    void LEDOff();
    void LEDBlink();
    int CW();
    int CCW();
    int ManualOpen();
    int ManualClose();
    bool IsOpened();
    bool IsClosed();
    int OpenBlind();
    int CloseBlind();
    int StopBlind();
    bool IsSWUpPushed();
    bool IsSWDownPushed();
    bool IsSWFunctionPushed();
    bool IsSWFunctionLongPushed();

protected:
};

extern KAutoBlind Blind;

#endif