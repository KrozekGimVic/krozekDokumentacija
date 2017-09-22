Osnove
========

`OpenGL <https://www.opengl.org/>`_ je knjižnica za risanje 2D in 3D vektorske
grafike. Opengl je trenutno na verziji 4.5, mi pa se bomoučili verzijo 3.x, ki
je že dovolj stara, da jo podpira večina računalnikov, hkrati pa je dovolj
nova, da je že potreben noveji pristop, z razliko od OpenGL 2.

Kako deluje
-----------

Open GL je knjižnica, ki komunicira s storjno opremo na računalniku,
predvsem z grafično kartico, da doseže strojno pospešeno risanje. Zaradi
tega so njeni ukazi na precej nižjem nivoju kot običajno. Najbolj običajna
implementacija OpenGL na Linux-u je Mesa, nVidia pa ima na primer svojo
implementacijo.

Proces si lahko natančneje prebere `tukaj
<http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Chapter-1:-The-Graphics-Pipeline.html>`_,
za nas pa naj bo dovolj naslednjih 7 korakov, ki opisujejo, kako poteka pot
ptrevarjanja podatkov v risbo.

* seznam točk -- podatki za risbo
* globalno stanje in teksture -- globalni podatki, ki so na voljo shaderju
* vertex shader -- računanje pozicij
* sestavljanje trikotnikov
* rasterizacija -- spreminjanje gladkih robov v piksle
* fragment shader -- dobi slke, ustvari svetlobo, vrne seznam barv (najbolj zahteven korak)
* buffers and blending -- nariše na zaslon, več bufferjev, globina

.. image:: img/pipeline.png

Instalacija
-----------
Potrebovali bomo ``g++``, ``cmake`` in knjižnice za ``opengl``, ``glut`` in
``glew``. Sledili bomo gradivu na `opengl-tutorial.org
<http://www.opengl-tutorial.org/>`_, kodo pa lahko dobite z

.. code-block:: bash

  git clone https://github.com/opengl-tutorials/ogl

Projekt zgradite tko kot ponavadi, če ste v mapi ``ogl/`` naredite ``build/`` folder in poženete
``cmake``. Programe zaganjate preko launch skript, ki jih ustvari ``cmake``.

.. code-block:: bash

  mkdir - build/
  cd build/
  cmake ..
  make
  ./launch-tutorial01_first_window.sh

Prvo okno
---------

.. code-block:: cpp

  // Include standard headers
  #include <stdio.h>
  #include <stdlib.h>

  // Include GLEW
  #include <GL/glew.h>

  // Include GLFW
  #include <glfw3.h>
  GLFWwindow* window;

  // Include GLM
  #include <glm/glm.hpp>
  using namespace glm;

  int main(void) {
      // Initialise GLFW
      if (!glfwInit()) {
          fprintf(stderr, "Failed to initialize GLFW\n");
          getchar();
          return -1;
      }

      glfwWindowHint(GLFW_SAMPLES, 4);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      // To make MacOS happy; should not be needed
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

      // Open a window and create its OpenGL context
      window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
      if (window == NULL) {
          fprintf(stderr,
                  "Failed to open GLFW window. If you have an Intel GPU, "
                  "they are not 3.3 compatible. Try the 2.1 "
                  "version of the tutorials.\n");
          getchar();
          glfwTerminate();
          return -1;
      }
      glfwMakeContextCurrent(window);

      // Initialize GLEW
      if (glewInit() != GLEW_OK) {
          fprintf(stderr, "Failed to initialize GLEW\n");
          getchar();
          glfwTerminate();
          return -1;
      }

      // Ensure we can capture the escape key being pressed below
      glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

      // Dark blue background
      glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

      do {
          // Clear the screen. It's not mentioned before Tutorial 02,
          // but it can cause flickering, so it's there nonetheless.
          glClear(GL_COLOR_BUFFER_BIT);

          // Draw nothing, see you in tutorial 2 !

          // Swap buffers
          glfwSwapBuffers(window);
          glfwPollEvents();

      }  // Check if the ESC key was pressed or the window was closed
      while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);

      // Close OpenGL window and terminate GLFW
      glfwTerminate();

      return 0;
  }

