# Introduction
 - The project focus on creating a 3D enivernment and rendering an image based on the enivernment we just defined using Ray-Tracing algorthim. To make the image looks more realistic, the following shading technique and lighting effects have been implemented including, Phong shading, Lambert shading, Point-light, Spot-light, Area-light, and mirror reflection effect. The project is implemented by OpenFrameWork, which is a C++ toolkit. In order to run this project, you may download the OpenFrameWork toolkit by cliking following link:  [Link To Download OpenFrameWork](https://openframeworks.cc/download/)

## Creating an OpenFrameWork Project on your computer(You may skip this steps if you are familiar with OpenFrameWork).
- After you downloaded the OpenFrameWork to your computer, you may unzip the zip file you just downloaded. Then, in the same directory, you may find a folder that containes all the necessarily files for the OpenFrameWork (e.g The name of the folder should appear as the following formate : of_XXXXXXXXX_XXX_release). 
![Screen Shot 2021-01-25 at 11 19 10 PM](https://user-images.githubusercontent.com/25276186/105812874-cd8e7b00-5f63-11eb-825e-b75305c4ca86.png)

- Once you open that folder, you may find another folder called **projectGenerator**. 
![Screen Shot 2021-01-25 at 11 25 47 PM](https://user-images.githubusercontent.com/25276186/105813492-c1ef8400-5f64-11eb-90d6-d98aa878290a.png)

- Open the folder, than you may find a file called **projectGenerator**.
![Screen Shot 2021-01-25 at 11 27 58 PM](https://user-images.githubusercontent.com/25276186/105813686-0f6bf100-5f65-11eb-8fc0-7d06c9c6a501.png)

- If it is your first time to run **projectGenerator** file, you may have **runMeFirst.command** file first. First Select the **runMeFirst.command** the file. Then, right clik the file and run the file in Terminal. 
![Screen Shot 2021-01-25 at 11 29 50 PM](https://user-images.githubusercontent.com/25276186/105814400-37a81f80-5f66-11eb-8953-84c9acbc0a41.png)

- Open the projectGenerator. Then, you may name the project with anyname you want. Then, in the addons area, you may have to add **ofxassimpmodelloader** and **ofxgui** addons to your project in order to run all source codes of this project. Finally, creating the project by cliking the **Generate** button.               
![Screen Shot 2021-01-25 at 11 40 45 PM](https://user-images.githubusercontent.com/25276186/105814820-cd43af00-5f66-11eb-9e99-7880e934ea31.png)

## Copy all the source code to your project.
- After generating the poject, you may go to the privious folder. Then, go to the folder, which is named **apps**. Then, open the folder called **myApps**. Then, find the project you just generated. 
![Screen Shot 2021-01-25 at 11 56 41 PM](https://user-images.githubusercontent.com/25276186/105816664-6f649680-5f69-11eb-9a9c-5594f2c043b8.png)

- Then, you may download **src** and **bin** folders from this GitHub page. Then **copy** and **replace** both of the folders that you just downloaded into your project's directory.
![Screen Shot 2021-01-26 at 12 03 17 AM](https://user-images.githubusercontent.com/25276186/105817127-0f222480-5f6a-11eb-96d8-4d3ddfadc1c9.png)
![Screen Shot 2021-01-26 at 1 40 00 AM](https://user-images.githubusercontent.com/25276186/105828113-9d50d780-5f77-11eb-8435-05d218a7e11e.png)

## Copy the reference of source code to your IDE
- Now open your project using Xcode. 
![Screen Shot 2021-01-26 at 9 15 52 PM](https://user-images.githubusercontent.com/25276186/105946237-bad77d00-601b-11eb-85b3-3d73ccf19ca5.png)
- You may select the **src** folder from the left side bar area. Then, right click the folder and select **Add Files to ..**
![Screen Shot 2021-01-26 at 9 26 23 PM](https://user-images.githubusercontent.com/25276186/105947042-3c7bda80-601d-11eb-861e-b20d20cb4575.png)
- Finally, add all the **.cpp and .h** files exclude **ofApp.cpp, ofApp.h, and main.cpp** to your project. 
![Screen Shot 2021-01-26 at 9 45 57 PM](https://user-images.githubusercontent.com/25276186/105948532-f1af9200-601f-11eb-8953-c89ea8d293cf.png)

# Source code explaination
- Now if you compile and run the project, you will have a Window as the following picture. First, all the small spheres in **yellow** and **black** color are representing the **point light**, which emits light ray in 360 degree. Then, the two small spheres in **yellow** and **white** color with arrows are representing the spot-light. The two panels in **yellow** and **blue** colors with many arrows are representing the area-light. The three big spheres in **blue**,**yellow**,and **red** colors are defined as the **sceneObject**. The rabbit, which is sitting on the **yellow** sphere is a Mesh object. Finally, the wall panels and the table panels are defined as **plane** object, which is inherited from the **SceneObject**.
![Screen Shot 2021-01-26 at 9 56 25 PM](https://user-images.githubusercontent.com/25276186/105949349-63d4a680-6021-11eb-853f-d062f4cca61f.png)

