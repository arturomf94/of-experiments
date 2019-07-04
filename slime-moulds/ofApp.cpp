#include "ofApp.h"

// Create array to keep mould data
int data [1000][1000] = { };

void ofApp::makePoint(int posx, int posy){
  mesh.addVertex(ofPoint(posx, posy, 0)); // make a new vertex
  mesh.addColor(ofFloatColor(0,0,0));  // add a color at that vertex
  data[posx][posy] = 1;
}

//--------------------------------------------------------------
void ofApp::setup(){

  // Create N "points" randomly distributed in grid (1000 x 1000)

  mesh.setMode(OF_PRIMITIVE_POINTS);
  int N = 10000;
  int start_point_x = 400 + rand() % 100;
  int start_point_y = 400 + rand() % 100;
  int x = start_point_x;
  int y = start_point_y;
  int i = 0;
  while (i < N){
    if (x >= 1000) {
      x = 999;
    } else {
      if (x < 0 ) {
        x = 0;
      } else {
        x = x + rand() % 3 * (int)(pow(-1, i));
      }
    }
    if (y >= 1000) {
      y = 999;
    } else {
      if (y < 0 ) {
        y = 0;
      } else {
        y = y + rand() % 3 * (int)(pow(-1, i));
      }
    }
    if (data[x][y] == 0) {
      makePoint(x, y);
      i++;
    }
  }

}

//--------------------------------------------------------------
void ofApp::draw(){

mesh.draw();

}
