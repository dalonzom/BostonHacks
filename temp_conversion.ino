int temp_conversion(int raw)  {
  const int B = 4275;
  const int R0 = 100000;
  
  float R = 1023/raw-1.0;
  R = R0*R;
  
  float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  
  return temp;
}
