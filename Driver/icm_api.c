#include"icm_api.h"
#include"icm45686_driver.h"
#include<math.h>

//初始化
void icm_init();
//读温度
float icm_read_temp();
//读加速度
uint8_t icm_read_accel(float*ax,float*ay,float*az);
//读陀螺仪
uint8_t icm_read_gyro(float*gx,float*gy,float*gz);

//初始化
void icm_init()
{
    while(icm45686_init())
    {
        // printf("init err\n");
        osDelay(100);
    }
}

//读温度
float icm_read_temp()
{
    int16_t temp=0;
    if(!icm45686_read_temp(&temp))
    {
        return (float)(temp/128.0+25);
    }
    return 0.0;
}
//读加速度
uint8_t icm_read_accel(float*ax,float*ay,float*az)
{
    int16_t accel_x=0;
    int16_t accel_y=0;
    int16_t accel_z=0;
    if(!icm45686_read_accel(&accel_x,&accel_y,&accel_z))
    {
        //按量程转换到正确单位
        if(ax)*ax=(float)(accel_x/1024.0);
        if(ay)*ay=(float)(accel_y/1024.0);
        if(az)*az=(float)(accel_z/1024.0);
    }
    return 0;
}
//读陀螺仪
uint8_t icm_read_gyro(float*gx,float*gy,float*gz)
{
    int16_t gyro_x=0;
    int16_t gyro_y=0;
    int16_t gyro_z=0;
    if(!icm45686_read_gyro(&gyro_x,&gyro_y,&gyro_z))
    {
        //按量程转换到正确单位
        if(gx)*gx=(float)(gyro_x/8.2);
        if(gy)*gy=(float)(gyro_y/8.2);
        if(gz)*gz=(float)(gyro_z/8.2);
    }
    return 0;
}
