//
//  LEXMKDiatonicFunction.c
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT
//

#include "LEXMKDiatonicFunction.h"

const LEXMKDiatonicFunction LEXMKDiatonicFunctionNull = {0, 0, 0, 0, 0, 0};

LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithMode(LEXMKMode mode)
{
    LEXMKDiatonicFunction func;
    switch (mode) {
        case LEXMKModeMajorNatural:
            // T T H T T T H
            func = LEXMKDFuncMake(2,2,1,2,2,2,1);
            break;
        case LEXMKModeMinorHarmonic:
            func = LEXMKDFuncMake(2,1,2,2,1,3,1);
            break;
        case LEXMKModeMinorMelodic:
            func = LEXMKDFuncMake(2,1,2,2,2,2,1);
            break;
        case LEXMKModeMinorNatural:
            func = LEXMKDFuncMake(2, 1, 2, 2, 1, 2, 2);
            break;
        default:
            func = LEXMKDiatonicFunctionNull;
            break;
    }
    return func;
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithIntervals(int i1,
                                                               int i2,
                                                               int i3,
                                                               int i4,
                                                               int i5,
                                                               int i6,
                                                               int i7)
{
    int intervals[7] = {i1, i2, i3 , i4, i5, i6, i7};
    return LEXMKDiatonicFunctionMakeWithIntervalVector(intervals);
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithIntervalVector(const int * intervals)
{
    LEXMKDiatonicFunction func;
    for (int i = 0; i <=7; i++) {
        func.intervals[i] = intervals[i];
    }
    return func;
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithUncompletedIntervals(int i1,
                                                                          int i2,
                                                                          int i3,
                                                                          int i4,
                                                                          int i5,
                                                                          int i6)
{
    int intervals [6] = {i1, i2, i3 , i4, i5, i6};
    return LEXMKDiatonicFunctionMakeWithUncompletedIntervalVector(intervals);
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithUncompletedIntervalVector(const int * intervals)
{
    int sum = 0;
    int interval = 0;
    LEXMKDiatonicFunction func;
    for (int i = 0; i < 6; i ++) {
        interval = intervals[i];
        sum += interval;
        if (sum >= 12) {
            return LEXMKDiatonicFunctionNull;
        }
        func.intervals[i] = interval;
    }
    interval = 12 - sum;
    func.intervals[6] = interval;
    return func;
}

int LEXMKDiatonicFunctionDifferentIntervalIndexInFunctions(LEXMKDiatonicFunction func1, LEXMKDiatonicFunction func2)
{
    for (int i = 0; i < 7; i++) {
        if (func1.intervals[i] != func2.intervals[i]) {
            return i;
        }
    }
    return -1;
}

bool LEXMKDiatonicFunctionIsEqualToFunction(LEXMKDiatonicFunction func1, LEXMKDiatonicFunction func2)
{
    return LEXMKDiatonicFunctionDifferentIntervalIndexInFunctions(func1, func2) == -1 ? true : false;
}

bool LEXMKDiatonicFunctionIsValid(LEXMKDiatonicFunction function)
{
    int sum = 0;
    for (int i = 0 ; i <= 7; i ++) {
        sum += function.intervals[i];
    }
    return (sum == 12);
}