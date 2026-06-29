# Winfetch

A fast, neofetch-like system information tool for Windows, written in pure C.

## ✨ Features

- **Fast performance** — Written in pure C with minimal dependencies
- **ASCII logos** — Automatic Windows version detection (8, 8.1, 10, 11)
- **System info** — CPU, GPU (with VRAM), RAM usage
- **User info** — Username and OS version
- **Cross-version support** — Works from Windows 8 to Windows 11

## 🚀 Installation
[https://github.com/Steve5741/Winfetch/releases/tag/windows-fetch](https://github.com/Steve5741/Winfetch/releases)

## Build from source (requires CMake)

### Clone the repository
git clone https://github.com/Steve5741/Winfetch.git

### Build with CMake
cmake -B build
cmake --build build

### Run
./build/Debug/winfetch.exe

### Requirements
- Windows 8 or later
- CMake 3.15+
- C compiler (MSVC, GCC, or Clang)

## 📖 Usage

- Show system information
- Add to PATH (optional)
- Copy winfetch.exe to a folder in your PATH

## 🗺️ Roadmap

- CPU detection
- RAM usage with percentage
- GPU name and VRAM
- User and OS info
- ASCII logos for Windows 8/8.1/10/11
- Customizable colors
- More system info (disk, network, uptime)
- Configuration file support

## 🤝 Contributing
Contributions are welcome! Feel free to:
- Open issues for bugs or feature requests
- Submit pull requests
- Suggest improvements

## 📄 License
This project is licensed under the MIT License — see the LICENSE file for details.

## 🙏 Acknowledgments
Inspired by neofetch and fastfetch.
