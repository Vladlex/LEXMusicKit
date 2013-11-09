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

- (void)intervalValuesTest
{
    XCTAssertTrue(LEXMKIntervalPerfectUnison == 0, @"Unison (Tonic) should be 0");
    XCTAssertTrue(LEXMKIntervalAugmentedFourth == LEXMKIntervalDiminishedFifth, @"Augmented fourth and diminished fifth should have same value");
    XCTAssertTrue(LEXMKIntervalPerfectOctave == 12, @"Octave should be equal 12");
}

- (void)intervalsMathTest
{
    LEXMKInterval interval;
    
    interval = LEXMKIntervalPitchInterval(LEXMKIntervalPerfectUnison, LEXMKIntervalPerfectOctave);
    XCTAssertTrue(interval == 0, @"Interval perfect unisone and perfect octave should be twelwe");
    
    interval = LEXMKIntervalPitchIntervalClass(LEXMKIntervalPerfectFifth, LEXMKIntervalPerfectFifth + 12 * 3);
    XCTAssertTrue(interval == LEXMKIntervalPerfectFifth, @"Pitch interval classes should be limited by one octave");
    
    interval = LEXMKIntervalPerfectFourth;
    XCTAssertTrue(interval == LEXMKIntervalPitchIntervalClass(LEXMKIntervalPerfectFifth, LEXMKIntervalPerfectOctave),
                  @"Fourth and  pitcht interval class of fifth and octave should have same value");
    
    interval = LEXMKIntervalMinorSecond;
    XCTAssertTrue(interval == LEXMKIntervalOctaveLimitedInvertedInterval(LEXMKIntervalMajorSeventh + LEXMKIntervalPerfectOctave * 2), @"Inverted major seventh at any octave should be minor second");
}

- (void)intervalGetOctaveTest
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

@end
