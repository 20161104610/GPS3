//
//  main.c
//  GPS
//
//  Created by 20161104610 on 17/6/16.
//  Copyright © 2017年 20161104610. All rights reserved.
//

#include <stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int i,j;
    char name[10];
    char utc1[10],minu1[10],ss1[10],yesno[10],nor1[10],eas1[10],lon1[10],groud1[10],time1[10],more1[10];
    char utc2[10],minu2[10],ss2[10],nor2[10],eas2[10],lon2[10],groud2[10],time2[10],more2[10];
    char a[1000][1000];
    
    FILE *fr;
    FILE *fw;
    
    fr=fopen("/Users/a201611046101/Desktop/GPS/GPS170510.log","r+");
    fw=fopen("/Users/a201611046101/Desktop/GPS/GPS.csv","w");
    
    for(i=0;i<=1000;i++)
    {
        fgets(a[i],63,fr);
        //printf("%s",a[i]);
    }
    printf("\n");
    
    fprintf(fw,"时,分,秒,效用,北纬,东经,地面速率,航向,月日年,磁偏角\n");
    
    for(j=0;j<=1000;j++)
    {
        strncpy(name,&a[j][0],4);
        if(name[1]=='G')
        {
            if(name[3]=='R')
            {
                strncpy(utc1,&a[j][7],2);
                utc1[2]='\0';
                strncpy(minu1,&a[j][8],2);
                minu1[2]='\0';
                strncpy(ss1,&a[j][10],2);
                ss1[2]='\0';
                strncpy(yesno,&a[j][14],1);
                yesno[1]='\0';
                strncpy(nor1,&a[j][16],9);
                nor1[9]='\0';
                strncpy(eas1,&a[j][27],9);
                eas1[9]='\0';
                strncpy(lon1,&a[j][39],5);
                lon1[5]='\0';
                strncpy(groud1,&a[j][45],5);
                groud1[5]='\0';
                strncpy(time1,&a[j][51],6);
                time1[6]='\0';
                strncpy(more1,&a[j][59],3);
                more1[3]='\0';
                printf("当前%s时%s分%s秒,效用为%s,北纬为%s,东经为%s,地面速率为%s,航向为%s,月日年为%s,磁偏角为%s\n",utc1,minu1,ss1,yesno,nor1,eas1,lon1,groud1,time1,more1);
                fprintf(fw,"%s,%s,%s,%s,%s%s,%s,%s,%s,%s\n",utc1,minu1,ss1,yesno,nor1,eas1,lon1,groud1,time1,more1);
            }
            else if(name[3]=='G')
            {
                strncpy(utc2,&a[j][7],6);
                utc2[2]='\0';
                strncpy(minu2,&a[j][8],2);
                minu2[2]='\0';
                strncpy(ss2,&a[j][10],2);
                ss2[2]='\0';
                strncpy(nor2,&a[j][14],9);
                nor2[9]='\0';
                strncpy(eas2,&a[j][25],9);
                eas2[9]='\0';
                strncpy(lon2,&a[j][37],1);
                lon2[1]='\0';
                strncpy(groud2,&a[j][39],2);
                groud2[2]='\0';
                strncpy(time2,&a[j][43],4);
                time2[4]='\0';
                strncpy(more2,&a[j][54],3);
                more2[3]='\0';
                printf("当前%s时%s分%s秒,效用为%s,北纬为%s,东经为%s,地面速率为%s,航向为%s,月日为%s,磁偏角为%s\n",utc2,minu2,ss2,yesno,nor2,eas2,lon2,groud2,time2,more2);
                fprintf(fw,"%s,%s,%s,%s,%s%s,%s,%s,%s,%s\n",utc2,minu2,ss2,yesno,nor2,eas2,lon2,groud2,time2,more2);
            }
        }
        else
        {
            continue;
        }
    }
    
    fclose(fr);
    
}
