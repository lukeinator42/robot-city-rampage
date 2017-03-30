//
// Created by Lukas Grasse on 2017-03-18.
// Added Code by Mitchell Wever on 2017-03-29
//

#ifndef HW_OPENGL_ROBOT_H
#define HW_OPENGL_ROBOT_H


class Robot {
  public:
   Robot();
   Robot(float);
   void head();
   void neck();
   void body();
   void draw();
};


#endif //HW_OPENGL_ROBOT_H
