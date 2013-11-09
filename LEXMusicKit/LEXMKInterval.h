//
//  LEXMKInterval.h
//  iChord
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 iTech. All rights reserved.
//

#ifndef iChord_LEXMKInterval_h
#define iChord_LEXMKInterval_h


enum  {
    // Simple intervals
    LEXMKIntervalPerfectUnison = 0,
    LEXMKIntervalMinorSecond,
    LEXMKIntervalMajorSecond,
    LEXMKIntervalMinorThird,
    LEXMKIntervalMajorThird,
    LEXMKIntervalPerfectFourth,
    LEXMKIntervalAugmentedFourth = 6,
    LEXMKIntervalDiminishedFifth = 6,
    LEXMKIntervalPerfectFifth,
    LEXMKIntervalMinorSixth,
    LEXMKIntervalMajorSixth,
    LEXMKIntervalMinorSeventh,
    LEXMKIntervalMajorSeventh,
    // Compound intervals
    LEXMKIntervalPerfectOctave = 12,    // There is no need to straight point this value, it's always be twelve. This assignment is just for readability.
};
typedef int LEXMKInterval;

LEXMKInterval LEXMKIntervalPitchInterval(int semitone1, int semintone2);
LEXMKInterval LEXMKIntervalPitchIntervalClass(int semitone1, int semitone2);
LEXMKInterval LEXMKIntervalPitchIntervalClassMod6(int semitone1, int semitone2);

LEXMKInterval LEXMKIntervalOctaveLimitedInvertedInterval(LEXMKInterval interval);

int LEXMKIntervalGetOctave(LEXMKInterval interval);

// See Inverted intervals!

#endif
