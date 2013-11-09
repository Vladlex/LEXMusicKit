//
//  LEXMKDegree.cpp
//
//  Created by Alexei Gordeev on 09.11.13.
//  Copyright (c) 2013 Alexei Gordeed
//  MIT Licese: http://opensource.org/licenses/MIT


#include "LEXMKDegree.h"


bool LEXMKDegreeIsUnstable(LEXMKDegree degree)
{
    return !LEXMKDegreeIsStable(degree);
}

bool LEXMKDegreeIsStable(LEXMKDegree degree)
{
    return (degree == LEXMKDegreeTonic ||
            degree == LEXMKDegreeMediant ||
            degree == LEXMKDegreeDominant );
}



