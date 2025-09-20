//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2025-08-05 16:34:27 taubin>
//------------------------------------------------------------------------
//
// Faces.cpp
//
// Written by: <Tobias Moraut>
//
// Software developed for the course
// Digital Geometry Processing
// Copyright (c) 2025, Gabriel Taubin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Brown University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL GABRIEL TAUBIN BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <math.h>
#include "Faces.hpp"
  
Faces::Faces(const int nV, const vector<int>& coordIndex) {
    _indices = coordIndex;
    vector<int> _cacheIndices;
    _numVertices = nV;
    _cacheIndices.push_back(0);
    int nextFace = 1;
    for (int i =0 ; i < _indices.size(); i++){
        if(coordIndex[i] < 0){
            _cacheIndices.push_back(i + 1);
            _indices[i] = - nextFace;
            nextFace++;
        }
    }
    _indices[_indices.size() - 1] = -nextFace;
}

int Faces::getNumberOfVertices() const {
  return _numVertices;
}  

int Faces::getNumberOfFaces() const {
    return _cacheIndices.size();
}

int Faces::getNumberOfCorners() const {
  return _indices.size();
}

int Faces::getFaceSize(const int iF) const {
  int numFaces = getNumberOfFaces();
    if(iF < 0 || iF >= numFaces) 
        return -1;

    int faceIndex = getFaceFirstCorner(iF);
    int faceSizeCounter = 0;
    while(_indices[faceIndex + faceSizeCounter] >= 0){
        faceSizeCounter++;
    }
    return faceSizeCounter;
}

int Faces::getFaceFirstCorner(const int iF) const {
    int numFaces = getNumberOfFaces();
    if(iF < 0 || iF >= numFaces)
        return -1;

    int faceIndex = _cacheIndices[iF];
    return -1; 
}

int Faces::getFaceVertex(const int iF, const int j) const {
  int numFaces = getNumberOfFaces();
  if(iF < 0 || iF >= numFaces) 
        return -1;

  int faceIndex = getFaceFirstCorner(iF);
  int faceSize = getFaceSize(iF);

  if(j <= faceSize && j >= 0){
    return _indices[faceIndex + j];
  }
  else return -1;
}

int Faces::getCornerFace(const int iC) const {
  if(iC < 0 || iC >= _indices.size())
    return -1;

  int faceCount = 0;
  for(int i = 0; i < iC; i++){
    if(_indices[i] == -1)
      faceCount++;
  }
  return faceCount;
}

int Faces::getNextCorner(const int iC) const {
    if (iC >= _indices.size()){
        return -1;
    }

    if (_indices[iC] < 0){
        return -1;
    }

    int nextCorner = _indices[iC + 1];
    if(nextCorner < 0){
        return _cacheIndices[-nextCorner - 1];
    } else{
        return iC + 1;
    }
}

