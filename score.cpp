#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<sstream>

using namespace std;

int main()
{
    string line,name,sex,score;
    struct Student{string name;string sex;float score;};
    fstream scores("score.csv");
    if(!scores.is_open())
    { 
	cout<<"Could not find the file."<<endl;
	return 0;
    } 
    int count=0;
    Student *stu=new Student[50];
    while(getline(scores,line))
    {
	if(count==0)
	{
	    count++;
	    continue;
	}
	else
	{   stringstream ss(line);
	    getline(ss,name,',');
	    getline(ss,sex,',');
	    getline(ss,score,',');
	    sex.erase(0,1);
	    score.erase(0,1); 
	    stu[count].name=name;
	    stu[count].sex=sex;
	    char p[10];
	    strcpy(p,score.c_str());
	    stu[count].score=atof(p);
	}
	count++;
    }
    float aveall,aveboy,avegirl;
    float sum=0,sumb=0,sumg=0;
    int cb=0,cg=0;
    for(int i=1;i<count;i++)
    {
	sum+=stu[i].score;
	if(stu[i].sex=="Female")
	{
	    sumg+=stu[i].score;
	    cg++;
	}
	else if(stu[i].sex=="Male")
	{
	    sumb+=stu[i].score;
	    cb++;
	}
    }
    aveall=sum/(count-1);
    aveboy=sumb/cb;
    avegirl=sumg/cg;
    cout<<"全班平均分："<<aveall<<endl;
    cout<<"所有男生平均分："<<aveboy<<endl;
    cout<<"所有女生平均分："<<avegirl<<endl;
    Student stum;
    float max;
    int maxp;
    for(int j=1;j<count-1;j++)
    {
	max=stu[j].score;
        maxp=j;
	stum=stu[j];
	for(int k=j+1;k<count;k++)
	{
	    if(stu[k].score>max)
	    {
		max=stu[k].score;
		maxp=k;
		stum=stu[k];
	    }
	}
	stu[maxp]=stu[j];
	stu[j]=stum;
    }
    for(int l=1;l<count;l++)
    {
	cout<<stu[l].name<<"    "<<stu[l].sex<<"    "<<stu[l].score<<endl;
    }
    return 0;
}
