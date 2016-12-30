//
//  VectorGrow.hpp
//  GrowStrokeLearn
//
//  Created by Zerc on 3/22/16.
//
//

#ifndef VectorGrow_hpp
#define VectorGrow_hpp

#include "ofMain.h"
#include "ofxSvg.h"

class VectorGrow{
public:
    ofxSVG svg;
    vector<ofPolyline> outlinesL;
    vector<ofPolyline> outlinesR;
    ofPolyline lineL;
    ofPolyline lineR;
    float step;
    struct growData{
        float step;
        int offset;
    };
    vector<growData> growDatasL;
    vector<growData> growDatasR;
    int sizeTotalL, sizeTotalR;
    ofPath path;
    void setup(string path);
    void update(float _step);
    void draw();
};
#endif /* VectorGrow_hpp */
