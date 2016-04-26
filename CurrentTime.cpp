//
// Created by Josue on 4/25/2016.
//

#include <iostream>
#include "CurrentTime.h"

CurrentTime::CurrentTime() {
    GetSystemTime(&systemTime);
    this->timeInSeconds = time(0);
    this->millisecondsElapsed = systemTime.wMilliseconds;
    this->currentTime = formatSecondsAndMillisIntoTime();
}

void CurrentTime::setTimeInSeconds(double timeInSeconds) {
    this->timeInSeconds = timeInSeconds + 0.00;
}

CurrentTime::CurrentTime(double timeInSeconds, double timeInMilliseconds) {
    this->timeInSeconds = timeInMilliseconds;
    this->millisecondsElapsed = timeInMilliseconds;
}

void CurrentTime::setMilliseconds(double millisecondsElapsed) {
    this->millisecondsElapsed = millisecondsElapsed;
}

double CurrentTime::getSeconds() {
    return this->timeInSeconds;
}

double CurrentTime::getMilliseconds() {
    return this->millisecondsElapsed;
}

double CurrentTime::getTimeElapsed(CurrentTime startTime) {

    std::cout  << std::to_string(startTime.getCurrentTime()) + ", " + std::to_string(this->currentTime) << std::endl;
    return startTime.getCurrentTime() - this->currentTime;
}

double CurrentTime::getCurrentTime() {
    return this->currentTime;
}

double CurrentTime::formatSecondsAndMillisIntoTime() {
    return this->timeInSeconds + (this->millisecondsElapsed / 1000);
}




















