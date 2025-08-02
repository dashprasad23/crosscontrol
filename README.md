# crosscontrol

**crosscontrol** is a cross-platform Node.js native addon for automating mouse and keyboard input, and reading screen pixel data. Useful for scripting, testing, and UI automation tasks.

---

## ✨ Features

- Move the mouse to any screen coordinates
- Perform left, right, or middle clicks
- Read the current mouse position
- Simulate individual keys or key combinations
- Get the RGB/Hex color of any screen pixel

---

## ✅ Platform Support

- ✅ **macOS** – Fully tested
- 🟡 **Windows** – In progress (core functions work)
- ❌ **Linux** – Not supported

---

## 📦 Installation

```bash
npm install crosscontrol
```

> ⚠️ Requires native build toolchain:
> - **macOS:** Xcode Command Line Tools
> - **Windows:** Visual Studio with C++ support + Windows Build Tools
> - **Linux:** Not supported

---

## 🚀 Usage Example

```js
const cc = require('crosscontrol');

cc.moveMouse(500, 300);
cc.clickMouse();

console.log(cc.getMousePosition()); // { x: 500, y: 300 }

cc.typeKey("a");
cc.typeCombo(["ctrl", "c"]);

const rgb = cc.getPixelColor(100, 100);
console.log(rgb); // { r: 255, g: 255, b: 255 }

console.log(cc.getPixelHex(100, 100)); // "#ffffff"

await cc.typeString("hello world\n");
```

---

## 🧩 API Reference

### Mouse

- `moveMouse(x, y)`
- `clickMouse()`
- `rightClickMouse()`
- `middleClickMouse()`
- `getMousePosition() → { x, y }`

### Keyboard

- `typeKey(key)`
- `typeKeyWithState(key, isDown)`
- `typeCombo([keys])`
- `typeString(str, delay?)`

### Pixel

- `getPixelColor(x, y) → { r, g, b }`
- `getPixelHex(x, y) → "#rrggbb"`

---

## 📄 License

MIT

---

## 🤝 Contributing

Contributions welcome – especially for improving Windows support!
