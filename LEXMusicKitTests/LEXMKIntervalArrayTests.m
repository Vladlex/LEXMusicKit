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

@end
