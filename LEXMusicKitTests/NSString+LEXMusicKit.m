//
//  NSString+LEXMusicKit.m
//  iChord
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 iTech. All rights reserved.
//

#import "NSString+LEXMusicKit.h"
#import "LEXLog.h"

NSString * NSStringFromLEXMKIntervalUsingDefaultNotation(LEXMKInterval interval)
{
    switch (interval) {
        case LEXMKIntervalPerfectUnison:
            return @"P1";
        case LEXMKIntervalMinorSecond:
            return @"m2";
        case LEXMKIntervalMajorSecond:
            return @"M2";
        case LEXMKIntervalMinorThird:
            return @"m3";
        case LEXMKIntervalMajorThird:
            return @"M3";
        case LEXMKIntervalPerfectFourth:
            return @"P4";
        case LEXMKIntervalDiminishedFifth:
            return @"d5";
        case LEXMKIntervalMinorSixth:
            return @"m6";
        case LEXMKIntervalMajorSixth:
            return @"M6";
        case LEXMKIntervalMinorSeventh:
            return @"m7";
        case LEXMKIntervalMajorSeventh:
            return @"M7";
        case LEXMKIntervalPerfectOctave:
            return @"P8";
        default:
        {
            int octave = LEXMKIntervalGetOctave(interval);
            LEXMKInterval simpleInterval = interval % 12;
            // Dangerous area. Be aware of recursion.
            NSString *simpleIntervalSign = NSStringFromLEXMKIntervalUsingDefaultNotation(simpleInterval);
            return [NSString stringWithFormat:@"%dO+%@", octave, simpleIntervalSign];
        }
            break;
    }
    return nil;
}

NSString * NSStringFromLEXMKIntervalUsingSemitonesAndTones(LEXMKInterval interval)
{
    NSString *sign;
    switch (interval) {
        case LEXMKIntervalPerfectUnison:
            sign = @"0";
            break;
        case LEXMKIntervalMinorSecond:
            sign = @"S";
            break;
        case LEXMKIntervalMajorSecond:
            sign = @"T";
            break;
        default:
        {
            int integralPart = interval / 2;
            BOOL isEndedWithSemitone = ((interval % 12) != 0);
            sign = [NSString stringWithFormat:@"%dT", integralPart];
            if (isEndedWithSemitone) {
                sign = [sign stringByAppendingString:@"+S"];
            }
        }
            break;
    }
    return sign;
}

NSString * NSStringFromLEXMKIntervalUsingSignNotation(LEXMKInterval interval, LEXMKIntervalSignNotation notation)
{
    NSString *sign;
    switch (notation) {
        case LEXMKIntervalSignNotationDefault:
            sign = NSStringFromLEXMKIntervalUsingDefaultNotation(interval);
            break;
        case LEXMKIntervalSignNotationSemitonesOnly:
            sign = [NSString stringWithFormat:@"%d", interval];
            break;
        case LEXMKIntervalSignNotationSemitonesAndTones:
            sign = NSStringFromLEXMKIntervalUsingSemitonesAndTones(interval);
            break;
        default:
            sign = @"~";
            break;
    }
    return sign;
}

NSString * NSStringFromLEXMKDiatonicFunctionUsingNotation(LEXMKDiatonicFunction func,
                                                          LEXMKIntervalSignNotation notation,
                                                          NSString * signSeparator)
{
    NSMutableString *signs = [NSMutableString string];
    for (int i = 0; i < 7; i++) {
        LEXMKInterval interval = func.intervals[i];
        [signs appendString:NSStringFromLEXMKIntervalUsingSignNotation(interval,
                                                                       notation)];
        if (i != 6 && signSeparator) {
            [signs appendString:signSeparator];
        }
    }
    return signs;
}


@implementation NSString (LEXMusicKit)

@end
