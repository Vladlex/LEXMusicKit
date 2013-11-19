//
//  LEXMKChordOpt.c
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 19.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "LEXMKChordOpt.h"

LEXMKChordOpt LEXMKChordOptMakeWithTypeAndInfo(LEXMKChordOptType type, int info)
{
    LEXMKChordOpt opt;
    opt.type = type;
    opt.info = info;
    return opt;
}

bool LEXMKChordOptHasOptWithTypeAndInfo(LEXMKChordOpt *opts,
                                        unsigned int length,
                                        LEXMKChordOptType type,
                                        int info,
                                        unsigned int *outFoundOptIdx)
{
    if (opts != NULL && length > 0) {
        for (int i = 0; i < length; i++) {
            LEXMKChordOpt opt = opts[i];
            if (opt.type == type && opt.info == info) {
                if (outFoundOptIdx != NULL) {
                    *outFoundOptIdx = i;
                }
                return true;
            }
        }
    }
    return false;
}

LEXMKChordOpt *LEXMKChordCreateOptsWithTypeFromOpts(LEXMKChordOpt * opts,
                                                    unsigned int length,
                                                    LEXMKChordOptType type,
                                                    unsigned int * outFoundOptsLength)
{
    if (opts != NULL && length > 0) {
        unsigned int optsLength = 0;
        LEXMKChordOpt *resultOpts = malloc(sizeof(LEXMKChordOpt) * 10);
        LEXMKChordOpt opt;
        for (int i = 0 ; i< length; i++) {
            opt = opts[i];
            if (opt.type == type) {
                resultOpts[optsLength] = opt;
                optsLength +=1;
            }
        }
        if (optsLength > 0) {
            *outFoundOptsLength = optsLength;
            resultOpts = realloc(resultOpts, sizeof(LEXMKChordOpt) * optsLength);
            return resultOpts;
        }
        else {
            free(resultOpts);
        }
    }
    *outFoundOptsLength = 0;
    return NULL;
}