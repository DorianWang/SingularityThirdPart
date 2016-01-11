#include "GLFWLoop.h"

namespace firstGameLoop{

void firstGameLoop::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
   if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
      std::cout << "Right Click!" << std::endl;
      glfwSetWindowShouldClose(window, GL_TRUE);
   }
   //Call function of object.
}

void firstGameLoop::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
   std::cout << "Scrolled: " << yoffset << std::endl;
}

void firstGameLoop::error_callback(int error, const char* description)
{
   //TODO: Add connection to logger here.
   //fputs(description, stderr);
}

void firstGameLoop::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
   if (action == GLFW_PRESS){
      switch (key){
         case (GLFW_KEY_ESCAPE):
            glfwSetWindowShouldClose(window, GL_TRUE); //Close window.
         case (GLFW_KEY_SPACE):
            spinMod = spinMod * -1;
         default:
            ;//Nothing!
      }
   }
}



int firstGameLoop::openGLTest()
{
   if ( !glfwInit() )
      return 0; // Something bad happened...

   glfwSetErrorCallback(this -> error_callback);

   GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

   if ( !window ){
      glfwTerminate();
      return 0;
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, this.key_callback);
   glfwSwapInterval(1); //Set time between buffer switches.
   glfwGetCursorPos(window, &xpos, &ypos);
   glfwSetMouseButtonCallback(window, this.mouse_button_callback);

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
      cout << glfwGetTime() <<endl;
      cout << xpos << ", " << ypos << endl;

      glfwSwapBuffers(window);
      glfwPollEvents();

   }

   //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
   cout << xpos << ", " << ypos << endl;
   glfwDestroyWindow(window);
   glfwTerminate(); //All done.
   return 1;
}




}








