float light_map(int raw)  {
  float light = map(raw, 0, 800, 0, 100);
  
  return light;  
}
