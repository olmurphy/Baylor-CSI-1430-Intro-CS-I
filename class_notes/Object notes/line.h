//
//  line.h
//  Object notes
//
//  Created by Owen Murphy on 11/8/19.
//  Copyright © 2019 Owen Murphy. All rights reserved.
//

#ifndef line_h
#define line_h

#include "point.h"

class line {
private:
    point p1;
    point p2;
    
public:
    line() {
        p1.x = 0;
        p1.y = 0;
        p2.x = 1;
        p2.y = 1;
    }
    
};

#endif /* line_h */
