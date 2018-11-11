from Tkinter import *
import record_data
import nightlyGraph
import overallGraphs
import serial

class Application(Frame):
    def plot_history(self):
        print "hi there, everyone!"
        overallGraphs.overallGraphs(1)

    def plot_recent(self):
        print "Ugh"
        nightlyGraph.nightlyGraph(1)

    def collect_data(self):
        print "Woo"
	record_data.record_data(2)
        ser = serial.Serial("COM1",9600)
        ser.write("1")

    def createWidgets(self):
	self.data= Button(self)
        self.data["text"] = "Start",
        self.data["command"] = self.collect_data
        self.data.pack({"side": "left"})

        self.plot= Button(self)
        self.plot["text"] = "Analyze Previous Night"
        self.plot["command"] = self.plot_recent
        self.plot.pack({"side": "left"})

        self.overall= Button(self)
        self.overall["text"] = "Analyze History"
        self.overall["command"] = self.plot_history
        self.overall.pack({"side": "left"})

        self.CLOSE = Button(self)
        self.CLOSE["text"] = "Close"
        self.CLOSE["fg"]   = "red"
        self.CLOSE["command"] =  self.quit
        self.CLOSE.pack({"side": "left"})
        

    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

root = Tk()
app = Application(master=root)
app.mainloop()
root.destroy()
