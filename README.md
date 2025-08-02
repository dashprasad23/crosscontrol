# crosscontrol

**crosscontrol** is a cross-platform Node.js native addon for simulating keyboard and mouse input and reading pixel data. It provides high-level APIs for automating user interactions on macOS and Windows (Windows support in progress).

## ✨ Features

- Move mouse to any screen coordinate
- Click mouse (left, right, middle)
- Get current mouse position
- Type characters or combinations of keys
- Get RGB or Hex color of a pixel on screen

---

## 🚀 Installation

```bash
npm install crosscontrol
```

You must have `node-gyp` and a proper C++ build toolchain installed:
- On macOS: Xcode command line tools
- On Windows: [Windows Build Tools](https://github.com/felixrieseberg/windows-build-tools) + Visual Studio
- On Linux: `build-essential`, `libx11-dev`, etc.

---

## 🔧 Build from Source

```bash
npm install
npx node-gyp configure build
```

---

## 📦 Usage

```js
const cc = require('crosscontrol');

// Move the mouse to coordinates (500, 300)
cc.moveMouse(500, 300);

// Left-click
cc.clickMouse();

// Right-click
cc.rightClickMouse();

// Get mouse position
const pos = cc.getMousePosition();
console.log(pos); // { x: 500, y: 300 }

// Type a key
cc.typeKey("a");

// Press and release a key manually
cc.typeKeyWithState("ctrl", true);  // key down
cc.typeKeyWithState("ctrl", false); // key up

// Type a combination of keys (e.g., Ctrl+C)
cc.typeCombo(["ctrl", "c"]);

// Get RGB color at pixel (100, 100)
const color = cc.getPixelColor(100, 100);
console.log(color); // { r: 255, g: 255, b: 255 }

// Get pixel color as hex
const hex = cc.getPixelHex(100, 100);
console.log(hex); // "#ffffff"

// Type a full string slowly
await cc.typeString("hello world\n");
```

---

## 🧩 API Reference

### 🖱 Mouse

#### `moveMouse(x: number, y: number)`
Moves the mouse to screen coordinate (x, y).

#### `clickMouse()`
Performs a left mouse click.

#### `rightClickMouse()`
Performs a right mouse click.

#### `middleClickMouse()`
Performs a middle mouse click.

#### `getMousePosition(): { x: number, y: number }`
Returns the current mouse position.

---

### 🎹 Keyboard

#### `typeKey(key: string)`
Presses and releases the given key (e.g., `"a"`, `"ctrl"`, `"return"`, `"space"`).

#### `typeKeyWithState(key: string, isKeyDown: boolean)`
Manually control key press state.
- `true`: key down
- `false`: key up

#### `typeCombo(keys: string[])`
Presses multiple keys together (useful for combos like `["ctrl", "c"]`).

#### `typeString(str: string, delay?: number)`
Types a string character-by-character with optional delay (default 20ms between keys).
Supports:
- Letters a–z
- Digits 0–9
- `space`, `enter` (`\n`)
Unrecognized characters are ignored.

---

### 🎨 Screen

#### `getPixelColor(x: number, y: number): { r, g, b }`
Returns the RGB color at the screen coordinate (x, y).

#### `getPixelHex(x: number, y: number): string`
Returns the hex string of the color at (x, y), e.g., `"#00ffcc"`.

---

## ✅ Supported Keys

Currently supports basic keys like:
- Letters: `a`–`z`
- Digits: `0`–`9`
- Modifiers: `ctrl`, `shift`, `alt`, `cmd`
- Special: `space`, `tab`, `return`, `escape`, `delete`, `minus`, `equal`, etc.

Add more keys in the `typeKey` implementation if needed.

---

## 🖥 Platform Support

- ✅ macOS (fully implemented)
- 🟡 Windows (in progress — PRs welcome!)
- ❌ Linux (not yet supported)

---

## 🛠 Development

Folder structure:

```
crosscontrol/
├── mac/              # macOS-specific native functions
├── win/              # Windows-specific native functions
├── src/
│   └── main.cpp      # N-API bindings
├── mouse.h           # Shared header with declarations
├── binding.gyp       # Build config
└── index.js          # JavaScript wrapper with extras
```

---

## 📄 License

MIT

---

## 🤝 Contributing

Feel free to open issues or submit PRs to improve Windows support, add new keys, or optimize the build system.