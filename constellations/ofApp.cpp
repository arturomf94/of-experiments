#include "ofApp.h"

// minor modifications to
// original code in https://github.com/junkiyoshi/Insta20190604

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(20);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int n = 500;
	vector<glm::vec3> locations(n);
	for (int i = 0; i < n; i++) {

		auto R = 400;
		auto r = ofRandom(0, 400);
		auto u = ofRandom(600) + ofGetFrameNum() * ofRandom(0, 1.0) * (ofRandom(1) < 0.3 ? 1 : -1);
		auto v = ofRandom(600) + ofGetFrameNum() * ofRandom(0, 1.0) * (ofRandom(1) < 0.3 ? 1 : -1);

		locations[i] = this->make_point(R, r, u, v);
	}

	ofFill();
	ofSetColor(255);
	for (auto& location : locations) {

		ofDrawSphere(location, 3);
		for (auto& other : locations) {

			if (location == other) { continue; }

			auto distance = glm::distance(location, other);
			if (distance < 70) {

				ofDrawLine(location, other);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}
