from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy import Column, Integer, String, extract
from service.userservice import User

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] ='mysql+pymysql://root:root@101.35.107.33:3306/musics'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class manager(db.Model):
    __tablename__ = 'manager'
    opid = db.Column(db.Integer,primary_key=True)
    passwd = db.Column(db.String(255))
    mname = db.Column(db.String(255))
    icon = db.Column(db.String(255))
    def __init__(self,opid,passwd,mname,icon):
        self.opid = opid
        self.passwd = passwd
        self.mname = mname
        self.icon = icon

#获取管理员个人信息
def getOpInfo(opid):
    opInfo = db.session.query(manager).filter_by(opid=opid)
    return opInfo

def getOpInfo_Bymname(mname):
    opInfo = db.session.query(manager).filter_by(mname=mname)
    return opInfo
