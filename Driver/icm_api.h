#pragma once

//初始化
void icm_init();
//读温度
float icm_read_temp();
//读加速度
uint8_t icm_read_accel(float*ax,float*ay,float*az);
//读陀螺仪
uint8_t icm_read_gyro(float*gx,float*gy,float*gz);
