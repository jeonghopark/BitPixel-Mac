#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxTonic.h"
#include "ofxGui.h"

#include "ScaleSetting.h"


struct blackWhitePixels{
    int indexPos;
    int pixelN;
    int firstValue;
    vector<int> numberPixels;
};

struct colorPixels{
    int indexPos;
    int pixelN;
    int firstValue;
    vector<int> numberPixels;
};


struct melody{
    vector<int> melodyLine;
};


struct noteList{
    vector<int> noteArray;
};


using namespace Tonic;


class ofApp : public ofBaseApp{
    
    ofxTonicSynth synth1;
    ofxTonicSynth synth2;
    ofxTonicSynth synth3;
    ofxTonicSynth synth4;
    ofxTonicSynth synth5;
    ofxTonicSynth synth6;
    ofxTonicSynth synth7;
    ofxTonicSynth synthMain;
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioRequested (float * output, int bufferSize, int nChannels);
    
//    void audioOut(ofSoundBuffer & buffer);
    
    
    ofSoundStream soundStream;
    
    bool bPlayNote;
    bool bCameraCapturePlay;
    
    
    // ofxTonic
    void synthSetting();
    ControlGenerator bpm;
    ControlGenerator metro;
    ofEvent<float> * metroOut;
    void triggerReceive(float & metro);
    
    int index;
    int noteIndex;
    
    
    // Main
    int screenW, screenH;
    
    
    //openCV
    ofVideoGrabber cam;
    
    ofxCvColorImage camColorCV;
    ofxCvColorImage centerCam;
    ofxCvColorImage faceCam;
    
    ofPixels cannyInverted;
    
    ofImage edge;
    ofImage printCam;
    
    
    ofImage printImage;
    
    
    ofxCvColorImage downScaleCam;
    ofImage downScaleCanny;
    ofImage downScaleEdge;
    ofPixels downGray;
    
    ofPixels gray;
    bool camOpen;
    float cannyThreshold1;
    float cannyThreshold2;
    float grayThreshold;
    
    ofImage bufferImg;
    
    // Basic Pixels
    float pixelStepS;
    int changeVideoWidth, changeVideoHeight;
    vector<float> pixelBright;
    void drawTrianglePixel();
    int thresholdValue;
    vector<blackWhitePixels> whitePixels;
    vector<blackWhitePixels> blackPixels;
    blackWhitePixels _wPix;
    int pixelCircleSize;
    
    //Video
    int camSize, changedCamSize;
    float cameraScreenRatio;
    
    
    // Graphics
    void drawPixelNumbersCircleNotes();
    void drawPlayingShapeNotes();
    
    void drawPlayingShapeNote( vector<int> _vNote, int _scoreCh );
    
    // control Panel
    void drawControlElement();
    void debugControlPDraw();
    float ctrlPnX, ctrlPnY, ctrlPnW, ctrlPnH;
    int guideWidthStepSize, guideHeightStepSize;
    int maxSpeed, minSpeed;
    void controlGuide();
    
    float stepBasePos;
    
    float ctrlRectS;
    
    ofPoint speedCPos;
    float speedCSize;
    bool bSpeedCtrl;
    
    ofPoint thresholdCPos;
    float thresholdCSize;
    bool bthresholdCtrl;
    
    ofPoint intervalPos;
    float intervalSize;
    bool bInterval;
    
    // base Interface
    void drawBaseInterface();
    ofPoint base4Pos;
    ofPoint base5Pos;
    ofPoint base6Pos;
    ofPoint base7Pos;
    ofPoint base8Pos;
    ofPoint base9Pos;
    float baseSize;
    void drawShapeCeterLine(ofPoint pos, int base, int size, ofColor _c);
    void drawShapeCeterLineColorRotation(ofPoint pos, int base, int size, ofColor color);
    void drawShape(ofPoint pos, int base, int size);
    void drawPixelAllNoteShape();
    void drawPixelAllNoteShapes( vector<int> _vNote, int _scoreCh );
    
    
    int baseSelection;
    
    
    ofxCvGrayscaleImage grayImage;
    
    
    // Decimal to N Base
    vector<int> convertDecimalToNBase(int n, int base, int size);
    
    // Line Score
    void drawLineScore();
    
    vector<int> oldScoreNote;
    vector<noteList> noteLists;
    
    int lineScoreStepX, lineScoreStepY;
    void scoreMake();
    
    
    int intervalDist;
    
    ScaleSetting scaleSetting;
    
    
    void drawScoreCircleLine( vector<int> _vNote, int _scoreCh );
    void trigScoreNote( vector<int> _vNote, ofxTonicSynth _synthIn, int _scoreCh );
    
    
    float pixeShapeSize;
    
    int lineScoreNumber;
    
    
    float touchDownDefault;
    
    vector<bool> ctrlSlider;
    
    
    bool allPlayOnOff;
    
    
    void debugInformation();
    
    
    
    void guiSetting();
    ofxPanel gui;
    ofParameterGroup parametersMain;
    ofParameterGroup parameters;
    
    ofParameter<float> thresholdF;
    ofParameter<float> mainVolume;
    ofParameter<int> baseNum;
    ofParameter<string> frameRate;
    ofParameter<string> noteNum;
    ofParameter<string> faceNum;
    
    void changedBaseNum(int & param);
    bool bChangedBaseNum;
    
    
    ofParameterGroup parameters2;
    ofParameter<float> thresholdF2;
    
    
    
    
    vector<melody> melodies;
    
    void checkSameNote( vector<int> _vNote, ofxTonicSynth _synthIn, int _scoreCh );
    
    int notePosition(int _note, int _stepLine);
    
    
    ofxCv::ObjectFinder faceFind;
    
    int changedCamW, changedCamH;
    
    
    bool debugView;
    
    
    ofVec2f faceCenter;
    
    
    
    
    
};
