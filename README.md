# LED Matrix Clock (10x10) – Arduino Project

This repository contains multiple Arduino `.ino` files with prebuilt animations and functions for a **10x10 LED Matrix Clock (Matrixuhr / Digitaluhr)**.

The project is designed for a **10 × 10 LED field** that is controlled using a matrix scheme (row/column addressing).

---

## Features

- ⏰ Digital clock display
- 🎞️ Prebuilt animations
- 🔁 Reusable animation functions
- 💡 Matrix-based LED control (10x10)
- 🧩 Modular `.ino` files for easy customization

---

## Hardware Requirements

- Arduino board (e.g., Uno, Nano, Mega)
- 10x10 LED matrix (row/column matrix scheme)
- Appropriate resistors for LEDs
- Optional: RTC module (e.g., DS3231) for accurate timekeeping
- Breadboard or PCB
- Jumper wires

---

## Project Structure

The repository contains multiple `.ino` files:

- `Main.ino` – Main program entry point
- Animation files – Prebuilt animation patterns
- Function files – Matrix control and display logic

All `.ino` files inside the same folder are automatically combined by the Arduino IDE during compilation.

Example structure:

```
MatrixClock/
│── MatrixClock.ino
│── animations.ino
│── matrixFunctions.ino
│── clockLogic.ino
```

> Important: The main `.ino` file must have the **same name as the folder**.

---

## How to Import the Project into Arduino IDE

### Option 1 – Open the Project (Recommended)

1. Download this repository:
   - Click **Code → Download ZIP**  
   - OR clone it using:
     ```
     git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git
     ```

2. Extract the folder (if downloaded as ZIP).

3. Make sure:
   - The folder name matches the main `.ino` file name.

4. Open the main `.ino` file:
   - Double-click the file  
   OR  
   - Arduino IDE → **File → Open → Select the main `.ino` file**

5. Select your board:
   ```
   Tools → Board → Select your Arduino model
   ```

6. Select the correct port:
   ```
   Tools → Port → Select COM Port
   ```

7. Click **Upload**.

---

### Option 2 – Import into an Existing Sketch

1. Create a new sketch in Arduino IDE.
2. Open the sketch folder:
   ```
   Sketch → Show Sketch Folder
   ```
3. Copy all provided `.ino` files into this folder.
4. Restart Arduino IDE if needed.
5. Upload to your board.

---

## Customization

You can easily modify or extend the project:

- Add new animations
- Change animation speed
- Adjust brightness
- Modify matrix scanning logic
- Add RTC support for real-time clock functionality
- Change pin assignments to match your wiring

---

## Important Notes

- Ensure correct row/column wiring.
- Use transistors or driver ICs if controlling many LEDs simultaneously.
- Check current limits of your Arduino board.
- Multiplexing timing affects brightness and stability.

---


## Contributions

Feel free to fork this project, improve animations, and submit pull requests.

---

Happy building!
