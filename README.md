# accretion-thingi

<img width="1920" height="1080" alt="20261005_23h50m49s_grim" src="https://github.com/user-attachments/assets/9878593a-97d9-4281-97da-7446cdc36d37" />
<img width="1920" height="1080" alt="20261004_21h48m00s_grim" src="https://github.com/user-attachments/assets/4a5f72b2-7bdf-4e2d-a447-2c36229f2d84" />






A minimal C-based physics simulation demonstrating the orbital decay of a 3D particle swarm into a 2D accretion disk via inelastic collisions and the conservation of angular momentum. Built with Raylib.

## Dependencies
- `gcc`
- `raylib`

## Build & Run
#### For Linux - 
Download raylib from your preferred package manager. 
```bash
gcc accr.c main.c -lraylib -lm -o pl
./pl
```

#### For Windows - 
- Download the **64-bit** version of `w64devkit` from its [official GitHub releases](https://github.com/skeeto/w64devkit/releases).
- Extract the zip file and double-click `w64devkit.exe` to open the terminal.
- Navigate to the cloned repo and run:
```bash
make
./accretion.exe
```

#### For macOS -
Install raylib using Homebrew, then use the provided Mac Makefile:
```bash
brew install raylib
make -f Makefile.mac
./accretion
```
