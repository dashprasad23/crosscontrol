const binding = require('node-gyp-build')(__dirname);  // Assumes build/Release/crosscontrol.node is here
console.log('Native module exports:', Object.keys(binding));  // Debug line

const cc = {
  ...binding,

  /**
   * Type a string character by character using `typeKey`.
   * @param {string} str - The string to type.
   * @param {number} delay - Delay in milliseconds between keystrokes.
   */
  typeString: async function (str, delay = 20) {
    for (let i = 0; i < str.length; i++) {
      const ch = str[i].toLowerCase();

      if (ch === " ") {
        this.typeKey("space");
      } else if (ch === "\n") {
        this.typeKey("return");
      } else if (/^[a-z0-9]$/.test(ch)) {
        this.typeKey(ch);
      } else {
        console.warn(`Unsupported character: '${ch}'`);
      }

      if (delay > 0) await new Promise((r) => setTimeout(r, delay));
    }
  },

  /**
   * Get pixel color in hex format.
   */
  getPixelHex: function (x, y) {
    const { r, g, b } = this.getPixelColor(x, y);
    return '#' + [r, g, b].map(c => c.toString(16).padStart(2, '0')).join('');
  }
};

// ✅ DEMO USAGE

// cc.moveMouse(400, 300);
// cc.clickMouse();

// const pos = cc.getMousePosition();
// console.log('Mouse Position:', pos);

// cc.typeKey("a");

// cc.rightClickMouse();
// cc.middleClickMouse();

// cc.typeCombo(["ctrl", "c"]);

// cc.getPixelColor(pos.x, pos.y);
// console
