---
layout: post
title: Button design
categories: design
excerpt: "Designing buttons for interactive media"
tags:
  - design
  - arduino
  - android
  - button
  - bluetooth
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-05 11:27'
modified: '2019-12-05 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

This post is about creating buttons with logos and text, keeping style and typeface similar for all buttons. All the processing is done using [ImageMagick](https://karttur.github.io/setup-theme-blog/blog/install-imagemagick/).

### Basic buttons

The [freepik page for buttons vectors](https://www.freepik.com/free-vectors/buttons) contain a large selection of basic free forms and designs. As a starting point I chose the [realistic set of glass plates](https://www.freepik.com/free-vector/realistic-set-transparent-glass-plates-blank-shining-frames-isolated-background_3519664.htm#page=1&query=buttons&position=35#position=35&page=1&query=buttons).

#### Removing the background (trial)

I tried to change the background checker boarding a bit, but that did not work out because the variation in color is too large. I just kept the trials there in case I ever want to try again. Just skip the rest of this section.

convert realistic-set-transparent-glass-plates-blank-shining-frames-isolated-background_1441-2441.jpg -fuzz 10% -fill 'rgb(180,180,180)' -opaque 'rgb(80,80,80)' result.png


convert realistic-set-transparent-glass-plates-blank-shining-frames-isolated-background_1441-2441.jpg -fuzz 10% -fill 'rgb(148,148,148)' -opaque 'rgb(80,80,80)' result.png

convert result.png -fuzz 20% -fill 'rgb(148,148,148)' -opaque 'rgb(120,120,120)' result2.png

#### Cut out single buttons

Starting with the full size image (2441.jpg with the size 5000x3875), the commands for extracting the different default shapes are given below. The parameter _+repage_ must be given to shrink the produced <span class='file'>.png</span> to the actual region with content.

##### Circle

**With margin**

convert -extract 1630x1630+58+95 2441.jpg +repage circle_1630x1630.png

**Without margin**

convert -extract 1610x1610+68+105 2441.jpg +repage circle_nomargin-1610x1610.png

##### Landscape

**With margin**

convert -extract 2705x1575+2005+100 2441.jpg +repage landscape_2705x1575.png

**Without margin**

convert -extract 2690x1555+2015+115 2441.jpg +repage landscape_nomargin-2690x1555.png

**Without rim**

convert -extract 2670x1535+2025+125 2441.jpg +repage landscape_norim-2670x1535.png

##### Large panorama

**With margin**

convert -extract 4460x660+330+1840 2441.jpg +repage largepano_4460x660.png

**Without margin**

convert -extract 4440x640+340+1850 2441.jpg +repage largepano_nomargin-4440x640.png

**Without rim**

convert -extract 4400x600+360+1870 2441.jpg +repage largepano_norim-4400x600.png

##### Square

**With margin**

convert -extract 1000x1000+200+2720 2441.jpg +repage square.png

**Without margin**

convert -extract 980x980+210+2730 2441.jpg +repage square_nomargin-980x980.png

**Without rim**

convert -extract 940x940+230+2750 2441.jpg +repage square_norim-940x940.png

##### Small panorama

**With margin**

convert -extract 2630x430+1400+2640 2441.jpg +repage smallpano_2630x430.png

**Without margin**

convert -extract 2610x410+1410+2650 2441.jpg +repage smallpano_nomargin-2610x410.png

**Without rim**

convert -extract 2590x390+1420+2660 2441.jpg +repage smallpano_norim-2590x390.png

##### Medium panorama

**With margin**

convert -extract 2630x560+1400+3160 2441.jpg +repage mediumpano_2630x560.png

**Without margin**

convert -extract 2610x540+1410+3170 2441.jpg +repage mediumpano_nomargin-2610x540.png

**Without rim**

convert -extract 2590x520+1420+3180 2441.jpg +repage mediumpano_norim-2590x520.png

##### Portrait

**With margin**

convert -extract 580x980+4240+2740 2441.jpg +repage portrait_580x980.png

**Without margin**

convert -extract 560x960+4250+2750 2441.jpg +repage portrait_nomargin-560x960.png

**Without rim**

convert -extract 540x940+4260+2760 2441.jpg +repage portrait_norim-540x940.png

### Bluetooth connect button

In this example you will use a bluetooth standard logo and create a Bluetooth connect button using one of the basic button shapes prepared above.

The required steps are:

1. Grab a bluetooth logo that you like from the internet,
2. Resize the Bluetooth logo to the final button height,
3. Create image with the text you want ("Connect"),
4. Combine the images with the logo and the text,
5. Convert the basic button to the same size as the combined logo+text image, and
6. Overlay text and button with transparency

#### 1. Bluetooth logo

![My Map](../../images/bluetooth_logo.png){: .pull-right}

Grab a bluetooth logo that you like from the internet. You have to grab it with margins if you want that, or use [ImageMagick](https://karttur.github.io/setup-theme-blog/blog/install-imagemagick) to put on margins, alternatively centering the logo when processing. I just grabbed the logo shown to the right.

#### 2. Resize Bluetooth logo

You have to set a width and height for you button. As you are using ImageMagick it is very easy to change the formats later. Once you have decided on the dimensions, resize the bluetooth logo to the selected height (41 lines in the example):

<span class='terminal'>$ convert bluetooth_logo.png -resize x41 bluetooth_logo-x41.png</span>

If you want to change the background color (white in the example) to some color that better matches the button (this might be advantageous for the final overlay) use the parameter combinations _fuzz_, _fill_ and _opaque_. The parameter _fuzz_ determines how close to _opaque_ (white in the example) a pixel must be to be converted to _fill_. Higher values of _fuzz_ will change more generously.

This example changes the background to a blueish-grey color resembling the button background.

![My Map](../../images/bluetooth_logo-grey-x41.png){: .pull-right}

<span class='terminal'>$ convert bluetooth_logo.png -resize x41 -fuzz 40% -fill 'rgb(121,140,145)' -opaque white bluetooth_logo-grey-x41.png</span>

While this example changes the background to a a very light blue.

![My Map](../../images/bluetooth_logo-blue-x41.png){: .pull-right}

<span class='terminal'>$ convert bluetooth_logo.png -resize x41 -fuzz 40% -fill 'rgb(121,140,145)' -opaque white bluetooth_logo-blue-x41.png</span>

#### 3. Button text

The text you want to appear on the button must also be designed, for example regarding type face, font size, color, weight (normal, bold or italics) and position. The height of the text image should equal the height of the logo (41 lines in this example). The width can be set freely or adjusted to fit the button you are going to use. In the latter case the width should equal "final width" - "logo width", as you will join the logo and the text to create the items to be put in the button.

![My Map](../../images/connect_text.png){: .pull-right}
With the first example you get letters with only outlines (as the parameter _fill_ is set to _none_):

```
convert -size 171x41 xc:white \
	-strokewidth 2 -stroke black -fill none \
	-font Arial -family Arial -pointsize 40 -strokewidth 1 -stroke blue \
	-annotate +10+35 "Connect" \
	connect_text.png
```

In this second example the letters are solid:
```
convert -size 171x41 xc:white \
	-font Arial -family Arial -pointsize 40 -strokewidth 1 -stroke blue -fill blue \
	-annotate +10+35 "Connect" \
	connect_text.png
```

![My Map](../../images/connect_text-grey.png){: .pull-right}
If you want a text background that blends better with the button, set another _xc_ color (note these are the same two colors as set for the logo background above):

```
convert -size 171x41 xc:'rgb(121,140,145)' \
	-stroke 'rgb(13,49,149)' -fill 'rgb(13,49,149)' \
	-font Arial -family Arial -pointsize 40 \
	-annotate +10+35 "Connect" \
	connect_text.png
```
![My Map](../../images/connect_text-blue.png){: .pull-right}
or

```
convert -size 171x41 xc:'rgb(225,225,255)' \
	-stroke 'rgb(13,49,149)' -fill 'rgb(13,49,149)' \
	-font Arial -family Arial -pointsize 40 \
	-annotate +10+35 "Connect" \
	connect_text.png
```

#### 4. Join logo and text

![My Map](../../images/bluetooth_connect-btn-overlay-blue_200x41.png){: .pull-right}

If you created a logo and a text with the same height, just assemble them horisontally:

<span class='terminal'>$ convert bluetooth_logo-blue-x41.png connect_text-blue.png +append bluetooth_connect-btn-overlay-blue_200x41.png</span>

To join vertically just change from _+append_ to _-append_.

#### 5. Button size

![My Map](../../images/bluetooth_btn-200x41.png){: .pull-right}
As the button overlay is ready you have the size (200x41 in the example). You have to select one of the default sized buttons and resize it to fit the overlay. In the example it must be one of the "panorama" sizes. You also have to decide if you want a button with or without margin or rim. You can also use IamgeMagick to either [shave](https://karttur.github.io/setup-theme-blog/blog/install-imagemagick/#shave) the image further or [add a frame](https://karttur.github.io/setup-theme-blog/blog/install-imagemagick/#set-border-and-colors).

<span class='terminal'>$ convert mediumpano_nomargin.png -resize 200x41! bluetooth_btn-200x41.png</span>

##### Change button color

![My Map](../../images/bluertooth_btn-200x41.png){: .pull-right}
Here is an example of how to add some blue tint to the button.

<span class='terminal'>$ composite -blend 90 bluetooth_btn-200x41.png \( -size 200x41 xc:'rgb(120,120,255)'  \) bluertooth_btn-200x41.png</span>

#### 6. Overlay to final button

You should now have two images of the same size (and in different versions), the basic button and the logo+text image to overlay. You need to decide on how to set the transparency for the overlay.

##### Blended overlay

![My Map](../../images/bluetooth_connect-btn_200x41_v01.png){: .pull-right}
The first example of a 50/50 blended overview makes use of the original button:

<span class='terminal'>$ composite -blend 50 bluetooth_btn-200x41.png bluetooth_connect-btn-overlay_200x41.png bluetooth_connect-btn_200x41_v01.png</span>

![My Map](../../images/bluertooth_connect-btn_200x41_v02.png){: .pull-right}
Alternatively use the button with added blue tint:

Because of the white background in the overlay (logo+text image) the button fades away.

##### Transparent overlay

![My Map](../../images/bluetooth_connect-btn_200x41_v03.png){: .pull-right}
You can also overlay the logo+text by setting its background to transparent. The results is better if you then use the text+logo image that already has a background that is close to the button background.

<span class='terminal'>$ convert bluertooth_btn-200x41.png \( bluetooth_connect-btn-overlay_200x41.png -fuzz 10% -transparent 'rgb(121,140,145)' \) -gravity center -composite  bluetooth_connect-btn_200x41_v03.png
</span>

### Complete process

The complete process for producing three alternative buttons for Bluetooth connect.

```
### Complete process ###

# 0 get the basic button

convert -extract 2590x520+1420+3180 2441.jpg +repage mediumpano_norim-2590x520.png

# 1. Grab Bluetooth logo from the internet, name it "convert bluetooth_logo.png"

# 2. Resize Bluetooth logo

convert bluetooth_logo.png -resize x41 -fuzz 40% -fill 'rgb(121,140,145)' -opaque white bluetooth_logo-grey-x41.png

# with alternative background

convert bluetooth_logo.png -resize x41 -fuzz 40% -fill 'rgb(225,225,255)' -opaque white bluetooth_logo-blue-x41.png

# 3. Button text with color set to the same as for the logo

convert -size 171x41 xc:'rgb(121,140,145)' \
	-stroke 'rgb(13,49,149)' -fill 'rgb(13,49,149)' \
	-font Arial -family Arial -pointsize 40 \
	-annotate +10+35 "Connect" \
	connect_text-grey.png

# with alternative background

convert -size 171x41 xc:'rgb(225,225,255)' \
	-stroke 'rgb(13,49,149)' -fill 'rgb(13,49,149)' \
	-font Arial -family Arial -pointsize 40 \
	-annotate +10+35 "Connect" \
	connect_text-blue.png

# 4. Join logo and text

convert bluetooth_logo-grey-x41.png connect_text-grey.png +append bluetooth_connect-btn-overlay-grey_200x41.png

convert bluetooth_logo-blue-x41.png connect_text-blue.png +append bluetooth_connect-btn-overlay-blue_200x41.png

# 5. Button size

convert mediumpano_nomargin.png -resize 200x41! bluetooth_btn-200x41.png

# Add some blue tint

composite -blend 90 bluetooth_btn-200x41.png \( -size 200x41 xc:'rgb(120,120,255)'  \) bluertooth_btn-200x41.png

#### 6. Overlay to final button

# blended overlay with two different tints of blue

composite -blend 50 bluetooth_btn-200x41.png bluetooth_connect-btn-overlay-blue_200x41.png bluetooth_connect-btn_200x41_v01.png

composite -blend 50 bluertooth_btn-200x41.png bluetooth_connect-btn-overlay-blue_200x41.png bluertooth_connect-btn_200x41_v02.png

# or transparent overlay

convert bluertooth_btn-200x41.png \( bluetooth_connect-btn-overlay-grey_200x41.png -fuzz 10% -transparent 'rgb(121,140,145)' \) -gravity center -composite  bluetooth_connect-btn_200x41_v03.png
```
