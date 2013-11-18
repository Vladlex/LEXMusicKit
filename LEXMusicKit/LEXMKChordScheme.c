//
//  LEXMKChordScheme.c
//  LEXMusicKit
//
//  Created by Vladlex on 17.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "LEXMKChordScheme.h"

typedef struct _LEXMKChordScheme {
    LEXMKChordMode mode;
    LEXMKChordOpt *opts;
    unsigned int optsLength;
} LEXMKChordScheme;

LEXMKChordSchemeRef LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordMode mode, LEXMKChordOpt * opts, unsigned int optsLength)
{
    
    LEXMKChordSchemeRef scheme;
    LEXMKChordOpt *schemeOpts;
    
    scheme = malloc(sizeof(LEXMKChordScheme));
    scheme->mode = mode;
    if (optsLength > 0) {
        size_t optSize = sizeof(LEXMKChordOpt) * optsLength;
        schemeOpts = malloc(optSize);
        memcpy(schemeOpts, opts, optSize);
    }
    else {
        schemeOpts = NULL;
    }
    scheme->opts = schemeOpts;
    scheme->optsLength = optsLength;
    return scheme;
}

int LEXMKChordSchemeDestroy(LEXMKChordSchemeRef scheme)
{
    if (scheme->opts != NULL) {
        free(scheme->opts);
    }
    free(scheme);
    return EXIT_SUCCESS;
}

LEXMKChordMode LEXMKChordSchemeGetMode(LEXMKChordSchemeRef scheme)
{
    return scheme->mode;
}

unsigned int LEXMKChordSchemeGetOptsLength(LEXMKChordSchemeRef scheme)
{
    return scheme->optsLength;
}

LEXMKChordOpt * LEXMKChordSchemeGetOpts(LEXMKChordSchemeRef scheme)
{
    return scheme->opts;
}

LEXMKInterval *LEXMKChordSchemeGetIntervals(LEXMKChordSchemeRef scheme, bool isRelated)
{
    return NULL;
}

LEXMKInterval * LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordMode mode, int susVal, unsigned int *outLength)
{
    bool canContinue = true;
    unsigned int length;
    
    LEXMKInterval triad2interval;
    LEXMKInterval triad3interval;
    switch (susVal) {
        case LEXMKchordSus2:     // Sus2
            triad2interval = LEXMKIntervalMajorSecond;
            break;
        case LEXMKchordSus4:     // Sus4
            triad2interval = LEXMKIntervalPerfectFourth;
            break;
        default:
            triad2interval = 0;
            break;
    }
    
    switch (mode) {
        case LEXMKChordModeMajor:
            if (triad2interval == 0) {
                triad2interval = LEXMKIntervalMajorThird;
            }
            triad3interval = LEXMKIntervalPerfectFifth;
            break;
        case LEXMKChordModeMinor:
            if (triad2interval == 0) {
                triad2interval = LEXMKIntervalMinorThird;
            }
            triad3interval = LEXMKIntervalPerfectFifth;
            break;
        case LEXMKChordModeAug:
            triad2interval = LEXMKIntervalMajorThird;
            triad3interval = triad2interval + LEXMKIntervalMajorThird;
            break;
        case LEXMKChordModeDim:
            triad2interval = LEXMKIntervalMinorThird;
            triad3interval = triad2interval + LEXMKIntervalMinorThird;
            break;
        default:
            canContinue = false;
            break;
    }
    if (!canContinue){
        if (outLength) {
            *outLength = 0;
        }
        return NULL;
    }
    
    LEXMKInterval *intervals;
    if (mode == LEXMKChordModeDim) {
        length = 3;
        intervals = malloc(sizeof(LEXMKInterval) * length);
        intervals[2] = triad3interval + LEXMKIntervalMinorThird;
    }
    else {
        length = 2;
        intervals = malloc(sizeof(LEXMKInterval) * length);
    }
    if (outLength) {
        *outLength = length;
    }
    intervals[0] = triad2interval;
    intervals[1] = triad3interval;
    return intervals;
}

LEXMKIntervalArrayRef LEXMKIntervalArrayCreateWithScheme(LEXMKChordSchemeRef scheme,
                                                       LEXMKChordOpt **outUnrecognizedOpts,
                                                       unsigned int * outUnrecognizedOptsLength)
{
    LEXMKChordOpt * opts = scheme->opts;
    unsigned int optsLength = scheme->optsLength;
    int susVal = -1;
    for (int i = 0; i < optsLength; i ++) {
        LEXMKChordOpt opt = opts[i];
        if (opt.type == LEXMKChordOptTypeSus) {
            susVal = opt.info;
            break;
        }
    }
    
    LEXMKInterval *intervals;
    unsigned int length;
    intervals = LEXMKIntervalCreateIntervalsForModeAndSusVal(scheme->mode,
                                                       susVal,
                                                       &length);
    // many other thing should be done
    
    LEXMKIntervalArrayRef array = LEXMKIntervalArrayCreateWithIntervals(intervals,
                                                                        length,
                                                                        false);
    free(intervals);
    return array;
}

