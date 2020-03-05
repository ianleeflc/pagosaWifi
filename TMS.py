# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:\Users\yli\Desktop\untitled.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!

import urllib.request
import requests
from PyQt5 import QtCore, QtGui, QtWidgets
import sys
from PyQt5.QtWidgets import QMainWindow, QApplication


class Ui_MainWindow(QtGui.QMainWindow):
    def __init__(sefl):
        super().__init__()
        self.setupUi(self)
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.lcdNumber = QtWidgets.QLCDNumber(self.centralwidget)
        self.lcdNumber.setGeometry(QtCore.QRect(10, 20, 181, 71))
        self.lcdNumber.setObjectName("lcdNumber")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Temperature Monitoring System"))

def read_data_thingspeak():
    URL='https://api.thingspeak.com/channels/983197/fields/1.json?api_key=26ZX2F1R5YCUA83A&results=20'
    print(URL)
    get_data=requests.get(URL).json()
    feild_1=get_data['feeds']
    print(feild_1)
    t=[]
    for x in feild_1:
        print(x['field1'])
        t.append(x['field1'])

if __name__ == '__main__':
#    read_data_thingspeak()
    app=QtGui.QApplication(sys.argv)
    ex=Ui_MainWindow()
    ex.show()
    app.exec_()
#    sys.exit(app.exec_())


