/*
 * Shows the grid
 */
void showGrid() {
  setElements(0xFF);
  setCmd(0x42);
 delay(multiSpeed);
  setElements(0xFF);
  setCmd(0x43);
 delay(multiSpeed);
}
