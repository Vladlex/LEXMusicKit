//
//  LEXMKIntervalArrayRef.h
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 12.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#ifndef LEXMusicKit_LEXMKIntervalArrayRef_h
#define LEXMusicKit_LEXMKIntervalArrayRef_h

#include "LEXMKInterval.h"

/**
    LEXMKIntervalArrayRef is interval array whic contains intervals and it's relative position
 */

typedef struct _LEXMKIntervalArray * LEXMKIntervalArrayRef;


/*  --- === Destroying arrays === --- */

/**
 Destroy malloced intervals.You should not use array after destroying in any way.
 @param array Array to destroy
 @returns EXIT_SUCCESS if all ok.
 */
int LEXMKIntervalArrayDestroy(LEXMKIntervalArrayRef array);

/* --- === Initialization arrays === --- */

/**
 Initing given array.
 @param array An allocated array to initialize. 
 @description This method initialized with NULL intervals, zero length and mark intervals as related to each other (isRelative = true).
 @returns EXIT_SUCCESS if all Ok.
 */
int LEXMKIntervalArrayInit(LEXMKIntervalArrayRef array);


/* --- === Accessors === --- */

/**
	Let you know intervals
	@param array Array with needed intervals
	@param intervals Array intervals. May be Null.
	@param length Array intervals length. May be Null.
	@returns EXIT_SUCCESS if all ok.
 */
int LEXMKIntervalArrayGetIntervals(LEXMKIntervalArrayRef array, LEXMKInterval ** outIntervals, unsigned int *outLength);

/**
	Returns array length.
	@param array Array which length you want to know.
	@returns Array length.
 */
unsigned int LEXMKIntervalArrayGetLength(LEXMKIntervalArrayRef array);

/**
	Returns bool value which means if containing intervals are relative to each other.
	@param array Array which intervals relation you want to know.
	@returns 'true' if intervals are positioned relatively to each other ot 'false' if intervals are positioned relatively by an anstract zero point.
 */
bool LEXMKIntervalArrayGetIsRelative(LEXMKIntervalArrayRef array);


/*   --- === Creating arrays === --- */

/**
	Returns created LEXMKInterval instance.
	@param intervals An existing intervals vector with valid length. This vector will be copied.
	@param length Length of the intervals vector.
	@param isRelated Are given intervals positioned relative each other.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
	@returns LEXMKIntervalArrayRef instance.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateWithIntervals(LEXMKInterval * intervals, unsigned int length, bool isRelated);

/**
    Returns created interval array with copied intervals of another array appended by given interval.
	@param array Source array which interval.
	@param interval Interval which should be added to array at last position.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
	@returns LEXMKIntervalArrayRef instance.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateByAddingIntervalToArray(LEXMKIntervalArrayRef array, LEXMKInterval interval);

/**
	Returns created interval array with intervals
	@param array Source array
	@param intervals Intervals which should be added to created array after source interval array intervals.
 May be NULL (length should be 0 though).
	@param length Length of the intervals vector. May be 0 (intervals should be NULL though).
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
	@returns LEXMKIntervalArrayRef instance.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateByAddingIntervalsToArray(LEXMKIntervalArrayRef array, LEXMKInterval *intervals, unsigned int length);

/**
	Returns LEXMKIntervalArrayRef containing all of given interval array intervals.
	@param arrays Vector of LEXMKIntervalArrayRef instances.
    @param length Length of arrays vecotr.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
    @warning All arrays should have same isRealated value!
	@returns LEXMKIntervalArrayRef instance or LEXMKIntervalArrayRefNull if something wrong.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateByUnionIntervalArrays(LEXMKIntervalArrayRef * arrays, unsigned int length);


/*  --- === Array comparison === --- */

/**
	Check if given arrays are equal.
	@param array1 Array to compare.
	@param array2 Array to compare.
	@returns 'true' if array have same intervals in the same order.
 */
bool LEXMKIntervalArrayIsEqual(LEXMKIntervalArrayRef array1, LEXMKIntervalArrayRef array2);

/**
    Check if given array is empty.
    @param array Array to check.
    @returns 'true' if arra have not element and it's length is 0.
 */
bool LEXMKIntervalArrayIsEmpty(LEXMKIntervalArrayRef array);


/*  --- === Array modifying operations === --- */
/**
	Search for repeating intervals and remove them.
	@param array Array which repeating intervals should be removed.
    @returns 0 if all Ok.
 */
int LEXMKIntervalArrayRemoveRepeatingIntervals(LEXMKIntervalArrayRef array);

/**
	Search for repeating intervals ignoring intervals octave. As intancse unison and octave will be the same interval.
	@param array Array which repeating intervals will be removed.
	@returns 0 if all Ok.
 */
int LEXMKIntervalArrayRemoveRepeatingIntervalsIgnoringOctaves(LEXMKIntervalArrayRef array);

/**
	Adds interval to array.
	@param array Array which should be appended by interval.
	@param interval An interval which should be added to array.
	@returns 0 if all Ok.
 */
int LEXMKIntervalArrayAddInterval(LEXMKIntervalArrayRef array, LEXMKInterval interval);

/**
 Adds intervals to array.
 @param array Array which should be appended by intervals.
 @param interval An interval vector which should be added to array.
 @param length Adding interval vector length.
 @returns EXIT_SUCCESS if all Ok.
 */
int LEXMKIntervalArrayAddIntervals(LEXMKIntervalArrayRef array, LEXMKInterval *intervals, unsigned int length);

/**
	Inserts interval to array.
	@param array Array which should be appended by interval.
	@param interval An interval which chould be inserted to array.
	@param position Desired position of inserting interval.
	@returns 0 if all Ok. -2 if index is wrong.
 */
int LEXMKIntervalArrayInsertIntervalAtIndex(LEXMKIntervalArrayRef array, LEXMKInterval interval, unsigned int position);

int LEXMKIntervalArrayRefRemoveInterval(LEXMKIntervalArrayRef array, LEXMKInterval interval);
bool LEXMKIntervalArrayRefHasInterval(LEXMKIntervalArrayRef array, LEXMKInterval interval);
 int LEXMKIntervalArrayRefIndexOfInterval(LEXMKIntervalArrayRef array, LEXMKInterval interval);
int  LEXMKIntervalArrayRefIndexesOfInterval(LEXMKIntervalArrayRef array, unsigned int ** intervalIndexes, unsigned int * length);
int LEXMKIntervalArrayRefOrderIntervals(LEXMKIntervalArrayRef array);

#endif
