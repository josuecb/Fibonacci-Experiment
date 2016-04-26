//
// Created by Josue on 4/25/2016.
//

#ifndef CURRENTTIME_H
#define CURRENTTIME_H


#include <windows.h>
#include <time.h>

class CurrentTime {
private:
    double currentTime;
    double timeInSeconds, millisecondsElapsed;
    SYSTEMTIME systemTime;
    double formatSecondsAndMillisIntoTime();
public:
    CurrentTime(double, double);
    CurrentTime();
    void setTimeInSeconds(double);
    void setMilliseconds(double);
    double getSeconds();
    double getMilliseconds();
    double getTimeElapsed(CurrentTime);
    double getCurrentTime();
};


#endif //MAC281_CURRENTTIME_H