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
    LEXMKIntervalArray array;
    {
        LEXMKInterval intervals[3] = {LEXMKIntervalPerfectUnison, LEXMKIntervalMinorThird, LEXMKIntervalPerfectFifth};
        array = LEXMKIntervalArrayCreateWithIntervals(intervals,
                                                      3,
                                                      false);
    }
    XCTAssertFalse(array.isRelated, @"Array created with false 'isRealted' parameter should have false value for 'isRelated'");
    XCTAssertTrue(array.intervals[0] == LEXMKIntervalPerfectUnison, @"Array should have right intervals. Expected %d, but it's %d", LEXMKIntervalPerfectUnison, array.intervals[0]);
    XCTAssertTrue(array.intervals[1] == LEXMKIntervalMinorThird, @"Array should have right intervals. Expected %d, but it's %d", LEXMKIntervalMinorThird, array.intervals[1]);
    XCTAssertTrue(array.intervals[2] == LEXMKIntervalPerfectFifth, @"Array should have right intervals. Expected %d, but it's %d", LEXMKIntervalPerfectFifth, array.intervals[2]);
    XCTAssertTrue(array.length == 3, @"Array should have right length");
    
    {
        LEXMKIntervalArray otherArray = LEXMKIntervalArrayCreateByAddingIntervalToArray(array, LEXMKIntervalMinorSixth);
        LEXMKIntervalArrayDestroy(array);
        array = otherArray;
    }
    XCTAssertTrue(array.length == 4, @"Array created by adding interval should have right length");
    XCTAssertTrue(array.intervals[2] == LEXMKIntervalPerfectFifth, @"Array created by adding array should have right old interval at the right index. Expected %d, but it's %d", LEXMKIntervalPerfectFifth, array.intervals[2]);
    XCTAssertTrue(array.intervals[3] == LEXMKIntervalMinorSixth, @"Array created by adding interval should have right interval at the right index. Expected %d, but it's %d", LEXMKIntervalMinorSixth, array.intervals[3]);
    
    {
        LEXMKInterval *intervals = malloc(sizeof(LEXMKInterval) * 3);
        intervals[0] = LEXMKIntervalMinorSecond;
        intervals[1] = LEXMKIntervalMinorSeventh;
        intervals[2] = LEXMKIntervalMajorSeventh;
        LEXMKIntervalArray otherArray = LEXMKIntervalArrayCreateByAddingIntervalsToArray(array,
                                                                                         intervals,
                                                                                         3);
        LEXMKIntervalArrayDestroy(array);
        array = otherArray;
    }
    XCTAssertTrue(array.length == 7, @"Array created by adding intervals should have right length");
    XCTAssertTrue(array.intervals[6] == LEXMKIntervalMajorSeventh, @"Array created by adding intervals should have right interval at the right index");
    
    LEXMKIntervalArrayDestroy(array);
}

@end
