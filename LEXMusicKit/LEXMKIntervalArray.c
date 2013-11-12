//
//  LEXMKIntervalArray.c
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 12.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#include "LEXMKIntervalArray.h"

#include <stdlib.h>
#include <memory.h>

LEXMKIntervalArray LEXMKIntervalArrayCreateWithIntervals(LEXMKInterval * intervals, unsigned int length, bool isRelated)
{
    LEXMKIntervalArray array;
    LEXMKInterval *arIntervals;
    
    arIntervals = malloc(sizeof(LEXMKInterval) * length);
    memcpy(arIntervals,
           intervals,
           length);
    array.intervals = arIntervals;
    array.length = length;
    array.isRelated = isRelated;
    return array;
}

LEXMKIntervalArray LEXMKIntervalArrayCreateByAddingIntervalToArray(LEXMKIntervalArray array, LEXMKInterval interval)
{
    LEXMKInterval *arIntervals;
    LEXMKIntervalArray extendedArray;
    unsigned int length;

    length = array.length + 1;
    arIntervals = malloc(sizeof(LEXMKInterval) * length);
    memcpy(arIntervals, array.intervals, array.length);
    arIntervals[length - 1] = interval;
    extendedArray.intervals = arIntervals;
    extendedArray.length = length;
    extendedArray.isRelated = array.isRelated;
    return extendedArray;
}


LEXMKIntervalArray LEXMKIntervalArrayCreateByAddingIntervalsToArray(LEXMKIntervalArray array, LEXMKInterval *intervals, unsigned int length)
{
    LEXMKInterval *arIntervals;
    LEXMKIntervalArray extendedArray;
    unsigned int extendedArrayLength;
    
    extendedArrayLength = (array.length + length);
    arIntervals = malloc(sizeof(LEXMKInterval) * extendedArrayLength);
    memcpy(&arIntervals[0], array.intervals, array.length);
    memcpy(&arIntervals[array.length], intervals, length);
    extendedArray.intervals = arIntervals;
    extendedArray.isRelated = array.isRelated;
    extendedArray.length = extendedArrayLength;
    return extendedArray;
}



void LEXMKIntervalArrayDestroy(LEXMKIntervalArray array)
{
    free(array.intervals);
}
