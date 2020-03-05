# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'v3_singleLCDBG.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


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
        MainWindow.resize(1174, 709)
        MainWindow.setAutoFillBackground(False)
        MainWindow.setStyleSheet("")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.textEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(30, 40, 480, 50))
        self.textEdit.setStyleSheet("font: 10pt \"Italic\";")
        self.textEdit.setLineWidth(0)
        self.textEdit.setObjectName("textEdit")
        self.lcdNumber = QtWidgets.QLCDNumber(self.centralwidget)
        self.lcdNumber.setGeometry(QtCore.QRect(100, 90, 201, 81))
        self.lcdNumber.setObjectName("lcdNumber")
        self.BGImg = QtWidgets.QLabel(self.centralwidget)
        self.BGImg.setGeometry(QtCore.QRect(0, 0, 1171, 711))
        self.BGImg.setText("")
        self.BGImg.setPixmap(QtGui.QPixmap("f1.jpg"))
        self.BGImg.setScaledContents(True)
        self.BGImg.setObjectName("BGImg")
        self.BGImg.raise_()
        '''usr code'''
        self.timer=QTimer()
        self.timer.setInterval(1000)
        self.timer.start()
        #self.cnter=1
        self.read_data_thingspeak()
        self.timer.timeout.connect(self.updateLCD)
        '''usr code'''

        self.textEdit.raise_()
        self.lcdNumber.raise_()
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.textEdit.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Italic\'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Pool No. 1 Temp in </span><span style=\" font-size:18pt; vertical-align:super;\">o</span><span style=\" font-size:18pt;\">F</span></p></body></html>"))
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
