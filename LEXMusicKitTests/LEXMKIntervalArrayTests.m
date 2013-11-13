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

- (void)testIntervalArrayCreation
{
    LEXMKIntervalArrayRef array = malloc(sizeof(LEXMKIntervalArrayRef));
    LEXMKIntervalArrayInit(array);
    
    LEXMKInterval *intervals;
    unsigned int length;
    LEXMKIntervalArrayGetIntervals(array, &intervals, &length);
    XCTAssert(intervals == NULL, @"In inited array intervals should be NULL");
    XCTAssert(length == 0, @"Array of inited array should be 0 but it's %u", length);
    
    LEXMKIntervalArrayDestroy(array);
    
    length = 6;
    intervals = malloc(sizeof(LEXMKInterval) * length);
    for (int i = 0; i < length; i++) {
        intervals[i] = i;
    }
    array = LEXMKIntervalArrayCreateWithIntervals(intervals,
                                                  length,
                                                  true);
    free(intervals);
    LEXMKIntervalArrayGetIntervals(array, &intervals, NULL);
    
    BOOL allIntervalsAreValid = YES;
    for (int i = 0; i < length; i ++) {
        if (intervals[i]!=i) {
            allIntervalsAreValid = NO;
            break;
        }
    }
    XCTAssertTrue(allIntervalsAreValid, @"Some of interval is wrong");
    LEXMKIntervalArrayDestroy(array);
}

@end
