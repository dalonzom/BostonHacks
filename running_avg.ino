int running_avg(int* array, int count, int overallCount)  {
  int avg_start = 0;
  float sum = 0;
  int num_el = float(count);
 
  if(count >= 20 )  {  
    avg_start = count - 20;
    num_el = 20;
  }
  if(count < 20 && overallCount != 0 )
  {
    for(int i = 50-(20-count); i < 50; i++)
    {
      sum +=array[i]; 
    }
  }
  
  for(int ii = avg_start; ii<count; ii++)  {
    sum += array[ii];
  }

  if(count==0)
    return array[0]; 
  float average = sum/num_el;
  
  return int(average);
}
