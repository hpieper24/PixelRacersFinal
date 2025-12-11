# Pixel Racers - 2D Racing Game

## Project Over
Pixel Racers is a top-down 2D racing game built with C++11 and SDL_Plotter. The player controls a car racing against AI opponents on an animatedd scrolling highway, avoiding obstacles, tracking laps, and competing for the highest score across 3 laps. The game demostrates object-oriented design, real-time input handling, basic AI behavior, collision detection, and a full screen/state system.

## Team Members & Roles
Jody Spikes | Core Mechanics | Game mechanics, car design and movement, AI cars, obstacles, collision
Hailey Pieper | UI & Aesthetics | Scoring sytem, text display, game screens, colors
Ian Dudley | Integration & Architecture | Code cleanup, combining files, main game engine

## Build Instructions

### Prerequisites
C++11 compiler
SDL2 libraries

## Gameplay Guide

### Objective
Complete 3 laps by surviving, passing AI cars (10 pts), avoiding obstacles (5 pts), while score accumulates over time. Complete lap 3 for victory.

### Controls
Up Arrow | Accelerate
Down Arrow | Brake
Left & Right Arrows | Steer lanes
M | Toggle Infinite Mode
P | Pause/Resume
B | Pause -> Main Menu
I | Main -> Instructions
S | Start Race
C | Restart (Game Over/Win)
Q | Quit Infinite Mode

### Screens and Game Floy

Start Screen
  Title and prompts
  S to start, I for instructions, M for Infinite Mode

Instructions Screen
  Shows basic controls and scoring rules
  S to start race, B to go back to Start

Playing Screen
  Scrolling road, AI cars, obstacles
  Score,lap count, and speed displayed
  P to pause

Pause Screen
  P to resme
  B to go back to Main menu

Game Over Screen
  Shows final score and what you hit (AI car or Obstacle)
  C to restart the race, B to go back to Start

Win Screen
  Reached when lap 3 is complete
  Shows final score
  C to restart the race

### On-Screen Display

Top-Left Corner of the Screen:
  Score:
  1234
  Speed:
  5
  Lap: 1/3

Score Increases:
  Over time while youa re alive (multiplies at higher speeds)
  When you successfully pass AI cars
  When you survive obstacles that scroll past you

Lap increases:
  Based on score thresholds up to 3 laps in normal mode

### Scoring System

Time survived: Base points each frame, scaled by your current speed
Passing an AI car: +10 points
Avoiding an Obstacle: +5 points

### Infinite Mode

Press M at start screen to toggle Infinite Mode
In Infinite Mode:
  The lab system no longer ends the race at top 3.
  You can keep driving and scoring until you crash or quit.
Press Q while racing to end Infinite Mode game.

## Features Implemented

### Required Features

Top-down 2D racetrack
  Scrolling background with road, lane markers, and edges

Player-controlled car
  Movement with arrow keys, responds in real time

AI-controlled cars (3 total)
  Move down the track, change lanes, and can be passed by the player.

Collision detection
  Detects when the player hits AI cars or obstacles and triggers Game Over.

Lap counting and race completion
  Lap count displayed on screen; game reaches Win Screen on completing 3 laps in normal mode.

Modular class structure
  Multiple classes split by responsibility (car, AI, background, etc)

### Enhancements Beyond Requirements

Start menu and instructions screen
Pause screen with menu return
Game Over and Win screens with text feedback
On-screen display for score, speed, and laps
Infinite Mode toggle for endless play

## Known Bugs and Limitations

AI behavior is simple
  AI cars follow basic line patterns and do not actively avoid the player

Laps are score-based
  Laps are tied to score thresholds rather than physical track distance

Fixed resolution
  Game is designed for a specific ROW x COL resolution and does not resize dynamically

No audio
  There are currently no engine sounds, collision sounds, or background music.

Occasional spawn overlaps
  In rare cases on restart or respawn, AI cars or obstacles may spawn close together

Lane Center Line
  Dashes lag during spawn causing extra large lines

## Design Summary
  Object-Oriented Design
    Game logic split into multiple classes (cars, background, obstacles, etc)

  State-based Screens
    A Screen base class with derived screens (Start, Instructions, Playing, etc) managedby a simple game state enum.

  Scoring and Laps
    Points logic tracks over time and events; lap count is derived from score, up to 3 laps for the win condition in normal     mode.

  Player-centric Speed
    Player speed controls scroll rate of the background, AI, and obstacles, giving the illusion of forward motion and           influencing scoring.