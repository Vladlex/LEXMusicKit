//
//  LEXMKMode.h
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT//


#ifndef LEXMKMode_h
#define LEXMKMode_h

enum  {
    LEXMKModeMajorNatural = 0,       // T T S T T T S
    LEXMKModeMinorNatural,       // T S T T S T T
    LEXMKModeMinorHarmonic,      // T S T T T T S
    LEXMKModeMinorMelodic,        // T S T T H 3S S
    
    // ...
    LEXMKModeNonexistent         // Use just for counting all known modes. All inserting modes should be added BEFORE this val.
};
typedef int LEXMKMode;

#define LEXMKModeModesCount LEXMKModeNonexistent

/// In guitar chords building usually uses ony natural modes
#define LEXMKModeMajor LEXMKModeMajorNatural
#define LEXMKModeMinor LEXMKModeMinorNatural

#endif //LEXMKMode_h