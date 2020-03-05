# v2, arduino master, ESP, single display slot, data from thingspeak
import time
import requests
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import sys

class Ui_MainWindow(QWidget):
    def __init__(self,parent=None):
        super(Ui_MainWindow, self).__init__(parent)

    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.lcdNumber = QtWidgets.QLCDNumber(self.centralwidget)
        self.lcdNumber.setGeometry(QtCore.QRect(10, 20, 181, 71))
        self.lcdNumber.setObjectName("lcdNumber")
        '''usr code'''
        self.timer=QTimer()
        self.timer.setInterval(1000)
        self.timer.start()
        #self.cnter=1
        self.read_data_thingspeak()
        self.timer.timeout.connect(self.updateLCD)
        '''usr code'''
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Temperature Monitoring System"))

    def updateLCD(self): #display the variable 'event' to the display
        self.lcdNumber.display(self.t[-1])
        #self.cnter+=1
        self.read_data_thingspeak()

    def read_data_thingspeak(self):
        URL='https://api.thingspeak.com/channels/983197/fields/1.json?api_key=26ZX2F1R5YCUA83A&results=20'
        print(URL)
        get_data=requests.get(URL).json()
        feild_1=get_data['feeds']
        #print(feild_1)
        self.t=[]
        for x in feild_1:
            #print(x['field1'])
            self.t.append(x['field1'])
        #return self.t[-1]

''' user code '''
if __name__ == '__main__':
    #tt=read_data_thingspeak()
    app=QtWidgets.QApplication(sys.argv)
    MainWindow=QtWidgets.QMainWindow()
    ui=Ui_MainWindow()
    ui.setupUi(MainWindow)
#    ui.updateLCD(tt[-1])
    #tt[-1]+='1'
    MainWindow.show()
    sys.exit(app.exec_())
''' user code '''
