//
//  LEXMKDiatonicFunction.h
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//



#ifndef LEXMKDiatonicFunction_h
#define LEXMKDiatonicFunction_h

#include <stdbool.h>
#include "LEXMKMode.h"

#define LEXMKDFCreate(i1,i2,i3,i4,i5,i6,i7) LEXMKDiatonicFunctionCreateWithIntervals(i1,i2,i3,i4,i5,i6,i7)

/// The 'diatonic function' or 'chord area' - is mask of ranges from one degree to another. The value of range is number of halftones from given degree to the next. I. e. for natural major function[0] will be '2'. This is not very good way to keep info but I can't find another way.
typedef struct LEXMKDiatonicFunction {int ranges[7];} LEXMKDiatonicFunction;


LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithUncompletedIntervals(int i1, int i2, int i3, int i4, int i5, int i6);
LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithIntervals(int i1, int i2, int i3, int i4, int i5, int i6, int i7);

LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithUncompletedIntervalVector(const int * ranges);
LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithIntervalVector(const int * ranges);

/** Easy way to create diatonic functions by mode.
 @param LEXMusicMode An mode constant. See valid constants in LEXMusicMode enum.
 @return An usable LEXMKDiatonicFunction variable in case of valid mode and LEXMKDiatonicFunctionNull if mode unknown.
 */
LEXMKDiatonicFunction LEXMKDiatonicFunctionCreateWithMode(LEXMKMode mode);

bool LEXMKDiatonicFunctionIsEqualToFunction(LEXMKDiatonicFunction func1, LEXMKDiatonicFunction func2);

/** Validate function. Valid function elements sum should be always equal to 12 (number of halftones in scale).
 @param function An LEXMKDiatonicFunction variable to validate.
 @return YES if function is valid.
 */
bool LEXMKDiatonicFunctionIsValid(LEXMKDiatonicFunction function);

/** A function constant with all zero-ranges.
 */
extern const LEXMKDiatonicFunction LEXMKDiatonicFunctionNull;


#endif //LEXMKDiatonicFunction