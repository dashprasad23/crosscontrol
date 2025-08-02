{
  "targets": [
    {
      "target_name": "crosscontrol",
      "sources": [
        "src/main.cpp"
      ],
      "conditions": [
        ["OS=='mac'", {
          "sources": [
            "src/mac/move_mouse.cpp",
            "src/mac/click_mouse.cpp",
            "src/mac/get_mouse_position.cpp",
            "src/mac/get_pixel_color.cpp",
            "src/mac/right_click_mouse.cpp",
            "src/mac/middle_click_mouse.cpp",
            "src/mac/type_combo.cpp"
          ]
        }],
        ["OS=='win'", {
          "sources": [
            "src/win/mouse_win.cpp"
          ]
        }]
      ]
    }
  ]
}
