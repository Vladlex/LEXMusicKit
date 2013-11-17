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

LEXMKInterval * LEXMKIntervalArrayGetIntervals(LEXMKIntervalArrayRef array);

/**
	Let you know intervals
	@param array Array with needed intervals. This parameter should not be NULL.
	@param intervals Array intervals. May be Null.
	@param length Array intervals length. May be Null.
	@returns EXIT_SUCCESS if all ok.
 */
int LEXMKIntervalArrayGetIntervalsAndLength(LEXMKIntervalArrayRef array, LEXMKInterval ** outIntervals, unsigned int *outLength);

/**
	Returns array length.
	@param array Array which length you want to know. This parameter should not be NULL.
	@returns Array length.
 */
unsigned int LEXMKIntervalArrayGetLength(LEXMKIntervalArrayRef array);

/**
	Returns bool value which means if containing intervals are relative to each other.
	@param array Array which intervals relation you want to know. This paramter should not be NULL.
	@returns 'true' if intervals are positioned relatively to each other ot 'false' if intervals are positioned relatively by an anstract zero point.
 */
bool LEXMKIntervalArrayGetIsRelative(LEXMKIntervalArrayRef array);

/**
 Check if given array is empty.
 @param array Array to check.
 @returns 'true' if array does not has elements and it's length is 0.
 */
bool LEXMKIntervalArrayIsEmpty(LEXMKIntervalArrayRef array);

/*   --- === Creating arrays === --- */

LEXMKIntervalArrayRef LEXMKIntervalArrayCreate();

/**
	Returns created LEXMKInterval instance.
	@param intervals An existing intervals vector with valid length. This vector copying.
	@param length Length of the intervals vector.
	@param isRelated Are given intervals positioned relative each other.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
	@returns LEXMKIntervalArrayRef instance.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateWithIntervals(LEXMKInterval * intervals, unsigned int length, bool isRelated);

/**
    Returns created interval array with copied intervals of another array appended by given interval.
	@param array Source array which interval. This parameter should not be NULL.
	@param interval Interval which should be added to array at last position.
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
	@returns LEXMKIntervalArrayRef instance.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateByAddingIntervalToArray(LEXMKIntervalArrayRef array, LEXMKInterval interval);

/**
	Returns created interval array with intervals
	@param array Source array. This parameter should not be NULL.
	@param intervals Intervals which should be added to created array after source interval array intervals.
 May be NULL (length should be 0 though).
	@param length Length of the intervals vector. May be 0 (intervals should be NULL though).
    @warning You're responsible to destroy created array using 'LEXMKIntervalArrayRefDestroy'.
	@returns LEXMKIntervalArrayRef instance.
 */
LEXMKIntervalArrayRef LEXMKIntervalArrayCreateByAddingIntervalsToArray(LEXMKIntervalArrayRef array, LEXMKInterval *intervals, unsigned int length);

/*  --- === Array comparison === --- */

/**
	Check if given arrays are equal.
	@param array1 Array to compare.
	@param array2 Array to compare.
	@returns 'true' if array have same intervals in the same order.
 */
bool LEXMKIntervalArrayIsEqual(LEXMKIntervalArrayRef array1, LEXMKIntervalArrayRef array2);


/*  --- === Array modifying operations === --- */

/**
	Adds interval to array.
	@param array Array which should be appended by interval.
	@param interval An interval which should be added to array.
	@returns EXIT_SUCCESS if all Ok.
 */
int LEXMKIntervalArrayAddInterval(LEXMKIntervalArrayRef array, LEXMKInterval interval);

/**
 Inserts interval to array.
 @param array Array which should be appended by interval.
 @param interval An interval which chould be inserted to array.
 @param position Desired position of inserting interval.
 @returns EXIT_SUCCESS if all Ok.
 */
int LEXMKIntervalArrayInsertIntervalAtIndex(LEXMKIntervalArrayRef array, LEXMKInterval interval, unsigned int idx);


#endif
