#include "GLFWLoop.h"

namespace firstGameLoop{

//Actual object
firstGameLoop gameMain;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
   if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
      std::cout << "Right Click!" << std::endl;
      glfwSetWindowShouldClose(window, GL_TRUE);
   }
   //Call function of object.
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
   std::cout << "Scrolled: " << yoffset << std::endl;
}

void error_callback(int error, const char* description)
{
   //TODO: Add connection to logger here.
   //fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
   if (action == GLFW_PRESS){
      switch (key){
         case (GLFW_KEY_ESCAPE):
            glfwSetWindowShouldClose(window, GL_TRUE); //Close window.
         case (GLFW_KEY_SPACE):
            gameMain.spinMod = gameMain.spinMod * -1;
         default:
            ;//Nothing for now!
      }
   }
}



int firstGameLoop::openGLTest()
{
   if ( !glfwInit() )
      return 0; // Something bad happened...

   glfwSetErrorCallback(error_callback);

   GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

   if ( !window ){
      glfwTerminate();
      return 0;
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, key_callback);
   glfwSwapInterval(1); //Set time between buffer switches.
   glfwGetCursorPos(window, &xpos, &ypos);
   glfwSetMouseButtonCallback(window, mouse_button_callback);

   glfwSetScrollCallback(window, scroll_callback);

   double time = glfwGetTime();

   while (!glfwWindowShouldClose(window))
   {
      // Keep running, this defines what happens when someone has not used alt-f4 or the close button on the window.
      float ratio;
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      ratio = width / (float) height;
      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glRotatef((float) glfwGetTime() * spinMod *10.f, 0.f, 0.f, 1.f);
      glBegin(GL_TRIANGLES);
      glColor3f(1.f, 0.f, 0.f);
      glVertex3f(-0.6f, -0.4f, 0.f);
      glColor3f(0.f, 1.f, 0.f);
      glVertex3f(0.6f, -0.4f, 0.f);
      glColor3f(0.f, 0.f, 1.f);
      glVertex3f(0.f, 0.6f, 0.f);
      glEnd();

      glfwGetCursorPos(window, &xpos, &ypos);
      std::cout << glfwGetTime() << std::endl;
      std::cout << xpos << ", " << ypos << std::endl;

      glfwSwapBuffers(window);
      glfwPollEvents();

   }

   //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
   std::cout << xpos << ", " << ypos << std::endl;
   glfwDestroyWindow(window);
   glfwTerminate(); //All done.
   return 1;
}

firstGameLoop::firstGameLoop()
{
   xpos = 0.0;
   ypos = 0.0;
   spinMod = 1;
}

firstGameLoop::~firstGameLoop()
{
   ;
}


}








