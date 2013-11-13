//
//  LEXMKDegree.h
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT//

#ifndef LEXMKDegree_h
#define LEXMKDegree_h

#include <stdbool.h>

enum  {
    LEXMKDegreeTonic = 0,        // (T)
    LEXMKDegreeSupertonic,       // One whole step from tonic
    LEXMKDegreeMediant,          // Midway between tonic and dominant
    LEXMKDegreeSubdominant,      // (S) Lower dominant, same interval below tonic dominant is above tonic
    LEXMKDegreeDominant,         // (D) 2nd importance to the tonic
    LEXMKDegreeSubmediant,       // Lower mediant, midway between tonic and subdominant
    LEXMKDegreeLeadingNote       // One whole step below tonic. If this degree lowered it's usually called subtonic.
};
typedef int LEXMKDegree;

/// Check if given degree is unstable. Unstable degrees are supertonic, subdominant, submediant and leading note/subtonic.
bool LEXMKDegreeIsUnstable(LEXMKDegree degree);

/// Check if given degree is stable. Stable degrees are tonic, mediant and dominant.
bool LEXMKDegreeIsStable(LEXMKDegree degree);

#endif //LEXMKDegree_h
