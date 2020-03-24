#pragma once

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C"
{
#endif

  void InitArcada();
  void InitDisplay();

  void FillScreen(uint16_t color);
  void DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

  void CanvasInit(int w, int h);
  void CanvasFillScreen(uint16_t color);
  void CanvasDrawFilledRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  void CanvasDrawFilledCirc(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  void CanvasBlit(int x, int y);

  int16_t ReadJoystickX();
  int16_t ReadJoystickY();
  uint8_t ReadButtons();
  bool WasButtonAPressed(uint8_t buttons);
  bool WasButtonBPressed(uint8_t buttons);
  bool WasButtonStartPressed(uint8_t buttons);
  bool WasButtonSelectPressed(uint8_t buttons);
  bool WasButtonUpPressed(uint8_t buttons);
  bool WasButtonRightPressed(uint8_t buttons);
  bool WasButtonDownPressed(uint8_t buttons);
  bool WasButtonLeftPressed(uint8_t buttons);
  void SetBacklight(uint8_t brightness);

#ifdef __cplusplus /* If this is a C++ compiler, end C linkage */
}
#endif
