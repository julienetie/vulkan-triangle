#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const unit32_t WIDTH = 800;
const unit32_t HEIGHT = 800;

class HelloTriangleApplicaiton {
    public:
        void run () {
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }       
    
    private: 
        void initWindow(){
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        }

        void initVulkan (){

        }

        void mainLoop(){
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
        }

        void cleanup (){
            glfwDestroyWindow(window);
            glfwTerminate();
        }
};

int main () {
    HelloTriangleApplicaiton app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std:cerr << e.what() << std::end1;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

