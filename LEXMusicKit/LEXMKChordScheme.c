//
//  LEXMKChordScheme.c
//  LEXMusicKit
//
//  Created by Vladlex on 17.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "LEXMKChordScheme.h"

typedef struct _LEXMKChordScheme {
    LEXMKChordMode mode;
    LEXMKChordOpt *opts;
    unsigned int optsLength;
} LEXMKChordScheme;

LEXMKChordSchemeRef LEXMKChordSchemeCreateWithModeAndOpts(LEXMKChordMode mode, LEXMKChordOpt * opts, unsigned int optsLength)
{
    
    LEXMKChordSchemeRef scheme;
    LEXMKChordOpt *schemeOpts;
    
    scheme = malloc(sizeof(LEXMKChordScheme));
    scheme->mode = mode;
    if (optsLength > 0) {
        size_t optSize = sizeof(LEXMKChordOpt) * optsLength;
        schemeOpts = malloc(optSize);
        memcpy(schemeOpts, opts, optSize);
    }
    else {
        schemeOpts = NULL;
    }
    scheme->opts = schemeOpts;
    scheme->optsLength = optsLength;
    return scheme;
}

int LEXMKChordSchemeDestroy(LEXMKChordSchemeRef scheme)
{
    if (scheme->opts != NULL) {
        free(scheme->opts);
    }
    free(scheme);
    return EXIT_SUCCESS;
}

LEXMKChordMode LEXMKChordSchemeGetMode(LEXMKChordSchemeRef scheme)
{
    return scheme->mode;
}

unsigned int LEXMKChordSchemeGetOptsLength(LEXMKChordSchemeRef scheme)
{
    return scheme->optsLength;
}

LEXMKChordOpt * LEXMKChordSchemeGetOpts(LEXMKChordSchemeRef scheme)
{
    return scheme->opts;
}

LEXMKInterval *LEXMKChordSchemeGetIntervals(LEXMKChordSchemeRef scheme, bool isRelated)
{
    
    return NULL;
}

LEXMKIntervalArrayRef LEXMKChordSchemeGetIntervalArray(LEXMKChordSchemeRef scheme, bool isRelated)
{
    
    return NULL;
}

