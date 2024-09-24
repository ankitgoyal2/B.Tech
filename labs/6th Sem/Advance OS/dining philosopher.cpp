#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#define N 3
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N
using namespace std;
int state[N],phil[N] = { 0, 1, 2 };
sem_t mutex,S[N];

void test(int phnum)
{
	if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
		state[phnum] = EATING;
		usleep(2);
		cout<<"Philosopher "<<phnum + 1<<" is eating\n";
		sem_post(&S[phnum]);
	}
}
void take_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum] = HUNGRY;
	cout<<"Philosopher "<<phnum + 1<<" is hungry\n";
	test(phnum);
	sem_post(&mutex);
	sem_wait(&S[phnum]);
	usleep(1);
}
void put_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum] = THINKING;
	cout<<"Philosopher "<<phnum + 1<<" is thinking\n";
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}
void* philospher(void* num)
{
    int x=0;
	while (x<3)
    {
		int* i = (int *)num;
		usleep(1);
		take_fork(*i);
		usleep(0);
		put_fork(*i);
        x++;
	}
}
int main()
{
	int i;
	pthread_t thread_id[N];
	sem_init(&mutex, 0, 1);
	for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);
	for (i = 0; i < N; i++)
    {
		pthread_create(&thread_id[i], NULL, philospher, &phil[i]);
		cout<<"Philosopher "<<i+1<<" is thinking\n";
	}
	for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}
