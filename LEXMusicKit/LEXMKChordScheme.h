//
//  LEXMKChordScheme.h
//  LEXMusicKit
//
//  Created by Vladlex on 17.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#ifndef LEXMusicKit_LEXMKChordScheme_h
#define LEXMusicKit_LEXMKChordScheme_h

#include "LEXMKInterval.h"

enum {
    LEXMKChordModeMajor = 0,
    LEXMKChordModeMinor,
    LEXMKChordModeDim,
    LEXMKChordModeAug
};
typedef int LEXMKChordMode;

enum {
    LEXMKChordOptTypeUnknown = -1,
    LEXMKChordOptTypeWide,
    LEXMKChordOptTypeSus,
    LEXMKChordOptTypeAdd,
    LEXMKChordOptTypeAltBass
};
typedef int LEXMKChordOptType;

struct LEXMKChordOpt {
    LEXMKChordOptType type;
    int info;
};
typedef struct LEXMKChordOpt LEXMKChordOpt;

LEXMKChordOpt LEXMKChordOptMakeWithTypeAndInfo(LEXMKChordOptType type, int info);
LEXMKChordOpt LEXMKChordOptMakeWideMakeWithInterval(LEXMKInterval interval);
LEXMKChordOpt LEXMKChordOptMakeSus2();
LEXMKChordOpt LEXMKChordOptMakeSus4();
LEXMKChordOpt LEXMKChordOptMakeAltBassWithTonicShift(LEXMKInterval shift);
LEXMKChordOpt LEXMKChordOptMakeAddWithInterval(LEXMKInterval interval);

typedef struct LEXMKChordScheme LEXMKChordSchemeRef;

LEXMKChordSchemeRef LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordMode mode, LEXMKChordOpt * opts, unsigned int optsLength);
int LEXMKChordSchemeDestroy(LEXMKChordSchemeRef scheme);

LEXMKChordMode LEXMKChordSchemeGetMode(LEXMKChordSchemeRef scheme);
unsigned int LEXMKChordSchemeGetOptsLength(LEXMKChordSchemeRef scheme);
LEXMKChordOpt * LEXMKChordSchemeGetOpts(LEXMKChordSchemeRef scheme);

#endif
