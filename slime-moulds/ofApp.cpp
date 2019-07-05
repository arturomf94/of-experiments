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

  // Create N points in 1000 x 1000 grid.

  mesh.setMode(OF_PRIMITIVE_POINTS);
  int N = 100000;
  int start_point_x = 450 + rand() % 100;
  int start_point_y = 450 + rand() % 100;
  int x = start_point_x;
  int y = start_point_y;
  int i = 0;
  int w = 1000;
  int h = 1000;
  while (i < N){
    if (x >= w ){
      // Slime could get "trapped" near boundaries, so look somewhere else.
      x = rand() % 1000;
    } else {
      if (x < 0 ){
        x = rand() % 1000;
      } else {
        x = x + rand() % 3 * (int)(pow(-1, i));
      }
    }
    if (y >= h ){
      y = rand() % 1000;
    } else {
      if (y < 0 ){
        y = rand() % 1000;
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
