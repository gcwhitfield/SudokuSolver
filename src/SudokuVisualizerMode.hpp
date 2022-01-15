#include "Mode.hpp"

struct SudokuVisualizerMode : Mode {

    void draw(glm::uvec2 const &drawable_size);
    void handle_key(GLFWwindow *window, int key, int scancode, int action, int mods);
    void update(float elapsed);
    
};