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

/**
    Struct describing interval group.
 */
typedef struct LEXMKIntervalArray {
	LEXMKInterval * intervals; /**< An interval vector */
	unsigned int length; /**< Length of the intervals vector */
	bool isRelated; /**< 'true' if each interval positioned relative to previous interva. 'false' if each interval positioned relative to an abstract 'zero' value */
} LEXMKIntervalArray;

/*   --- === Creating arrays === --- */
/**
	Returns created LEXMKInterval instance.
	@param intervals An existing intervals vector with valid length. This vector will be copied.
	@param length Length of the intervals vector.
	@param isRelated Are given intervals positioned relative each other.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayDestroy'.
	@returns LEXMKIntervalArray instance.
 */
LEXMKIntervalArray LEXMKIntervalArrayCreateWithIntervals(LEXMKInterval * intervals, unsigned int length, bool isRelated);

/**
    Returns created interval array with copied intervals of another array appended by given interval.
	@param array Source array which interval.
	@param interval Interval which should be added to array at last position.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayDestroy'.
	@returns LEXMKIntervalArray instance.
 */
LEXMKIntervalArray LEXMKIntervalArrayCreateByAddingIntervalToArray(LEXMKIntervalArray array, LEXMKInterval interval);

/**
	Returns created interval array with intervals
	@param array Source array
	@param intervals Intervals which should be added to created array after source interval array intervals.
	@param length Length of the intervals vector.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayDestroy'.
	@returns LEXMKIntervalArray instance.
 */
LEXMKIntervalArray LEXMKIntervalArrayCreateByAddingIntervalsToArray(LEXMKIntervalArray array, LEXMKInterval *intervals, unsigned int length);

/**
	Returns LEXMKIntervalArray containing all of given interval array intervals.
	@param arrays Vector of LEXMKIntervalArray instances.
    @param length Length of arrays vecotr.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayDestroy'.
    @warning All arrays should have same isRealated value!
	@returns LEXMKIntervalArray instance or LEXMKIntervalArrayNull if something wrong.
 */
LEXMKIntervalArray LEXMKIntervalArrayCreateByUnionIntervalArrays(LEXMKIntervalArray * arrays, unsigned int length);

/*  --- === Destroying arrays === --- */
void LEXMKIntervalArrayDestroy(LEXMKIntervalArray array);


/*  --- === Array operations === --- */
void LEXMKIntervalArrayRemoveRepeatingIntervals(LEXMKIntervalArray array);
void LEXMKIntervalArrayRemoveRepeatingIntervalsIgnoringOctaves(LEXMKIntervalArray array);
void LEXMKIntervalArrayAddInterva(LEXMKIntervalArray array, LEXMKInterval interval);
void LEXMKIntervalArrayInsertIntervalAtIndex(LEXMKIntervalArray array, LEXMKInterval interval, unsigned int position);
void LEXMKIntervalArrayRemoveInterval(LEXMKIntervalArray array, LEXMKInterval interval);
bool LEXMKIntervalArrayHasInterval(LEXMKIntervalArray array, LEXMKInterval interval);
 int LEXMKIntervalArrayIndexOfInterva(LEXMKIntervalArray array, LEXMKInterval interval);
void LEXMKIntervalOrderIntervals(LEXMKIntervalArray array);

/*  --- === Constants === --- */
extern const LEXMKIntervalArray LEXMKIntervalArrayNull;

#endif
