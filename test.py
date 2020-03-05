import sys
from PyQt5.QtWidgets import QMainWindow, QApplication
class Example(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.statusBar().showMessage('Ready')
        self.setGeometry(300,300,450,150)
        self.setWindowTitle('Statusbar')
        self.show()
#app=QApplication(sys.argv)
print(sys.argv[0])
ex=Example()
sys.exit(app.exec_())








