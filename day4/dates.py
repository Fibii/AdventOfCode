import datetime
class Dates:
    def __init__(self):
        file = open("input.txt")
        data = []
        for i in file.readlines():
            data.append(i.rstrip())

        self.dates = sorted(data, key=lambda x: datetime.datetime.strptime(x.split("] ")[0].replace("[", "").replace(" ", "-").replace(":", "-"), '%Y-%m-%d-%H-%M'))




d = Dates()