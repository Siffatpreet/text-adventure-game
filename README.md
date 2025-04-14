# Text-Based Adventure Game

## Overview

This is a simple text-based adventure game written in C, where the player navigates through different rooms and encounters enemies to fight. The game provides a basic combat system where the player can move between rooms, face enemies, and engage in combat.

## Features

- Navigate between different rooms.
- Fight enemies with basic health and attack power.
- Player health and enemy health are displayed during combat.
- The game ends when the player's health reaches 0.

## Game Mechanics

1. **Rooms**:
   - Each room has a description, and some rooms may contain enemies.
   - The player can move to the next room by choosing "yes" when prompted.
   - If a room contains an enemy, the player will engage in combat before moving to the next room.

2. **Combat**:
   - The player and the enemy take turns attacking each other.
   - The player has health and attack power, as does the enemy.
   - The fight continues until either the player or the enemy is defeated.

3. **Player Stats**:
   - The player starts with 100 health and 20 attack power.
   - The player can face different enemies with varying health and attack power.

4. **Enemies**:
   - Enemies are placed randomly in the rooms.
   - The game currently features two types of enemies: Goblin and Orc.
