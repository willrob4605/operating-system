import time
import threading
import random


class philosopher:
    def __init__(self,number,state):
          self.number=number
          self.state=state


class fork:
    def __init__(self,number,state):
            self.number=number
            self.state=state
            self.lock=threading.Lock()


philosophers=[]
forks=[]
threads=[]

# semaphore 
lock=threading.Semaphore(4)

start_time=time.time()

def timestamp():
      total=int(time.time()-start_time)
      minutes=total//60
      seconds=total%60
      return f"[{minutes:02}:{seconds:02}]"


for i in range(5):
      philosophers.append(philosopher(i+1,'thinking'))
      forks.append(fork(i+1,'down'))

def eat(i):
      left_fork=forks[i]
      right_fork=forks[(i+1)%5]

      while True:
            # thinking state
            philosophers[i].state='thinking'
            print(timestamp()+" Philosopher "+str(philosophers[i].number)+" is Thinking.")
            time.sleep(random.uniform(1,3))

            # acquire lock
            lock.acquire()

            #pick up forks
            left_fork.lock.acquire()
            print(timestamp()+" Philosopher "+str(philosophers[i].number)+" picked up Left Fork")
            time.sleep(1.0)
            right_fork.lock.acquire()
            print(timestamp()+" Philosopher "+str(philosophers[i].number)+" picked up Right Fork")
            time.sleep(1.0)

            #eating state
            philosophers[i].state='eating'
            print(timestamp()+" Philosopher "+str(philosophers[i].number)+" is Eating.")
            time.sleep(5.0)

            #put down forks
            right_fork.lock.release()
            print(timestamp()+" Philosopher "+str(philosophers[i].number)+" put down Right Fork")
            time.sleep(1.0)
            left_fork.lock.release()
            print(timestamp()+" Philosopher "+str(philosophers[i].number)+" put down Left Fork")
            time.sleep(1.0)

            # release lock
            lock.release()

for i in range(5):
      t=(threading.Thread(target=eat,args=(i,)))
      threads.append(t)


if __name__ == '__main__':

    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()
