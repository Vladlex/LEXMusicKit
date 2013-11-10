//
//  LEXMKInterval.c
//  iChord
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT//


#include "LEXMKInterval.h"

#include <stdlib.h>
#include <math.h>
#include <limits.h>

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