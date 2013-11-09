//
//  LEXMKDiatonicFunction.c
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT
//

#include "LEXMKDiatonicFunction.h"

const LEXMKDiatonicFunction LEXMKDiatonicFunctionNull = {0, 0, 0, 0, 0, 0};

LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithMode(LEXMKMode mode)
{
    LEXMKDiatonicFunction func;
    switch (mode) {
        case LEXMKModeMajorNatural:
            // T T H T T T H
            func = LEXMKDFCreate(2,2,1,2,2,2,1);
            break;
        case LEXMKModeMinorHarmonic:
            func = LEXMKDFCreate(2,1,2,2,1,3,1);
            break;
        case LEXMKModeMinorMelodic:
            func = LEXMKDFCreate(2,1,2,2,2,2,1);
            break;
        case LEXMKModeMinorNatural:
            func = LEXMKDFCreate(2, 1, 2, 2, 1, 2, 2);
            break;
        default:
            func = LEXMKDiatonicFunctionNull;
            break;
    }
    return func;
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithIntervals(int r1,
                                                               int r2,
                                                               int r3,
                                                               int r4,
                                                               int r5,
                                                               int r6,
                                                               int r7)
{
    int ranges[7] = {r1, r2, r3, r4, r5, r6, r7};
    return LEXMKDiatonicFunctionCreateWithIntervalVector(ranges);
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithIntervalVector(const int * ranges)
{
    LEXMKDiatonicFunction func;
    for (int i = 0; i <=7; i++) {
        func.ranges[i] = ranges[i];
    }
    return func;
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithUncompletedIntervals(int r1,
                                                                          int r2,
                                                                          int r3,
                                                                          int r4,
                                                                          int r5,
                                                                          int r6)
{
    int ranges [6] = {r1, r2, r3 ,r4 , r5, r6};
    return LEXMKDiatonicFunctionCreateWithUncompletedIntervalVector(ranges);
}

LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithUncompletedIntervalVector(const int * ranges)
{
    int sum = 0;
    int range = 0;
    LEXMKDiatonicFunction func;
    for (int i = 0; i < 6; i ++) {
        range = ranges[i];
        sum += range;
        if (sum >= 12) {
            return LEXMKDiatonicFunctionNull;
        }
        func.ranges[0] = range;
    }
    range = 12 - sum;
    func.ranges[6] = range;
    return func;
}

bool LEXMKDiatonicFunctionIsEqualToFunction(LEXMKDiatonicFunction func1, LEXMKDiatonicFunction func2)
{
    for (int i = 0; i <= 7; i++) {
        if (func1.ranges[i] != func2.ranges[i]) {
            return false;
        }
    }
    return true;
}

bool LEXMKDiatonicFunctionIsValid(LEXMKDiatonicFunction function)
{
    int sum = 0;
    for (int i = 0 ; i <= 7; i ++) {
        int range = function.ranges[i];
        sum += range;
    }
    return (sum == 12);
}