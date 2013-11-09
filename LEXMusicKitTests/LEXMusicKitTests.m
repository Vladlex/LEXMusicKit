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

@interface LEXMusicKitTests : XCTestCase

@end

@implementation LEXMusicKitTests

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
    
    func = LEXMKDiatonicFunctionCreateWithIntervals(0, 1, 2, 3, 4, 5, 6);
    XCTAssertFalse(LEXMKDiatonicFunctionIsEqualToFunction(func, LEXMKDiatonicFunctionNull), @"Diatonic function equaling function works bad");
    XCTAssertFalse(LEXMKDiatonicFunctionIsValid(func), @"Diatonic function validation function works bad");
}

- (void)testDiatonicFunctionCreationWithUncompletedRanges
{
    LEXMKDiatonicFunction func1 = LEXMKDiatonicFunctionCreateWithMode(LEXMKModeMajorNatural);
    int * ranges = malloc(sizeof(int) * 6);
    // 2,2,1,2,2,2,1
    ranges[0] = 2;
    ranges[1] = 2;
    ranges[2] = 1;
    ranges[3] = 2;
    ranges[4] = 2;
    ranges[5] = 2;
    QLog(@"Func 1 %@", NSStringFromLEXMKDiatonicFunctionUsingNotation(func1, LEXMKIntervalSignNotationSemitonesAndTones, @" "));
    
    LEXMKDiatonicFunction func2 = LEXMKDiatonicFunctionCreateWithIntervalVector(ranges);
    XCTAssertFalse(LEXMKDiatonicFunctionIsValid(func2), @"Function created with uncompleted interval should not be valid");
    
    QLog(@"Func 2 %@", NSStringFromLEXMKDiatonicFunctionUsingNotation(func1, LEXMKIntervalSignNotationSemitonesAndTones, @" "));
    
    func2 = LEXMKDiatonicFunctionCreateWithUncompletedIntervalVector(ranges);
    QLog(@"Func 2 %@", NSStringFromLEXMKDiatonicFunctionUsingNotation(func1, LEXMKIntervalSignNotationSemitonesAndTones, @" "));
    XCTAssertTrue(LEXMKDiatonicFunctionIsValid(func2), @"Function created with uncompleted intervals vector by automcompletion method should be valid");
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Functions with one mode created by different methods should be the same");
    
    free(ranges);
}

- (void)testDiatonicFunctionCreation
{
    LEXMKDiatonicFunction func1 = LEXMKDiatonicFunctionCreateWithMode(LEXMKModeMajorNatural);
    int * ranges = malloc(sizeof(int) * 7);
    // 2,2,1,2,2,2,1
    ranges[0] = 2;
    ranges[1] = 2;
    ranges[2] = 1;
    ranges[3] = 2;
    ranges[4] = 2;
    ranges[5] = 2;
    ranges[6] = 1;
    LEXMKDiatonicFunction func2 = LEXMKDiatonicFunctionCreateWithIntervalVector(ranges);
    
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Diatonic functions created by different methods should be equal");
    
    func2 = LEXMKDiatonicFunctionCreateWithIntervals(ranges[0],
                                                     ranges[1],
                                                     ranges[2],
                                                     ranges[3],
                                                     ranges[4],
                                                     ranges[5],
                                                     ranges[6]);
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Diatonic functions created by different methods should be equal");
    
    for (int i = 0; i <= 6 ; i++) {
        func2.ranges[i] = ranges[i];
    }
    free(ranges);
    XCTAssertTrue(LEXMKDiatonicFunctionIsEqualToFunction(func1, func2), @"Diatonic functions created by different methods should be equal");
    
}


- (void)testAllModesForConstructingDiatonicFunctions
{
    LEXMKDiatonicFunction func;
    for (LEXMKMode mode = 0; mode < LEXMKModeModesCount; mode ++) {
        func = LEXMKDiatonicFunctionCreateWithMode(mode);
        XCTAssertFalse(LEXMKDiatonicFunctionIsEqualToFunction(func, LEXMKDiatonicFunctionNull),
                       @"There is no diatonic function for mode %d", mode);
        
        XCTAssertTrue(LEXMKDiatonicFunctionIsValid(func),
                      @"Diatonic function created by mode %d should be valid", mode);
        
    }
    
}


@end
