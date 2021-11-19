#include <iostream>
using namespace std;
float yn[6];
float f(float x, float y){
    y=(x*(1+((x*x)/2))/(1-((x*x)/3)));
    return y;
}
int count=0;
void ImprovedEuler(int i,float h, float x[],float y[]){
    count=count+1;
    if (count==1){
        y[i]=2.0;
        yn[i]=2.0;
        ImprovedEuler(i,h,x,y);
        return;
    }
    if(i>6){
        return;
    }
    y[i+1]= y[i]+h*f(x[i]+(h/2),y[i]+(h/2) *f(x[i],y[i]));
    y[i+1]=yn[i+1];
    ImprovedEuler(i+1,h,x,y);
}
int main() {
    float x[]={1.0,1.1,1.2,1.3,1.4,1.5};
    ImprovedEuler(0,0.1,x,yn);
    int size = sizeof(yn)/sizeof(yn[0]);
    for(int i=0;i<size;i++){
        cout<<yn[i]<<endl;
    }
    system("pause");
}
