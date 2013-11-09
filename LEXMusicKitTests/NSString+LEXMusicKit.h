//
//  NSString+LEXMusicKit.h
//  iChord
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 iTech. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LEXMKInterval.h"
#import "LEXMKDiatonicFunction.h"

enum  {
    LEXMKIntervalSignNotationDefault,
    LEXMKIntervalSignNotationSemitonesAndTones,
    LEXMKIntervalSignNotationSemitonesOnly,
};
typedef int LEXMKIntervalSignNotation;

NSString * NSStringFromLEXMKIntervalUsingDefaultNotation(LEXMKInterval interval);
NSString * NSStringFromLEXMKIntervalUsingSemitonesAndTones(LEXMKInterval interval);
NSString * NSStringFromLEXMKIntervalUsingSignNotation(LEXMKInterval interval, LEXMKIntervalSignNotation notation);

NSString * NSStringFromLEXMKDiatonicFunctionUsingNotation(LEXMKDiatonicFunction func,
                                                          LEXMKIntervalSignNotation notation,
                                                          NSString *signSeparator);

@interface NSString (LEXMusicKit)

@end
