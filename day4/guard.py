import re
import datetime
class Guard:
    def __init__(self,id,begin,falls,wakes,date):
        self.id = id
        self.begin = begin
        self.falls = falls
        self.wakes = wakes
        self.date = datetime.datetime.strptime(date,'%Y-%m-%d-%H-%M')
        self.available = False
        self.sleepTime = 0
        self.maxSleep = 0
        self.dateList = [date]

    def addTime(self,time,begin,falls,wakes): #so when looping we can check if there's a guard object: add time
        t = datetime.datetime.strptime(time,'%Y-%m-%d-%H-%M')


        if falls == 'falls':
            #print('sleeptime from Guard class is:',self.sleepTime)
            self.date = t
        else: #sleeping
            self.dateList.append(t)
            #print('if reached with','b:',begin,'f;',falls,"w:",wakes)
            if self.sleepTime == 0:
                #print('timedela:',datetime.timedelta(self.sleepTime),'t:',t,'selfData:',self.date)
                self.sleepTime = datetime.timedelta(self.sleepTime) + (t - self.date)
                self.maxSleep = self.sleepTime
            else:
                self.sleepTime = self.sleepTime + (t - self.date)
                if  self.maxSleep < self.sleepTime:
                    self.maxSleep = self.sleepTime

        #print('from Guard, id:',self.id,'date:',self.date,"sleep;",self.sleepTime)

