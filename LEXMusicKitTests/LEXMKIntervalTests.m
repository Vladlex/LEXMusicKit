//
//  LEXMKIntervalTests.m
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "LEXMKInterval.h"

@interface LEXMKIntervalTests : XCTestCase

@end

@implementation LEXMKIntervalTests

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

- (void)testIntervalValues
{
    XCTAssertTrue(LEXMKIntervalPerfectUnison == 0, @"Unison (Tonic) should be 0");
    XCTAssertTrue(LEXMKIntervalAugmentedFourth == LEXMKIntervalDiminishedFifth, @"Augmented fourth and diminished fifth should have same value");
    XCTAssertTrue(LEXMKIntervalPerfectOctave == 12, @"Octave should be equal 12");
}

- (void)testIntervalMath
{
    LEXMKInterval interval;

    interval = LEXMKIntervalPitchIntervalClass(LEXMKIntervalPerfectFifth, LEXMKIntervalPerfectFifth + 12 * 3);
    XCTAssertTrue(interval == 0, @"Same intervals on different octaves should have pitch interval class 0");
    
    interval = LEXMKIntervalPerfectFourth;
    XCTAssertTrue(interval == LEXMKIntervalPitchIntervalClass(LEXMKIntervalPerfectFifth, LEXMKIntervalPerfectOctave),
                  @"Fourth and  pitcht interval class of fifth and octave should have same value");
    
    interval = LEXMKIntervalMinorSecond;
    XCTAssertTrue(interval == LEXMKIntervalOctaveLimitedInvertedInterval(LEXMKIntervalMajorSeventh + LEXMKIntervalPerfectOctave * 2), @"Inverted major seventh at any octave should be minor second");
}

- (void)testIntervalGetOctave
{
    LEXMKInterval interval;
    for (int i = 0; i < 5; i++) {
        interval = LEXMKIntervalMajorSeventh + LEXMKIntervalPerfectOctave * i;
        if (LEXMKIntervalGetOctave(interval) != i) {
            XCTAssertTrue(NO, @"Fail to get valid ocatev from interval %d. Expected %d, but get %d", interval, i, LEXMKIntervalGetOctave(interval));
            break;
        }
    }
}

- (void)testConsonancesAndDissonances
{
    LEXMKInterval interval;
    bool isConsonance;
    bool isPerfect;
    
    LEXMKInterval intervals [5] = {LEXMKIntervalPerfectUnison,
        LEXMKIntervalPerfectOctave |
        LEXMKIntervalPerfectFourth |
        LEXMKIntervalPerfectFifth |
        LEXMKIntervalPerfectUnison + 12 * 4};
    for (int i = 0; i < 5; i++) {
        interval = intervals[i];
        isConsonance = LEXMKIntervalIsConsonance(interval, &isPerfect);
        XCTAssertTrue(isConsonance && isPerfect, @"Knowingly consonance and perfect interval fail. Interval: %d, isConsonance: %@, isPerfect: %@", interval, isConsonance ? @"Y" : @"N", isPerfect ? @"Y" : @"N");
    }
    
    interval = LEXMKIntervalMajorSixth;
    isConsonance = LEXMKIntervalIsConsonance(interval, NULL);
    XCTAssertTrue(isConsonance, @"Knowingly consonance should be consonance. Also function should have not any problem with passed NULL");
    
    isConsonance = LEXMKIntervalIsConsonance(LEXMKIntervalMajorSecond, &isPerfect);
    XCTAssertFalse(isConsonance, @"Dissonance interval should defined as dissonance");
    
}

@end
