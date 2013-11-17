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
#include "LEXMKIntervalArray.h"

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

/** Chord option with type and related info.
 */
struct LEXMKChordOpt {
    LEXMKChordOptType type; /// Type of chord option.
    int info; /// Info make sense only when type defined.
};
typedef struct LEXMKChordOpt LEXMKChordOpt;

/*
    What info means for type?
 Wide - The widest interval in chord. Info is interval.
 Sus - suspended chord. Third interval changes to major second or perfect fourth. Make a note, that original third is no more in chord. Info is 0 for sus2 and 1 for sus4. 
 Add - adding given interval to a chord. Info is interval.
 AltBass - first note of chord is different from tonic. Info is shift from tonic like -2 for chord Am/G.
 */

/*
LEXMKChordOpt LEXMKChordOptMakeWithTypeAndInfo(LEXMKChordOptType type, int info);
LEXMKChordOpt LEXMKChordOptMakeWideMakeWithInterval(LEXMKInterval interval);
LEXMKChordOpt LEXMKChordOptMakeSus2();
LEXMKChordOpt LEXMKChordOptMakeSus4();
LEXMKChordOpt LEXMKChordOptMakeAltBassWithTonicShift(LEXMKInterval shift);
LEXMKChordOpt LEXMKChordOptMakeAddWithInterval(LEXMKInterval interval);
 */

typedef struct _LEXMKChordScheme * LEXMKChordSchemeRef;

LEXMKChordSchemeRef LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordMode mode, LEXMKChordOpt * opts, unsigned int optsLength);
int LEXMKChordSchemeDestroy(LEXMKChordSchemeRef scheme);

LEXMKChordMode LEXMKChordSchemeGetMode(LEXMKChordSchemeRef scheme);
unsigned int LEXMKChordSchemeGetOptsLength(LEXMKChordSchemeRef scheme);
LEXMKChordOpt * LEXMKChordSchemeGetOpts(LEXMKChordSchemeRef scheme);

LEXMKIntervalArrayRef LEXMKChordSchemeGetIntervalArray(LEXMKChordSchemeRef scheme, bool isRelated);

#endif
