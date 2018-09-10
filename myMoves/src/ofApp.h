#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofTrueTypeFont font;
    
    float rot;
    
    bool pdfS;
    
    bool pdfD;
    
    vector<string> sujeto {
        "El auge de la ultraderecha en Suecia",
        "\n Netflix"
    };
    
    vector<string> verbo {
        "lleva a Ikea a vender piezas",
        "\n estrena una película de terror"
    };
    
    vector<string> pred {
        "para montar el Tercer Reich",
        "\n basada en un anuncio de Securitas Direct"
    };
    
    ofPoint posi;
    
};
