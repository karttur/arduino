---
layout: post
title: MIT App Inventor
categories: ide
excerpt: "MIT App Inventor"
tags:
  - arduino IDE
  - MIT app inventor
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-11-10 11:27'
modified: '2019-11-10 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

[MIT App Inventor](https://appinventor.mit.edu) is a web application (app) Integrated Development Environment (IDE) for creating Android apps. If you want to know more visit the official page on [Getting Started with MIT App Inventor](https://appinventor.mit.edu/explore/get-started), that also links to some easier projects to start with.

## Get started

On the [official MIT App Inventor page](https://appinventor.mit.edu) click the <span class='button'>Create Apps!</span> button. If you have a Google account you can login with that directly, otherwise you have to create an account.

## My first Android + Arduino app

To learn how to develop an app for Android OS that  communicates with Arduino, I used the [Youtube instruction: How to Build Custom Android App for your Arduino Project using MIT App Inventor](https://www.youtube.com/watch?v=o-YVvxYiSuk). It is a very (very) quick tutorial, but it covers all the required steps. This post is the text version of parts of that Youtube instruction. The project aims at connecting an Arduino board with a single LED to an Android mobile phone using Bluetooth. The mobile interface will then be used for turning the LED on and off.

First you have to write and load the Arduino sketch and load it onto your Arduino board.

## Arduino sketch

```
#define ledPin 7

int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    state = 0;
  }
  else if (state =='1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
    state = 0;
  }
}
```

## Create button

For this project you need one button, for opening the Bluteooth connections on your Android mobile phone. ![My Map](../../images/bluertooth_connect-btn_200x41_v02.png){: .pull-right}
You can use any button design you like for this tutorial, if you want to make a customized button you can follow the tutorial on Karttur's [Button design page](../design-buttons).

## MIT App inventor

<figure>
<img src="../../images/mit_app_01.png">
<figcaption> MIT App Inventor Designer page.
</figcaption>
</figure>

The MIT App inventor Graphical User Interface (GUI) has two (2) modes (screen): _Designer_ and _Blocks_. The app always starts in _Designer_ mode and the buttons for switching are in the upper right corner. The designer screen contains 4 columns, with the following top rows: _Palette_, _Viewer_, _Components_ and _Properties_. The left column (with the _Palette_ top row) contains all the components that can be added (clicked-dragged-dropped) to the app under development (_Viewer_).

### Create a new project

From the upper menu of the MIT App Inventor, create a new project:

<span class='menu'>Projets -> Start new project</span>, give a <span class='textbox'>Project name:</span> and click <span class='button'>OK</span>.
mit_app_02_new-project

<figure>
<img src="../../images/mit_app_02_new-project.png">
<figcaption> Create New App Inventor Project.
</figcaption>
</figure>

The page listing "My Projects" will automatically open. Click on the project you want to work with to open the GUI.

<figure>
<img src="../../images/mit_app_03_my-projects.png">
<figcaption> MIT App Inventor list of user projects.
</figcaption>
</figure>

#### Link to mobile

You can create a link between the MIT App Inventor and your Android phone, and your project will be shown live in real time on your phone. To do that you first need to grab you mobile and download and install the [MIT AI2 Companion](https://apkpure.com/mit-ai2-companion/edu.mit.appinventor.aicompanion3) in your mobile phone. The app is available from google play store.

When you have the MIT AI2 Companion installed, go back to the MIT App Inventor (on your computer) and then select from the menu:

<span class='menu'>Connect -> AI companion</span>.

<figure>
<img src="../../images/mit_app_04_companion-connect.png">
<figcaption> MIT App Inventor Companion Connect.
</figcaption>
</figure>

You will be presented with a QR code, open the MIT AI2 Companion on you phone and either choose <span class='button'>Connect with code</span> or <span class='button'>Scan QR code</span>. The mobile phone in the _Disigner_ view will be reflected live on your Android phone.

### Design layout

![My Map](../../images/mit_app_05_horizontalarrangement.png){: .pull-right}
Add a horizontal arrangement: from the left column (_Palette_), click on the _Layout_ alternativ, then click and hold the mouse on _HorizontalArrangement_ and drag to the phone view. The _HorizontalArrangement_ will lock to the upper left corner.

<br><br>The _Components_ column will show _HorizontalArrangement1_ under the _Screen1_ component. The _Properties_ column shows the properties of the component _HorizontalArrangement1_. Change the following properties:

| property | value |
| AlignHorizontal | Center:3 |
| Height   | 6 percent  |
| Width   | Fill parent   |

Create a second _HorizontalArrangement_ just below the first, and set identical properties.

![My Map](../../images/mit_app_06_listpicker.png){: .pull-right}
In the _HorizontalArrangement2_ (the second one below) you should now add a _ListPicker_. In the left column, change in the menu:

<span class='menu'>User Interface -> ListPicker</span>; click hold and drag a _ListPicker_ to the component _HorizontalArrangement2_. The _Listpicker_ should be horizontally centered and show the text _Text for ListPicker1_. You are going to replace this text with a button (for example the button created above).

With _ListPicker1_ active, in the _Properties_ column erase the content for _Text_, and click the (empty) box for _Image_. in the dialog box that opens add the button image. Your image will probably not exactly fit the height of _HorizontalArrangement2_. Activate _HorizontalArrangement2_ and in the _Properties_ column change _Height_ to _Automatic_.

Create a third _HorizontalArrangement_, and set identical properties to the second (with _Height_ kept as _Automatic_). Then navigate in the left column to drag a _Label_ to _HorizontalArrangement3_:

<span class='menu'>User Interface -> Label</span>

By default the new component will be names _Label1_ and show the default text _Text for Label1_. Go to the _Properties_ of _Label1_ and change the _Text_ to _Not Connected_. Leave other options with their default values.

Create a fourth _HorizontalArrangement_, and set identical properties to the first (with _Height_ set to 6 percent). The add a fifth _HorizontalArrangement_ with _Height_ kept as _Automatic_ and add a label also to this component (_HorizontalArrangement5_). Change the text in the label (_Label2_) in _HorizontalArrangement5_ to _LED: OFF_ - this is the initial state of the LED once the app is up and running.

Create a sixth _HorizontalArrangement_, and keep the _Height_ at _Automatic_ while changing _AlignHorizontal_ and _Width_ as before. Add two (2) _Buttons_ to the _HorizontalArrangement_ (should be nr 6):

![My Map](../../images/mit_app_08_full-interface.png){: .pull-right}

<span class='menu'>User Interface -> Button</span>

The two buttons will align horisontally. To set a space between them, add a _VerticalArrangement_ and set both _Height_ and _Weight_ to 6 percent. Change the text of the two buttons to _Turn ON_ and _Turn OFF_. The _Designer_ interface of your Android App should then look similar to the illustration.

#### Invisible components

You must also add two invisible coomponents to your project: a _BluetoothClient_ and a _Clock_. As they are invisible you can drop them anywhere in your interface design. The way to get them from the menu:

<span class='menu'>Connectivity -> BluetoothClient</span>

<span class='menu'>Sensors -> Clock</span>

#### Rename components

To make the coding easier, you should rename the key components (i.e. all components except the arrangements) that you have to interactive with in the code blocks:

| Old name | New name |
| ListPicker1 | BTList |
| Button1   | TurnOnBtn |
| Button2  | TurnOffBtn |
| Label1   | ConnectStatus |
| Label2   | LEDStatus  |


### Block coding

With all the components added and logically named, it is time to turn to the block coding. Click the <span class='button'>Block</span> button in the upper right corner of MIT Inventor App. The GUI will change and show a white central area, that is where you are going to put the code blocks.

The blocks screen contains only 2 columns, with the hierarchical structure of components to the left and the viewer to the right. When you click on a component, all the possible code blocks for that components will form a middle column (or rather a column covering the left part of the viewer). The example below shows the blocks screen with the pop-out window for code associated with the _BTList_ component.

<figure>
<img src="../../images/mit_app_09_blocks-empty.png">
<figcaption> MIT App Inventor Blocks page.
</figcaption>
</figure>

When creating the code you first select the component that you want to relate the code to, then you select the code blocks that fulfill your needs. Rather than going through each step, the complete code for the project in this tutorial is shown in the figure below. To see all the individual steps in the coding, please have a look at the [Youtube instruction](https://www.youtube.com/watch?v=o-YVvxYiSuk). Note, however, that the components are named somewhat differently, and there are some other minor changes.

<figure>
<img src="../../images/mit_app_10_blocks-complete.png">
<figcaption> Complete code for the project in this tutorial.
</figcaption>
</figure>

### Build and install app

![My Map](../../images/mit_app_11_build-app.png){: .pull-right}
You can now build your app and install it on your Android mobile. From the MIT App Inventor menu choose:

<span class='menu'>Build -> App (provide QR code for apk)</span>

Your app will build and then you will be presented a QR code that you can scan with MIT AI2 Companion from your phone. When installing the app you have to accept bypassing the security settings (as your app is not provided by Google play).

Once installed, start your app as you start any other app. You should get the screen view of your project. Click the <span class='button'>Connect</span> button, and you will see all the Bluetooth devices paired to your phone. Pick the Arduino Bluetooth device. The text (label) under the <span class='button'>Connect</span> button should change to say _Connected_. You should then be able to turn the LED on and off with the two buttons on your mobile.
