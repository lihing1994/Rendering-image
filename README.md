# Introduction
 - The project focus on creating a 3D enivernment and rendering an image based on the enivernment we just defined using Ray-Tracing algorthim. To make the image looks more realistic, the following shading technique and lighting effects have been implemented including, Phong shading, Lambert shading, Point-light, Spot-light, Area-light, and mirror reflection effect. The project is implemented by OpenFrameWork, which is a C++ toolkit. In order to run this project, you may download the OpenFrameWork toolkit by cliking following link:  [Link To Download OpenFrameWork](https://openframeworks.cc/download/)<br /><br />


## Creating an OpenFrameWork Project on your computer(You may skip this steps if you are familiar with OpenFrameWork).
- After you downloaded the OpenFrameWork to your computer, you may unzip the zip file you just downloaded. Then, in the same directory, you may find a folder that containes all the necessarily files for the OpenFrameWork (e.g The name of the folder should appear as the following formate : of_XXXXXXXXX_XXX_release). 
![Screen Shot 2021-01-25 at 11 19 10 PM](https://user-images.githubusercontent.com/25276186/105812874-cd8e7b00-5f63-11eb-825e-b75305c4ca86.png)<br />
- Once you open that folder, you may find another folder called **projectGenerator**. 
![Screen Shot 2021-01-25 at 11 25 47 PM](https://user-images.githubusercontent.com/25276186/105813492-c1ef8400-5f64-11eb-90d6-d98aa878290a.png)<br />
- Open the folder, than you may find a file called **projectGenerator**.
![Screen Shot 2021-01-25 at 11 27 58 PM](https://user-images.githubusercontent.com/25276186/105813686-0f6bf100-5f65-11eb-8fc0-7d06c9c6a501.png)<br />
- If it is your first time to run **projectGenerator** file, you may have **runMeFirst.command** file first. First Select the **runMeFirst.command** the file. Then, right clik the file and run the file in Terminal. 
![Screen Shot 2021-01-25 at 11 29 50 PM](https://user-images.githubusercontent.com/25276186/105814400-37a81f80-5f66-11eb-8953-84c9acbc0a41.png)<br />
- Open the projectGenerator. Then, you may name the project with anyname you want. Then, in the addons area, you may have to add **ofxassimpmodelloader** and **ofxgui** addons to your project in order to run all source codes of this project. Finally, creating the project by cliking the **Generate** button.               
![Screen Shot 2021-01-25 at 11 40 45 PM](https://user-images.githubusercontent.com/25276186/105814820-cd43af00-5f66-11eb-9e99-7880e934ea31.png)<br /><br />


## Copy all the source code to your project.
- After generating the poject, you may go to the privious folder. Then, go to the folder, which is named **apps**. Then, open the folder called **myApps**. Then, find the project you just generated. 
![Screen Shot 2021-01-25 at 11 56 41 PM](https://user-images.githubusercontent.com/25276186/105816664-6f649680-5f69-11eb-9a9c-5594f2c043b8.png)
- Then, you may download **src** and **bin** folders from this GitHub page. Then **copy** and **replace** both of the folders that you just downloaded into your project's directory.
![Screen Shot 2021-01-26 at 12 03 17 AM](https://user-images.githubusercontent.com/25276186/105817127-0f222480-5f6a-11eb-96d8-4d3ddfadc1c9.png)
![Screen Shot 2021-01-26 at 1 40 00 AM](https://user-images.githubusercontent.com/25276186/105828113-9d50d780-5f77-11eb-8435-05d218a7e11e.png)<br /><br />


## Copy the reference of source code to your IDE
- Now open your project using Xcode. 
![Screen Shot 2021-01-26 at 9 15 52 PM](https://user-images.githubusercontent.com/25276186/105946237-bad77d00-601b-11eb-85b3-3d73ccf19ca5.png)
- You may select the **src** folder from the left side bar area. Then, right click the folder and select **Add Files to ..**
![Screen Shot 2021-01-26 at 9 26 23 PM](https://user-images.githubusercontent.com/25276186/105947042-3c7bda80-601d-11eb-861e-b20d20cb4575.png)
- Finally, add all the **.cpp and .h** files exclude **ofApp.cpp, ofApp.h, and main.cpp** to your project. 
![Screen Shot 2021-01-26 at 9 45 57 PM](https://user-images.githubusercontent.com/25276186/105948532-f1af9200-601f-11eb-8953-c89ea8d293cf.png)<br /><br />
# View objects explaination
- Now if you compile and run the project, you will have a Window as the following picture. First, all the small spheres in **yellow** and **black** color are representing the **point light**, which emits light ray in 360 degree. Then, the two small spheres in **yellow** and **white** color with arrows are representing the spot-light. The two panels in **yellow** and **blue** colors with many arrows are representing the area-light. The three big spheres in **blue**,**yellow**,and **red** colors are defined as the **sceneObject**. The rabbit, which is sitting on the **yellow** sphere is a Mesh object. Finally, the wall panels and the table panels are defined as **plane** object, which is inherited from the **SceneObject**.
![Screen Shot 2021-01-26 at 9 56 25 PM](https://user-images.githubusercontent.com/25276186/105949349-63d4a680-6021-11eb-853f-d062f4cca61f.png)<br /><br />

# Explanation of addLightSource function in RayTracingSystem
- The addLightSource function in **RayTracingSystem** is taking only one parameter, which is a pointer to **SceneObject**.<br /><br />
A **SceneObject** object can be one of the following object:
- **SceneObject**, which is the base object that can be added to **RayTracingSystem**.
- **Plane**, which is inherited from **SceneObject**.
- **Sphere**, which is inherited from **SceneObject**.
- **MeshObj**, which is inherited from **SceneObject**.<br /><br />


# Adding renderable scene object into the RayTracingSystem 
-  In **ofApp.cpp** file, you may add **floor plane/wall plane** object to the System. The following code are an examples to add **Plane** object to **RayTracingSystem**. 
```
this->_ray_tracing_system->addSceneObject(new Plane(glm::vec3(0,-2,0),glm::vec3(0,1,0),ofColor::lightCyan,40,40, nullptr,true)); // A mirror reflectable Plane with not texture.
this->_ray_tracing_system->addSceneObject(new Plane(glm::vec3(0,18,-20),glm::vec3(0,0,1),ofColor::skyBlue,40,40, new ofImage("wallPlaneTexter.jpeg"))); //A plane with texture but no mirror reflectable.
this->_ray_tracing_system->addSceneObject(new Plane(glm::vec3(0,18,-20),glm::vec3(0,0,1),ofColor::skyBlue,40,40))); // A plane with no texture and is no mirror reflectbale. 
```
Each parameter in the constructor of **Plane** object as following: <br />
The First : position of the plane.<br />
The second : normal vector of the plane.<br /> 
The thrid(optional) : the color of the plane.<br />
The fourth(optional) : the width of the plane.<br />
The fifth(optional): the length of the plane.<br />
The sixth(optional): the pointer to ofImage object.<br />
The last(optional): a boolean value stands if the plane is mirror reflectable or not.<br />

**Note: if you don't pass value to a optional parameter, the constructor of the **Plane** object will provide default value for it.**
![Screen Shot 2021-01-28 at 2 38 39 AM](https://user-images.githubusercontent.com/25276186/106126946-e38e6e00-6112-11eb-9cc1-5b23eae9f666.png)<br /> <br />

- In **ofApp.cpp** file, you may add **Sphere** to System. The following code is an example to add **Sphere** object to **RayTracingSystem**.
```
this->_ray_tracing_system->addSceneObject(new Sphere(glm::vec3(-4,2,0),3.0f,ofColor::blue)); // A sphere.
this->_ray_tracing_system->addSceneObject(new Sphere(glm::vec3(-6,2,0),3.0f)); // A sphere with default color.
this->_ray_tracing_system->addSceneObject(new Sphere(glm::vec3(-6,2,0),3.0f,ofColor::white,true)); // A mirror reflectable sphere.
```
Each parameter in the constructor of **Sphere** object as following: <br />
The First : position of the sphere.<br />
The second : the raduis of the sphere.<br /> 
The thrid(optional) : the color of the sphere.<br />
The fourth(optional) : a boolean value stands if the sphere is mirror reflectable or not.<br />
**Note: if you don't pass value to a optional parameter, the constructor of the **Sphere** object will provide default value for it.**
![Screen Shot 2021-01-28 at 3 13 43 AM](https://user-images.githubusercontent.com/25276186/106131210-3ff38c80-6117-11eb-93a5-500ae8b16f52.png)<br /><br />

- In **ofApp.cpp** file, you may add **MeshObj** object by importing information from an **obj** file, which is a geometry definition file format. To render image perfectly, the **obj** file should only contains information of **Triangle Mesh**. The following link is showing you how to convert **Polygon** faces to **Triangle** Mesh using AutoDesk Maya.<br />
[Convert Polygon faces to Triangle Mesh](https://knowledge.autodesk.com/support/maya/learn-explore/caas/CloudHelp/cloudhelp/2020/ENU/Maya-Modeling/files/GUID-46439E7A-3FD0-460B-93FC-23917179D101-htm.html)<br /><br />
 The following code is an example to add **MeshObj** object to **RayTracingSystem**.
```
this->_obj_file = new ofxAssimpModelLoader();
if(_obj_file->loadModel("Rabbit_Lowpoly_1.obj"))
{
    this->_ray_tracing_system->addSceneObject(new MeshObj(glm::vec3(0, 6, 2), _obj_file, ofColor::saddleBrown, ofColor::gray));
}
else
{
    std::cout<<"Can't not load the obj file"<<std::endl;
    return;
}
```
Each parameter in the constructor of **MeshObj** object as following: <br />
The first parameter: the position for obj file.<br />
The second: the pointer to **ofxAssimpModelLoader**, which is used to load obj file.<br /> 
The thrid(optional): the diffuse color for each **Triangle Mesh** in the **obj** file.<br />
The fourth(optional): the special color for each **Triangle Mesh** in the **obj** file.<br />
![Screen Shot 2021-01-28 at 4 32 07 AM](https://user-images.githubusercontent.com/25276186/106139093-d6c54680-6121-11eb-85f8-fb31f077b303.png)
<br /><br />

# Explanation of addLightSource function in RayTracingSystem. 
- The addLightSource function in the **RayTracingSystem** takes three parameters, a pointer to one type of light, and two boolean vaule. The first parameter is mandatory while second and the thrid are optional.
The first parameters is a pointer to one of lightscoure object as following: 
- LightSource, which is normal point light with 360 illumination angle.
- SpotLight, which is inherited from LightSource, and it has limited illumination angle.
- AreaLight, which is inherited from LightSource, and it is considered as integration of many of point light object in one panel. <br /><br />

The second of boolean parameter:
- It represents if the light being added to the **RayTracingSystem** is a **SpotLight** object or not. It is a optional parameter. If you don't provide a value to this parameter, the default value for this parameter is **false**. <br /><br />

The thrid pf boolean parameter: 
- It represents if the light being added to the **RayTracingSystem** is a **AreaLight** object or not. It is a optional paramter. If you don't provide a value to this parameter, the default value for this parameter is **false**. <br /><br />

# Adding different type of light source to the rendering system. 
- In **ofApp.cpp** file, you may add normal **LightSource** object, which is a **point light**, to rendering system. The following code is an example to add **LightSource** object to **RayTracingSystem**.
```
this->_ray_tracing_system->addLightSource(new LightSource(glm::vec3(-16,23,-17),5.0f,ofColor::yellow));
```
Each parameter in the constructor of **LightSource** object as following:
The first: the position of **LightSource**.<br />
The second: the intensity of the **LightSource**.<br /> 
The thrid: the color of the **LightSource**.<br />
The fourth(optional): the coefficient of Phong power of the **LightSource**.<br />
![Screen Shot 2021-01-29 at 2 49 43 AM](https://user-images.githubusercontent.com/25276186/106265984-b27a7000-61dc-11eb-8289-9cc0025f6e3a.png)
<br /><br />

- In **ofApp.cpp** file, you may add **SpotLight** object to rendering system. The following code is an example to add **SpotLight** object to **RayTracingSystem**.**A SpotLight is inherited from LightSource.**
```
// Note: The boolean parameter in the function addLightSource function is representing that 
//       if the lightsource being added is a SpotLightSource object or not. 
this->_ray_tracing_system->addLightSource(new SpotLightSource(glm::vec3(8,10,12),5.0f,15.0f,glm::vec3(-4,2,0),ofColor::white),true);
```
Each parameter in the constructor of **SpotLight** object as following:
The First: position of the SpotLight.<br />
The second: the intensity of the **SpotLight**.<br /> 
The thrid: the illumination angle of **SpotLight**.<br />
The fourth: the direction vector that SpotLight is pointing to.<br />
The fifth(optional): the color of the **SpotLight**.<br />

**Note: The last boolean parameter in addLightSource function is repersenting for if the light being added is a SpotLightSource object or not.**

![Screen Shot 2021-01-29 at 3 01 36 AM](https://user-images.githubusercontent.com/25276186/106267326-54e72300-61de-11eb-82ab-04e47671dc71.png)
<br /><br />

- In **ofApp.cpp** file, you may add **AreaLight** object to rendering system. The following code is an example to add **AreaLight** object to **RayTracingSystem**.
```
// Note: The second boolean parameter in the addLightSource function is representing 
//       if the lightsouce being added is a spotlight or not. 
//       In this case, you want to add a arealight, therefore it value of that boolean parameter is false.
//       The last boolean parameter in the addLightSource function is representing 
//       if the lightsouce being added is a arealight or not. 
//       In this case, the value of the boolean parameter is true. 
this->_ray_tracing_system->addLightSource(new AreaLight(glm::vec3(-15,5,0),glm::vec3(1,0,0),100.0f,-40.0f,ofColor::yellow,3.0f,3.0f,5),false,true);
```
Each parameter in the constructor of **AreaLight** object as following: <br />
The first : position of the **AreaLight**.<br />
The second : the outer normal of the **AreaLight**.<br /> 
The thrid : the intensity coefficient of **AreaLight**.<br />
The fourth : the rotation angle relative to axis, which is parallel to **AreaLight**.<br /> <br />
(e.g) For instanc, if an **AreaLight** object has a outer normal (1,0,0), the illumination dirction of the **AreaLight** is to the positive x axis.<br />
      Then, rotation angle for this **AreaLight** is relatvie to positvie y axis. <br /><br />
The fifth : the color of the **AreaLight**.<br />
The sixth : the length of the **AreaLight**.<br />
The seventh : the width of the **AreaLight**. <br/>
The last : number of n by n **pointLight** has been integraled in **AreaLight**. <br/>
(e.g) if the value of the last parameter is 5, it means there are number of 5x5, which is 25, pointLight objects has been included in the **AreaLight** <br/><br/>
**Note: The last boolean parameter in addLightSource function is repersenting for if the light being added is a AreaLight object or not.**
![Screen Shot 2021-01-29 at 7 41 04 PM](https://user-images.githubusercontent.com/25276186/106346216-46dee400-626a-11eb-9fae-2e0ab1e43459.png)

# GUI
- When you run the project, you may use the GUI panel, which located on the left top corner of window, to adjust information for different type of light source. You may change the postion for **SpotLight** and **AreaLight**. Also, you may change the coefficient intensity and power for each lights. Finally, you may change the illumination angle for the **SpotLight** and the rotation angle for the **AreaLight**. 
![Screen Shot 2021-01-29 at 9 51 37 PM](https://user-images.githubusercontent.com/25276186/106348621-60892700-627c-11eb-9e6f-e9c9b91a9513.png)

# Adding more controller to GUI
- If you wish to add more controller to GUI panel, you may begin with reviewing following link to obtain a basic understanding about **ofxGUI** object.[Tutorial of using GUI](https://openframeworks.cc/learning/01_basics/how_to_create_slider/)<br/><br/>

- Now following steps are an example to add another controller to changed position of an additional **AreaLight**.
Step 1: <br/>
In the **ofApp.h** file, you may define a new **ofxVec3Slider** variable, which is one of **component** can be add to **GUI** panel. 
![Screen Shot 2021-01-29 at 10 35 06 PM](https://user-images.githubusercontent.com/25276186/106349392-6c77e780-6282-11eb-8423-4eedf667ca19.png)<br/><br/>

Step 2: <br/>
In the **setup** function of **ofApp.cpp** file, you may add the component that you just defined into the **GUI** panel.<br/>
Following code is showing you an example to do so<br/>
```
this->_gui.add(this->_thrid_area_light_position.setup("Thrid(New Added) area-light position: ",ofVec3f(15,5,0),ofVec3f(-20,-20,-20), ofVec3f(20,20,20)));
```
Note: Each parameter for the **setup** function the component object you just defined in the **ofApp.h** file as following.<br/><br/>
First parameter: Initial value for the component.<br/>
Second parameter: The minimum(Min) value for the component.<br/>
Thrid parameter: The maximum(Max) value for the component.<br/><br/>
That is to say, the code shown above, give you a component, which it initial values for **x, y, and z** are **15, 5,and 0**. The Min values for **x,y, and z** are **-20, -20, and -20**. The Max values for **x, y, and z** are **20, 20, and 20**. 
![Screen Shot 2021-01-29 at 10 48 30 PM](https://user-images.githubusercontent.com/25276186/106349800-c0380000-6285-11eb-9b40-041831dfb2d4.png)
![Screen Shot 2021-01-29 at 10 59 15 PM](https://user-images.githubusercontent.com/25276186/106349801-c4641d80-6285-11eb-9850-6d27460e321c.png)
<br/><br/>

Step 3:
In the **update** function of **ofApp.cpp** file, you may call **updateAreaLightPosition** in the **RayTracingSystem** to update the position of a **AreaLight** object. Following code are an example to update the position for an area light.
```
this->_ray_tracing_system->updateAreaLightPosition(this->_thrid_area_light_position, 2);
```
The **updateAreaLightPosition** takes two parameter. The first parameter is the **ofxVec3Slider** object, which containe the inforamtion of new position that the **AreaLight** object should be shift to. The second parameter is the index of the **AreaLight** object in the **RayTracingSystem**. In this example, since there were two **AreaLight** objects were already added in the **RayTracingSystem**, the index of the latest **AreaLight** that has been added in the **RayTracingSystem** is 2 (index starts from 0).
![Screen Shot 2021-01-30 at 12 40 02 AM](https://user-images.githubusercontent.com/25276186/106352050-ffba1880-6294-11eb-9390-ff48d95b42f7.png)


# (Important) How to rendering an Image.
- After you add renderable object and different type of lights to the **RenderingSystem**, you may recompile and run the code again. Then you may press **"s"** key from keyboard to begin the process of rendering. After the process of rendering completed, you may press **"F4"** from keyboard to review the image that just been generated. 


