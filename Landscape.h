//
// Created by Lukas Grasse on 2017-03-18.
//

#ifndef HW_OPENGL_LANDSCAPE_H
#define HW_OPENGL_LANDSCAPE_H

class Landscape
{
  public:
   Landscape(const float min, const float max, const int grid_size);

   void drawCityGround();

   void draw();


  private:
   const float MIN;
   const float MAX;
   const int GRID_SIZE;
   const int *GridSize;

   int CITY[102][102][2];
};


#endif //HW_OPENGL_LANDSCAPE_H
