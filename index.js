const binding = require('node-gyp-build')(__dirname); // Loads native bindings (crosscontrol.node)

if (!binding || Object.keys(binding).length === 0) {
  console.warn('⚠️ Native module failed to load or is empty. Check build output and platform support.');
}

const cc = {
  ...binding,

  /**
   * Type a string character-by-character using `typeKey`.
   * @param {string} str - The string to type.
   * @param {number} delay - Delay in ms between key presses (default: 20).
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
        console.warn(`⚠️ Unsupported character: '${ch}'`);
      }

      if (delay > 0) await new Promise((r) => setTimeout(r, delay));
    }
  },

  /**
   * Get pixel color at (x, y) as a hex string like "#rrggbb".
   * @param {number} x
   * @param {number} y
   * @returns {string} - Hex color string.
   */
  getPixelHex: function (x, y) {
    const { r, g, b } = this.getPixelColor(x, y);
    return '#' + [r, g, b].map(c => c.toString(16).padStart(2, '0')).join('');
  }
};

module.exports = cc;
