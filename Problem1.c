
#include<stdio.h>
int x_final = 0;
int y_final = 0;
int x_step = 0; 
int y_step = 0;
int count = 0;

void countpath(int x_loc,int y_loc,char direction, int k){
	if(direction == 'r'){
		y_step = 0;
		x_loc++;
		x_step++;
		printf("Coordinate-(%d,%d) x_step=%d y_step=%d c=%d\n",x_loc,y_loc,x_step,y_step,count);
	}
	if(direction == 'u'){
		x_step = 0;
		y_loc++;
		y_step++;
		printf("Coordinate-(%d,%d) x_step=%d y_step=%d c=%d\n",x_loc,y_loc,x_step,y_step,count);
	}
	if(x_loc==x_final && y_loc==y_final){
		x_step = 0;
		y_step = 0;
		count++;
	}
	if(x_loc < x_final){
		if(x_step < k){
			int temp_x = x_step, temp_y = y_step;
			countpath(x_loc,y_loc,'r',k);
			x_step = temp_x;
			y_step = temp_y;
		}
	}
	if(y_loc < y_final){
		if(y_step < k){
			countpath(x_loc,y_loc,'u',k);
		}
	}
}

int main(){
	int x_path,y_path,constraint;
	printf("Enter the value of m,n,k =\n");
	scanf("%d %d %d",&x_path,&y_path,&constraint);
	x_final = x_path-1;
	y_final = y_path-1;
	printf("(%d,%d) \n",x_final,y_final);
	countpath(0,0,'r',constraint);
	x_step = 0, y_step = 0;
	countpath(0,0,'u',constraint);
	printf("%d",count);
}


