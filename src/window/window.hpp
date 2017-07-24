/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

#ifndef FRAMEWORK_WINDOW_HPP
#define FRAMEWORK_WINDOW_HPP

#include <memory>

namespace framework {

class window_implementation;

class window
{
public:
    window();
    ~window();

    void show();
    void hide();

private:
    std::unique_ptr<window_implementation> m_implementation;
};
}

#endif


/*

focused
Whether or not this Window has the keyboard or input focus.

requestFocus()
Requests that this Window get the input focus.

height
The height of this Stage.
onCloseRequest
Called when there is an external request to close this Window.
onHidden
Called just after the Window has been hidden.
onHiding
Called just prior to the Window being hidden.
onShowing
Called just prior to the Window being shown.
onShown
Called just after the Window is shown.
showing
Whether or not this Stage is showing (that is, open on the user's system).
width
The width of this Stage.
x
The horizontal location of this Stage on the screen.
y


alwaysOnTop
Defines whether this Stage is kept on top of other windows.

fullScreen
Specifies whether this Stage should be a full-screen, undecorated window.
iconified
Defines whether the Stage is iconified or not.
maxHeight
Defines the maximum height of this Stage.
maximized
Defines whether the Stage is maximized or not.
maxWidth
Defines the maximum width of this Stage.
minHeight
Defines the minimum height of this Stage.
minWidth
Defines the minimum width of this Stage.
resizable
Defines whether the Stage is resizable or not by the user.
title
Defines the title of the Stage.


boolean	isAlwaysOnTop()
Gets the value of the property alwaysOnTop.
boolean	isFullScreen()
Gets the value of the property fullScreen.
boolean	isIconified()
Gets the value of the property iconified.
boolean	isMaximized()
Gets the value of the property maximized.
boolean	isResizable()
Gets the value of the property resizable.

toBack()
Send the Window to the background.
toFront()
Bring the Window to the foreground.
*/
