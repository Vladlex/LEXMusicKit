//
//  LEXMKChordSchemeTests.m
//  LEXMusicKit
//
//  Created by Vladlex on 17.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "LEXMKChordScheme.h"

@interface LEXMKChordSchemeTests : XCTestCase

@end

@implementation LEXMKChordSchemeTests

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

- (void)testSchemeCreation

{
    LEXMKChordSchemeRef scheme = LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordModeMajor,
                                                                       NULL,
                                                                        0);
    XCTAssert(scheme != NULL, @"Scheme excpeted to be");
    XCTAssert(LEXMKChordSchemeGetOptsLength(scheme) == 0, @"Scheme opts length expected to be 0");
    XCTAssert(LEXMKChordSchemeGetOpts(scheme) == NULL, @"Scheme opts expected to be NULL");
    LEXMKChordSchemeDestroy(scheme);
}

- (void)testSchemeCreatingIntervalsForMajorMode
{
    unsigned int length;
    LEXMKInterval *intervals = LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordModeMajor,
                                                                      LEXMKChordSusNone,
                                                                      &length);
    XCTAssert(length == 2, @"Expected length should be %u, but it's %u", 2, length);
    XCTAssert(intervals[0] == LEXMKIntervalMajorThird, @"Expected first interval is %d, but it's %d", LEXMKIntervalMajorThird, intervals[0]);
    XCTAssert(intervals[1] == LEXMKIntervalPerfectFifth, @"Expected second interval is %d, but it's %d", LEXMKIntervalPerfectFifth, intervals[1]);
    free(intervals);
    
    intervals = LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordModeMajor,
                                                       LEXMKchordSus2,
                                                       &length);
    XCTAssert(length == 2, @"Expected length should be %u, but it's %u", 2, length);
    XCTAssert(intervals[0] == LEXMKIntervalMajorSecond, @"Expected first interval is %d, but it's %d", LEXMKIntervalMajorThird, intervals[0]);
    XCTAssert(intervals[1] == LEXMKIntervalPerfectFifth, @"Expected second interval is %d, but it's %d", LEXMKIntervalPerfectFifth, intervals[1]);
    free(intervals);

}

@end
