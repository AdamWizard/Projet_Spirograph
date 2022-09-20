# Project_Spirograph
This project started as a 4th year project for school.

This program allows you to make spirograph shapes by using virtual spinning gears, compared to a physical spirograph we have a key advantage: virtual discs are not real, and can pass through eachother! therefore we can make some extra fancy looking shapes with a little imagination!

# Installation
To install this project, you just need to clone it, all necessary files and libraries are included!

# Before running
## How to make your own shapes
To make your own shape you can go look for the init.txt file in the resources folder and modify it, please write like so:

A typical init.txt file:

![image](https://user-images.githubusercontent.com/48995051/183664990-c9ee371b-9ae1-4ad1-98b7-8bb64e290462.png)

If your init.txt respects this format, you are ready to run spirograph.exe and watch the program build your shape!

The text should remain the same, specify your desired amount of discs and write disc lines accordingly.
When writing a disc line you have to take into account: the radius of the disc, its position in regards to the previous disc, and its rotation
## 1. Discs
#### Number of discs (or gears)
- Here just type "Number_of_discs" and then the amount of discs you want to be in your spirograph.
#### Disc declaring
First put in the word "Disc" so that the program knows you are declaring a disc, then you can put in:
  - radius


    any number, as long as it does not exceed the screen bondaries, it is the radius of the disc you are declaring.
  - position


    "i" or "e" meaning respectively on the "interior" or "exterior" of the previous disc.
  - rotation


    "c" or "t" meaning respectively a "clockwise" or "trigonometric" (counter clockwise) rotation.
  
## 2. Pencils
#### Number of pencils
Here just type "Number_of_pencils" and then the amount of pencils you want, this modifies the amount of curves you will draw.
#### Pencil declaring
First put in the word "Pencil" so that the program knows you are declaring a pencil, then you can put in:
  - distance


  Any number, as long as it does not exceed the screen bondaries, it is the distance from the center of the last disc to your pencil.
 
## 3. Important note
Here i say "as long as it does not exceed the screen bondaries" pretty loosely, basically in the current version the program crashes if we try and draw outside of the drawing board, so just try and no exceed the boundaries please :)

# While running
## How to speed up or slow down
You can use the side arrow keys: 
  - holding `left arrow` slows down the movement and will eventually stop it

  - holding `right arrow` speeds up the movement, no upper limit of speed is defined.
## How to hide or show gears
You can simply press `spacebar` to toggle gear visibility, it is off by default.
## How to take a screenshot
You can press `s` to save a screenshot of what is currently on the drawing board, it will be saved in the `Projet_Spirograph\screenshots` folder and will be named with the date and time at which you saved it.
## How to quit
To quit at any point in execution simply close the window, of press `escape`.


## Future features
My immediate goal is adding UI elements to not force the user into a text file every time they watn to generate a different drawing.
Ellipses are also on the list, being able to use elliptic gears instead of round ones will open more drawing possibilities, and real spirographs do it so yeah we want to be like the cool kids.
