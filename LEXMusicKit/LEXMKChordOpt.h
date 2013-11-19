//
//  LEXMKChordOpt.h
//  LEXMusicKit
//
//  Created by Alexei Gordeev on 19.11.13.
//  Copyright (c) 2013 Alexei Gordeev. All rights reserved.
//

#ifndef LEXMusicKit_LEXMKChordOpt_h
#define LEXMusicKit_LEXMKChordOpt_h


enum {
    LEXMKChordOptTypeUnknown = -1,
    LEXMKChordOptTypeNotFound = 0,
    LEXMKChordOptTypeWide,
    LEXMKChordOptTypeSus,
    LEXMKChordOptTypeAdd,
    LEXMKChordOptTypeAltBass
};
typedef int LEXMKChordOptType;

/** Chord option with type and related info.
 
 What info means for type?
 Wide - The widest interval in chord. Info is interval.
 Sus - suspended chord. Third interval changes to major second or perfect fourth. Make a note, that original third is no more in chord. Info is LEXMKchordSus2 for sus2 and LEXMKchordSus4 for sus4.
 Add - adding given interval to a chord. Info is interval.
 AltBass - first note of chord is different from tonic. Info is shift from tonic like -2 for chord Am/G.
 */
struct LEXMKChordOpt {
    LEXMKChordOptType type; /// Type of chord option.
    int info; /// Info make sense only when type defined.
};
typedef struct LEXMKChordOpt LEXMKChordOpt;

LEXMKChordOpt LEXMKChordOptMakeWithTypeAndInfo(LEXMKChordOptType type, int info);

LEXMKChordOpt *LEXMKChordCreateOptsWithTypeFromOpts(LEXMKChordOpt * opts,
                                                    unsigned int length,
                                                    LEXMKChordOptType type,
                                                    unsigned int * outFoundOptsLength);

bool LEXMKChordOptHasOptWithTypeAndInfo(LEXMKChordOpt *opts,
                                        unsigned int length,
                                        LEXMKChordOptType type,
                                        int info,
                                        unsigned int *outFoundOptIdx);

#endif
