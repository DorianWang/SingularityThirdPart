#ifndef GLFWLOOP_H_INCLUDED
#define GLFWLOOP_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>

#include "DamageCalculator.h"

#define GLFW_INCLUDE_GLU
#include "GL\glfw3.h"

namespace firstGameLoop{


   class firstGameLoop
   {
      double xpos;
      double ypos;

   public:
      firstGameLoop();
      ~firstGameLoop();


      //Damage calculation things.

      //Testing OpenGL!
      int openGLTest();

      //Testing variables.
      int spinMod;

   };

   extern firstGameLoop gameMain;



   void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
   void error_callback(int error, const char* description);
   void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
   void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);




}

#endif // GLFWLOOP_H_INCLUDED
