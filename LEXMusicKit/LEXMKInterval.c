//
//  LEXMKInterval.c
//  iChord
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT//


#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include "LEXMKInterval.h"


#define LEXMKMAX(A, B) ((A) < (B) ? (B) : (A))

LEXMKInterval LEXMKIntervalPitchIntervalClass(int semitone1, int semitone2)
{
    return (semitone2 - semitone1) % 12;
}

LEXMKInterval LEXMKIntervalPitchIntervalClassMod6(int semitone1, int semitone2)
{
    return (semitone2 - semitone1) % 6;
}

LEXMKInterval LEXMKIntervalOctaveLimitedInvertedInterval(LEXMKInterval interval)
{
    return (12 - (interval % 12) );
}

int LEXMKIntervalGetOctave(LEXMKInterval interval)
{
    return interval / 12;
}

bool LEXMKIntervalIsConsonance(LEXMKInterval interval, bool * isPerfect)
{
    interval = interval % 12;
    bool isConsonance = false;
    if (interval == LEXMKIntervalPerfectUnison ||
        interval == LEXMKIntervalPerfectFourth ||
        interval == LEXMKIntervalPerfectFifth ||
        interval == LEXMKIntervalPerfectOctave) {
        if (isPerfect != NULL) {
            *isPerfect = true;
        }
        isConsonance = true;
    }
    else if (interval == LEXMKIntervalMajorThird ||
             interval == LEXMKIntervalMinorThird ||
             interval == LEXMKIntervalMinorSixth ||
             interval == LEXMKIntervalMajorSixth) {
        isConsonance = true;
        if (isPerfect != NULL) {
            isPerfect = false;
        }
    }
    return isConsonance;
}

bool LEXMKIntervalIsEqualIngnoringOctaves(LEXMKInterval interval1, LEXMKInterval interval2)
{
    return (interval1 % 12 == interval2 % 12);
}

int LEXMKIntervalCompare(LEXMKInterval interval1, LEXMKInterval interval2)
{
    return interval1 - interval2;
}

int LEXMKIntervalCompareForQSort(const void *arg1, const void *arg2)
{
    return LEXMKIntervalCompare(*(LEXMKInterval *)arg1, *(LEXMKInterval *)arg2);
}

void LEXMKIntervalSortIntervals(LEXMKInterval * intervals, unsigned int length)
{
    qsort(intervals, length, sizeof(LEXMKInterval), LEXMKIntervalCompareForQSort);
}
