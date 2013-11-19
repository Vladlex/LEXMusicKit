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
#include "LEXMKChordOpt.h"

enum {
    LEXMKChordModeMajor = 0,
    LEXMKChordModeMinor,
    LEXMKChordModeDim,
    LEXMKChordModeAug
};
typedef int LEXMKChordMode;


enum {
    LEXMKChordSusNone = 0,
    LEXMKChordSus2 = 1,
    LEXMKChordSus4 = 2
};

enum  {
    LEXMKChordRecognitionNotationClassic = 0,
    LEXMKChordRecognitionNotationGuitar
};
typedef int LEXMKChordRecognitionNotation;


typedef struct _LEXMKChordScheme * LEXMKChordSchemeRef;



/**
	Completely destroying scheme. All schemes created by method with 'Create' word should be destroyed by this method.
	@param scheme Scheme to destroy.
	@returns EXIT_SUCCESS if all is ok.
 */
int LEXMKChordSchemeDestroy(LEXMKChordSchemeRef scheme);

/**
	Returns chord scheme for mode and options.
	@param mode Chord mode.
	@param opts Chord optional modifiers.
	@param optsLength The length of the opts vector.
	@returns Chord scheme for mode and optional modifiers.
 */
LEXMKChordSchemeRef LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordMode mode, LEXMKChordOpt * opts, unsigned int optsLength);

/*  --- === Accessors === --- */
LEXMKChordMode LEXMKChordSchemeGetMode(LEXMKChordSchemeRef scheme);
unsigned int LEXMKChordSchemeGetOptsLength(LEXMKChordSchemeRef scheme);
LEXMKChordOpt * LEXMKChordSchemeGetOpts(LEXMKChordSchemeRef scheme);



LEXMKChordOpt *LEXMKChordSchemeGetOptsWithType(LEXMKChordSchemeRef scheme,
                                               LEXMKChordOptType type,
                                               unsigned int * outFoundOptsLength);

bool LEXMKChordSchemeHasOptWithTypeAndInfo(LEXMKChordSchemeRef scheme,
                                                       LEXMKChordOptType type,
                                                       int info,
                                           unsigned int *foundOptIdx);

/**
 Returns intervals for mode.
 @param mode Chord mode.
 @param susVal Value for sus type. Sus type transforms second interval to a major second or to a perfect fourth.
 @param outLength Upon return this value will continue length of given intervals. Usually it's triad (the length is 2, because first interval is always tonic) but fot diminished is 3.
 @returns An LEXMKInterval vector.
 */
LEXMKInterval * LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordMode mode, int susVal, unsigned int *outLength);


/**
	Returns interval array with intervals with NOT related with each other.
	@param scheme Scheme to generate intervals.
	@param *outUnrecognizedOpts Upon return this variable contains unrecognized opts. NULL if there are no unrecognized opts (normal behaviour).
	@param outUnrecognizedOptsLength Upon return this variable containts length of the outUnrecognizedOpts vector.
	@returns LEXMKIntervalArrayRef instance or NULL if mode is unknown.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateWithScheme(LEXMKChordSchemeRef scheme, LEXMKChordRecognitionNotation notation, LEXMKChordOpt **outUnrecognizedOpts, unsigned int *outUnrecognizedOptsLength);

#endif
