#include<stdio.h>
#include<conio.h>

struct process {
		int processId ;
		int priority ;
		int arrivalTime ;
		int burstTime ;
		int responseTime ;
};
struct process queue1[100], queue2[100], queue3[100] ;
int rear1 = -1 ;
int front1 = -1 ;
int rear2 = -1 ;
int front2 = -1 ;
int rear3 = -1 ;
int front3 = -1 ;
void queue1Push(struct process proc) {
	if(front1 == -1) {
		front1 = 0 ;
	}
	rear1 = rear1 + 1 ;
	queue1[rear1] = proc ;
}
void queue1Pop() {
	front1 = front1 + 1 ;
}
struct process queue1Front() {
	return queue1[front1] ;
}
void queue2Push(struct process proc) {
	if(front2 == -1) {
		front2 = 0 ;
	}
	rear2 = rear2 + 1 ;
	queue2[rear2] = proc ;
}
void queue2Pop() {
	front2 = front2 + 1 ;
}
struct process queue2Front() {
	return queue2[front2] ;
}
void queue3Push(struct process proc) {
	if(front3 == -1) {
		front3 = 0 ;
	}
	rear3 = rear3 + 1 ;
	queue3[rear3] = proc ;
}void queue3Pop() {
	front3 = front3 + 1 ;
}
struct process queue3Front() {
	return queue3[front3] ;
}
void createProcess(int n, struct process proc[]) {	
	int i ;
	for(i=0; i<n; i++) {
		printf("Enter Process Id") ;
		scanf("%d",&proc[i].processId) ;
		printf("Enter Process Arrival Time") ;
		scanf("%d",&proc[i].arrivalTime) ;
		printf("Enter Process Burst Time") ;
		scanf("%d",&proc[i].burstTime) ;
		printf("Enter Processes Priority") ;
		scanf("%d",&proc[i].priority) ;
		proc[i].responseTime = proc[i].burstTime ;
	}}
void assignProcessInQueue(int n, struct process proc[]) {
	int i ;
	for(i=0; i<n; i++) {
		if((proc[i].priority)>=0 && (proc[i].priority)<100) {
			queue1Push(proc[i]) ;
		} else if ((proc[i].priority)>=100 && (proc[i].priority)<200) {
			queue2Push(proc[i]) ;
		} else if ((proc[i].priority)>=200 && (proc[i].priority)<300) {
			queue3Push(proc[i]) ;
		} }	}
void printQueueFront() {
	int i ;
	printf("Process in Queue 1 - ") ;
	for(i=0;i<=rear1;i++) {
		printf("P%d  ",queue1[i].processId) ;
	}
	printf("\nProcess in Queue 2 - ") ;

	for(i=0;i<=rear2;i++) {
		printf("P%d  ",queue2[i].processId) ;
	}
	printf("\nProcess in Queue 3 - ") ;
	for(i=0;i<=rear3;i++) {
		printf("P%d  ",queue3[i].processId) ;
	}
	printf("\n") ;
}
void roundRobin(int n, struct process proc[]) {
 	int i,j,time,remain=n,flag=0,timeQuantum = 4,waitTime=0,turnAroundTime=0 ;
 	printf("\n\nProcess\t\tWaiting Time    Turnaround Time\n\n"); 
  	for(time=0,i=0;remain!=0;) {  	 
	    if((proc[i].responseTime<=timeQuantum) && (proc[i].responseTime)>0) { 
			time+=(proc[i].responseTime); 
	      	(proc[i].responseTime)=0; 
	      	flag=1; 
	    } else if((proc[i].responseTime)>0) { 
			(proc[i].responseTime)-=timeQuantum; 
			time+=timeQuantum; 
	    } if((proc[i].responseTime)==0 && flag==1) { 
		    remain--; 
			printf("Process[%d]\t\t%d\t\t%d\n",proc[i].processId,time-((proc[i].arrivalTime)-(proc[i].burstTime)),time-(proc[i].arrivalTime)); 
		    waitTime+=time-(proc[i].arrivalTime)-(proc[i].burstTime); 
			turnAroundTime+=time-(proc[i].arrivalTime); 
		    flag=0; 
	    } if(i==n-1) 
	    	i=0; 
	    else if((proc[i+1].arrivalTime)<=time) 
	    	i++; 
	    else 
	    	i=0; 
	} 
	printf("\nAverage Waiting Time= %f\n",waitTime*1.0/n); 
	printf("Avg Turnaround Time = %f\n\n",turnAroundTime*1.0/n); 
}void fcfs(int n, struct process proc[]) {
		float waiting_time[30], turnaround_time[30];
        float average_waiting_time = 0.0, average_turnaround_time = 0.0;
        int count, j, total_process=n;
        waiting_time[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                waiting_time[count] = 0;
                for(j = 0; j < count; j++)
                {
                        waiting_time[count] = waiting_time[count] + proc[j].burstTime ;
                }}
        printf("\nProcess\t\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                turnaround_time[count] = proc[count].burstTime + waiting_time[count];
                average_waiting_time = average_waiting_time + waiting_time[count];
                average_turnaround_time = average_turnaround_time + turnaround_time[count];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f", proc[count].processId, waiting_time[count], turnaround_time[count]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time / count;
        average_turnaround_time = average_turnaround_time / count;
        	printf("\nAverage Waiting Time= %f\n",average_waiting_time ); 
	printf("Avg Turnaround Time = %f\n\n",average_turnaround_time);        
}
void queueScheduling1() {
	roundRobin(rear1+1, queue1) ;
}
void queueScheduling3() {
	fcfs(rear3+1, queue3) ;
}
int main() {
	int n ;
	printf("How many process - ") ;
	scanf("%d",&n) ;
	struct process proc[n] ;
	createProcess(n, proc) ;
	assignProcessInQueue(n, proc) ;
	printQueueFront() ;
	queueScheduling1() ;
	queueScheduling3() ;

}

