//
//  LEXMKDiatonicFunction.h
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT




#ifndef LEXMKDiatonicFunction_h
#define LEXMKDiatonicFunction_h

#include <stdbool.h>
#include "LEXMKMode.h"

#define LEXMKDFuncMake(i1,i2,i3,i4,i5,i6,i7) LEXMKDiatonicFunctionMakeWithIntervals(i1,i2,i3,i4,i5,i6,i7)

/// The 'diatonic function' or 'chord area' - is mask of intervals from one degree to another. The value of intervals is number of halftones from given degree to the next. I. e. for natural major function[0] will be '2'. This is not very good way to keep info but I can't find another way.
typedef struct LEXMKDiatonicFunction {int intervals[7];} LEXMKDiatonicFunction;


LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithUncompletedIntervals(int i1, int i2, int i3, int i4, int i5, int i6);
LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithIntervals(int i1, int i2, int i3, int i4, int i5, int i6, int i7);

LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithUncompletedIntervalVector(const int * intervals);
LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithIntervalVector(const int * intervals);

/** Easy way to create diatonic functions by mode.
 @param LEXMusicMode An mode constant. See valid constants in LEXMusicMode enum.
 @return An usable LEXMKDiatonicFunction variable in case of valid mode and LEXMKDiatonicFunctionNull if mode unknown.
 */
LEXMKDiatonicFunction LEXMKDiatonicFunctionMakeWithMode(LEXMKMode mode);

int LEXMKDiatonicFunctionDifferentIntervalIndexInFunctions(LEXMKDiatonicFunction func1, LEXMKDiatonicFunction func2);

bool LEXMKDiatonicFunctionIsEqualToFunction(LEXMKDiatonicFunction func1, LEXMKDiatonicFunction func2);

/** Validate function. Valid function elements sum should be always equal to 12 (number of halftones in scale).
 @param function An LEXMKDiatonicFunction variable to validate.
 @return YES if function is valid.
 */
bool LEXMKDiatonicFunctionIsValid(LEXMKDiatonicFunction function);

/** A function constant with all zero-intervals.
 */
extern const LEXMKDiatonicFunction LEXMKDiatonicFunctionNull;


#endif //LEXMKDiatonicFunction