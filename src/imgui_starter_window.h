/*
 *   Imgui Starter Window for X-Plane
 *   William Good
 *
 *   This is a templete to allow you to use Imgui with X-Plane
 *
 *
 *
 *
 */
#ifndef SRC_IMGUIWIDGET_H_
#define SRC_IMGUIWIDGET_H_

#include "../src/ImgWindow/ImgWindow.h"
#include <vector>

extern void configureImgWindow();

class ImguiWidget: public ImgWindow {
protected:
    // texture number and size of the image we want to show
    static int      image_id;
    static ImVec2   image_size;
    // Counter for the number of windows opened
    static int      num_win;
    // I am window number...
    const int       myWinNum;
    // Values in node "Buttons" / "Checkboxes"
    bool makeRed = false;
    int         radioChoice = 1;
    // Values in node "Sliders"
    float       sliderVal1  = 250.0f;
    float       sliderVal2  = 0.0f;
    int         sliderVal3  = 50;
    float       sliderAngle = 0.0f;
    // Values in node "ComboBox"
    int         choice1     = 1;
    int         choice2     = 1;
    // Values in node "Input"
    std::string userText;
    int         userI1 = 123;
    int         userI2 = 1234;
    // Values in node "List"
    std::vector<const char*> listContent;
    int         listSelItem = 0;
public:
    ImguiWidget(int left, int top, int right, int bot,
                XPLMWindowDecoration decoration = xplm_WindowDecorationRoundRectangle,
                XPLMWindowLayer layer = xplm_WindowLayerFloatingWindows);
protected:
    void buildInterface() override;
private:

};

//

#endif /* SRC_IMGUIWIDGET_H_ */
