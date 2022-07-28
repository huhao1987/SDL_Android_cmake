## I build this project because I am begining to learn SDL and found it is little bit confused to import the SDL in Android project. I spent some time to find out a simple way to do it. And I want to share this method to the developers who want to use SDL in Android development. Cheers!

#### I use CMake in Android studio
#### I am still learning the SDL, so right now it only include the original SDL libary. I might update it when I begin to learn other SDL libary.
##### I am using the latest stable Android studio 2021.2.1 Patch 1, It might works in other versions, but I didn`t test that.
##### I want to do the less modification for the SDL source, so follow my method, you could use the latest code from SDL, if they don`t change a lot.

1. Build your Android project by using "Native c++" in Android studio
2. Download the latest SDL source code rom github https://github.com/libsdl-org/SDL and unzip them in a folder named "SDL"
3. Put the SDL folder in cpp folder of the project
4. Create your c++ source file for your SDL development in the cpp folder
5. Edit the CmakeLists.txt in the base cpp folder, overwirte it as 

```c++
cmake_minimum_required(VERSION 3.18.1)

project("main")

add_subdirectory(SDL)
INCLUDE_DIRECTORIES("SDL/include")

add_library(
        main
        SHARED
		//This is the main cpp file in your project, please replace it with your own file
        sample.cpp)
target_link_libraries(
        main
        SDL2)
    ```
6. Let`s edit the build.gradle(:app), add the below code in "Android" area

```Java
  sourceSets {
        main.java.srcDirs += 'src/main/cpp/SDL/android-project/app/src/main/java'
    }
	```
	
	It will port the sample source code from the SDL into your current project. 
	
7. Use "Refresh Linked C++ projects" and "Make Project" in Android studio and wait.

8. This step is only for using Koltin in your porject, if you are using Java, you could ignore it.
	But peronally, I suggest you could use Kotlin, it is a such nice language. 
	After step 7, you could find out that the "org.libsdl.app" has been imported in your project. open the SDLActivity, and search the class "SDLGenericMotionListener_API12", copy the code of it and comment it. next, create a java class in the folder named "SDLGenericMotionListener_API12", and pause the code in it. The reason is that the origial SDL Android project uses nested class, but the kotlin doesn`t support it, we have to move it out. I am still seeking a method to fix it, but now it is the best way to do it. 

9. in your MainActivity class, replace "Activity"/"AppCompatActivity" with "SDLActivity", delete all code in the class if you want. Because all code are unused.
10. Write your c++ code in int main(int argc, char *argv[]) {}. 
11. Compile and run

**If you have any question, please review the demo in the project.**