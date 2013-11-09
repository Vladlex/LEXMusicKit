//
//  LEXMusicKitTests.m
//  LEXMusicKitTests
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "LEXMusicKit.h"

#import "LEXLog.h"
#import "NSString+LEXMusicKit.h"

#define LEXMKDFuncToString(func) NSStringFromLEXMKDiatonicFunctionUsingNotation(func, LEXMKIntervalSignNotationSemitonesAndTones, @" ")

@interface LEXMKDiatonicFunctionTests : XCTestCase

@end

@implementation LEXMKDiatonicFunctionTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testMusicDegree
{
    XCTAssertTrue(LEXMKDegreeIsStable(LEXMKDegreeTonic),
                  @"Tonic should be stable degree.");
    XCTAssertTrue(LEXMKDegreeIsStable(2),
                  @"Mediant should be stable");
    XCTAssertTrue(LEXMKDegreeIsStable(4),
                  @"Dominant should be stable");
}

- (void)testBasicDiatonicFunction
{
    LEXMKDiatonicFunction func = LEXMKDiatonicFunctionNull;
    BOOL isFuncValid = LEXMKDiatonicFunctionIsValid(func);
    XCTAssertFalse(isFuncValid, @"Null diatonic function should not be valid");
    
    func = LEXMKDiatonicFunctionMakeWithIntervals(0, 1, 2, 3, 4, 5, 6);
    XCTAssertFalse(LEXMKDiatonicFunctionIsEqualToFunction(func, LEXMKDiatonicFunctionNull), @"Diatonic function equaling function works bad");
    XCTAssertFalse(LEXMKDiatonicFunctionIsValid(func), @"Diatonic function validation function works bad");
    
    func = LEXMKDiatonicFunctionMakeWithMode(LEXMKModeMajorNatural);
    XCTAssertTrue(LEXMKDiatonicFunctionIsValid(func), @"Functions made by LEXMKMode should always be valid");
}

- (void)testDiatonicFunctionCreationWithUncompletedIntervals
{
    LEXMKDiatonicFunction func1 = LEXMKDiatonicFunctionMakeWithMode(LEXMKModeMajorNatural);
    int * intervals = malloc(sizeof(int) * 6);
    // 2,2,1,2,2,2,1
    intervals[0] = 2;
    intervals[1] = 2;
    intervals[2] = 1;
    intervals[3] = 2;
    intervals[4] = 2;
    intervals[5] = 2;
    
    LEXMKDiatonicFunction func2 = LEXMKDiatonicFunctionMakeWithIntervalVector(intervals);
    XCTAssertFalse(LEXMKDiatonicFunctionIsValid(func2), @"Function made with uncompleted interval should not be valid");
    func2 = LEXMKDiatonicFunctionMakeWithUncompletedIntervalVector(intervals);
    QLog(@"Func 1: %@\nFunc 2: %@", LEXMKDFuncToString(func1), LEXMKDFuncToString(func2));
    QLog(@"Func 2: %@", NSStringFromLEXMKDiatonicFunctionUsingNotation(func2, LEXMKIntervalSignNotationDefault, @" "));
    XCTAssertTrue(LEXMKDiatonicFunctionIsValid(func2), @"Function made with uncompleted intervals vector by automcompletion method should be valid");
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Functions with one mode made by different methods should be the same");
    
    free(intervals);
}

- (void)testDiatonicFunctionCreation
{
    LEXMKDiatonicFunction func1 = LEXMKDiatonicFunctionMakeWithMode(LEXMKModeMajorNatural);
    int * intervals = malloc(sizeof(int) * 7);
    // 2,2,1,2,2,2,1
    intervals[0] = 2;
    intervals[1] = 2;
    intervals[2] = 1;
    intervals[3] = 2;
    intervals[4] = 2;
    intervals[5] = 2;
    intervals[6] = 1;
    LEXMKDiatonicFunction func2 = LEXMKDiatonicFunctionMakeWithIntervalVector(intervals);
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Diatonic functions made by different methods should be equal");
    int defIdx = LEXMKDiatonicFunctionDifferentIntervalIndexInFunctions(func1, func2);
    XCTAssertTrue(defIdx == -1, @"The different interval index for equal functions should be -1");
    
    func2 = LEXMKDiatonicFunctionMakeWithIntervals(intervals[0],
                                                     intervals[1],
                                                     intervals[2],
                                                     intervals[3],
                                                     intervals[4],
                                                     intervals[5],
                                                     intervals[6]);
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Diatonic functions made by different methods should be equal");
    
    for (int i = 0; i <= 6 ; i++) {
        func2.intervals[i] = intervals[i];
    }
    free(intervals);
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Diatonic functions made by different methods should be equal");
    
}


- (void)testAllModesForConstructingDiatonicFunctions
{
    LEXMKDiatonicFunction func;
    for (LEXMKMode mode = 0; mode < LEXMKModeModesCount; mode ++) {
        func = LEXMKDiatonicFunctionMakeWithMode(mode);
        XCTAssertFalse(LEXMKDiatonicFunctionIsEqualToFunction(func, LEXMKDiatonicFunctionNull),
                       @"There is no diatonic function for mode %d", mode);
        
        XCTAssertTrue(LEXMKDiatonicFunctionIsValid(func),
                      @"Diatonic function made by mode %d should be valid", mode);
        
    }
    
}


@end
