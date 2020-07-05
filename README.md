# imgui4xp

Imgui Template For X-Plane 11 Also Showing How To Support Multi Platform From Linux

I am documenting the process I took to get a multiplatform stand alone plugin that supports imgui on X-Plane built on Ubuntu 18.04 LTS. My goal it to make it easier for the next developer to accomplish the same task. With this template you should be able to develop an idea on FlyWithLua NG using its new support for imgui and when developed far enough then convert it to a stand alone plugin with no need for lua. I hope someone will find this useful.  

Thanks to kuroneko on x-plane.org and his repository at https://github.com/xsquawkbox/xsb_public we have added the ability to select the font you want to use and also use the ImGui::SetWindowFontScale(1.00) function to set the size you want your fonts to be. You first pick the font you want for the project then using the ImGui::SetWindowFontScale(1.00) function you can change the size of the font on any line you chose.

First clone imgui4xp using this command "git clone https://github.com/sparker256/imgui4xp.git" and put the resulting imgui4xp folder wherever you like. I normally put myself in the folder where I want the repository folder to reside first.

## Multi Platform Build from Linux

Since I develop on Linux my IDE of choice is QT Creator which is installed from my package manager.

I have scripts and make files that allow me to click on one button on my desktop and automatically build for all three platforms.

You will need a compiler to build the Linux files and the following command will get that for you.

`sudo apt-get install build-essential`

To build for Windows on Ubuntu you will need to use this command:

`sudo apt-get install mingw-w64`

To build the Mac files on Ubuntu you need to go to the osxcross GitHub site found here.

https://github.com/tpoechtrager/osxcross

And follow there instructions and then you will need to install the clang compiler using this command.

`sudo apt-get install clang-3.8`

With all this correctly installed you to should be able to build for all three platforms on Ubuntu using Cmake.

## Multi Platform Build using Docker

I have now also added the ability of using Docker to build for all three platforms.
Find more information in `docker/README.md`.

## Windows: Visual Studio

On Windows, you can use
[Visual Studio's "Open Folder" feature](https://docs.microsoft.com/en-us/cpp/build/open-folder-projects-cpp)
to open the project's `src` folder and build the plugin based on its CMake configuration.

Results will be in `src/build-win`.

## Windows: Visual Studio Native
Some modifications to the original CMAKE build tree was done:
* A new Visual Studio folder was added (`vstudio`) where it holds the main `sln` file.
* The `freetype2` folder was also added with few libraries compressed in`src\freetype2\libs\64` folder  for the build to succeed.
* `glew` files where added to `src\GL`, we use it as our GL Loader.
* Project was configured with the following ImGUI flags: `IMGUI_INCLUDE_IMCONFIG_H` and `IMGUI_IMPL_OPENGL_LOADER_GLEW`
* Three profile files were added to the project: `imgui4xp.prop`, `imgui4xp_debug.prop` and `imgui4xp_release.prop`. Their main goal is to allow to define shared and specific configuration for your build. 

** Pre and post Build Actions **
Please do remember you will need to:
* Unzip the "brotoli_and_freetype_libs_and_dlls.zip" in the `src\freetype2\libs\64\` folder first.
* After the build, copy the Dlls to your plugin folder in X-Plane. Mainly: `brotlidec.dll` and `brotlicommon.dll`
* At the end of the build we execute the following command from VS:

> copy /Y $(OutDir)win.xpl C:\XP11\Resources\plugins\imgui4xp\64\

The `XP11` represents a link to your `X-Plane` installation folder.
You can ignore any error related to the copy command you can remove it or modify it for your needs from the project properties window.

## Mac OS: Xcode

An Xcode project is provided as `imgui4xp.xcodeproj`.

You may want to change the value of the user-defined build macro
`XPLANE11_ROOT` in the build settings to point to your X-Plane 11
installation. Then the resulting binary is installed there right away.

## Imgui4xp

<img width="868" alt="Imgui4xp" src="https://github.com/sparker256/Imgui4xp/blob/master/imgui4xp_Github.jpg">
