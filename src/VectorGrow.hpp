//
//  VectorGrow.hpp
//  GrowStrokeLearn
//
//  Created by Zerc on 3/22/16.
//
//

#ifndef VectorGrow_hpp
#define VectorGrow_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxSvg.h"
class VectorGrow{
private:
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
public:
    void setup(string path){
        sizeTotalL = 0;
        sizeTotalR = 0;
        svg.load(path);
        step = 0.01;
        int res = 10;
        for (int i = 0; i < svg.getNumPath(); i++){
            ofPath p = svg.getPathAt(i);
            p.setPolyWindingMode(OF_POLY_WINDING_ODD);
            vector<ofPolyline>& lines = const_cast<vector<ofPolyline>&>(p.getOutline());
            int currShape = 0;
            for(int j=0; j < (int)lines.size();j++){
                if(i%2==0){
                    ofPolyline poly = lines[j].getResampledBySpacing(res);
                    outlinesL.push_back(poly);
                    growData d;
                    d.step = 0;
                    d.offset = sizeTotalL;
                    growDatasL.push_back(d);
                    sizeTotalL += poly.size();
                    currShape++;
                }else{
                    ofPolyline poly = lines[j].getResampledBySpacing(res);
                    growData d;
                    d.step = 0;
                    d.offset = sizeTotalR;
                    growDatasR.push_back(d);
                    sizeTotalR += poly.size();
                    outlinesR.push_back(poly);
                }
            }
        }
        cout <<  "sizeTotalL= " << sizeTotalL  << endl;
        cout <<  "sizeTotalR= " << sizeTotalR  << endl;
    }
    void update(float _step){
        if(_step>0 && _step <= 1){
            step = _step;
        }
    }
    void draw(){
        ofFill();
        ofSetColor(255, 255);
        int curSizePosL = sizeTotalL*step;
        int curSizePosR = sizeTotalL*step;

        for(int l = 0; l < outlinesL.size(); l++){
            int numL = curSizePosL - growDatasL[l].offset;
            int numR = curSizePosR - growDatasR[l].offset;
            if(numL>0 && numL <= outlinesL[l].size()){
                growDatasL[l].step = numL;
            }
            if(numL <0){
                growDatasL[l].step = 0;
            }
            if(growDatasL[l].step>0){
                ofBeginShape();
                for (int i = 0; i < growDatasL[l].step; i++){
                    ofVertex(outlinesL[l][i]);
                }
                float stepNormalize = growDatasL[l].step/outlinesL[l].size();
                int stepR = stepNormalize*outlinesR[l].size();
                for (int i = stepR-1; i > 0; i--){
                    ofVertex(outlinesR[l][i]);
                }
                ofEndShape();
            }
        }
    }
};
#endif /* VectorGrow_hpp */
