int light_map(int raw)  {
  int light = map(raw, 0, 800, 0, 100);
  
  return light;  
}
