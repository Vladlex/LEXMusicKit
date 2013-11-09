//
//  LEXLog.h
//  Alexei Gordeev
//
//  Created by Alexei Gordeev on 28.03.13.
//
//

#ifndef LEXLog_h
#define LEXLog_h

#define LOGDebug 1

#if LOGDebug == 1
#define QLog(FORMAT, ...) printf("%s\n", [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#endif

#define sBOOL(anBOOL) anBOOL ? @"YES" : @"NO"

#endif
