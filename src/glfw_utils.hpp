//
// Created by krasno on 2020-01-31.
//

#ifndef RAIN_ENGINE_GLFW_UTILS_HPP
#define RAIN_ENGINE_GLFW_UTILS_HPP


#include <GLFW/glfw3.h>

#define GUTIL_MAX(a, b) (((a) < (b)) ? (b) : (a))
#define GUTIL_MIN(a, b) (((b) < (a)) ? (b) : (a))

/**
 * Positions the window on the center of the monitor
 * @param window Window to be centered
 * @param monitor Monitor on which the window will be centered on
 */
void gUtilCenterWindow(GLFWwindow *window, GLFWmonitor *monitor) {
    if (!monitor)
        return;

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if (!mode)
        return;

    int monitorX, monitorY;
    glfwGetMonitorPos(monitor, &monitorX, &monitorY);

    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    glfwSetWindowPos(window,
                     monitorX + (mode->width - windowWidth) / 2,
                     monitorY + (mode->height - windowHeight) / 2);
}

/**
 * Gets the monitor in which the window is covering the most
 * @param window Window to be tested
 * @return Monitor in which the window is covering the most
 */
GLFWmonitor* gUtilGetBestMonitor(GLFWwindow *window) {
    int monitorCount;
    GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);

    if (!monitors)
        return nullptr;

    int windowX, windowY, windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glfwGetWindowPos(window, &windowX, &windowY);

    GLFWmonitor *bestMonitor = nullptr;
    int bestArea = 0;

    for (int i = 0; i < monitorCount; ++i) {
        GLFWmonitor *monitor = monitors[i];

        int monitorX, monitorY;
        glfwGetMonitorPos(monitor, &monitorX, &monitorY);

        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        if (!mode)
            continue;

        int areaMinX = GUTIL_MAX(windowX, monitorX);
        int areaMinY = GUTIL_MAX(windowY, monitorY);

        int areaMaxX = GUTIL_MIN(windowX + windowWidth, monitorX + mode->width);
        int areaMaxY = GUTIL_MIN(windowY + windowHeight, monitorY + mode->height);

        int area = (areaMaxX - areaMinX) * (areaMaxY - areaMinY);

        if (area > bestArea) {
            bestArea = area;
            bestMonitor = monitor;
        }
    }

    return bestMonitor;
}


#endif //RAIN_ENGINE_GLFW_UTILS_HPP
