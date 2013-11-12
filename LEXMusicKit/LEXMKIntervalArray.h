//
//  LEXMKIntervalArray.h
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 12.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#ifndef LEXMusicKit_LEXMKIntervalArray_h
#define LEXMusicKit_LEXMKIntervalArray_h

#include "LEXMKInterval.h"

typedef struct LEXMKIntervalArray {LEXMKInterval * intervals; unsigned int length; bool isRelated;} LEXMKIntervalArray;

/*   --- === Creating arrays === ---
 */

// All intervals array should be destroyed by 'LEXMKIntervalArrayDestroy' method.

LEXMKIntervalArray LEXMKIntervalArrayCreateWithIntervals(LEXMKInterval * intervals, unsigned int length, bool isRelated);

LEXMKIntervalArray LEXMKIntervalArrayCreateByAddingIntervalToArray(LEXMKIntervalArray array, LEXMKInterval interval);
LEXMKIntervalArray LEXMKIntervalArrayCreateByAddingIntervalsToArray(LEXMKIntervalArray array, LEXMKInterval *intervals, unsigned int length);

// returns Null if arrays 'isRelated' values different
LEXMKIntervalArray LEXMKIntervalArrayCreateByUnionIntervalArrays(LEXMKIntervalArray * arrays);

/*  --- === Destroying arrays === ---
 */
void LEXMKIntervalArrayDestroy(LEXMKIntervalArray array);


/*  --- === Array operations === ---
 */

void LEXMKIntervalArrayRemoveRepeatingIntervals(LEXMKIntervalArray array);
void LEXMKIntervalArrayRemoveRepeatingIntervalsIgnoringOctaves(LEXMKIntervalArray array);
void LEXMKIntervalArrayAddInterva(LEXMKIntervalArray array, LEXMKInterval interval);
void LEXMKIntervalArrayRemoveInterval(LEXMKIntervalArray array, LEXMKInterval interval);
bool LEXMKIntervalArrayHasInterval(LEXMKIntervalArray array, LEXMKInterval interval);
 int LEXMKIntervalArrayIndexOfInterva(LEXMKIntervalArray array, LEXMKInterval interval);
void LEXMKIntervalOrderIntervals(LEXMKIntervalArray array);

/*  --- === Constants === ---
 */
extern const LEXMKIntervalArray LEXMKIntervalArrayNull;

#endif
