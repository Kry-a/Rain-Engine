# Rain-Engine
An amateurish 3D game engine

## Building (Linux)
* 1 . Install the dependencies
```bash
sudo apt install cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev
```
or
```bash
su && yum install cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev
```
* 2 . Download the repository
```bash
git clone git@github.com:KrasnotR/Rain-Engine.git
cd Rain-Engine
git submodule update --init --recursive
```
* 3 . Build the project
```bash
./build.sh
```
* 4 . Run the project
```bash
cd build && ./Rain-Engine
```
