//
//  LEXMKChordScheme.c
//  LEXMusicKit
//
//  Created by Vladlex on 17.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#include <stdio.h>

#include "LEXMKChordScheme.h"

struct LEXMKChordScheme {
    LEXMKChordMode mode;
    LEXMKChordOpt *opts;
    unsigned int optsLength;
};

