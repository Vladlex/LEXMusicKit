//
//  LEXMKIntervalArray.c
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 12.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "LEXMKIntervalArray.h"


typedef struct _LEXMKIntervalArray{
	LEXMKInterval * intervals; /**< An interval vector */
	unsigned int length; /**< Length of the interval vector */
	bool isRelated; /**< 'true' if each interval positioned relative to previous interva. 'false' if each interval positioned relative to an abstract 'zero' value */
} LEXMKIntervalArray;

/*  --- === Destroying arrays === --- */

int LEXMKIntervalArrayDestroy(LEXMKIntervalArrayRef array)
{
    if (array->intervals != NULL) {
        free(array->intervals);
    }
    free(array);
    return EXIT_SUCCESS;
}


/*  --- === Initialization arrays === --- */

int LEXMKIntervalArrayInit(LEXMKIntervalArrayRef array)
{
    array->length = 0;
    array->intervals = NULL;
    array->isRelated = true;
    return EXIT_SUCCESS;
}


/*  --- === Creating === --- */

LEXMKIntervalArrayRef LEXMKIntervalArrayCreate()
{
    LEXMKIntervalArrayRef array = malloc(sizeof(LEXMKIntervalArray));
    LEXMKIntervalArrayInit(array);
    return array;
}

LEXMKIntervalArrayRef LEXMKIntervalArrayCreateWithIntervals(LEXMKInterval * intervals, unsigned int length, bool isRelated)
{
    LEXMKIntervalArrayRef array = malloc(sizeof(LEXMKIntervalArray));
    if (intervals != NULL) {
        size_t size = sizeof(LEXMKInterval) * length;
        array->intervals = malloc(size);
        memcpy(array->intervals, intervals, size);
    }
    else {
        array->intervals = NULL;
    }
    array->length = length;
    array->isRelated = isRelated;
    return array;
}

/*  --- === Accessors === --- */

int LEXMKIntervalArrayGetIntervals(LEXMKIntervalArrayRef array, LEXMKInterval ** outIntervals, unsigned int *outLength)
{
    if (outIntervals != NULL) {
        *outIntervals = array->intervals;
    }
    if (outLength != NULL) {
        *outLength = array->length;
    }
    return EXIT_SUCCESS;
}

unsigned int LEXMKIntervalArrayGetLength(LEXMKIntervalArrayRef array)
{
    return array->length;
}

bool LEXMKIntervalArrayGetIsRelative(LEXMKIntervalArrayRef array)
{
    return array->isRelated;
}