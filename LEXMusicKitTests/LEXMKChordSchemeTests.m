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
                                                       LEXMKChordSus2,
                                                       &length);
    XCTAssertTrue(length == 2, @"Expected length should be %u, but it's %u", 2, length);
    XCTAssertTrue(intervals[0] == LEXMKIntervalMajorSecond, @"Expected first interval is %d, but it's %d", LEXMKIntervalPerfectFourth, intervals[0]);
    XCTAssertTrue(intervals[1] == LEXMKIntervalPerfectFifth, @"Expected second interval is %d, but it's %d", LEXMKIntervalPerfectFifth, intervals[1]);
    free(intervals);
    
    intervals = LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordModeMajor,
                                                             LEXMKChordSus4,
                                                             &length);
    XCTAssertTrue(length == 2, @"Expected length should be %u, but it's %u", 2, length);
    XCTAssertTrue(intervals[0] == LEXMKIntervalPerfectFourth, @"Expected first interval is %d, but it's %d", LEXMKIntervalPerfectFourth, intervals[0]);
    XCTAssertTrue(intervals[1] == LEXMKIntervalPerfectFifth, @"Expected second interval is %d, but it's %d", LEXMKIntervalPerfectFifth, intervals[1]);
    free(intervals);
    
}

- (void)testSchemeCreatingIntervalsForDiminishedMode

{
    unsigned int length;
    LEXMKInterval *intervals;
    intervals = LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordModeDim,
                                                             LEXMKChordSusNone,
                                                             &length);
    XCTAssertTrue(length == 3, @"Expected length for aug mode is 3, but it's %u", length);
    LEXMKInterval lastInterval = 0;
    for (int i = 0; i < length; i++) {
        lastInterval += LEXMKIntervalMinorThird;
        XCTAssertTrue(intervals[i] == lastInterval, @"interval at index %d should be %d, but it's %d", i, lastInterval, intervals[i]);
    }
    free(intervals);
}

- (void)testSchemeCreatingIntervalsForAugmentedMode
{
    unsigned int length;
    LEXMKInterval *intervals;
    intervals = LEXMKIntervalCreateIntervalsForModeAndSusVal(LEXMKChordModeAug,
                                                             LEXMKChordSusNone,
                                                             &length);
    XCTAssertTrue(length == 2, @"Expected length is %u, but it's %u", 2, length);
    XCTAssertTrue(intervals != NULL, @"Expected non-null intervals");
    LEXMKInterval lastInterval = 0;
    for (int i = 0; i < length; i ++) {
        lastInterval += LEXMKIntervalMajorThird;
        XCTAssertTrue(lastInterval == intervals[i], @"Interval should be %u, but it's %u", lastInterval, intervals[i]);
    }
    free(intervals);
}

- (void)testChordGeneratingIntervals
{
    LEXMKChordOpt opt = LEXMKChordOptMakeWithTypeAndInfo(LEXMKChordOptTypeWide,
                                                         LEXMKIntervalMinorSeventh);
    LEXMKChordOpt opts[1] = {opt};
    LEXMKChordSchemeRef scheme = LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordModeMajor, opts, 1);
    LEXMKChordOpt *unrecOpts = NULL;
    unsigned int unrecOptsLength = 0;
    LEXMKIntervalArrayRef array = LEXMKIntervalArrayCreateWithScheme(scheme,
                                                                     LEXMKChordRecognitionNotationClassic
                                                                     , &unrecOpts, &unrecOptsLength);
    XCTAssertTrue(array != NULL, @"Expected non-null array");
    XCTAssertTrue(unrecOptsLength == 0 && unrecOpts == NULL, @"Expected that all opts are recognized");
}

@end
