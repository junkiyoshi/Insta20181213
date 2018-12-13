#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor color;
	for (int i = 0; i < 50; i++) {

		color.setHsb(i * 5, 255, 255);
		ofSetColor(color, 128);

		float noise_seed_x = ofRandom(1000);
		float noise_seed_y = ofRandom(1000);

		for (int l = 0; l < 5; l++) {

			int x = ofMap(ofNoise(noise_seed_x + (ofGetFrameNum() + l) * 0.05), 0, 1, 0, ofGetWidth());
			int y = ofMap(ofNoise(noise_seed_y + (ofGetFrameNum() + l) * 0.05), 0, 1, 0, ofGetHeight());

			x = (x / 15) * 15;
			y = (y / 15) * 15;

			glm::vec2 location = glm::vec2(x, y);

			ofDrawRectangle(location, 15, 15);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}