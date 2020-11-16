

#if 1


int Sensor_Read(int s1, int s2, int s3, int s4, int s5);
// int Sensor_Read(int s1, int s2, int s3, int s4);
int read_value[5];
//int read_value[4];

int Sensor_Read(int s1, int s2, int s3, int s4, int s5) {
//int Sensor_Read(int s1, int s2, int s3, int s4) {
      
      read_value[0] = s1;
      read_value[1] = s2;
      read_value[2] = s3;
      read_value[3] = s4;
      read_value[4] = s5;
      
      return 0;
}


int main()
{
    int s1 = 1;
    int s2 = 2;
    int s3 = 3;
    int s4 = 4;
    int s5 = 5;
      
   
    Sensor_Read(s1, s2, s3, s4, s5);
    //Sensor_Read(s1, s2, s3, s4);
    
    return 0;
    
}

#endif
