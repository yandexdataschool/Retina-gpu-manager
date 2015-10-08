#pragma once

#include "Grid.h"

#include <vector>
#include <cstdint>
#include <stdexcept>

const int GRID_SIZE = 30;
const int GRID_SIZE_X_ON_Z0 = GRID_SIZE;
const int GRID_SIZE_Y_ON_Z0 = GRID_SIZE;
const int GRID_SIZE_DX_OVER_DZ = GRID_SIZE;
const int GRID_SIZE_DY_OVER_DZ = GRID_SIZE;

const double RETINA_SHARPNESS_COEFFICIENT = 0.6;
const double TRACK_THRESHOLD = 0.9999;
const size_t MAX_TRACK_SIZE = 24;
const double PARAM_TOLERANCE = 0.6;
const double SCATTER_TOLERANCE = 0.000016;

        
struct Hit {
  float x;
  float y;
  float z;
  uint32_t id;
  uint32_t sensorId;
  Hit(float x, float y, float z, uint32_t id, uint32_t sensorId) :
    x(x),
    y(y),
    z(z),
    id(id),
    sensorId(sensorId)
  {
  }
  Hit() = default;
  Hit(const Hit& other) : Hit(other.x, other.y, other.z, other.id, other.sensorId)
  {
      
  }
};

struct TrackPure { 
public:
  double xOnZ0;
  double yOnZ0;
  double dxOverDz;
  double dyOverDz;
  TrackPure(double x0, double y0, double tx, double ty) noexcept : 
    xOnZ0(x0), yOnZ0(y0), dxOverDz(tx), dyOverDz(ty)  {}
  TrackPure(const Hit&, const Hit&);
  TrackPure() = default;
};

TrackPure operator*(const TrackPure& one, const double alpha);

TrackPure operator+(const TrackPure& one, const TrackPure& other);

struct Track {
public:
   
  int hitsNum;
  int hits[MAX_TRACK_SIZE];
  inline void addHit(int hitId) noexcept
  {
    if(hitsNum < MAX_TRACK_SIZE)
      hits[hitsNum++] = hitId;
  }
  Track() : hitsNum(0) { }
  
};

struct EventInfo
{
  std::vector<Hit> hits;
  double minX, minY, minZ, maxX, maxY, maxZ;
};

double getDistance(const TrackPure& track, const Hit& hit) noexcept;

std::vector<std::vector<double> > generateDimensions(const EventInfo& event);

bool isFit(const TrackPure& track, const Hit& hit, double zStart) noexcept;