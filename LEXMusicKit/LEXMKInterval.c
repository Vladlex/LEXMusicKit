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

LEXMKInterval LEXMKIntervalPitchInterval(int semitone1, int semitone2)
{
    return semitone2 - semitone1;
}

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