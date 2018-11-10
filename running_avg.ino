int running_avg(int* array, int count)  {
  int avg_start = 0;
  float sum = 0;
  int num_el = float(count);
 
  if(count >= 20)  {  
    avg_start = count - 20;
    num_el = 20;
  }
  for(int ii = avg_start; ii<count; ii++)  {
    sum += array[ii];
  }
  
  float average = sum/num_el;
  
  return int(average);
}
