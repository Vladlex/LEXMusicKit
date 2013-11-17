//
//  LEXMKIntervalArrayTests.m
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 12.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#import <XCTest/XCTest.h>

#include "LEXMKIntervalArray.h"

@interface LEXMKIntervalArrayTests : XCTestCase

@end

@implementation LEXMKIntervalArrayTests

- (void)setUp
{
    [super setUp];
    // Put setup code here; it will be run once, before the first test case.
}

- (void)tearDown
{
    // Put teardown code here; it will be run once, after the last test case.
    [super tearDown];
}

- (void)testInteralArrayInit
{
    LEXMKIntervalArrayRef array = malloc(sizeof(LEXMKIntervalArrayRef));
    LEXMKIntervalArrayInit(array);
    
    LEXMKInterval *intervals;
    unsigned int length;
    LEXMKIntervalArrayGetIntervalsAndLength(array, &intervals, &length);
    XCTAssert(intervals == NULL, @"In inited array intervals should be NULL");
    XCTAssert(length == 0, @"Array of inited array should be 0 but it's %u", length);
    
    LEXMKIntervalArrayDestroy(array);
}

- (void)testEmptyIntervalArrayCreation
{
    LEXMKIntervalArrayRef array = LEXMKIntervalArrayCreate();
    XCTAssert(LEXMKIntervalArrayGetIntervals(array) == NULL, @"In inited array intervals should be NULL");
    XCTAssert(LEXMKIntervalArrayGetLength(array) == 0, @"Array of inited array should be 0 but it's %u", LEXMKIntervalArrayGetLength(array));
    LEXMKIntervalArrayDestroy(array);
}

- (void)testIntervalArrayCretionWithIntervals
{
    LEXMKInterval srcIntervals[2] = {LEXMKIntervalPerfectUnison,
        LEXMKIntervalPerfectFifth};
    LEXMKIntervalArrayRef array = LEXMKIntervalArrayCreateWithIntervals(srcIntervals,
                                                                        2, false);
    LEXMKInterval *intervals = LEXMKIntervalArrayGetIntervals(array);
    unsigned int length = LEXMKIntervalArrayGetLength(array);
    XCTAssert(length == 2, @"Expected array length %u, but it's %u", 2, length);
    XCTAssert(intervals[0]==srcIntervals[0], @"Expected array interval %d, but it's %d", srcIntervals[0], intervals[0]);
    XCTAssert(intervals[1]==srcIntervals[1], @"Expected array interval %d, but it's %d", srcIntervals[1], intervals[1]);
    LEXMKIntervalArrayDestroy(array);
}

- (void)testIntervalArrayCreationWithAnotherInterval
{
    LEXMKInterval oneIntArray[1] = {LEXMKIntervalPerfectUnison};
    LEXMKIntervalArrayRef srcArray = LEXMKIntervalArrayCreateWithIntervals(oneIntArray, 1, true);
    LEXMKIntervalArrayRef rsltArray = LEXMKIntervalArrayCreateByAddingIntervalToArray(srcArray,
                                                                                      LEXMKIntervalMinorThird);
    XCTAssert(LEXMKIntervalArrayGetIntervals(rsltArray) != NULL, @"Expected non-null intervals");
    unsigned int rsltLength = LEXMKIntervalArrayGetLength(rsltArray);
    XCTAssert(rsltLength == 2, @"Expected array length %u but it's %u", 2, rsltLength);
    
    LEXMKIntervalArrayDestroy(rsltArray);
    
    LEXMKInterval srcIntervals[2] = {LEXMKIntervalMinorThird, LEXMKIntervalPerfectFifth};
    rsltArray = LEXMKIntervalArrayCreateByAddingIntervalsToArray(srcArray, srcIntervals, 2);
    
    XCTAssert(LEXMKIntervalArrayGetIntervals(rsltArray) != NULL, @"Ecpected non-null intervals");
    rsltLength = LEXMKIntervalArrayGetLength(rsltArray);
    XCTAssert(rsltLength == 3, @"Expected array length %u, but it's %u", 3, rsltLength);
    LEXMKIntervalArrayDestroy(rsltArray);
}

- (void)testIntervalArrayIntervalInserting

{
    LEXMKIntervalArrayRef array;
    LEXMKInterval *intervals;
    int funcExit = -1;
    
    
    // 1. Null array;
    array = NULL;
    intervals = malloc(sizeof(LEXMKInterval));
    intervals[0] = LEXMKIntervalPerfectFourth;
    funcExit = LEXMKIntervalArrayInsertIntervalAtIndex(array, intervals[0], 0);
    XCTAssert(funcExit == EXIT_FAILURE, @"Expeting failure when inserting interval to null array");
    
    // 2. One-element array (inserting at the last index)
    
    array = LEXMKIntervalArrayCreateWithIntervals(intervals, 1, true);
    free(intervals);
    funcExit = LEXMKIntervalArrayInsertIntervalAtIndex(array,
                                                       LEXMKIntervalPerfectFifth,
                                                       1);
    XCTAssert(funcExit == EXIT_SUCCESS, @"Expecting successfully function completion");
    unsigned int length = LEXMKIntervalArrayGetLength(array);
    XCTAssert(length == 2, @"Expecting array length %u, but it's %u", 2, length);
    intervals = LEXMKIntervalArrayGetIntervals(array);
    XCTAssert(intervals != NULL, @"Expecting non-null intervals afterr inserting interval to array");
    XCTAssert(intervals[0] == LEXMKIntervalPerfectFourth, @"Expecting first intervals array element to be %d, but it's %d", LEXMKIntervalPerfectFourth, intervals[0]);
    XCTAssert(intervals[1] == LEXMKIntervalPerfectFifth, @"Expecting second intervals array element to be %d, but it's %d", LEXMKIntervalPerfectFifth, intervals[1]);
    
    funcExit = LEXMKIntervalArrayInsertIntervalAtIndex(array, LEXMKIntervalPerfectOctave, 5);
    length = LEXMKIntervalArrayGetLength(array);
    XCTAssertTrue(funcExit == EXIT_FAILURE, @"Expecting failure when inserting interval at non-exists index %u to array with length %u", 5, length);
    LEXMKIntervalArrayDestroy(array);
    
}

@end
